#include "stdafx.h"
#include "Device.h"
#include "nsvr_region.h"
#include "protobuff_defs/HighLevelEvent.pb.h"
#include "logger.h"

Device::Device(
	std::string parentPlugin,
	DeviceDescriptor descriptor, 
	std::unique_ptr<DeviceVisualizer> visualizer,
	std::unique_ptr<HardwareBodygraphCreator> bodygraph,
	std::unique_ptr<HardwareNodeEnumerator> discoverer, 
	std::unique_ptr<HardwarePlaybackController> playback,
	std::unique_ptr<HardwareWaveform> haptics,
	std::unique_ptr<HardwareTracking> tracking
)
	: m_description(descriptor)
	, m_visualizer(std::move(visualizer))
	, m_bodygraph(std::move(bodygraph))
	, m_discoverer(std::move(discoverer))
	, m_playback(std::move(playback))
	, m_haptics(std::move(haptics))
	, m_originator(parentPlugin)
	, m_trackingProvider(std::move(tracking))
{
	m_discoverer->Discover();
	m_bodygraph->fetchDynamically();

	
	auto imus = m_discoverer->GetNodesOfType(nsvr_node_type_inertial_tracker);
	for (auto imu : imus) {
		m_trackingProvider->BeginStreaming(NodeId<local>{imu});
	}

}

void Device::DispatchEvent(const NullSpaceIPC::HighLevelEvent & event)
{
	switch (event.events_case()) {
	case NullSpaceIPC::HighLevelEvent::kPlaybackEvent:
		handlePlaybackEvent(event.parent_id(), event.playback_event());
		break;
	case NullSpaceIPC::HighLevelEvent::kLocationalEvent:
		handleLocationalEvent(event.parent_id(), event.locational_event());
	default:
		BOOST_LOG_SEV(clogger::get(), nsvr_severity_warning) << "[Device] Unrecognized request: " << event.events_case();
		break;
	}
}

void Device::DispatchEvent(const NullSpaceIPC::PlaybackEvent & playback_event)
{
}

void Device::DispatchEvent(uint64_t event_id, const NullSpaceIPC::SimpleHaptic & simple, const std::vector<nsvr_region>& regions)
{
	
	auto haptic_only = m_discoverer->FilterByType(m_bodygraph->GetNodesAtRegions(regions), nsvr_node_type_haptic);

	//So I guess the question is.. what do we do here.
	//Do we dispatch to only haptic nodes, in order of waveform->continueous->buffered?
	//Do we dispatch to anything that supports the correct apis? 
	//I think we need some Policies. 

	//policy{

	//if [haptic] and [supports waveform] then send IF  policy_strict?
	//if [led] and [supports waveform] then send IF policy_relaxed?
	//policy_greedy and policy_restrained?


	//so when you send an event you can say "let this be a greedy event, it will try to play on whatever it possibly can.
	//So if its a waveform, sure its gonna try to play on that kicker and that LED, not just an erm.
	//Or, "let this be a restrained event, only play on specific hardware that is really meant to support it". 
	
	/*
	Making up terminology: an event has an "execution class" such as haptic, led, kicker, etc.
	These events are implemented, at this level, by using the low level apis that somewhat correspond to the events.

	So with a "restrained" hint, it will only play on nodes that match the "execution class" of the event, and support the correct
	apis. With a "relaxed" hint, it will play on nodes that don't necessarily match the execution class, but do support the correct
	apis. 

	What does this get us? Just a ton of complexity?
	Freebees for the dev like: controlling all leds with haptics. Controlling a heat pad with a waveform.
	Triggering a kicker with a normal preset waveform instead of a specific impact event. 

	This could be the thing that allows the developer to say "hey, I want to target other hardware. I get that it might not be as good,
	but use your intelligence and do it". Or the dev can say, "Hey I want to target only this specific hardware". 
	
	
	*/
	for (const auto& node : haptic_only) {
		//if (m_discoverer->)
		//m_haptics->SubmitSimpleHaptic(event_id, node, SimpleHaptic(simple.effect(), simple.duration(), simple.strength()));
	}

	m_playback->CreateEventRecord(event_id, haptic_only);
}

