#include "stdafx.h"
#include "HardlightDevice.h"
#include <boost/uuid/random_generator.hpp>
#include <experimental/vector>
#include "PluginAPI.h"
#include "Locator.h"
#include "IMU_ID.h"


HardlightDevice::HardlightDevice(const InstructionSet& instructions) : m_drivers()
{

	auto& translator = Locator::Translator();

	for (int loc = (int)Location::Lower_Ab_Right; loc != (int)Location::Error; loc++) {

		m_drivers.insert(std::make_pair(
			(Location)loc, 
			std::make_unique<Hardlight_Mk3_ZoneDriver>(Location(loc), instructions))
		);
	}
}




void HardlightDevice::Configure(nsvr_core* ctx)
{


	nsvr_plugin_waveform_api waveform_api;
	waveform_api.client_data = this;
	waveform_api.activate_handler = [](uint64_t request_id, nsvr_node_id node_id, nsvr_default_waveform wave, uint32_t reps, float strength, void* cd) {
		AS_TYPE(HardlightDevice, cd)->handle_waveform(request_id, node_id, wave, reps, strength);
	};

	nsvr_register_waveform_api(ctx, &waveform_api);

	nsvr_plugin_playback_api playback_api;
	playback_api.client_data = this;
	playback_api.pause_handler = [](uint64_t handle, nsvr_node_id id, void* client_data) {
		AS_TYPE(HardlightDevice, client_data)->Pause(handle, id);
	};
	playback_api.cancel_handler = [](uint64_t handle, nsvr_node_id id, void* client_data) {
		AS_TYPE(HardlightDevice, client_data)->Cancel(handle, id);
	};
	playback_api.unpause_handler = [](uint64_t handle, nsvr_node_id id, void* client_data) {
		AS_TYPE(HardlightDevice, client_data)->Unpause(handle, id);
	};

	nsvr_register_playback_api(ctx, &playback_api);

	nsvr_plugin_buffered_api buffered_api;
	buffered_api.client_data = this;
	
	buffered_api.getsampleduration_handler = [](nsvr_node_id, double* outDuration, void* cd) {
		*outDuration = 25;
	};
	buffered_api.submit_handler = [](uint64_t request_id, nsvr_node_id id, const double* amplitudes, uint32_t count, void* cd) {
		AS_TYPE(HardlightDevice, cd)->Buffered(request_id, id, amplitudes, count);
	};
	nsvr_register_buffered_api(ctx, &buffered_api);

	


	
	
}



void HardlightDevice::Pause(ParentId handle, nsvr_node_id id)
{
	Location loc = static_cast<Location>(id);
	m_drivers[loc]->controlEffect(handle, 1);
}

void HardlightDevice::Cancel(ParentId  handle, nsvr_node_id id)
{
	Location loc = static_cast<Location>(id);
	m_drivers[loc]->controlEffect(handle, 3);
}

void HardlightDevice::Unpause(ParentId  handle, nsvr_node_id id)
{
	Location loc = static_cast<Location>(id);
	m_drivers[loc]->controlEffect(handle, 2);
}


void HardlightDevice::EnumerateNodesForDevice(nsvr_node_ids* ids)
{
	std::vector<nsvr_node_id> found_ids;
	for (const auto& device : m_drivers) {
		found_ids.push_back(device.second->GetId());
	}
	
	found_ids.push_back(NODE_IMU_CHEST);
	found_ids.push_back(NODE_IMU_RIGHT_UPPER_ARM);
	found_ids.push_back(NODE_IMU_LEFT_UPPER_ARM);

	for (std::size_t i = 0; i < found_ids.size(); i++) {
		ids->ids[i] = found_ids[i];
	}

	

	ids->node_count = found_ids.size();
}


void HardlightDevice::GetNodeInfo(nsvr_node_id id, nsvr_node_info* info) {

	if (id == NODE_IMU_CHEST) //chest imu 
	{
		info->concept = nsvr_node_concept_inertial_tracker;
		std::string outStr = "Hardlight Chest IMU ";
		std::copy(outStr.begin(), outStr.end(), info->name);
		return;
	}

	if (id == NODE_IMU_RIGHT_UPPER_ARM) {
		info->concept = nsvr_node_concept_inertial_tracker;
		std::string outStr = "Hardlight Right Upper Arm IMU ";
		std::copy(outStr.begin(), outStr.end(), info->name);
		return;
	}

	if (id == NODE_IMU_LEFT_UPPER_ARM) {
		info->concept = nsvr_node_concept_inertial_tracker;
		std::string outStr = "Hardlight Left Upper Arm IMU ";
		std::copy(outStr.begin(), outStr.end(), info->name);
		return;
	}

	const auto& t = Locator::Translator();
	auto it = std::find_if(m_drivers.begin(), m_drivers.end(), [id = id](const auto& driver) {
		return driver.second->GetId() == id;
	});

	if (it != m_drivers.end()) {
		info->concept = nsvr_node_concept_haptic;

		const auto& driver = it->second;
		std::string outStr = "Hardlight ZoneDriver " + t.ToString(driver->GetLocation());
		std::copy(outStr.begin(), outStr.end(), info->name);

	}
}




