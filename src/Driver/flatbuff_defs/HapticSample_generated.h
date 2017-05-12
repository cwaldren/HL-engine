// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_HAPTICSAMPLE_NULLSPACE_HAPTICFILES_H_
#define FLATBUFFERS_GENERATED_HAPTICSAMPLE_NULLSPACE_HAPTICFILES_H_

#include "flatbuffers/flatbuffers.h"

#include "HapticEffect_generated.h"
#include "HapticFrame_generated.h"
#include "Pattern_generated.h"
#include "Sequence_generated.h"

namespace NullSpace {
namespace HapticFiles {

struct HapticSample;
struct HapticSampleT;

struct HapticSampleT : public flatbuffers::NativeTable {
  float time;
  std::unique_ptr<NullSpace::HapticFiles::PatternT> pattern;
};

struct HapticSample FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_TIME = 4,
    VT_PATTERN = 6
  };
  float time() const { return GetField<float>(VT_TIME, 0.0f); }
  const NullSpace::HapticFiles::Pattern *pattern() const { return GetPointer<const NullSpace::HapticFiles::Pattern *>(VT_PATTERN); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<float>(verifier, VT_TIME) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_PATTERN) &&
           verifier.VerifyTable(pattern()) &&
           verifier.EndTable();
  }
  HapticSampleT *UnPack(const flatbuffers::resolver_function_t *resolver = nullptr) const;
};

struct HapticSampleBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_time(float time) { fbb_.AddElement<float>(HapticSample::VT_TIME, time, 0.0f); }
  void add_pattern(flatbuffers::Offset<NullSpace::HapticFiles::Pattern> pattern) { fbb_.AddOffset(HapticSample::VT_PATTERN, pattern); }
  HapticSampleBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  HapticSampleBuilder &operator=(const HapticSampleBuilder &);
  flatbuffers::Offset<HapticSample> Finish() {
    auto o = flatbuffers::Offset<HapticSample>(fbb_.EndTable(start_, 2));
    return o;
  }
};

inline flatbuffers::Offset<HapticSample> CreateHapticSample(flatbuffers::FlatBufferBuilder &_fbb,
    float time = 0.0f,
    flatbuffers::Offset<NullSpace::HapticFiles::Pattern> pattern = 0) {
  HapticSampleBuilder builder_(_fbb);
  builder_.add_pattern(pattern);
  builder_.add_time(time);
  return builder_.Finish();
}

inline flatbuffers::Offset<HapticSample> CreateHapticSample(flatbuffers::FlatBufferBuilder &_fbb, const HapticSampleT *_o, const flatbuffers::rehasher_function_t *rehasher = nullptr);

inline HapticSampleT *HapticSample::UnPack(const flatbuffers::resolver_function_t *resolver) const {
  (void)resolver;
  auto _o = new HapticSampleT();
  { auto _e = time(); _o->time = _e; };
  { auto _e = pattern(); if (_e) _o->pattern = std::unique_ptr<NullSpace::HapticFiles::PatternT>(_e->UnPack(resolver)); };
  return _o;
}

inline flatbuffers::Offset<HapticSample> CreateHapticSample(flatbuffers::FlatBufferBuilder &_fbb, const HapticSampleT *_o, const flatbuffers::rehasher_function_t *rehasher) {
  (void)rehasher;
  return CreateHapticSample(_fbb,
    _o->time,
    _o->pattern ? CreatePattern(_fbb, _o->pattern.get(), rehasher) : 0);
}

inline const NullSpace::HapticFiles::HapticSample *GetHapticSample(const void *buf) {
  return flatbuffers::GetRoot<NullSpace::HapticFiles::HapticSample>(buf);
}

inline bool VerifyHapticSampleBuffer(flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<NullSpace::HapticFiles::HapticSample>(nullptr);
}

inline void FinishHapticSampleBuffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<NullSpace::HapticFiles::HapticSample> root) {
  fbb.Finish(root);
}

inline std::unique_ptr<HapticSampleT> UnPackHapticSample(const void *buf, const flatbuffers::resolver_function_t *resolver = nullptr) {
  return std::unique_ptr<HapticSampleT>(GetHapticSample(buf)->UnPack(resolver));
}

}  // namespace HapticFiles
}  // namespace NullSpace

#endif  // FLATBUFFERS_GENERATED_HAPTICSAMPLE_NULLSPACE_HAPTICFILES_H_