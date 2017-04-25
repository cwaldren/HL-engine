// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_HAPTICPACKET_NULLSPACE_HAPTICFILES_H_
#define FLATBUFFERS_GENERATED_HAPTICPACKET_NULLSPACE_HAPTICFILES_H_

#include "flatbuffers/flatbuffers.h"

#include "Experience_generated.h"
#include "HapticEffect_generated.h"
#include "HapticFrame_generated.h"
#include "HapticSample_generated.h"
#include "Node_generated.h"
#include "Pattern_generated.h"
#include "Sequence_generated.h"
#include "TinyEffect_generated.h"
#include "TinyEffectArray_generated.h"

namespace NullSpace {
namespace HapticFiles {

struct Tracking;
struct TrackingT;

struct EngineCommandData;
struct EngineCommandDataT;

struct HandleCommand;
struct HandleCommandT;

struct HapticPacket;
struct HapticPacketT;

enum EngineCommand {
  EngineCommand_NO_COMMAND = 0,
  EngineCommand_PLAY_ALL = 1,
  EngineCommand_PAUSE_ALL = 2,
  EngineCommand_CLEAR_ALL = 3,
  EngineCommand_ENABLE_TRACKING = 4,
  EngineCommand_DISABLE_TRACKING = 5,
  EngineCommand_MIN = EngineCommand_NO_COMMAND,
  EngineCommand_MAX = EngineCommand_DISABLE_TRACKING
};

inline const char **EnumNamesEngineCommand() {
  static const char *names[] = { "NO_COMMAND", "PLAY_ALL", "PAUSE_ALL", "CLEAR_ALL", "ENABLE_TRACKING", "DISABLE_TRACKING", nullptr };
  return names;
}

inline const char *EnumNameEngineCommand(EngineCommand e) { return EnumNamesEngineCommand()[static_cast<int>(e)]; }

enum Command {
  Command_PLAY = 0,
  Command_PAUSE = 1,
  Command_RESET = 2,
  Command_RELEASE = 3,
  Command_MIN = Command_PLAY,
  Command_MAX = Command_RELEASE
};

inline const char **EnumNamesCommand() {
  static const char *names[] = { "PLAY", "PAUSE", "RESET", "RELEASE", nullptr };
  return names;
}

inline const char *EnumNameCommand(Command e) { return EnumNamesCommand()[static_cast<int>(e)]; }

enum FileType {
  FileType_NONE = 0,
  FileType_Experience = 1,
  FileType_Pattern = 2,
  FileType_Sequence = 3,
  FileType_HapticEffect = 4,
  FileType_Tracking = 5,
  FileType_HandleCommand = 6,
  FileType_EngineCommandData = 7,
  FileType_Node = 8,
  FileType_TinyEffectArray = 9,
  FileType_MIN = FileType_NONE,
  FileType_MAX = FileType_TinyEffectArray
};

struct FileTypeUnion {
  FileType type;

  flatbuffers::NativeTable *table;
  FileTypeUnion() : type(FileType_NONE), table(nullptr) {}
  FileTypeUnion(const FileTypeUnion &);
  FileTypeUnion &operator=(const FileTypeUnion &);
  ~FileTypeUnion();

  static flatbuffers::NativeTable *UnPack(const void *union_obj, FileType type, const flatbuffers::resolver_function_t *resolver);
  flatbuffers::Offset<void> Pack(flatbuffers::FlatBufferBuilder &_fbb, const flatbuffers::rehasher_function_t *rehasher = nullptr) const;

