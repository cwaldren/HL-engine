#include "stdafx.h"
#include "FakeTrackingProvider.h"

std::unique_ptr<FakeTrackingProvider> FakeTrackingBuilder::Build()
{
	return std::make_unique<FakeTrackingProvider>();
}

FakeTrackingProvider::FakeTrackingProvider()
{
}

void FakeTrackingProvider::BeginStreaming(NodeId<local> whichNode)
{
}

void FakeTrackingProvider::EndStreaming(NodeId<local> whichNode)
{
}

void FakeTrackingProvider::OnUpdate(std::function<void(NodeId<local>, nsvr_quaternion*)> handler)
{
}