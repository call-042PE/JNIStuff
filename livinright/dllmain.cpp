#include "includes.h"
#pragma comment(lib, "libMinHook-x64.lib")
#include "MinHook.h"

void MainThread()
{

    AllocConsole();
    FILE* fIn;
    FILE* fOut;
    freopen_s(&fIn, "conin$", "r", stdin);
    freopen_s(&fOut, "conout$", "w", stdout);
    freopen_s(&fOut, "conout$", "w", stderr);

    std::cout << "Injected !" << std::endl;

    JavaVM* p_jvm{ nullptr };
    jint kek = JNI_GetCreatedJavaVMs(&p_jvm, 1, nullptr);


    JNIEnv* p_env{ nullptr }; // JNI interface pointer
    p_jvm->AttachCurrentThread((void**)&p_env, nullptr);

    jobject userDataObj = myjni::get_userdata_obj(p_env);

    jstring lifetime = p_env->NewStringUTF("Lifetime");
    jstring user = p_env->NewStringUTF("__asm");
    jstring expiry = p_env->NewStringUTF("1819328784");

    p_env->SetObjectField(userDataObj, myjni::get_userdata_field(p_env, "subscription"), lifetime);
    p_env->SetObjectField(userDataObj, myjni::get_userdata_field(p_env, "username"), user);
    p_env->SetObjectField(userDataObj, myjni::get_userdata_field(p_env, "expiry"), expiry);

    p_env->SetObjectField(myjni::get_keyauth_obj(p_env), myjni::get_keyauth_field(p_env), userDataObj);

    //std::cout << string_decoder::irisutils(p_env, "(\u00174\u00133YoL#\f-\u00134\u0006n\u0017&Rn\u00052L!��#\f5\r4\u0010n\u0011%\u0010%\u0017\u0010\u00023\u00107\f2\u0007") << std::endl;

}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        MH_Initialize();
        DisableThreadLibraryCalls(hModule);
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, nullptr, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

