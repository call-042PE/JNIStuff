#include "jni.h"

jobject myjni::get_keyauth_obj(JNIEnv* p_env) {
    jclass instancesClass = p_env->FindClass("su/binair/api/utils/Instances");
    jfieldID keyauthInstanceID = p_env->GetStaticFieldID(instancesClass, "keyAuth", "Lsu/binair/api/utils/keyauth/KeyAuth;");
    return p_env->GetStaticObjectField(instancesClass, keyauthInstanceID);
}

jfieldID myjni::get_keyauth_field(JNIEnv* p_env) {
    jclass keyauthClass = p_env->FindClass("su/binair/api/utils/keyauth/KeyAuth");
    return p_env->GetFieldID(keyauthClass, "userData", "Lsu/binair/api/utils/keyauth/UserData;");
}

jfieldID myjni::get_userdata_field(JNIEnv* p_env, const char* field_name) {
    jclass userDataClass = p_env->FindClass("su/binair/api/utils/keyauth/UserData");
    return p_env->GetFieldID(userDataClass, field_name, "Ljava/lang/String;");
}

jobject myjni::get_userdata_obj(JNIEnv* p_env) {
    jclass userDataClass = p_env->FindClass("su/binair/api/utils/keyauth/UserData");
    return p_env->AllocObject(userDataClass);
}