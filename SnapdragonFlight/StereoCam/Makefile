# This Makefile goes in each module, and allows building of an individual module library.
# It is expected that each developer will add targets of their own for building and running
# tests, for example.

# derive module name from directory

MODULE_DIR = SnapdragonFlight/StereoCam
MODULE = $(subst /,,$(MODULE_DIR))

BUILD_ROOT ?= $(subst /$(MODULE_DIR),,$(CURDIR))
export BUILD_ROOT

include $(BUILD_ROOT)/mk/makefiles/module_targets.mk

load: ut_nocov_SDFLIGHT
	adb push ./test/ut/linux-linaro-cross-arm-ut-nocov-gnu-bin/test_ut /eng/load/scam_test_ut
