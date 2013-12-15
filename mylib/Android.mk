LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := init
LOCAL_SRC_FILES := _log.c
LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)