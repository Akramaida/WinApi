#include <iostream>
#include <Windows.h>
#include <Imacces.h>
#include <atlstr.h>
#include <napi.h>


using namespase Napi;

Napi::Value Method(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	
 	USER_INFO_0* buffer;
	DWORD entries;
	DWORD total_entries;
	DWORD resume_handle 0;

	NET_API_STATUS a = NetUserEnum(
		NULL,
		0, 0,	
		(BYTE**)&buffer,
		4096,
 		&entries,
		&total_entries,	
		&resume_handle
	),

	Napi::Array userArray = Napi::Array::New(info.Env(), entries);

	for(uint32_t i = 0; i < entries; i++)
	{
		auto&& user = string (CW2A(buffer[i].usri0_name));
		userArray[i] = Napi::String::New(info.Env(), user);
	}

	return userArray;

}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "check"),
              Napi::Function::New(env, Method));
  return exports;
}

NODE_API_MODULE(check, Init)