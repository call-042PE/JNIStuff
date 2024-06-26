#pragma once
#include <jni.h>

namespace myjni {
	jobject get_keyauth_obj(JNIEnv* p_env);
	jfieldID get_keyauth_field(JNIEnv* p_env);
	jfieldID get_userdata_field(JNIEnv* p_env, const char* field_name);
	jobject get_userdata_obj(JNIEnv* p_env);
}