#ifndef FOOJNI_H
#define FOOJNI_H

#define LOG_TAG "FOO_JNI.cpp"
#define LOG_NDEBUG 1

#include "jni.h"

// #include <limits.h>

#include <android-base/chrono_utils.h>
// #include <utils/Timers.h>
// #include <utils/misc.h>
// #include <utils/String8.h>
#include <utils/Log.h>


#include <mypackage/mysubpackage/foo/1.0/ITest.h>

using ::mypackage::mysubpackage::foo::V1_0::ITest;

using android::hardware::Return;
using android::hardware::Void;
// using android::String8;
using android::sp;

class FooJNI {

    public:
        inline static sp<ITest> fooHal = nullptr;
        inline static bool fooHalExists = true;
        inline static const char *classPathName = "com/fooJniJava/FooJniJava";

    public:
        static bool getFooHal();
        
        static void processReturn(const Return<void> &ret, const char* functionName);        
        static int registerNativeMethods(JNIEnv* env, const char* className, JNINativeMethod* gMethods, int numMethods);
        static int register_jni_foo(JNIEnv* env);

        static void nativeInit(JNIEnv* env, jobject /* obj */);
        static jstring getTest(JNIEnv* env, jclass /* clazz */);
        static jboolean setTest(JNIEnv*  env, jclass /* clazz */, jstring governor);


};

#endif