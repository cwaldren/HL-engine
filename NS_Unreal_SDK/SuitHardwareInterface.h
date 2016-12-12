#pragma once

#include "ICommunicationAdapter.h"
#include "InstructionBuilder.h"
#include "Locator.h"
#include <boost\lockfree\spsc_queue.hpp>
#include <queue>
class SuitHardwareInterface
{
public:
	struct VersionInfo {
		unsigned int Major;
		unsigned int Minor;
		VersionInfo(unsigned int major, unsigned int minor) :Major(major), Minor(minor) {}
	};

	struct SuitStatusUpdate {
		enum class SuitStatus {ImuInitialize, DrvInitialize, Booted};
		SuitStatus Stage;
		unsigned int Response;
		SuitStatusUpdate(unsigned int stage, unsigned int responsecode) :Stage(SuitStatus(stage)), Response(responsecode) {}
	};
	typedef std::function<void(const SuitHardwareInterface::VersionInfo&)> VersionInfoCallback;
	SuitHardwareInterface(std::shared_ptr<ICommunicationAdapter>, std::shared_ptr<InstructionSet> iset, std::shared_ptr<boost::asio::io_service> io);
	~SuitHardwareInterface();
	void SetAdapter(std::shared_ptr<ICommunicationAdapter> adapter);
	void PlayEffect(Location location, Effect effect);
	void HaltEffect(Location location);
	void RequestSuitVersion();
	void PlayEffectContinuous(Location location, Effect effect);
	void HaltAllEffects();
	void PingSuit();
	void EnableIMUs();
	void DisableIMUs();
	void UseImmediateMode();
	void UseDeferredMode();
	
private:
	std::shared_ptr<boost::asio::io_service> _io;
	std::shared_ptr<ICommunicationAdapter> adapter;
	void executeImmediately(Packet packet);
	void executeLater( Packet packet);
	void chooseExecutionStrategy( Packet packet);
	InstructionBuilder builder;
	bool _useDeferredWriting;
	std::queue<uint8_t> _preWriteBuffer;
	std::vector<uint8_t> _writeBuffer;
	boost::asio::deadline_timer _writeTimer;
	boost::asio::deadline_timer _batchingDeadline;
	boost::posix_time::milliseconds _batchingTimeout = boost::posix_time::milliseconds(20);
	boost::posix_time::milliseconds _writeInterval = boost::posix_time::milliseconds(10);
	void writeBuffer();
	boost::lockfree::spsc_queue<uint8_t> _lfQueue;
	std::mutex _needsFlushMutex;
	bool _isBatching;
	
	std::unordered_map<SuitStatusUpdate::SuitStatus, std::unordered_map<unsigned int, std::string>> _errorCodes;
	
};

