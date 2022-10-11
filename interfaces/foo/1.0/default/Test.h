#ifndef MYPACKAGE_MYSUBPACKAGE_FOO_V1_0_ITEST_H
#define MYPACKAGE_MYSUBPACKAGE_FOO_V1_0_ITEST_H

// Mesmo caminho após:
// mypackage.mysubpackage.foo@1.0_genc++_headers/gen/
#include <mypackage/mysubpackage/foo/1.0/ITest.h>

namespace mypackage {
namespace mysubpackage {
namespace foo {
namespace V1_0 {
namespace implementation {

using ::android::hardware::hidl_string;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::mypackage::mysubpackage::foo::V1_0::ITest;

class Test : public ITest {

    public:
        Return<bool> setTest(const hidl_string& param) override;
        Return<void> getTest(getTest_cb _hidl_c) override;
};

extern "C" ITest* HIDL_FETCH_ITest(const char* name);

} // namespace implementation
} // namespace V1_0 
} // namespace foo
} // namespace mysubpackage
} // namespace mypackage

#endif