  NullSpace::HapticFiles::ExperienceT *AsExperience() { return type == FileType_Experience ? reinterpret_cast<NullSpace::HapticFiles::ExperienceT *>(table) : nullptr; }
  NullSpace::HapticFiles::PatternT *AsPattern() { return type == FileType_Pattern ? reinterpret_cast<NullSpace::HapticFiles::PatternT *>(table) : nullptr; }
  NullSpace::HapticFiles::SequenceT *AsSequence() { return type == FileType_Sequence ? reinterpret_cast<NullSpace::HapticFiles::SequenceT *>(table) : nullptr; }
  NullSpace::HapticFiles::HapticEffectT *AsHapticEffect() { return type == FileType_HapticEffect ? reinterpret_cast<NullSpace::HapticFiles::HapticEffectT *>(table) : nullptr; }
  TrackingT *AsTracking() { return type == FileType_Tracking ? reinterpret_cast<TrackingT *>(table) : nullptr; }
  HandleCommandT *AsHandleCommand() { return type == FileType_HandleCommand ? reinterpret_cast<HandleCommandT *>(table) : nullptr; }
  EngineCommandDataT *AsEngineCommandData() { return type == FileType_EngineCommandData ? reinterpret_cast<EngineCommandDataT *>(table) : nullptr; }
  NullSpace::HapticFiles::NodeT *AsNode() { return type == FileType_Node ? reinterpret_cast<NullSpace::HapticFiles::NodeT *>(table) : nullptr; }
};

inline const char **EnumNamesFileType() {
  static const char *names[] = { "NONE", "Experience", "Pattern", "Sequence", "HapticEffect", "Tracking", "HandleCommand", "EngineCommandData", "Node", "TinyEffectArray", nullptr };
  return names;
}

inline const char *EnumNameFileType(FileType e) { return EnumNamesFileType()[static_cast<int>(e)]; }

template<typename T> struct FileTypeTraits {
  static const FileType enum_value = FileType_NONE;
};

template<> struct FileTypeTraits<NullSpace::HapticFiles::Experience> {
  static const FileType enum_value = FileType_Experience;
};

template<> struct FileTypeTraits<NullSpace::HapticFiles::Pattern> {
  static const FileType enum_value = FileType_Pattern;
};

template<> struct FileTypeTraits<NullSpace::HapticFiles::Sequence> {
  static const FileType enum_value = FileType_Sequence;
};

template<> struct FileTypeTraits<NullSpace::HapticFiles::HapticEffect> {
  static const FileType enum_value = FileType_HapticEffect;
};

template<> struct FileTypeTraits<Tracking> {
  static const FileType enum_value = FileType_Tracking;
};

template<> struct FileTypeTraits<HandleCommand> {
  static const FileType enum_value = FileType_HandleCommand;
};

template<> struct FileTypeTraits<EngineCommandData> {
  static const FileType enum_value = FileType_EngineCommandData;
};

template<> struct FileTypeTraits<NullSpace::HapticFiles::Node> {
  static const FileType enum_value = FileType_Node;
};

template<> struct FileTypeTraits<NullSpace::HapticFiles::TinyEffectArray> {
  static const FileType enum_value = FileType_TinyEffectArray;
};

inline bool VerifyFileType(flatbuffers::Verifier &verifier, const void *union_obj, FileType type);

struct TrackingT : public flatbuffers::NativeTable {
  bool enable;
};

struct Tracking FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_ENABLE = 4
  };
  bool enable() const { return GetField<uint8_t>(VT_ENABLE, 0) != 0; }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_ENABLE) &&
           verifier.EndTable();
  }
  TrackingT *UnPack(const flatbuffers::resolver_function_t *resolver = nullptr) const;
};

struct TrackingBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_enable(bool enable) { fbb_.AddElement<uint8_t>(Tracking::VT_ENABLE, static_cast<uint8_t>(enable), 0); }
  TrackingBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  TrackingBuilder &operator=(const TrackingBuilder &);
  flatbuffers::Offset<Tracking> Finish() {
    auto o = flatbuffers::Offset<Tracking>(fbb_.EndTable(start_, 1));
    return o;
  }
};

inline flatbuffers::Offset<Tracking> CreateTracking(flatbuffers::FlatBufferBuilder &_fbb,
    bool enable = false) {
  TrackingBuilder builder_(_fbb);
  builder_.add_enable(enable);
  return builder_.Finish();
}