void HardlightDevice::SetupDeviceAssociations(nsvr_bodygraph* g)
{
	nsvr_bodygraph_associate(g, "upperChestActuators:0", m_drivers[Location::Chest_Left]->GetId());
	nsvr_bodygraph_associate(g, "leftAbActuators:0", m_drivers[Location::Upper_Ab_Left]->GetId());
	nsvr_bodygraph_associate(g, "leftAbActuators:1", m_drivers[Location::Mid_Ab_Left]->GetId());
	nsvr_bodygraph_associate(g, "leftAbActuators:2", m_drivers[Location::Lower_Ab_Left]->GetId());

	nsvr_bodygraph_associate(g, "leftShoulderActuator", m_drivers[Location::Shoulder_Left]->GetId());
	nsvr_bodygraph_associate(g, "leftUpperArmActuator", m_drivers[Location::Upper_Arm_Left]->GetId());
	nsvr_bodygraph_associate(g, "leftLowerArmActuator", m_drivers[Location::Forearm_Left]->GetId());

	nsvr_bodygraph_associate(g, "upperBackActuators:0", m_drivers[Location::Upper_Back_Left]->GetId());


	nsvr_bodygraph_associate(g, "upperChestActuators:1", m_drivers[Location::Chest_Right]->GetId());
	nsvr_bodygraph_associate(g, "rightAbActuators:0", m_drivers[Location::Upper_Ab_Right]->GetId());
	nsvr_bodygraph_associate(g, "rightAbActuators:1", m_drivers[Location::Mid_Ab_Right]->GetId());
	nsvr_bodygraph_associate(g, "rightAbActuators:2", m_drivers[Location::Lower_Ab_Right]->GetId());

	nsvr_bodygraph_associate(g, "rightShoulderActuator", m_drivers[Location::Shoulder_Right]->GetId());
	nsvr_bodygraph_associate(g, "rightUpperArmActuator", m_drivers[Location::Upper_Arm_Right]->GetId());
	nsvr_bodygraph_associate(g, "rightLowerArmActuator", m_drivers[Location::Forearm_Right]->GetId());

	nsvr_bodygraph_associate(g, "upperBackActuators:1", m_drivers[Location::Upper_Back_Right]->GetId());

	nsvr_bodygraph_associate(g, "chestCenter", NODE_IMU_CHEST);
	nsvr_bodygraph_associate(g, "rightUpperArmActuator", NODE_IMU_RIGHT_UPPER_ARM);
	nsvr_bodygraph_associate(g, "leftUpperArmActuator", NODE_IMU_LEFT_UPPER_ARM);




}

//void HardlightDevice::handle(uint64_t request_id, uint64_t device_id, nsvr_waveform* wave) {
//	auto it = std::find_if(m_drivers.begin(), m_drivers.end(), [device_id](const auto& driver) { return driver.second->GetId() == device_id; });
//	if (it != m_drivers.end()) {
//		BasicHapticEventData data = {};
//		nsvr_default_waveform stuff;
//		nsvr_waveform_getname(wave, &stuff);
//		data.effect = stuff;
//		nsvr_waveform_getstrength(wave, &data.strength);
//
//		float duration = 0;
//		uint32_t repetitions = 0;
//		nsvr_waveform_getrepetitions(wave, &repetitions);
//		if (repetitions > 0) {
//			duration = 0.25f * repetitions;
//		}
//		data.duration = duration;
//		(*it).second->consumeLasting(std::move(data), request_id);
//	}
//}
void HardlightDevice::handle_waveform(uint64_t request_id, nsvr_node_id device_id, nsvr_default_waveform waveform, uint32_t reps, float strength)
{
	BasicHapticEventData data = { 0 };
	data.effect = waveform;
	data.strength = strength;
	data.repetitions = reps;
	handle_waveform(request_id, device_id, std::move(data));
}

void HardlightDevice::handle_waveform(uint64_t request_id, nsvr_node_id node_id, BasicHapticEventData data)
{
	auto it = std::find_if(m_drivers.begin(), m_drivers.end(), [node_id](const auto& driver) { return driver.second->GetId() == node_id; });
	if (it != m_drivers.end()) {
		(*it).second->consumeLasting(std::move(data), request_id);
	}
}


void HardlightDevice::Buffered(uint64_t request_id, nsvr_node_id node_id, const double * amps, uint32_t length)
{
	auto it = std::find_if(m_drivers.begin(), m_drivers.end(), [device_id = node_id](const auto& driver) { return driver.second->GetId() == device_id; });
	if (it != m_drivers.end()) {
		(*it).second->realtime(std::vector<double>(amps, amps + length), request_id);
	}
}
CommandBuffer HardlightDevice::GenerateHardwareCommands(float dt)
{
	CommandBuffer result;
	for (auto& driver_pair : m_drivers) {
		CommandBuffer cl = driver_pair.second->update(dt);
		result.insert(result.begin(), cl.begin(), cl.end());
	}
	return result;
		
}



//DisplayResults HardlightDevice::QueryDrivers()
//{
//	DisplayResults representations;
//
//	for (const auto& driver : m_drivers) {
//		auto result = driver->QueryCurrentlyPlaying();
//		if (result) {
//			representations.push_back(*result);
//		}
//	}
//
//	return representations;
//}
//


ZoneModel::UserCommand::UserCommand(): id(0), command(Command::Unknown)
{
}

ZoneModel::UserCommand::UserCommand(ParentId id, Command c) : id(id), command(c)
{
}


