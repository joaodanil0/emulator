


TARGET_CPU_ABI := x86_64
TARGET_ARCH := x86_64
TARGET_ARCH_VARIANT := x86_64

TARGET_2ND_CPU_ABI := x86
TARGET_2ND_ARCH := x86
TARGET_2ND_ARCH_VARIANT := x86_64

TARGET_PRELINK_MODULE := false
include build/make/target/board/BoardConfigGsiCommon.mk
include build/make/target/board/BoardConfigEmuCommon.mk

BOARD_USERDATAIMAGE_PARTITION_SIZE := 576716800

BOARD_SEPOLICY_DIRS += device/generic/goldfish/sepolicy/x86
BOARD_SEPOLICY_DIRS += device/casa/emulator/sepolicy

# Wifi.
#BOARD_WLAN_DEVICE           := emulator
#BOARD_HOSTAPD_DRIVER        := NL80211
#BOARD_WPA_SUPPLICANT_DRIVER := NL80211
#BOARD_HOSTAPD_PRIVATE_LIB   := lib_driver_cmd_simulated
#BOARD_WPA_SUPPLICANT_PRIVATE_LIB := lib_driver_cmd_simulated
#WPA_SUPPLICANT_VERSION      := VER_0_8_X
#WIFI_DRIVER_FW_PATH_PARAM   := "/dev/null"
#WIFI_DRIVER_FW_PATH_STA     := "/dev/null"
#WIFI_DRIVER_FW_PATH_AP      := "/dev/null"
