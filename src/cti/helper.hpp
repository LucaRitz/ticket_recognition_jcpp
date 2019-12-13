#pragma once

#include <jni.h>

namespace cti::java {
    const char* getAlgorithmName(JNIEnv* env, jobject& algorithm);
    void throwCtiException(JNIEnv* env, const char* message);
}