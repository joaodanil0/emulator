#include <aidl/mypackage/mysubpackage/fooAIDL/ITest.h>

#include <iostream>
#include <string>

#include <android/binder_manager.h>

using ::aidl::mypackage::mysubpackage::fooAIDL::ITest;


int main(int argc, char *argv[]) {

    std::shared_ptr<ITest> mHal;
    std::string a;
    bool c;

    if (argc != 2) {
        std::cout << "USAGE ./cpu_client <conservative|powersave|performance|schedutil>\n";
        exit(0);
    }

    AIBinder* binder = AServiceManager_waitForService("mypackage.mysubpackage.fooAIDL.ITest/default");

    if (binder == nullptr){
        std::cout << "Failed to get cpu service\n";
        exit(-1);
    }

    mHal = ITest::fromBinder(ndk::SpAIBinder(binder));


    mHal->getTest(&a);
    std::cout << "getScalingGovernor:" << a << std::endl;

    mHal->setTest(argv[1], &c);
    std::cout << "setScalingGovernor:" << c << std::endl;

    mHal->getTest(&a);
    std::cout << "getScalingGovernor:" << a << std::endl;

    return 0;
}