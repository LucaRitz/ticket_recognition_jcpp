#include <com_bfh_ticket_Cti.h>
#include <com_bfh_ticket_Matcher.h>
#include <include/extraction/extraction_algorithms.hpp>
#include <include/matching/matching_algorithms.hpp>
#include <include/matcher.hpp>
#include <include/metadata_reader.hpp>
#include <cstring>

using cti::Matcher;
using cti::MetadataReader;
using cti::ExtractionAlgorithms;
using cti::MatchingAlgorithms;
using cti::ExtractionAlgorithm;
using cti::MatchingAlgorithm;

JNIEXPORT jobject JNICALL Java_com_bfh_ticket_Cti_matcher
        (JNIEnv * env, jobject object, jstring algorithm) {
    const char* nativeAlgorithmString = env->GetStringUTFChars(algorithm, nullptr);

    MatchingAlgorithm* matchingAlgorithm = nullptr;
    if (strcmp("SIFT", nativeAlgorithmString) == 0) {
        matchingAlgorithm = MatchingAlgorithms::sift().release();
    } else if (strcmp("ORB", nativeAlgorithmString) == 0) {
        matchingAlgorithm = MatchingAlgorithms::orb().release();
    }

    if (matchingAlgorithm != nullptr) {
        auto* matcher = new Matcher(*matchingAlgorithm);
        jclass matchingClass = env->FindClass("com/bfh/ticket/Matcher");
        jmethodID constructor = env->GetMethodID(matchingClass, "<init>", "(J)V");
        return env->NewObject(matchingClass, constructor, reinterpret_cast<jlong>(matcher));
    }

    return nullptr;
}

JNIEXPORT jobject JNICALL Java_com_bfh_ticket_Cti_reader
        (JNIEnv * env, jobject object, jstring algorithm) {
    const char* nativeAlgorithmString = env->GetStringUTFChars(algorithm, nullptr);

    ExtractionAlgorithm* extractionAlgorithm = nullptr;
    if (strcmp("SIFT", nativeAlgorithmString) == 0) {
        extractionAlgorithm = ExtractionAlgorithms::sift().release();
    } else if (strcmp("ORB", nativeAlgorithmString) == 0) {
        extractionAlgorithm = ExtractionAlgorithms::orb().release();
    }

    if (extractionAlgorithm != nullptr) {
        auto* reader = new MetadataReader(*extractionAlgorithm);
        jclass matchingClass = env->FindClass("com/bfh/ticket/MetadataReader");
        jmethodID constructor = env->GetMethodID(matchingClass, "<init>", "(J)V");
        return env->NewObject(matchingClass, constructor, reinterpret_cast<jlong>(reader));
    }

    return nullptr;
}