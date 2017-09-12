#pragma once
#include <memory>
#include <unordered_map>
#include "Device2.h"
#include <mutex>
#include "DriverConfigParser.h"
#include "SimulatedDevice.h"
#include "DeviceDescriptor.h"
// Should break this into two interfaces: adding/removing, and the data operations

class DriverMessenger;
class DeviceContainer {
public:
	using DeviceFn = std::function<void(Device2*)>;
	void AddDevice(nsvr_device_id id, PluginApis& apis, Parsing::BodyGraphDescriptor);
	
	void RemoveDevice(nsvr_device_id id);
	void Each(DeviceFn);
	void EachSimulation(std::function<void(SimulatedDevice*)> action);
	DeviceContainer();

	Device2* Get(nsvr_device_id id);

	void OnDeviceAdded(DeviceFn);
	void OnPreDeviceRemoved(DeviceFn);

private:
	void addDevice(const DeviceDescriptor&, PluginApis&,  Parsing::BodyGraphDescriptor);

	std::vector<std::unique_ptr<Device2>> m_devices;
	std::vector<std::unique_ptr<SimulatedDevice>> m_simulations;
	std::vector<DeviceFn> m_deviceAddedSubs;
	std::vector<DeviceFn> m_deviceRemovedSubs;

	std::mutex m_deviceLock;
	void notify(const std::vector<DeviceFn>& devices, Device2* device);
	
};


