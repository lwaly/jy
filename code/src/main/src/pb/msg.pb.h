// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msg.proto

#ifndef PROTOBUF_INCLUDED_msg_2eproto
#define PROTOBUF_INCLUDED_msg_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_msg_2eproto 

namespace protobuf_msg_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[4];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_msg_2eproto
class MsgBody;
class MsgBodyDefaultTypeInternal;
extern MsgBodyDefaultTypeInternal _MsgBody_default_instance_;
class MsgBody_Request;
class MsgBody_RequestDefaultTypeInternal;
extern MsgBody_RequestDefaultTypeInternal _MsgBody_Request_default_instance_;
class MsgBody_Response;
class MsgBody_ResponseDefaultTypeInternal;
extern MsgBody_ResponseDefaultTypeInternal _MsgBody_Response_default_instance_;
class MsgHead;
class MsgHeadDefaultTypeInternal;
extern MsgHeadDefaultTypeInternal _MsgHead_default_instance_;
namespace google {
namespace protobuf {
template<> ::MsgBody* Arena::CreateMaybeMessage<::MsgBody>(Arena*);
template<> ::MsgBody_Request* Arena::CreateMaybeMessage<::MsgBody_Request>(Arena*);
template<> ::MsgBody_Response* Arena::CreateMaybeMessage<::MsgBody_Response>(Arena*);
template<> ::MsgHead* Arena::CreateMaybeMessage<::MsgHead>(Arena*);
}  // namespace protobuf
}  // namespace google

// ===================================================================

class MsgHead : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:MsgHead) */ {
 public:
  MsgHead();
  virtual ~MsgHead();

  MsgHead(const MsgHead& from);