inline flatbuffers::Offset<Tracking> CreateTracking(flatbuffers::FlatBufferBuilder &_fbb, const TrackingT *_o, const flatbuffers::rehasher_function_t *rehasher = nullptr);

struct EngineCommandDataT : public flatbuffers::NativeTable {
  EngineCommand command;
};

struct EngineCommandData FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_COMMAND = 4
  };
  EngineCommand command() const { return static_cast<EngineCommand>(GetField<int16_t>(VT_COMMAND, 0)); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int16_t>(verifier, VT_COMMAND) &&
           verifier.EndTable();
  }
  EngineCommandDataT *UnPack(const flatbuffers::resolver_function_t *resolver = nullptr) const;
};

struct EngineCommandDataBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_command(EngineCommand command) { fbb_.AddElement<int16_t>(EngineCommandData::VT_COMMAND, static_cast<int16_t>(command), 0); }
  EngineCommandDataBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  EngineCommandDataBuilder &operator=(const EngineCommandDataBuilder &);
  flatbuffers::Offset<EngineCommandData> Finish() {
    auto o = flatbuffers::Offset<EngineCommandData>(fbb_.EndTable(start_, 1));
    return o;
  }
};

inline flatbuffers::Offset<EngineCommandData> CreateEngineCommandData(flatbuffers::FlatBufferBuilder &_fbb,
    EngineCommand command = EngineCommand_NO_COMMAND) {
  EngineCommandDataBuilder builder_(_fbb);
  builder_.add_command(command);
  return builder_.Finish();
}

inline flatbuffers::Offset<EngineCommandData> CreateEngineCommandData(flatbuffers::FlatBufferBuilder &_fbb, const EngineCommandDataT *_o, const flatbuffers::rehasher_function_t *rehasher = nullptr);

struct HandleCommandT : public flatbuffers::NativeTable {
  uint64_t handle;
  Command command;
};

struct HandleCommand FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_HANDLE = 4,
    VT_COMMAND = 6
  };
  uint64_t handle() const { return GetField<uint64_t>(VT_HANDLE, 0); }
  Command command() const { return static_cast<Command>(GetField<int16_t>(VT_COMMAND, 0)); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint64_t>(verifier, VT_HANDLE) &&
           VerifyField<int16_t>(verifier, VT_COMMAND) &&
           verifier.EndTable();
  }
  HandleCommandT *UnPack(const flatbuffers::resolver_function_t *resolver = nullptr) const;
};

struct HandleCommandBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_handle(uint64_t handle) { fbb_.AddElement<uint64_t>(HandleCommand::VT_HANDLE, handle, 0); }
  void add_command(Command command) { fbb_.AddElement<int16_t>(HandleCommand::VT_COMMAND, static_cast<int16_t>(command), 0); }
  HandleCommandBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  HandleCommandBuilder &operator=(const HandleCommandBuilder &);
  flatbuffers::Offset<HandleCommand> Finish() {
    auto o = flatbuffers::Offset<HandleCommand>(fbb_.EndTable(start_, 2));
    return o;
  }
};

inline flatbuffers::Offset<HandleCommand> CreateHandleCommand(flatbuffers::FlatBufferBuilder &_fbb,
    uint64_t handle = 0,
    Command command = Command_PLAY) {
  HandleCommandBuilder builder_(_fbb);
  builder_.add_handle(handle);
  builder_.add_command(command);
  return builder_.Finish();
}

inline flatbuffers::Offset<HandleCommand> CreateHandleCommand(flatbuffers::FlatBufferBuilder &_fbb, const HandleCommandT *_o, const flatbuffers::rehasher_function_t *rehasher = nullptr);

struct HapticPacketT : public flatbuffers::NativeTable {
  std::string name;
  FileTypeUnion packet;
  uint64_t handle;
};

