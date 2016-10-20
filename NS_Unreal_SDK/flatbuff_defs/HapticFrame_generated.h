// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_HAPTICFRAME_NULLSPACE_HAPTICFILES_H_
#define FLATBUFFERS_GENERATED_HAPTICFRAME_NULLSPACE_HAPTICFILES_H_

#include "flatbuffers/flatbuffers.h"

#include "HapticEffect_generated.h"
#include "Sequence_generated.h"

namespace NullSpace {
namespace HapticFiles {

struct HapticFrame;

struct HapticFrame FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_FRAME = 4,
    VT_PRIORITY = 6,
    VT_TIME = 8
  };
  const flatbuffers::Vector<flatbuffers::Offset<NullSpace::HapticFiles::Sequence>> *frame() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<NullSpace::HapticFiles::Sequence>> *>(VT_FRAME); }
  uint16_t priority() const { return GetField<uint16_t>(VT_PRIORITY, 0); }
  float time() const { return GetField<float>(VT_TIME, 0.0f); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_FRAME) &&
           verifier.Verify(frame()) &&
           verifier.VerifyVectorOfTables(frame()) &&
           VerifyField<uint16_t>(verifier, VT_PRIORITY) &&
           VerifyField<float>(verifier, VT_TIME) &&
           verifier.EndTable();
  }
};

struct HapticFrameBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_frame(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<NullSpace::HapticFiles::Sequence>>> frame) { fbb_.AddOffset(HapticFrame::VT_FRAME, frame); }
  void add_priority(uint16_t priority) { fbb_.AddElement<uint16_t>(HapticFrame::VT_PRIORITY, priority, 0); }
  void add_time(float time) { fbb_.AddElement<float>(HapticFrame::VT_TIME, time, 0.0f); }
  HapticFrameBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  HapticFrameBuilder &operator=(const HapticFrameBuilder &);
  flatbuffers::Offset<HapticFrame> Finish() {
    auto o = flatbuffers::Offset<HapticFrame>(fbb_.EndTable(start_, 3));
    return o;
  }
};

inline flatbuffers::Offset<HapticFrame> CreateHapticFrame(flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<NullSpace::HapticFiles::Sequence>>> frame = 0,
    uint16_t priority = 0,
    float time = 0.0f) {
  HapticFrameBuilder builder_(_fbb);
  builder_.add_time(time);
  builder_.add_frame(frame);
  builder_.add_priority(priority);
  return builder_.Finish();
}

inline flatbuffers::Offset<HapticFrame> CreateHapticFrameDirect(flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<NullSpace::HapticFiles::Sequence>> *frame = nullptr,
    uint16_t priority = 0,
    float time = 0.0f) {
  return CreateHapticFrame(_fbb, frame ? _fbb.CreateVector<flatbuffers::Offset<NullSpace::HapticFiles::Sequence>>(*frame) : 0, priority, time);
}

inline const NullSpace::HapticFiles::HapticFrame *GetHapticFrame(const void *buf) {
  return flatbuffers::GetRoot<NullSpace::HapticFiles::HapticFrame>(buf);
}

inline bool VerifyHapticFrameBuffer(flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<NullSpace::HapticFiles::HapticFrame>(nullptr);
}

inline void FinishHapticFrameBuffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<NullSpace::HapticFiles::HapticFrame> root) {
  fbb.Finish(root);
}

}  // namespace HapticFiles
}  // namespace NullSpace

#endif  // FLATBUFFERS_GENERATED_HAPTICFRAME_NULLSPACE_HAPTICFILES_H_