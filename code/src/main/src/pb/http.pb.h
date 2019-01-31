// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: http.proto

#ifndef PROTOBUF_INCLUDED_http_2eproto
#define PROTOBUF_INCLUDED_http_2eproto

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
#include <google/protobuf/map.h>  // IWYU pragma: export
#include <google/protobuf/map_entry.h>
#include <google/protobuf/map_field_inl.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_http_2eproto 

namespace protobuf_http_2eproto {
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
}  // namespace protobuf_http_2eproto
class HttpMsg;
class HttpMsgDefaultTypeInternal;
extern HttpMsgDefaultTypeInternal _HttpMsg_default_instance_;
class HttpMsg_HeadersEntry_DoNotUse;
class HttpMsg_HeadersEntry_DoNotUseDefaultTypeInternal;
extern HttpMsg_HeadersEntry_DoNotUseDefaultTypeInternal _HttpMsg_HeadersEntry_DoNotUse_default_instance_;
class HttpMsg_ParamsEntry_DoNotUse;
class HttpMsg_ParamsEntry_DoNotUseDefaultTypeInternal;
extern HttpMsg_ParamsEntry_DoNotUseDefaultTypeInternal _HttpMsg_ParamsEntry_DoNotUse_default_instance_;
class HttpMsg_Upgrade;
class HttpMsg_UpgradeDefaultTypeInternal;
extern HttpMsg_UpgradeDefaultTypeInternal _HttpMsg_Upgrade_default_instance_;
namespace google {
namespace protobuf {
template<> ::HttpMsg* Arena::CreateMaybeMessage<::HttpMsg>(Arena*);
template<> ::HttpMsg_HeadersEntry_DoNotUse* Arena::CreateMaybeMessage<::HttpMsg_HeadersEntry_DoNotUse>(Arena*);
template<> ::HttpMsg_ParamsEntry_DoNotUse* Arena::CreateMaybeMessage<::HttpMsg_ParamsEntry_DoNotUse>(Arena*);
template<> ::HttpMsg_Upgrade* Arena::CreateMaybeMessage<::HttpMsg_Upgrade>(Arena*);
}  // namespace protobuf
}  // namespace google

// ===================================================================

class HttpMsg_HeadersEntry_DoNotUse : public ::google::protobuf::internal::MapEntry<HttpMsg_HeadersEntry_DoNotUse, 
    ::std::string, ::std::string,
    ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
    ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
    0 > {
public:
  typedef ::google::protobuf::internal::MapEntry<HttpMsg_HeadersEntry_DoNotUse, 
    ::std::string, ::std::string,
    ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
    ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
    0 > SuperType;
  HttpMsg_HeadersEntry_DoNotUse();
  HttpMsg_HeadersEntry_DoNotUse(::google::protobuf::Arena* arena);
  void MergeFrom(const HttpMsg_HeadersEntry_DoNotUse& other);
  static const HttpMsg_HeadersEntry_DoNotUse* internal_default_instance() { return reinterpret_cast<const HttpMsg_HeadersEntry_DoNotUse*>(&_HttpMsg_HeadersEntry_DoNotUse_default_instance_); }
  void MergeFrom(const ::google::protobuf::Message& other) final;
  ::google::protobuf::Metadata GetMetadata() const;
};

// -------------------------------------------------------------------

class HttpMsg_ParamsEntry_DoNotUse : public ::google::protobuf::internal::MapEntry<HttpMsg_ParamsEntry_DoNotUse, 
    ::std::string, ::std::string,
    ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
    ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
    0 > {
public:
  typedef ::google::protobuf::internal::MapEntry<HttpMsg_ParamsEntry_DoNotUse, 
    ::std::string, ::std::string,
    ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
    ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
    0 > SuperType;
  HttpMsg_ParamsEntry_DoNotUse();
  HttpMsg_ParamsEntry_DoNotUse(::google::protobuf::Arena* arena);
  void MergeFrom(const HttpMsg_ParamsEntry_DoNotUse& other);
  static const HttpMsg_ParamsEntry_DoNotUse* internal_default_instance() { return reinterpret_cast<const HttpMsg_ParamsEntry_DoNotUse*>(&_HttpMsg_ParamsEntry_DoNotUse_default_instance_); }
  void MergeFrom(const ::google::protobuf::Message& other) final;
  ::google::protobuf::Metadata GetMetadata() const;
};

