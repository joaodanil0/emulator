#include "FooJNI.h"

JNINativeMethod methods[] = {
    { "nativeInit", "()V", (void*) FooJNI::nativeInit },
    { "nativeGetTest", "()Ljava/lang/String;", (void*) FooJNI::getTest },
    { "nativeSetTest", "(Ljava/lang/String;)Z", (void*) FooJNI::setTest },
};

std::mutex fooHalMutex;

bool FooJNI::getFooHal() {
    
    if (fooHalExists && fooHal == nullptr) {

        fooHal = ITest::getService(); // Proxy to the service

        if (fooHal != nullptr) {
            ALOGI("Loaded foo HAL service");
        } 
        else {
            ALOGI("Couldn't load foo HAL service");
            fooHalExists = false;
        }
    }
    return fooHal != nullptr;
}

void FooJNI::nativeInit(JNIEnv* env, jobject /* obj */) {
    fooHalMutex.lock();
    getFooHal();
    fooHalMutex.unlock();
}

void FooJNI::processReturn(const Return<void> &ret, const char* functionName) {
    if (!ret.isOk()) {
        ALOGE("%s() failed: foo HAL service not available.", functionName);
        fooHal = nullptr;
    }
}

jstring FooJNI::getTest(JNIEnv* env, jclass /* clazz */) { // static method has jclass
    jstring jstr = NULL;

    std::lock_guard<std::mutex> lock(fooHalMutex);
    if (FooJNI::getFooHal()) {
        android::base::Timer t;

        Return<void> ret = FooJNI::fooHal->getTest(
            [&](android::hardware::hidl_string result) { // Callback                
                ALOGD("getTest result %s", result.c_str());
                jstr = env->NewStringUTF(result.c_str());  // new Java String object
            }
        );

        FooJNI::processReturn(ret, "getTest");

        if (t.duration() > 20ms) {
            ALOGW("Excessive delay in getTest");
        }
    }

    return jstr;
}

jboolean FooJNI::setTest(JNIEnv*  env, jclass /* clazz */, jstring governor) {

    ALOGD("nativeSetTest");

    std::lock_guard<std::mutex> lock(fooHalMutex);

    bool ret = false;
    if (FooJNI::getFooHal()) {
        android::base::Timer t;

        const char* cGovernor = env->GetStringUTFChars(governor, NULL);
        ret = FooJNI::fooHal->setTest(cGovernor);
        env->ReleaseStringUTFChars(governor, cGovernor);

        if (t.duration() > 20ms) {
            ALOGW("Excessive delay in setScalingGovernor");
        }
    }

    return ret;
}

int FooJNI::registerNativeMethods(JNIEnv* env, const char* className, JNINativeMethod* gMethods, int numMethods) {
    
    jclass clazz;

    ALOGE("registerNativeMethods '%s'", className);

    clazz = env->FindClass(className);

    if (clazz == NULL) {
        ALOGE("Native registration unable to find class '%s'", className);
        return JNI_FALSE;
    }

    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        ALOGE("RegisterNatives failed for '%s'", className);
        return JNI_FALSE;
    }

    return JNI_TRUE;
}

int FooJNI::register_jni_foo(JNIEnv* env) {
    if (!registerNativeMethods(env, FooJNI::classPathName, methods, sizeof(methods) / sizeof(methods[0]))) {
        return JNI_FALSE;
    }

    return JNI_TRUE;
}