struct HapticPacket FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_NAME = 4,
    VT_PACKET_TYPE = 6,
    VT_PACKET = 8,
    VT_HANDLE = 10
  };
  const flatbuffers::String *name() const { return GetPointer<const flatbuffers::String *>(VT_NAME); }
  FileType packet_type() const { return static_cast<FileType>(GetField<uint8_t>(VT_PACKET_TYPE, 0)); }
  const void *packet() const { return GetPointer<const void *>(VT_PACKET); }
  uint64_t handle() const { return GetField<uint64_t>(VT_HANDLE, 0); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_NAME) &&
           verifier.Verify(name()) &&
           VerifyField<uint8_t>(verifier, VT_PACKET_TYPE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_PACKET) &&
           VerifyFileType(verifier, packet(), packet_type()) &&
           VerifyField<uint64_t>(verifier, VT_HANDLE) &&
           verifier.EndTable();
  }
  HapticPacketT *UnPack(const flatbuffers::resolver_function_t *resolver = nullptr) const;
};

struct HapticPacketBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) { fbb_.AddOffset(HapticPacket::VT_NAME, name); }
  void add_packet_type(FileType packet_type) { fbb_.AddElement<uint8_t>(HapticPacket::VT_PACKET_TYPE, static_cast<uint8_t>(packet_type), 0); }
  void add_packet(flatbuffers::Offset<void> packet) { fbb_.AddOffset(HapticPacket::VT_PACKET, packet); }
  void add_handle(uint64_t handle) { fbb_.AddElement<uint64_t>(HapticPacket::VT_HANDLE, handle, 0); }
  HapticPacketBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  HapticPacketBuilder &operator=(const HapticPacketBuilder &);
  flatbuffers::Offset<HapticPacket> Finish() {
    auto o = flatbuffers::Offset<HapticPacket>(fbb_.EndTable(start_, 4));
    return o;
  }
};

inline flatbuffers::Offset<HapticPacket> CreateHapticPacket(flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    FileType packet_type = FileType_NONE,
    flatbuffers::Offset<void> packet = 0,
    uint64_t handle = 0) {
  HapticPacketBuilder builder_(_fbb);
  builder_.add_handle(handle);
  builder_.add_packet(packet);
  builder_.add_name(name);
  builder_.add_packet_type(packet_type);
  return builder_.Finish();
}

inline flatbuffers::Offset<HapticPacket> CreateHapticPacketDirect(flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    FileType packet_type = FileType_NONE,
    flatbuffers::Offset<void> packet = 0,
    uint64_t handle = 0) {
  return CreateHapticPacket(_fbb, name ? _fbb.CreateString(name) : 0, packet_type, packet, handle);
}

inline flatbuffers::Offset<HapticPacket> CreateHapticPacket(flatbuffers::FlatBufferBuilder &_fbb, const HapticPacketT *_o, const flatbuffers::rehasher_function_t *rehasher = nullptr);

inline TrackingT *Tracking::UnPack(const flatbuffers::resolver_function_t *resolver) const {
  (void)resolver;
  auto _o = new TrackingT();
  { auto _e = enable(); _o->enable = _e; };
  return _o;
}

inline flatbuffers::Offset<Tracking> CreateTracking(flatbuffers::FlatBufferBuilder &_fbb, const TrackingT *_o, const flatbuffers::rehasher_function_t *rehasher) {
  (void)rehasher;
  return CreateTracking(_fbb,
    _o->enable);
}

inline EngineCommandDataT *EngineCommandData::UnPack(const flatbuffers::resolver_function_t *resolver) const {
  (void)resolver;
  auto _o = new EngineCommandDataT();
  { auto _e = command(); _o->command = _e; };
  return _o;
}

inline flatbuffers::Offset<EngineCommandData> CreateEngineCommandData(flatbuffers::FlatBufferBuilder &_fbb, const EngineCommandDataT *_o, const flatbuffers::rehasher_function_t *rehasher) {
  (void)rehasher;
  return CreateEngineCommandData(_fbb,
    _o->command);
}

