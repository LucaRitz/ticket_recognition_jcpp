#include <com_bfh_ticket_Cti.h>
#include <include/sift/sift_matching_algorithm.hpp>
#include <include/sift/sift_extraction_algorithm.hpp>
#include <include/matcher.hpp>
#include <include/metadata_reader.hpp>
#include <cstring>

using cti::SiftMatchingAlgorithm;
using cti::SiftExtractionAlgorithm;
using cti::Matcher;
using cti::MetadataReader;

#include "com_bfh_ticket_Matcher.h"

JNIEXPORT jobject JNICALL Java_com_bfh_ticket_Cti_matcher
        (JNIEnv * env, jobject object, jstring algorithm) {
    const char* nativeAlgorithmString = env->GetStringUTFChars(algorithm, nullptr);
    if (strcmp("SIFT", nativeAlgorithmString) == 0) {
        auto * algorithmImpl = new SiftMatchingAlgorithm;
        auto* matcher = new Matcher(*algorithmImpl);
        jclass matchingClass = env->FindClass("com/bfh/ticket/Matcher");
        jmethodID constructor = env->GetMethodID(matchingClass, "<init>", "(J)V");
        return env->NewObject(matchingClass, constructor, reinterpret_cast<jlong>(matcher));
    }
    return nullptr;
}

JNIEXPORT jobject JNICALL Java_com_bfh_ticket_Cti_reader
        (JNIEnv * env, jobject object, jstring algorithm) {
    const char* nativeAlgorithmString = env->GetStringUTFChars(algorithm, nullptr);
    if (strcmp("SIFT", nativeAlgorithmString) == 0) {
        auto * algorithmImpl = new SiftExtractionAlgorithm;
        auto* reader = new MetadataReader(*algorithmImpl);
        jclass matchingClass = env->FindClass("com/bfh/ticket/MetadataReader");
        jmethodID constructor = env->GetMethodID(matchingClass, "<init>", "(J)V");
        return env->NewObject(matchingClass, constructor, reinterpret_cast<jlong>(reader));
    }
    return nullptr;
}