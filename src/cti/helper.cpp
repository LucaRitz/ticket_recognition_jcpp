#include "helper.hpp"

const char* cti::java::getAlgorithmName(JNIEnv *env, jobject& algorithm) {
    jclass javaAlgorithmClass = env->FindClass("com/bfh/ticket/Algorithm");
    jmethodID javaAlgorithmNameMethod = env->GetMethodID(javaAlgorithmClass, "name", "()Ljava/lang/String;");
    auto javaAlgorithmName = (jstring) env->CallObjectMethod(algorithm, javaAlgorithmNameMethod);
    return env->GetStringUTFChars(javaAlgorithmName, nullptr);
}