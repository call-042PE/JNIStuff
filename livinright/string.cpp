#include "string.h"

//two method for decrypting the obfuscator of the jar i was working one

//just a simple xor function

const char* string_decoder::irisutils(JNIEnv* p_env, const char* string) {
    jclass irisUtilsClass = p_env->FindClass("su/binair/api/utils/IrisUtils");
    jmethodID kFonction = p_env->GetStaticMethodID(irisUtilsClass, "k", "(Ljava/lang/String;)Ljava/lang/String;");
    jstring arg1 = p_env->NewStringUTF(string);
    jstring result = (jstring)p_env->CallStaticObjectMethod(irisUtilsClass, kFonction, arg1);
    p_env->ReleaseStringUTFChars(arg1, NULL);
    if (result == NULL) {
        return 0;
    }
    jboolean isCopy = (jboolean)false;
    return p_env->GetStringUTFChars(result, &isCopy);
}

const char* string_decoder::checker_task(JNIEnv* p_env, const char* string) {
    jclass jklass = p_env->FindClass("su/binair/api/tasks/CheckerTask");
    jmethodID method = p_env->GetStaticMethodID(jklass, "k", "(Ljava/lang/String;)Ljava/lang/String;");
    jstring arg1 = p_env->NewStringUTF(string);
    jstring result = (jstring)p_env->CallStaticObjectMethod(jklass, method, arg1);
    p_env->ReleaseStringUTFChars(arg1, NULL);
    if (result == NULL) {
        return 0;
    }
    jboolean isCopy = (jboolean)false;
    return p_env->GetStringUTFChars(result, &isCopy);
}

const char* string_decoder::proxy_delete(JNIEnv* p_env, const char* string) {
    jclass jklass = p_env->FindClass("su/binair/api/controller/ProxyDeleteController");
    jmethodID method = p_env->GetStaticMethodID(jklass, "k", "(Ljava/lang/String;)Ljava/lang/String;");
    jstring arg1 = p_env->NewStringUTF(string);
    jstring result = (jstring)p_env->CallStaticObjectMethod(jklass, method, arg1);
    p_env->ReleaseStringUTFChars(arg1, NULL);
    if (result == NULL) {
        return 0;
    }
    jboolean isCopy = (jboolean)false;
    return p_env->GetStringUTFChars(result, &isCopy);
}

const char* string_decoder::request_utils(JNIEnv* p_env, const char* string) {
    jclass jklass = p_env->FindClass("su/binair/api/utils/RequestUtils");
    jmethodID method = p_env->GetStaticMethodID(jklass, "k", "(Ljava/lang/String;)Ljava/lang/String;");
    jstring arg1 = p_env->NewStringUTF(string);
    jstring result = (jstring)p_env->CallStaticObjectMethod(jklass, method, arg1);
    p_env->ReleaseStringUTFChars(arg1, NULL);
    if (result == NULL) {
        return 0;
    }
    jboolean isCopy = (jboolean)false;
    return p_env->GetStringUTFChars(result, &isCopy);
}