inline HandleCommandT *HandleCommand::UnPack(const flatbuffers::resolver_function_t *resolver) const {
  (void)resolver;
  auto _o = new HandleCommandT();
  { auto _e = handle(); _o->handle = _e; };
  { auto _e = command(); _o->command = _e; };
  return _o;
}

inline flatbuffers::Offset<HandleCommand> CreateHandleCommand(flatbuffers::FlatBufferBuilder &_fbb, const HandleCommandT *_o, const flatbuffers::rehasher_function_t *rehasher) {
  (void)rehasher;
  return CreateHandleCommand(_fbb,
    _o->handle,
    _o->command);
}

inline HapticPacketT *HapticPacket::UnPack(const flatbuffers::resolver_function_t *resolver) const {
  (void)resolver;
  auto _o = new HapticPacketT();
  { auto _e = name(); if (_e) _o->name = _e->str(); };
  { auto _e = packet_type(); _o->packet.type = _e; };
  { auto _e = packet(); if (_e) _o->packet.table = FileTypeUnion::UnPack(_e, packet_type(), resolver); };
  { auto _e = handle(); _o->handle = _e; };
  return _o;
}

inline flatbuffers::Offset<HapticPacket> CreateHapticPacket(flatbuffers::FlatBufferBuilder &_fbb, const HapticPacketT *_o, const flatbuffers::rehasher_function_t *rehasher) {
  (void)rehasher;
  return CreateHapticPacket(_fbb,
    _o->name.size() ? _fbb.CreateString(_o->name) : 0,
    _o->packet.type,
    _o->packet.Pack(_fbb),
    _o->handle);
}

inline bool VerifyFileType(flatbuffers::Verifier &verifier, const void *union_obj, FileType type) {
  switch (type) {
    case FileType_NONE: return true;
    case FileType_Experience: return verifier.VerifyTable(reinterpret_cast<const NullSpace::HapticFiles::Experience *>(union_obj));
    case FileType_Pattern: return verifier.VerifyTable(reinterpret_cast<const NullSpace::HapticFiles::Pattern *>(union_obj));
    case FileType_Sequence: return verifier.VerifyTable(reinterpret_cast<const NullSpace::HapticFiles::Sequence *>(union_obj));
    case FileType_HapticEffect: return verifier.VerifyTable(reinterpret_cast<const NullSpace::HapticFiles::HapticEffect *>(union_obj));
    case FileType_Tracking: return verifier.VerifyTable(reinterpret_cast<const Tracking *>(union_obj));
    case FileType_HandleCommand: return verifier.VerifyTable(reinterpret_cast<const HandleCommand *>(union_obj));
    case FileType_EngineCommandData: return verifier.VerifyTable(reinterpret_cast<const EngineCommandData *>(union_obj));
    case FileType_Node: return verifier.VerifyTable(reinterpret_cast<const NullSpace::HapticFiles::Node *>(union_obj));
    case FileType_TinyEffectArray: return verifier.VerifyTable(reinterpret_cast<const NullSpace::HapticFiles::TinyEffectArray *>(union_obj));
    default: return false;
  }
}

inline flatbuffers::NativeTable *FileTypeUnion::UnPack(const void *union_obj, FileType type, const flatbuffers::resolver_function_t *resolver) {
  switch (type) {
    case FileType_NONE: return nullptr;
    case FileType_Experience: return reinterpret_cast<const NullSpace::HapticFiles::Experience *>(union_obj)->UnPack(resolver);
    case FileType_Pattern: return reinterpret_cast<const NullSpace::HapticFiles::Pattern *>(union_obj)->UnPack(resolver);
    case FileType_Sequence: return reinterpret_cast<const NullSpace::HapticFiles::Sequence *>(union_obj)->UnPack(resolver);
    case FileType_HapticEffect: return reinterpret_cast<const NullSpace::HapticFiles::HapticEffect *>(union_obj)->UnPack(resolver);
    case FileType_Tracking: return reinterpret_cast<const Tracking *>(union_obj)->UnPack(resolver);
    case FileType_HandleCommand: return reinterpret_cast<const HandleCommand *>(union_obj)->UnPack(resolver);
    case FileType_EngineCommandData: return reinterpret_cast<const EngineCommandData *>(union_obj)->UnPack(resolver);
    case FileType_Node: return reinterpret_cast<const NullSpace::HapticFiles::Node *>(union_obj)->UnPack(resolver);
    default: return nullptr;
  }
}

