
#define LOG_TAG "mypackage.mysubpackage.foo@1.0-service"

#include <mypackage/mysubpackage/foo/1.0/ITest.h>

#include <log/log.h>
#include <hidl/HidlTransportSupport.h>

#include "Test.h"

using android::sp;
using android::status_t;
using android::OK;

// libhwbinder:
using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;

// Generated HIDL files
using mypackage::mysubpackage::foo::V1_0::ITest;
using mypackage::mysubpackage::foo::V1_0::implementation::Test;

using namespace mypackage;

int main(int /* argc */, char** /* argv */) {
    ALOGI("Foo Service 1.0 for test is starting.");

    // Android Strong Pointer (don't GC until exit)
    sp<ITest> service = new Test();
    if (service == nullptr) {
        ALOGE("Can not create an instance of ITest HAL, exiting.");
        return 1;
    }

    // system/libhidl/transport/include/hidl/HidlTransportSupport.h
    // Configures the threadpool used for handling incoming RPC calls in this process:
    // @param maxThreads maximum number of threads in this process
    // @param callerWillJoin whether the caller will join the threadpool later.
    configureRpcThreadpool(1, true /*callerWillJoin*/);

    // registerAsService calls registerAsServiceInternal in
    // system/libhidl/transport/ServiceManagement.cpp
    // registerAsServiceInternal registers with hwservicemanager
    status_t status = service->registerAsService();
    if (status != OK) {
        ALOGE("Could not register service for ITest HAL (%d), exiting.", status);
        return 1;
    }
    ALOGI("Test Service is ready");

    // system/libhidl/transport/include/hidl/HidlTransportSupport.h
    // Joins a threadpool that you configured earlier
    joinRpcThreadpool();

    // In normal operation, we don't expect the thread pool to exit
    ALOGE("Test Service is shutting down");
    return 1;
}