// -------------------------------------------------------------------

class HttpMsg_Upgrade : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:HttpMsg.Upgrade) */ {
 public:
  HttpMsg_Upgrade();
  virtual ~HttpMsg_Upgrade();

  HttpMsg_Upgrade(const HttpMsg_Upgrade& from);

  inline HttpMsg_Upgrade& operator=(const HttpMsg_Upgrade& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  HttpMsg_Upgrade(HttpMsg_Upgrade&& from) noexcept
    : HttpMsg_Upgrade() {
    *this = ::std::move(from);
  }

  inline HttpMsg_Upgrade& operator=(HttpMsg_Upgrade&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const HttpMsg_Upgrade& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const HttpMsg_Upgrade* internal_default_instance() {
    return reinterpret_cast<const HttpMsg_Upgrade*>(
               &_HttpMsg_Upgrade_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(HttpMsg_Upgrade* other);
  friend void swap(HttpMsg_Upgrade& a, HttpMsg_Upgrade& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline HttpMsg_Upgrade* New() const final {
    return CreateMaybeMessage<HttpMsg_Upgrade>(NULL);
  }

  HttpMsg_Upgrade* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<HttpMsg_Upgrade>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const HttpMsg_Upgrade& from);
  void MergeFrom(const HttpMsg_Upgrade& from);
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
  void InternalSwap(HttpMsg_Upgrade* other);
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

  // string protocol = 2;
  void clear_protocol();
  static const int kProtocolFieldNumber = 2;
  const ::std::string& protocol() const;
  void set_protocol(const ::std::string& value);
  #if LANG_CXX11
  void set_protocol(::std::string&& value);
  #endif
  void set_protocol(const char* value);
  void set_protocol(const char* value, size_t size);
  ::std::string* mutable_protocol();
  ::std::string* release_protocol();
  void set_allocated_protocol(::std::string* protocol);

  // bool is_upgrade = 1;
  void clear_is_upgrade();
  static const int kIsUpgradeFieldNumber = 1;
  bool is_upgrade() const;
  void set_is_upgrade(bool value);

  // @@protoc_insertion_point(class_scope:HttpMsg.Upgrade)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr protocol_;
  bool is_upgrade_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_http_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class HttpMsg : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:HttpMsg) */ {
 public:
  HttpMsg();
  virtual ~HttpMsg();

  HttpMsg(const HttpMsg& from);

  inline HttpMsg& operator=(const HttpMsg& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  HttpMsg(HttpMsg&& from) noexcept
    : HttpMsg() {
    *this = ::std::move(from);
  }

  inline HttpMsg& operator=(HttpMsg&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const HttpMsg& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const HttpMsg* internal_default_instance() {
    return reinterpret_cast<const HttpMsg*>(
               &_HttpMsg_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  void Swap(HttpMsg* other);
  friend void swap(HttpMsg& a, HttpMsg& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline HttpMsg* New() const final {
    return CreateMaybeMessage<HttpMsg>(NULL);
  }

  HttpMsg* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<HttpMsg>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const HttpMsg& from);
  void MergeFrom(const HttpMsg& from);
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
  void InternalSwap(HttpMsg* other);
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

  typedef HttpMsg_Upgrade Upgrade;

  // accessors -------------------------------------------------------

  // map<string, string> headers = 9;
  int headers_size() const;
  void clear_headers();
  static const int kHeadersFieldNumber = 9;
  const ::google::protobuf::Map< ::std::string, ::std::string >&
      headers() const;
  ::google::protobuf::Map< ::std::string, ::std::string >*
      mutable_headers();

  // map<string, string> params = 11;
  int params_size() const;
  void clear_params();
  static const int kParamsFieldNumber = 11;
  const ::google::protobuf::Map< ::std::string, ::std::string >&
      params() const;
  ::google::protobuf::Map< ::std::string, ::std::string >*
      mutable_params();

  // string url = 8;
  void clear_url();
  static const int kUrlFieldNumber = 8;
  const ::std::string& url() const;
  void set_url(const ::std::string& value);
  #if LANG_CXX11
  void set_url(::std::string&& value);
  #endif
  void set_url(const char* value);
  void set_url(const char* value, size_t size);
  ::std::string* mutable_url();
  ::std::string* release_url();
  void set_allocated_url(::std::string* url);

  // bytes body = 10;
  void clear_body();
  static const int kBodyFieldNumber = 10;
  const ::std::string& body() const;
  void set_body(const ::std::string& value);
  #if LANG_CXX11
  void set_body(::std::string&& value);
  #endif
  void set_body(const char* value);
  void set_body(const void* value, size_t size);
  ::std::string* mutable_body();
  ::std::string* release_body();
  void set_allocated_body(::std::string* body);

  // string path = 14;
  void clear_path();
  static const int kPathFieldNumber = 14;
  const ::std::string& path() const;
  void set_path(const ::std::string& value);
  #if LANG_CXX11
  void set_path(::std::string&& value);
  #endif
  void set_path(const char* value);
  void set_path(const char* value, size_t size);
  ::std::string* mutable_path();
  ::std::string* release_path();
  void set_allocated_path(::std::string* path);

  // .HttpMsg.Upgrade upgrade = 12;
  bool has_upgrade() const;
  void clear_upgrade();
  static const int kUpgradeFieldNumber = 12;
  private:
  const ::HttpMsg_Upgrade& _internal_upgrade() const;
  public:
  const ::HttpMsg_Upgrade& upgrade() const;
  ::HttpMsg_Upgrade* release_upgrade();
  ::HttpMsg_Upgrade* mutable_upgrade();
  void set_allocated_upgrade(::HttpMsg_Upgrade* upgrade);

  // int32 type = 1;
  void clear_type();
  static const int kTypeFieldNumber = 1;
  ::google::protobuf::int32 type() const;
  void set_type(::google::protobuf::int32 value);

  // int32 http_major = 2;
  void clear_http_major();
  static const int kHttpMajorFieldNumber = 2;
  ::google::protobuf::int32 http_major() const;
  void set_http_major(::google::protobuf::int32 value);

  // int32 http_minor = 3;
  void clear_http_minor();
  static const int kHttpMinorFieldNumber = 3;
  ::google::protobuf::int32 http_minor() const;
  void set_http_minor(::google::protobuf::int32 value);

  // int32 content_length = 4;
  void clear_content_length();
  static const int kContentLengthFieldNumber = 4;
  ::google::protobuf::int32 content_length() const;
  void set_content_length(::google::protobuf::int32 value);

  // int32 method = 5;
  void clear_method();
  static const int kMethodFieldNumber = 5;
  ::google::protobuf::int32 method() const;
  void set_method(::google::protobuf::int32 value);

  // int32 status_code = 6;
  void clear_status_code();
  static const int kStatusCodeFieldNumber = 6;
  ::google::protobuf::int32 status_code() const;
  void set_status_code(::google::protobuf::int32 value);

  // int32 encoding = 7;
  void clear_encoding();
  static const int kEncodingFieldNumber = 7;
  ::google::protobuf::int32 encoding() const;
  void set_encoding(::google::protobuf::int32 value);

  // float keep_alive = 13;
  void clear_keep_alive();
  static const int kKeepAliveFieldNumber = 13;
  float keep_alive() const;
  void set_keep_alive(float value);

  // bool is_decoding = 15;
  void clear_is_decoding();
  static const int kIsDecodingFieldNumber = 15;
  bool is_decoding() const;
  void set_is_decoding(bool value);

  // @@protoc_insertion_point(class_scope:HttpMsg)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::MapField<
      HttpMsg_HeadersEntry_DoNotUse,
      ::std::string, ::std::string,
      ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
      ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
      0 > headers_;
  ::google::protobuf::internal::MapField<
      HttpMsg_ParamsEntry_DoNotUse,
      ::std::string, ::std::string,
      ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
      ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
      0 > params_;
  ::google::protobuf::internal::ArenaStringPtr url_;
  ::google::protobuf::internal::ArenaStringPtr body_;
  ::google::protobuf::internal::ArenaStringPtr path_;
  ::HttpMsg_Upgrade* upgrade_;
  ::google::protobuf::int32 type_;
  ::google::protobuf::int32 http_major_;
  ::google::protobuf::int32 http_minor_;
  ::google::protobuf::int32 content_length_;
  ::google::protobuf::int32 method_;
  ::google::protobuf::int32 status_code_;
  ::google::protobuf::int32 encoding_;
  float keep_alive_;
  bool is_decoding_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_http_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// HttpMsg_Upgrade

// bool is_upgrade = 1;
inline void HttpMsg_Upgrade::clear_is_upgrade() {
  is_upgrade_ = false;
}
inline bool HttpMsg_Upgrade::is_upgrade() const {
  // @@protoc_insertion_point(field_get:HttpMsg.Upgrade.is_upgrade)
  return is_upgrade_;
}
inline void HttpMsg_Upgrade::set_is_upgrade(bool value) {
  
  is_upgrade_ = value;
  // @@protoc_insertion_point(field_set:HttpMsg.Upgrade.is_upgrade)
}

// string protocol = 2;
inline void HttpMsg_Upgrade::clear_protocol() {
  protocol_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& HttpMsg_Upgrade::protocol() const {
  // @@protoc_insertion_point(field_get:HttpMsg.Upgrade.protocol)
  return protocol_.GetNoArena();
}
inline void HttpMsg_Upgrade::set_protocol(const ::std::string& value) {
  
  protocol_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:HttpMsg.Upgrade.protocol)
}
#if LANG_CXX11
inline void HttpMsg_Upgrade::set_protocol(::std::string&& value) {
  
  protocol_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:HttpMsg.Upgrade.protocol)
}
#endif
inline void HttpMsg_Upgrade::set_protocol(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  protocol_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:HttpMsg.Upgrade.protocol)
}
inline void HttpMsg_Upgrade::set_protocol(const char* value, size_t size) {
  
  protocol_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:HttpMsg.Upgrade.protocol)
}
inline ::std::string* HttpMsg_Upgrade::mutable_protocol() {
  
  // @@protoc_insertion_point(field_mutable:HttpMsg.Upgrade.protocol)
  return protocol_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* HttpMsg_Upgrade::release_protocol() {
  // @@protoc_insertion_point(field_release:HttpMsg.Upgrade.protocol)
  
  return protocol_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void HttpMsg_Upgrade::set_allocated_protocol(::std::string* protocol) {
  if (protocol != NULL) {
    
  } else {
    
  }
  protocol_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), protocol);
  // @@protoc_insertion_point(field_set_allocated:HttpMsg.Upgrade.protocol)
}

// -------------------------------------------------------------------

// HttpMsg

// int32 type = 1;
inline void HttpMsg::clear_type() {
  type_ = 0;
}
inline ::google::protobuf::int32 HttpMsg::type() const {
  // @@protoc_insertion_point(field_get:HttpMsg.type)
  return type_;
}
inline void HttpMsg::set_type(::google::protobuf::int32 value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:HttpMsg.type)
}

// int32 http_major = 2;
inline void HttpMsg::clear_http_major() {
  http_major_ = 0;
}
inline ::google::protobuf::int32 HttpMsg::http_major() const {
  // @@protoc_insertion_point(field_get:HttpMsg.http_major)
  return http_major_;
}
inline void HttpMsg::set_http_major(::google::protobuf::int32 value) {
  
  http_major_ = value;
  // @@protoc_insertion_point(field_set:HttpMsg.http_major)
}

// int32 http_minor = 3;
inline void HttpMsg::clear_http_minor() {
  http_minor_ = 0;
}
inline ::google::protobuf::int32 HttpMsg::http_minor() const {
  // @@protoc_insertion_point(field_get:HttpMsg.http_minor)
  return http_minor_;
}
inline void HttpMsg::set_http_minor(::google::protobuf::int32 value) {
  
  http_minor_ = value;
  // @@protoc_insertion_point(field_set:HttpMsg.http_minor)
}

// int32 content_length = 4;
inline void HttpMsg::clear_content_length() {
  content_length_ = 0;
}
inline ::google::protobuf::int32 HttpMsg::content_length() const {
  // @@protoc_insertion_point(field_get:HttpMsg.content_length)
  return content_length_;
}
inline void HttpMsg::set_content_length(::google::protobuf::int32 value) {
  
  content_length_ = value;
  // @@protoc_insertion_point(field_set:HttpMsg.content_length)
}

// int32 method = 5;
inline void HttpMsg::clear_method() {
  method_ = 0;
}
inline ::google::protobuf::int32 HttpMsg::method() const {
  // @@protoc_insertion_point(field_get:HttpMsg.method)
  return method_;
}
inline void HttpMsg::set_method(::google::protobuf::int32 value) {
  
  method_ = value;
  // @@protoc_insertion_point(field_set:HttpMsg.method)
}

// int32 status_code = 6;
inline void HttpMsg::clear_status_code() {
  status_code_ = 0;
}
inline ::google::protobuf::int32 HttpMsg::status_code() const {
  // @@protoc_insertion_point(field_get:HttpMsg.status_code)
  return status_code_;
}
inline void HttpMsg::set_status_code(::google::protobuf::int32 value) {
  
  status_code_ = value;
  // @@protoc_insertion_point(field_set:HttpMsg.status_code)
}

// int32 encoding = 7;
inline void HttpMsg::clear_encoding() {
  encoding_ = 0;
}
inline ::google::protobuf::int32 HttpMsg::encoding() const {
  // @@protoc_insertion_point(field_get:HttpMsg.encoding)
  return encoding_;
}
inline void HttpMsg::set_encoding(::google::protobuf::int32 value) {
  
  encoding_ = value;
  // @@protoc_insertion_point(field_set:HttpMsg.encoding)
}

// string url = 8;
inline void HttpMsg::clear_url() {
  url_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& HttpMsg::url() const {
  // @@protoc_insertion_point(field_get:HttpMsg.url)
  return url_.GetNoArena();
}
inline void HttpMsg::set_url(const ::std::string& value) {
  
  url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:HttpMsg.url)
}
#if LANG_CXX11
inline void HttpMsg::set_url(::std::string&& value) {
  
  url_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:HttpMsg.url)
}
#endif
inline void HttpMsg::set_url(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:HttpMsg.url)
}
inline void HttpMsg::set_url(const char* value, size_t size) {
  
  url_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:HttpMsg.url)
}
inline ::std::string* HttpMsg::mutable_url() {
  
  // @@protoc_insertion_point(field_mutable:HttpMsg.url)
  return url_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* HttpMsg::release_url() {
  // @@protoc_insertion_point(field_release:HttpMsg.url)
  
  return url_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void HttpMsg::set_allocated_url(::std::string* url) {
  if (url != NULL) {
    
  } else {
    
  }
  url_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), url);
  // @@protoc_insertion_point(field_set_allocated:HttpMsg.url)
}

// map<string, string> headers = 9;
inline int HttpMsg::headers_size() const {
  return headers_.size();
}
inline void HttpMsg::clear_headers() {
  headers_.Clear();
}
inline const ::google::protobuf::Map< ::std::string, ::std::string >&
HttpMsg::headers() const {
  // @@protoc_insertion_point(field_map:HttpMsg.headers)
  return headers_.GetMap();
}
inline ::google::protobuf::Map< ::std::string, ::std::string >*
HttpMsg::mutable_headers() {
  // @@protoc_insertion_point(field_mutable_map:HttpMsg.headers)
  return headers_.MutableMap();
}

// bytes body = 10;
inline void HttpMsg::clear_body() {
  body_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& HttpMsg::body() const {
  // @@protoc_insertion_point(field_get:HttpMsg.body)
  return body_.GetNoArena();
}
inline void HttpMsg::set_body(const ::std::string& value) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:HttpMsg.body)
}
#if LANG_CXX11
inline void HttpMsg::set_body(::std::string&& value) {
  
  body_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:HttpMsg.body)
}
#endif
inline void HttpMsg::set_body(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:HttpMsg.body)
}
inline void HttpMsg::set_body(const void* value, size_t size) {
  
  body_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:HttpMsg.body)
}
inline ::std::string* HttpMsg::mutable_body() {
  
  // @@protoc_insertion_point(field_mutable:HttpMsg.body)
  return body_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* HttpMsg::release_body() {
  // @@protoc_insertion_point(field_release:HttpMsg.body)
  
  return body_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void HttpMsg::set_allocated_body(::std::string* body) {
  if (body != NULL) {
    
  } else {
    
  }
  body_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), body);
  // @@protoc_insertion_point(field_set_allocated:HttpMsg.body)
}