inline flatbuffers::Offset<void> FileTypeUnion::Pack(flatbuffers::FlatBufferBuilder &_fbb, const flatbuffers::rehasher_function_t *rehasher) const {
  switch (type) {
    case FileType_NONE: return 0;
    case FileType_Experience: return CreateExperience(_fbb, reinterpret_cast<const NullSpace::HapticFiles::ExperienceT *>(table), rehasher).Union();
    case FileType_Pattern: return CreatePattern(_fbb, reinterpret_cast<const NullSpace::HapticFiles::PatternT *>(table), rehasher).Union();
    case FileType_Sequence: return CreateSequence(_fbb, reinterpret_cast<const NullSpace::HapticFiles::SequenceT *>(table), rehasher).Union();
    case FileType_HapticEffect: return CreateHapticEffect(_fbb, reinterpret_cast<const NullSpace::HapticFiles::HapticEffectT *>(table), rehasher).Union();
    case FileType_Tracking: return CreateTracking(_fbb, reinterpret_cast<const TrackingT *>(table), rehasher).Union();
    case FileType_HandleCommand: return CreateHandleCommand(_fbb, reinterpret_cast<const HandleCommandT *>(table), rehasher).Union();
    case FileType_EngineCommandData: return CreateEngineCommandData(_fbb, reinterpret_cast<const EngineCommandDataT *>(table), rehasher).Union();
    case FileType_Node: return CreateNode(_fbb, reinterpret_cast<const NullSpace::HapticFiles::NodeT *>(table), rehasher).Union();
    default: return 0;
  }
}

inline FileTypeUnion::~FileTypeUnion() {
  switch (type) {
    case FileType_Experience: delete reinterpret_cast<NullSpace::HapticFiles::ExperienceT *>(table); break;
    case FileType_Pattern: delete reinterpret_cast<NullSpace::HapticFiles::PatternT *>(table); break;
    case FileType_Sequence: delete reinterpret_cast<NullSpace::HapticFiles::SequenceT *>(table); break;
    case FileType_HapticEffect: delete reinterpret_cast<NullSpace::HapticFiles::HapticEffectT *>(table); break;
    case FileType_Tracking: delete reinterpret_cast<TrackingT *>(table); break;
    case FileType_HandleCommand: delete reinterpret_cast<HandleCommandT *>(table); break;
    case FileType_EngineCommandData: delete reinterpret_cast<EngineCommandDataT *>(table); break;
    case FileType_Node: delete reinterpret_cast<NullSpace::HapticFiles::NodeT *>(table); break;
    default:;
  }
}

inline const NullSpace::HapticFiles::HapticPacket *GetHapticPacket(const void *buf) {
  return flatbuffers::GetRoot<NullSpace::HapticFiles::HapticPacket>(buf);
}

inline bool VerifyHapticPacketBuffer(flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<NullSpace::HapticFiles::HapticPacket>(nullptr);
}

inline void FinishHapticPacketBuffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<NullSpace::HapticFiles::HapticPacket> root) {
  fbb.Finish(root);
}

inline std::unique_ptr<HapticPacketT> UnPackHapticPacket(const void *buf, const flatbuffers::resolver_function_t *resolver = nullptr) {
  return std::unique_ptr<HapticPacketT>(GetHapticPacket(buf)->UnPack(resolver));
}

}  // namespace HapticFiles
}  // namespace NullSpace

#endif  // FLATBUFFERS_GENERATED_HAPTICPACKET_NULLSPACE_HAPTICFILES_H_
