#include "jni.h"
#include "utils/Log.h"
#include "utils/misc.h"


namespace FooJNI {
     int register_jni_foo(JNIEnv* env);
};

using namespace FooJNI;

extern "C" jint JNI_OnLoad(JavaVM* vm, void* /* reserved */)
{
    JNIEnv* env = NULL;
    jint result = -1;

    if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) {
        ALOGE("GetEnv failed!");
        return result;
    }
    ALOG_ASSERT(env, "Could not retrieve the env!");

    FooJNI::register_jni_foo(env);
    return JNI_VERSION_1_4;
}