// map<string, string> params = 11;
inline int HttpMsg::params_size() const {
  return params_.size();
}
inline void HttpMsg::clear_params() {
  params_.Clear();
}
inline const ::google::protobuf::Map< ::std::string, ::std::string >&
HttpMsg::params() const {
  // @@protoc_insertion_point(field_map:HttpMsg.params)
  return params_.GetMap();
}
inline ::google::protobuf::Map< ::std::string, ::std::string >*
HttpMsg::mutable_params() {
  // @@protoc_insertion_point(field_mutable_map:HttpMsg.params)
  return params_.MutableMap();
}

// .HttpMsg.Upgrade upgrade = 12;
inline bool HttpMsg::has_upgrade() const {
  return this != internal_default_instance() && upgrade_ != NULL;
}
inline void HttpMsg::clear_upgrade() {
  if (GetArenaNoVirtual() == NULL && upgrade_ != NULL) {
    delete upgrade_;
  }
  upgrade_ = NULL;
}
inline const ::HttpMsg_Upgrade& HttpMsg::_internal_upgrade() const {
  return *upgrade_;
}
inline const ::HttpMsg_Upgrade& HttpMsg::upgrade() const {
  const ::HttpMsg_Upgrade* p = upgrade_;
  // @@protoc_insertion_point(field_get:HttpMsg.upgrade)
  return p != NULL ? *p : *reinterpret_cast<const ::HttpMsg_Upgrade*>(
      &::_HttpMsg_Upgrade_default_instance_);
}
inline ::HttpMsg_Upgrade* HttpMsg::release_upgrade() {
  // @@protoc_insertion_point(field_release:HttpMsg.upgrade)
  
  ::HttpMsg_Upgrade* temp = upgrade_;
  upgrade_ = NULL;
  return temp;
}
inline ::HttpMsg_Upgrade* HttpMsg::mutable_upgrade() {
  
  if (upgrade_ == NULL) {
    auto* p = CreateMaybeMessage<::HttpMsg_Upgrade>(GetArenaNoVirtual());
    upgrade_ = p;
  }
  // @@protoc_insertion_point(field_mutable:HttpMsg.upgrade)
  return upgrade_;
}
inline void HttpMsg::set_allocated_upgrade(::HttpMsg_Upgrade* upgrade) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete upgrade_;
  }
  if (upgrade) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      upgrade = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, upgrade, submessage_arena);
    }
    
  } else {
    
  }
  upgrade_ = upgrade;
  // @@protoc_insertion_point(field_set_allocated:HttpMsg.upgrade)
}

