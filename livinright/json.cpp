#include "json.h"
#include <iostream>

//coded this for nothing didnt have to use it but anyway

jobject json_object::create(JNIEnv* p_env, const char* key, const char* value) {
    jclass cls = p_env->FindClass("org/json/JSONObject"); // get JSONObject
    jmethodID constructor_id = p_env->GetMethodID(cls, "<init>", "()V"); // get the init method
    jobject jsonObj = p_env->NewObject(cls, constructor_id); // init a new object of JSONObject
    jmethodID method = p_env->GetMethodID(cls, "put", "(Ljava/lang/String;Ljava/lang/Object;)Lorg/json/JSONObject;"); // get the put function
    p_env->CallObjectMethod(jsonObj, method, p_env->NewStringUTF(key), p_env->NewStringUTF(value)); // call the put method with the params
    //jfieldID mapID = p_env->GetFieldID(cls, "map", "Ljava/util/Map;");
    //jobject map_obj = p_env->GetObjectField(obj, mapID);
    return jsonObj;
}