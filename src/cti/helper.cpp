#include "helper.hpp"

const char* cti::java::getAlgorithmName(JNIEnv *env, jobject& algorithm) {
    jclass javaAlgorithmClass = env->FindClass("com/bfh/ticket/Algorithm");
    jmethodID javaAlgorithmNameMethod = env->GetMethodID(javaAlgorithmClass, "name", "()Ljava/lang/String;");
    auto javaAlgorithmName = (jstring) env->CallObjectMethod(algorithm, javaAlgorithmNameMethod);
    return env->GetStringUTFChars(javaAlgorithmName, nullptr);
}

void cti::java::throwCtiException(JNIEnv* env, const char* message) {
    jclass javaCtiExceptionClass = env->FindClass("com/bfh/ticket/exception/CtiException");
    env->ThrowNew(javaCtiExceptionClass, message);
}