// float keep_alive = 13;
inline void HttpMsg::clear_keep_alive() {
  keep_alive_ = 0;
}
inline float HttpMsg::keep_alive() const {
  // @@protoc_insertion_point(field_get:HttpMsg.keep_alive)
  return keep_alive_;
}
inline void HttpMsg::set_keep_alive(float value) {
  
  keep_alive_ = value;
  // @@protoc_insertion_point(field_set:HttpMsg.keep_alive)
}

// string path = 14;
inline void HttpMsg::clear_path() {
  path_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& HttpMsg::path() const {
  // @@protoc_insertion_point(field_get:HttpMsg.path)
  return path_.GetNoArena();
}
inline void HttpMsg::set_path(const ::std::string& value) {
  
  path_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:HttpMsg.path)
}
#if LANG_CXX11
inline void HttpMsg::set_path(::std::string&& value) {
  
  path_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:HttpMsg.path)
}
#endif
inline void HttpMsg::set_path(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  path_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:HttpMsg.path)
}
inline void HttpMsg::set_path(const char* value, size_t size) {
  
  path_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:HttpMsg.path)
}
inline ::std::string* HttpMsg::mutable_path() {
  
  // @@protoc_insertion_point(field_mutable:HttpMsg.path)
  return path_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* HttpMsg::release_path() {
  // @@protoc_insertion_point(field_release:HttpMsg.path)
  
  return path_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void HttpMsg::set_allocated_path(::std::string* path) {
  if (path != NULL) {
    
  } else {
    
  }
  path_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), path);
  // @@protoc_insertion_point(field_set_allocated:HttpMsg.path)
}

// bool is_decoding = 15;
inline void HttpMsg::clear_is_decoding() {
  is_decoding_ = false;
}
inline bool HttpMsg::is_decoding() const {
  // @@protoc_insertion_point(field_get:HttpMsg.is_decoding)
  return is_decoding_;
}
inline void HttpMsg::set_is_decoding(bool value) {
  
  is_decoding_ = value;
  // @@protoc_insertion_point(field_set:HttpMsg.is_decoding)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_http_2eproto
