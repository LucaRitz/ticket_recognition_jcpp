#include <com_bfh_ticket_Cti.h>
#include <include/sift/sift_matching_algorithm.hpp>
#include <include/sift/sift_extraction_algorithm.hpp>
#include <include/point.hpp>
#include <cstring>
#include <iostream>

using cti::SiftMatchingAlgorithm;
using cti::SiftExtractionAlgorithm;

JNIEXPORT jobject JNICALL Java_com_bfh_ticket_Cti_matcher
        (JNIEnv * env, jobject object, jstring algorithm) {
    const char* nativeAlgorithmString = env->GetStringUTFChars(algorithm, nullptr);
    if (strcmp("SIFT", nativeAlgorithmString) == 0) {
        auto * algorithmImpl = new SiftMatchingAlgorithm;
        jclass matchingClass = env->FindClass("com/bfh/ticket/Matcher");
        jmethodID constructor = env->GetMethodID(matchingClass, "<init>", "(J)V");
        return env->NewObject(matchingClass, constructor, &algorithmImpl);
    }
    return nullptr;
}

JNIEXPORT jobject JNICALL Java_com_bfh_ticket_Cti_reader
        (JNIEnv * env, jobject object, jstring algorithm) {
    const char* nativeAlgorithmString = env->GetStringUTFChars(algorithm, nullptr);
    if (strcmp("SIFT", nativeAlgorithmString) == 0) {
        auto * algorithmImpl = new SiftExtractionAlgorithm;
        jclass matchingClass = env->FindClass("com/bfh/ticket/MetadataReader");
        jmethodID constructor = env->GetMethodID(matchingClass, "<init>", "(J)V");
        return env->NewObject(matchingClass, constructor, &algorithmImpl);
    }
    return nullptr;
}