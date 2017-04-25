// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_LOGMESSAGE_NULLSPACE_LOGGING_H_
#define FLATBUFFERS_GENERATED_LOGMESSAGE_NULLSPACE_LOGGING_H_

#include "flatbuffers/flatbuffers.h"

namespace NullSpace {
namespace Logging {

struct LogMessage;

struct LogMessage FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_MESSAGE = 4
  };
  const flatbuffers::String *message() const { return GetPointer<const flatbuffers::String *>(VT_MESSAGE); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_MESSAGE) &&
           verifier.Verify(message()) &&
           verifier.EndTable();
  }
};

struct LogMessageBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_message(flatbuffers::Offset<flatbuffers::String> message) { fbb_.AddOffset(LogMessage::VT_MESSAGE, message); }
  LogMessageBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  LogMessageBuilder &operator=(const LogMessageBuilder &);
  flatbuffers::Offset<LogMessage> Finish() {
    auto o = flatbuffers::Offset<LogMessage>(fbb_.EndTable(start_, 1));
    return o;
  }
};

inline flatbuffers::Offset<LogMessage> CreateLogMessage(flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> message = 0) {
  LogMessageBuilder builder_(_fbb);
  builder_.add_message(message);
  return builder_.Finish();
}

inline flatbuffers::Offset<LogMessage> CreateLogMessageDirect(flatbuffers::FlatBufferBuilder &_fbb,
    const char *message = nullptr) {
  return CreateLogMessage(_fbb, message ? _fbb.CreateString(message) : 0);
}

inline const NullSpace::Logging::LogMessage *GetLogMessage(const void *buf) {
  return flatbuffers::GetRoot<NullSpace::Logging::LogMessage>(buf);
}

inline bool VerifyLogMessageBuffer(flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<NullSpace::Logging::LogMessage>(nullptr);
}

inline void FinishLogMessageBuffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<NullSpace::Logging::LogMessage> root) {
  fbb.Finish(root);
}

}  // namespace Logging
}  // namespace NullSpace

#endif  // FLATBUFFERS_GENERATED_LOGMESSAGE_NULLSPACE_LOGGING_H_