  inline MsgHead& operator=(const MsgHead& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MsgHead(MsgHead&& from) noexcept
    : MsgHead() {
    *this = ::std::move(from);
  }

  inline MsgHead& operator=(MsgHead&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const MsgHead& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const MsgHead* internal_default_instance() {
    return reinterpret_cast<const MsgHead*>(
               &_MsgHead_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(MsgHead* other);
  friend void swap(MsgHead& a, MsgHead& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MsgHead* New() const final {
    return CreateMaybeMessage<MsgHead>(NULL);
  }

  MsgHead* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<MsgHead>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const MsgHead& from);
  void MergeFrom(const MsgHead& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(MsgHead* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // fixed32 cmd = 1;
  void clear_cmd();
  static const int kCmdFieldNumber = 1;
  ::google::protobuf::uint32 cmd() const;
  void set_cmd(::google::protobuf::uint32 value);

  // fixed32 seq = 2;
  void clear_seq();
  static const int kSeqFieldNumber = 2;
  ::google::protobuf::uint32 seq() const;
  void set_seq(::google::protobuf::uint32 value);

  // sfixed32 len = 3;
  void clear_len();
  static const int kLenFieldNumber = 3;
  ::google::protobuf::int32 len() const;
  void set_len(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:MsgHead)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 cmd_;
  ::google::protobuf::uint32 seq_;
  ::google::protobuf::int32 len_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_msg_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class MsgBody_Request : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:MsgBody.Request) */ {
 public:
  MsgBody_Request();
  virtual ~MsgBody_Request();

  MsgBody_Request(const MsgBody_Request& from);

  inline MsgBody_Request& operator=(const MsgBody_Request& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MsgBody_Request(MsgBody_Request&& from) noexcept
    : MsgBody_Request() {
    *this = ::std::move(from);
  }

  inline MsgBody_Request& operator=(MsgBody_Request&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const MsgBody_Request& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const MsgBody_Request* internal_default_instance() {
    return reinterpret_cast<const MsgBody_Request*>(
               &_MsgBody_Request_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(MsgBody_Request* other);
  friend void swap(MsgBody_Request& a, MsgBody_Request& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MsgBody_Request* New() const final {
    return CreateMaybeMessage<MsgBody_Request>(NULL);
  }

  MsgBody_Request* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<MsgBody_Request>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const MsgBody_Request& from);
  void MergeFrom(const MsgBody_Request& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(MsgBody_Request* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string route = 2;
  void clear_route();
  static const int kRouteFieldNumber = 2;
  const ::std::string& route() const;
  void set_route(const ::std::string& value);
  #if LANG_CXX11
  void set_route(::std::string&& value);
  #endif
  void set_route(const char* value);
  void set_route(const char* value, size_t size);
  ::std::string* mutable_route();
  ::std::string* release_route();
  void set_allocated_route(::std::string* route);

  // uint32 route_id = 1;
  void clear_route_id();
  static const int kRouteIdFieldNumber = 1;
  ::google::protobuf::uint32 route_id() const;
  void set_route_id(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:MsgBody.Request)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr route_;
  ::google::protobuf::uint32 route_id_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_msg_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class MsgBody_Response : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:MsgBody.Response) */ {
 public:
  MsgBody_Response();
  virtual ~MsgBody_Response();

  MsgBody_Response(const MsgBody_Response& from);

  inline MsgBody_Response& operator=(const MsgBody_Response& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MsgBody_Response(MsgBody_Response&& from) noexcept
    : MsgBody_Response() {
    *this = ::std::move(from);
  }

  inline MsgBody_Response& operator=(MsgBody_Response&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const MsgBody_Response& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const MsgBody_Response* internal_default_instance() {
    return reinterpret_cast<const MsgBody_Response*>(
               &_MsgBody_Response_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(MsgBody_Response* other);
  friend void swap(MsgBody_Response& a, MsgBody_Response& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MsgBody_Response* New() const final {
    return CreateMaybeMessage<MsgBody_Response>(NULL);
  }

  MsgBody_Response* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<MsgBody_Response>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const MsgBody_Response& from);
  void MergeFrom(const MsgBody_Response& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(MsgBody_Response* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bytes msg = 2;
  void clear_msg();
  static const int kMsgFieldNumber = 2;
  const ::std::string& msg() const;
  void set_msg(const ::std::string& value);
  #if LANG_CXX11
  void set_msg(::std::string&& value);
  #endif
  void set_msg(const char* value);
  void set_msg(const void* value, size_t size);
  ::std::string* mutable_msg();
  ::std::string* release_msg();
  void set_allocated_msg(::std::string* msg);

  // int32 code = 1;
  void clear_code();
  static const int kCodeFieldNumber = 1;
  ::google::protobuf::int32 code() const;
  void set_code(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:MsgBody.Response)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr msg_;
  ::google::protobuf::int32 code_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_msg_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class MsgBody : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:MsgBody) */ {
 public:
  MsgBody();
  virtual ~MsgBody();

  MsgBody(const MsgBody& from);

  inline MsgBody& operator=(const MsgBody& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MsgBody(MsgBody&& from) noexcept
    : MsgBody() {
    *this = ::std::move(from);
  }

  inline MsgBody& operator=(MsgBody&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const MsgBody& default_instance();

  enum MsgTypeCase {
    kReqTarget = 1,
    kRspResult = 2,
    MSG_TYPE_NOT_SET = 0,
  };

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const MsgBody* internal_default_instance() {
    return reinterpret_cast<const MsgBody*>(
               &_MsgBody_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  void Swap(MsgBody* other);
  friend void swap(MsgBody& a, MsgBody& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MsgBody* New() const final {
    return CreateMaybeMessage<MsgBody>(NULL);
  }

  MsgBody* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<MsgBody>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const MsgBody& from);
  void MergeFrom(const MsgBody& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(MsgBody* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef MsgBody_Request Request;
  typedef MsgBody_Response Response;

  // accessors -------------------------------------------------------

  // bytes data = 3;
  void clear_data();
  static const int kDataFieldNumber = 3;
  const ::std::string& data() const;
  void set_data(const ::std::string& value);
  #if LANG_CXX11
  void set_data(::std::string&& value);
  #endif
  void set_data(const char* value);
  void set_data(const void* value, size_t size);
  ::std::string* mutable_data();
  ::std::string* release_data();
  void set_allocated_data(::std::string* data);

  // bytes add_on = 4;
  void clear_add_on();
  static const int kAddOnFieldNumber = 4;
  const ::std::string& add_on() const;
  void set_add_on(const ::std::string& value);
  #if LANG_CXX11
  void set_add_on(::std::string&& value);
  #endif
  void set_add_on(const char* value);
  void set_add_on(const void* value, size_t size);
  ::std::string* mutable_add_on();
  ::std::string* release_add_on();
  void set_allocated_add_on(::std::string* add_on);

  // string trace_id = 5;
  void clear_trace_id();
  static const int kTraceIdFieldNumber = 5;
  const ::std::string& trace_id() const;
  void set_trace_id(const ::std::string& value);
  #if LANG_CXX11
  void set_trace_id(::std::string&& value);
  #endif
  void set_trace_id(const char* value);
  void set_trace_id(const char* value, size_t size);
  ::std::string* mutable_trace_id();
  ::std::string* release_trace_id();
  void set_allocated_trace_id(::std::string* trace_id);

  // .MsgBody.Request req_target = 1;
  bool has_req_target() const;
  void clear_req_target();
  static const int kReqTargetFieldNumber = 1;
  private:
  const ::MsgBody_Request& _internal_req_target() const;
  public:
  const ::MsgBody_Request& req_target() const;
  ::MsgBody_Request* release_req_target();
  ::MsgBody_Request* mutable_req_target();
  void set_allocated_req_target(::MsgBody_Request* req_target);

  // .MsgBody.Response rsp_result = 2;
  bool has_rsp_result() const;
  void clear_rsp_result();
  static const int kRspResultFieldNumber = 2;
  private:
  const ::MsgBody_Response& _internal_rsp_result() const;
  public:
  const ::MsgBody_Response& rsp_result() const;
  ::MsgBody_Response* release_rsp_result();
  ::MsgBody_Response* mutable_rsp_result();
  void set_allocated_rsp_result(::MsgBody_Response* rsp_result);

  void clear_msg_type();
  MsgTypeCase msg_type_case() const;
  // @@protoc_insertion_point(class_scope:MsgBody)
 private:
  void set_has_req_target();
  void set_has_rsp_result();

  inline bool has_msg_type() const;
  inline void clear_has_msg_type();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr data_;
  ::google::protobuf::internal::ArenaStringPtr add_on_;
  ::google::protobuf::internal::ArenaStringPtr trace_id_;
  union MsgTypeUnion {
    MsgTypeUnion() {}
    ::MsgBody_Request* req_target_;
    ::MsgBody_Response* rsp_result_;
  } msg_type_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::uint32 _oneof_case_[1];

  friend struct ::protobuf_msg_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MsgHead

// fixed32 cmd = 1;
inline void MsgHead::clear_cmd() {
  cmd_ = 0u;
}
inline ::google::protobuf::uint32 MsgHead::cmd() const {
  // @@protoc_insertion_point(field_get:MsgHead.cmd)
  return cmd_;
}
inline void MsgHead::set_cmd(::google::protobuf::uint32 value) {
  
  cmd_ = value;
  // @@protoc_insertion_point(field_set:MsgHead.cmd)
}

// fixed32 seq = 2;
inline void MsgHead::clear_seq() {
  seq_ = 0u;
}
inline ::google::protobuf::uint32 MsgHead::seq() const {
  // @@protoc_insertion_point(field_get:MsgHead.seq)
  return seq_;
}
inline void MsgHead::set_seq(::google::protobuf::uint32 value) {
  
  seq_ = value;
  // @@protoc_insertion_point(field_set:MsgHead.seq)
}

// sfixed32 len = 3;
inline void MsgHead::clear_len() {
  len_ = 0;
}
inline ::google::protobuf::int32 MsgHead::len() const {
  // @@protoc_insertion_point(field_get:MsgHead.len)
  return len_;
}
inline void MsgHead::set_len(::google::protobuf::int32 value) {
  
  len_ = value;
  // @@protoc_insertion_point(field_set:MsgHead.len)
}

// -------------------------------------------------------------------

// MsgBody_Request

// uint32 route_id = 1;
inline void MsgBody_Request::clear_route_id() {
  route_id_ = 0u;
}
inline ::google::protobuf::uint32 MsgBody_Request::route_id() const {
  // @@protoc_insertion_point(field_get:MsgBody.Request.route_id)
  return route_id_;
}
inline void MsgBody_Request::set_route_id(::google::protobuf::uint32 value) {
  
  route_id_ = value;
  // @@protoc_insertion_point(field_set:MsgBody.Request.route_id)
}

// string route = 2;
inline void MsgBody_Request::clear_route() {
  route_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MsgBody_Request::route() const {
  // @@protoc_insertion_point(field_get:MsgBody.Request.route)
  return route_.GetNoArena();
}
inline void MsgBody_Request::set_route(const ::std::string& value) {
  
  route_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:MsgBody.Request.route)
}
#if LANG_CXX11
inline void MsgBody_Request::set_route(::std::string&& value) {
  
  route_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:MsgBody.Request.route)
}
#endif
inline void MsgBody_Request::set_route(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  route_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:MsgBody.Request.route)
}
inline void MsgBody_Request::set_route(const char* value, size_t size) {
  
  route_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:MsgBody.Request.route)
}
inline ::std::string* MsgBody_Request::mutable_route() {
  
  // @@protoc_insertion_point(field_mutable:MsgBody.Request.route)
  return route_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MsgBody_Request::release_route() {
  // @@protoc_insertion_point(field_release:MsgBody.Request.route)
  
  return route_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MsgBody_Request::set_allocated_route(::std::string* route) {
  if (route != NULL) {
    
  } else {
    
  }
  route_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), route);
  // @@protoc_insertion_point(field_set_allocated:MsgBody.Request.route)
}

// -------------------------------------------------------------------

// MsgBody_Response

// int32 code = 1;
inline void MsgBody_Response::clear_code() {
  code_ = 0;
}
inline ::google::protobuf::int32 MsgBody_Response::code() const {
  // @@protoc_insertion_point(field_get:MsgBody.Response.code)
  return code_;
}
inline void MsgBody_Response::set_code(::google::protobuf::int32 value) {
  
  code_ = value;
  // @@protoc_insertion_point(field_set:MsgBody.Response.code)
}

// bytes msg = 2;
inline void MsgBody_Response::clear_msg() {
  msg_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MsgBody_Response::msg() const {
  // @@protoc_insertion_point(field_get:MsgBody.Response.msg)
  return msg_.GetNoArena();
}
inline void MsgBody_Response::set_msg(const ::std::string& value) {
  
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:MsgBody.Response.msg)
}
#if LANG_CXX11
inline void MsgBody_Response::set_msg(::std::string&& value) {
  
  msg_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:MsgBody.Response.msg)
}
#endif
inline void MsgBody_Response::set_msg(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:MsgBody.Response.msg)
}
inline void MsgBody_Response::set_msg(const void* value, size_t size) {
  
  msg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:MsgBody.Response.msg)
}
inline ::std::string* MsgBody_Response::mutable_msg() {
  
  // @@protoc_insertion_point(field_mutable:MsgBody.Response.msg)
  return msg_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MsgBody_Response::release_msg() {
  // @@protoc_insertion_point(field_release:MsgBody.Response.msg)
  
  return msg_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MsgBody_Response::set_allocated_msg(::std::string* msg) {
  if (msg != NULL) {
    
  } else {
    
  }
  msg_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), msg);
  // @@protoc_insertion_point(field_set_allocated:MsgBody.Response.msg)
}

// -------------------------------------------------------------------

// MsgBody

// .MsgBody.Request req_target = 1;
inline bool MsgBody::has_req_target() const {
  return msg_type_case() == kReqTarget;
}
inline void MsgBody::set_has_req_target() {
  _oneof_case_[0] = kReqTarget;
}
inline void MsgBody::clear_req_target() {
  if (has_req_target()) {
    delete msg_type_.req_target_;
    clear_has_msg_type();
  }
}
inline const ::MsgBody_Request& MsgBody::_internal_req_target() const {
  return *msg_type_.req_target_;
}
inline ::MsgBody_Request* MsgBody::release_req_target() {
  // @@protoc_insertion_point(field_release:MsgBody.req_target)
  if (has_req_target()) {
    clear_has_msg_type();
      ::MsgBody_Request* temp = msg_type_.req_target_;
    msg_type_.req_target_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline const ::MsgBody_Request& MsgBody::req_target() const {
  // @@protoc_insertion_point(field_get:MsgBody.req_target)
  return has_req_target()
      ? *msg_type_.req_target_
      : *reinterpret_cast< ::MsgBody_Request*>(&::_MsgBody_Request_default_instance_);
}
inline ::MsgBody_Request* MsgBody::mutable_req_target() {
  if (!has_req_target()) {
    clear_msg_type();
    set_has_req_target();
    msg_type_.req_target_ = CreateMaybeMessage< ::MsgBody_Request >(
        GetArenaNoVirtual());
  }
  // @@protoc_insertion_point(field_mutable:MsgBody.req_target)
  return msg_type_.req_target_;
}

// .MsgBody.Response rsp_result = 2;
inline bool MsgBody::has_rsp_result() const {
  return msg_type_case() == kRspResult;
}
inline void MsgBody::set_has_rsp_result() {
  _oneof_case_[0] = kRspResult;
}
inline void MsgBody::clear_rsp_result() {
  if (has_rsp_result()) {
    delete msg_type_.rsp_result_;
    clear_has_msg_type();
  }
}
inline const ::MsgBody_Response& MsgBody::_internal_rsp_result() const {
  return *msg_type_.rsp_result_;
}
inline ::MsgBody_Response* MsgBody::release_rsp_result() {
  // @@protoc_insertion_point(field_release:MsgBody.rsp_result)
  if (has_rsp_result()) {
    clear_has_msg_type();
      ::MsgBody_Response* temp = msg_type_.rsp_result_;
    msg_type_.rsp_result_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline const ::MsgBody_Response& MsgBody::rsp_result() const {
  // @@protoc_insertion_point(field_get:MsgBody.rsp_result)
  return has_rsp_result()
      ? *msg_type_.rsp_result_
      : *reinterpret_cast< ::MsgBody_Response*>(&::_MsgBody_Response_default_instance_);
}
inline ::MsgBody_Response* MsgBody::mutable_rsp_result() {
  if (!has_rsp_result()) {
    clear_msg_type();
    set_has_rsp_result();
    msg_type_.rsp_result_ = CreateMaybeMessage< ::MsgBody_Response >(
        GetArenaNoVirtual());
  }
  // @@protoc_insertion_point(field_mutable:MsgBody.rsp_result)
  return msg_type_.rsp_result_;
}

// bytes data = 3;
inline void MsgBody::clear_data() {
  data_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MsgBody::data() const {
  // @@protoc_insertion_point(field_get:MsgBody.data)
  return data_.GetNoArena();
}
inline void MsgBody::set_data(const ::std::string& value) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:MsgBody.data)
}
#if LANG_CXX11
inline void MsgBody::set_data(::std::string&& value) {
  
  data_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:MsgBody.data)
}
#endif
inline void MsgBody::set_data(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:MsgBody.data)
}
inline void MsgBody::set_data(const void* value, size_t size) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:MsgBody.data)
}
inline ::std::string* MsgBody::mutable_data() {
  
  // @@protoc_insertion_point(field_mutable:MsgBody.data)
  return data_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MsgBody::release_data() {
  // @@protoc_insertion_point(field_release:MsgBody.data)
  
  return data_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MsgBody::set_allocated_data(::std::string* data) {
  if (data != NULL) {
    
  } else {
    
  }
  data_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), data);
  // @@protoc_insertion_point(field_set_allocated:MsgBody.data)
}

// bytes add_on = 4;
inline void MsgBody::clear_add_on() {
  add_on_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MsgBody::add_on() const {
  // @@protoc_insertion_point(field_get:MsgBody.add_on)
  return add_on_.GetNoArena();
}
inline void MsgBody::set_add_on(const ::std::string& value) {
  
  add_on_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:MsgBody.add_on)
}
#if LANG_CXX11
inline void MsgBody::set_add_on(::std::string&& value) {
  
  add_on_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:MsgBody.add_on)
}
#endif
inline void MsgBody::set_add_on(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  add_on_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:MsgBody.add_on)
}
inline void MsgBody::set_add_on(const void* value, size_t size) {
  
  add_on_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:MsgBody.add_on)
}
inline ::std::string* MsgBody::mutable_add_on() {
  
  // @@protoc_insertion_point(field_mutable:MsgBody.add_on)
  return add_on_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MsgBody::release_add_on() {
  // @@protoc_insertion_point(field_release:MsgBody.add_on)
  
  return add_on_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MsgBody::set_allocated_add_on(::std::string* add_on) {
  if (add_on != NULL) {
    
  } else {
    
  }
  add_on_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), add_on);
  // @@protoc_insertion_point(field_set_allocated:MsgBody.add_on)
}

// string trace_id = 5;
inline void MsgBody::clear_trace_id() {
  trace_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MsgBody::trace_id() const {
  // @@protoc_insertion_point(field_get:MsgBody.trace_id)
  return trace_id_.GetNoArena();
}
inline void MsgBody::set_trace_id(const ::std::string& value) {
  
  trace_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:MsgBody.trace_id)
}
#if LANG_CXX11
inline void MsgBody::set_trace_id(::std::string&& value) {
  
  trace_id_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:MsgBody.trace_id)
}
#endif
inline void MsgBody::set_trace_id(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  trace_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:MsgBody.trace_id)
}
inline void MsgBody::set_trace_id(const char* value, size_t size) {
  
  trace_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:MsgBody.trace_id)
}
inline ::std::string* MsgBody::mutable_trace_id() {
  
  // @@protoc_insertion_point(field_mutable:MsgBody.trace_id)
  return trace_id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MsgBody::release_trace_id() {
  // @@protoc_insertion_point(field_release:MsgBody.trace_id)
  
  return trace_id_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MsgBody::set_allocated_trace_id(::std::string* trace_id) {
  if (trace_id != NULL) {
    
  } else {
    
  }
  trace_id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), trace_id);
  // @@protoc_insertion_point(field_set_allocated:MsgBody.trace_id)
}

inline bool MsgBody::has_msg_type() const {
  return msg_type_case() != MSG_TYPE_NOT_SET;
}
inline void MsgBody::clear_has_msg_type() {
  _oneof_case_[0] = MSG_TYPE_NOT_SET;
}
inline MsgBody::MsgTypeCase MsgBody::msg_type_case() const {
  return MsgBody::MsgTypeCase(_oneof_case_[0]);
}
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_msg_2eproto
