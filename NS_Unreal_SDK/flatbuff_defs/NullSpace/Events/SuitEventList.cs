// automatically generated by the FlatBuffers compiler, do not modify

namespace NullSpace.Events
{

using System;
using FlatBuffers;

public struct SuitEventList : IFlatbufferObject
{
  private Table __p;
  public ByteBuffer ByteBuffer { get { return __p.bb; } }
  public static SuitEventList GetRootAsSuitEventList(ByteBuffer _bb) { return GetRootAsSuitEventList(_bb, new SuitEventList()); }
  public static SuitEventList GetRootAsSuitEventList(ByteBuffer _bb, SuitEventList obj) { return (obj.__assign(_bb.GetInt(_bb.Position) + _bb.Position, _bb)); }
  public void __init(int _i, ByteBuffer _bb) { __p.bb_pos = _i; __p.bb = _bb; }
  public SuitEventList __assign(int _i, ByteBuffer _bb) { __init(_i, _bb); return this; }

  public SuitEvent? Events(int j) { int o = __p.__offset(4); return o != 0 ? (SuitEvent?)(new SuitEvent()).__assign(__p.__indirect(__p.__vector(o) + j * 4), __p.bb) : null; }
  public int EventsLength { get { int o = __p.__offset(4); return o != 0 ? __p.__vector_len(o) : 0; } }

  public static Offset<SuitEventList> CreateSuitEventList(FlatBufferBuilder builder,
      VectorOffset eventsOffset = default(VectorOffset)) {
    builder.StartObject(1);
    SuitEventList.AddEvents(builder, eventsOffset);
    return SuitEventList.EndSuitEventList(builder);
  }

  public static void StartSuitEventList(FlatBufferBuilder builder) { builder.StartObject(1); }
  public static void AddEvents(FlatBufferBuilder builder, VectorOffset eventsOffset) { builder.AddOffset(0, eventsOffset.Value, 0); }
  public static VectorOffset CreateEventsVector(FlatBufferBuilder builder, Offset<SuitEvent>[] data) { builder.StartVector(4, data.Length, 4); for (int i = data.Length - 1; i >= 0; i--) builder.AddOffset(data[i].Value); return builder.EndVector(); }
  public static void StartEventsVector(FlatBufferBuilder builder, int numElems) { builder.StartVector(4, numElems, 4); }
  public static Offset<SuitEventList> EndSuitEventList(FlatBufferBuilder builder) {
    int o = builder.EndObject();
    return new Offset<SuitEventList>(o);
  }
  public static void FinishSuitEventListBuffer(FlatBufferBuilder builder, Offset<SuitEventList> offset) { builder.Finish(offset.Value); }
};


}
