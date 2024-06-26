#pragma once
#include "jnihook.h"
namespace json_object {
	jobject create(JNIEnv* p_env, const char* key, const char* value);
}