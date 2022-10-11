#define LOG_TAG "mypackage.mysubpackage.fooAIDL-service"

#include <android-base/logging.h>
#include <android/binder_process.h>
#include <binder/ProcessState.h>

#include <android/binder_manager.h>
#include <binder/IServiceManager.h>

#include "Test.h"

using aidl::mypackage::mysubpackage::fooAIDL::Test;
using std::string_literals::operator""s;

int main() {
    // Enable vndbinder to allow vendor-to-vendor binder calls.
    android::ProcessState::initWithDriver("/dev/vndbinder");

    ABinderProcess_startThreadPool();

    LOG(INFO) << "Test aidl service for fooAIDL is starting.,,";

    std::shared_ptr<Test> test = ndk::SharedRefBase::make<Test>();
    const std::string name = Test::descriptor + "/default"s;
    CHECK_EQ(STATUS_OK, AServiceManager_addService(test->asBinder().get(), name.c_str()));

    LOG(INFO) << "Initialized fooAIDL cpu";

    ABinderProcess_joinThreadPool();

    return EXIT_FAILURE;  // should not reach
}