void Device::DispatchEvent(uint64_t event_id, const NullSpaceIPC::SimpleHaptic& simple, const std::vector<NodeId<local>>& nodes)
{
	//todo: wholesale switch to using NodeId<local> internall as well
	std::vector<nsvr_node_id> temp;
	for (NodeId<local> n : nodes) {
		temp.emplace_back(n.value);
	}

	auto haptic_only = m_discoverer->FilterByType(temp, nsvr_node_type_haptic);

	for (const auto& node : haptic_only) {
		//todo: FIX
		//m_haptics->SubmitSimpleHaptic(event_id, node, SimpleHaptic(simple.effect(), simple.duration(), simple.strength()));
	}

	m_playback->CreateEventRecord(event_id, haptic_only); 
}

DeviceId<local> Device::id() const
{
	return DeviceId<local>{m_description.id};
}

std::string Device::name() const
{
	return m_description.displayName;
}


nsvr_device_concept Device::concept() const
{
	return m_description.concept;
}

std::string Device::parentPlugin() const
{
	return m_originator;
}

void Device::OnReceiveTrackingUpdate(TrackingHandler handler)
{
	m_trackingProvider->OnUpdate([this, callback = handler](NodeId<local> node, nsvr_quaternion* quat) {
		const auto& regions = m_bodygraph->GetRegionsForNode(node.value);
		for (const auto& region : regions) {
			callback(region, quat);
		}
	});
}

void Device::ForEachNode(std::function<void(Node*)> action)
{
	m_discoverer->ForEachNode(action);
}

void Device::update_visualizer(double dt)
{
	m_visualizer->simulate(dt);
}

std::vector<std::pair<nsvr_region, RenderedNode>> Device::render_visualizer()
{
	std::vector<std::pair<nsvr_region, RenderedNode>> taggedNodes;
	std::vector<RenderedNode> nodes = m_visualizer->render();
	for (const auto& node : nodes) {
		const auto& regions = m_bodygraph->GetRegionsForNode(node.Id.value);
		for (nsvr_region region : regions) {
			taggedNodes.emplace_back(region, node);
		}
	}
	return taggedNodes;
}

template<typename T, typename E>
std::vector<T> protoBufToVec(const google::protobuf::RepeatedField<E>& inArray) {
	std::vector<T> result;
	result.reserve(inArray.size());
	for (const auto& a : inArray) {
		result.push_back(static_cast<T>(a));
	}
	return result;
}

void Device::handleLocationalEvent(uint64_t event_id, const NullSpaceIPC::LocationalEvent & locational)
{
	switch (locational.events_case()) {
	case NullSpaceIPC::LocationalEvent::EventsCase::kSimpleHaptic:
		handleSimpleHaptic(event_id, locational.simple_haptic());
		break;
	default:
		break;
	}

}

void Device::handleSimpleHaptic(uint64_t event_id, const NullSpaceIPC::SimpleHaptic& simple)
{
	/*std::vector<nsvr_node_id> nodes;
	if (simple.where_case() == NullSpaceIPC::SimpleHaptic::kNodes) {
		nodes = protoBufToVec<nsvr_node_id>(simple.nodes().nodes());
	}
	else {
		auto regions = protoBufToVec<nsvr_region>(simple.regions().regions());
		nodes = m_bodygraph->GetNodesAtRegions(regions);
	}
	

	auto hapticNodes = m_discoverer->FilterByType(nodes, nsvr_node_type_haptic);

	for (nsvr_node_id node : hapticNodes) {
		m_haptics->SubmitSimpleHaptic(event_id, node, SimpleHaptic(simple.effect(), simple.duration(), simple.strength()));
	}

	m_playback->CreateEventRecord(event_id, hapticNodes);*/

}

void Device::handlePlaybackEvent(uint64_t id, const NullSpaceIPC::PlaybackEvent& playbackEvent)
{

	switch (playbackEvent.command()) {
	case NullSpaceIPC::PlaybackEvent_Command_UNPAUSE:
		m_playback->Resume(id);
		break;
	case NullSpaceIPC::PlaybackEvent_Command_PAUSE:
		m_playback->Pause(id);
		break;
	case NullSpaceIPC::PlaybackEvent_Command_CANCEL:
		m_playback->Cancel(id);
		break;
	default:
		break;
	}
}
