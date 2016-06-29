#pragma once
#include <unordered_map>
#include "Instruction.h"
#include <vector>
#include "Packet.h"
#include "json\json.h"
#include "json\json-forwards.h"
using std::string;
class InstructionBuilder
{
public:
	InstructionBuilder();
	~InstructionBuilder();
	InstructionBuilder UseInstruction(string name);
	InstructionBuilder WithParam(string key, int val);
	bool Verify();
	Packet Build();
	bool LoadInstructions(Json::Value json);
private:
	std::unordered_map<string, Instruction> instructions;
	std::string instruction;

	std::unordered_map<string, string> parameters;
	std::unordered_map<string, std::unordered_map<string, uint8_t>> paramDict;
	bool LoadKeyValue(std::unordered_map<string, uint8_t> dict, Json::Value json);
};

