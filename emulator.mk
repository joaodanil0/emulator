$(call inherit-product, $(SRC_TARGET_DIR)/product/sdk_phone_x86_64.mk)

PRODUCT_NAME := emulator
PRODUCT_DEVICE := emulator
PRODUCT_MODEL := Full Android on CoyotePad, meep-meep

PRODUCT_PACKAGES += \
    mypackage.mysubpackage.foo@1.0 \
    mypackage.mysubpackage.foo@1.0-service

PRODUCT_PACKAGES_DEBUG += subpackage_foo_tester

PRODUCT_PACKAGES += \
    mypackage.mysubpackage.fooAIDL \
    mypackage.mysubpackage.fooAIDL-service

# PRODUCT_PACKAGES_DEBUG += foo_AIDL_tester

PRODUCT_PACKAGES += \
    libfooJNI \
    com.fooJniJava \
    FoohidlServices \
    FoohidlServicesJava \
    FooAidlServicesJava \



