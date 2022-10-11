

PRODUCT_SOONG_NAMESPACES += device/generic/goldfish # for libwifi-hal-emu
PRODUCT_SOONG_NAMESPACES += device/generic/goldfish-opengl # for goldfish deps.

ifdef NET_ETH0_STARTONBOOT
  PRODUCT_VENDOR_PROPERTIES += net.eth0.startonboot=1
endif

# Ensure we package the BIOS files too.
PRODUCT_HOST_PACKAGES += \
	bios.bin \
	vgabios-cirrus.bin \
