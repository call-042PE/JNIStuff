#pragma once
#include <jni.h>
namespace string_decoder {
	const char* irisutils(JNIEnv* p_env, const char* string);
	const char* checker_task(JNIEnv* p_env, const char* string);
	const char* proxy_delete(JNIEnv* p_env, const char* string);
	const char* request_utils(JNIEnv* p_env, const char* string);
}