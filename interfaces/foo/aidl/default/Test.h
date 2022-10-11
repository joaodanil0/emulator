#pragma once

// Mesmo caminho após:
// mypackage.mysubpackage.fooAIDL-V1-ndk_platform-source/gen/include/
// dentro da pasta out/
#include <aidl/mypackage/mysubpackage/fooAIDL/BnTest.h>

namespace aidl::mypackage::mysubpackage::fooAIDL {

class Test : public BnTest {
  public:
    ndk::ScopedAStatus getTest(std::string* _aidl_return) override;
    ndk::ScopedAStatus setTest(const std::string& in_param, bool* _aidl_return) override;
};

}  // namespace aidl::mypackage::mysubpackage::fooAIDL
