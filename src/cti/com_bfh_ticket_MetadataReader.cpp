#include <com_bfh_ticket_MetadataReader.h>

#include <include/metadata_reader.hpp>
#include <include/metadata.hpp>
#include <include/ticket.hpp>
#include <include/ticket_image.hpp>
#include <include/extraction/extraction_algorithms.hpp>
#include <include/extraction/extraction_algorithm.hpp>
#include <include/extraction/extraction_options.hpp>
#include <string.h>

#include "helper.hpp"

using cti::MetadataReader;
using cti::Metadata;
using cti::Ticket;
using cti::TicketImage;
using cti::ExtractionAlgorithms;
using cti::ExtractionAlgorithm;
using cti::ExtractionOptions;
using cti::java::getAlgorithmName;

const ExtractionOptions readReaderOptions(JNIEnv* env, jobject& javaOptions) {
    jclass javaExtractionOptionsClass = env->FindClass("com/bfh/ticket/MetadataReaderOptions");
    jmethodID javaGetRatioTestThreshold = env->GetMethodID(javaExtractionOptionsClass, "getRatioTestThreshold", "()D");
    jmethodID javaGetLanguage = env->GetMethodID(javaExtractionOptionsClass, "getLanguage", "()Ljava/lang/String;");

    jdouble javaRatioTestThreshold = env->CallDoubleMethod(javaOptions, javaGetRatioTestThreshold);
    auto javaLanguage = (jstring) env->CallObjectMethod(javaOptions, javaGetLanguage);

    const char* language = env->GetStringUTFChars(javaLanguage, nullptr);

    auto ratioTestThreshold = static_cast<double>(javaRatioTestThreshold);

    return ExtractionOptions(ratioTestThreshold >= 0 ? ratioTestThreshold : 0.7,
            strcmp("", language) == 0 ? std::string("eng") : std::string(language));
}

/*
 * Class:     com_bfh_ticket_MetadataReader
 * Method:    initialize
 * Signature: (Lcom/bfh/ticket/Algorithm;Lcom/bfh/ticket/MetadataReaderOptions;)J
 */
JNIEXPORT jlong JNICALL Java_com_bfh_ticket_MetadataReader_initialize
        (JNIEnv* env, jobject object, jobject javaAlgorithm, jobject javaOptions) {
    const char* nativeAlgorithmString = getAlgorithmName(env, javaAlgorithm);

    const ExtractionOptions options = readReaderOptions(env, javaOptions);
    ExtractionAlgorithm* extractionAlgorithm = nullptr;
    if (strcmp("SIFT", nativeAlgorithmString) == 0) {
        extractionAlgorithm = ExtractionAlgorithms::sift(options).release();
    } else if (strcmp("ORB", nativeAlgorithmString) == 0) {
        extractionAlgorithm = ExtractionAlgorithms::orb(options).release();
    }

    if (extractionAlgorithm != nullptr) {
        auto* reader = new MetadataReader(*extractionAlgorithm);
        return (jlong) reader;
    }

    return jlong(-1);
}

/*
 * Class:     com_bfh_ticket_MetadataReader
 * Method:    read
 * Signature: (JLcom/bfh/ticket/Ticket;Lcom/bfh/ticket/TicketImage;)Lcom/bfh/ticket/Metadata;
 */
JNIEXPORT jobject JNICALL Java_com_bfh_ticket_MetadataReader_read
        (JNIEnv* env, jobject obj, jlong pointer, jlong ticketPointer, jobject javaTicketImage) {
    auto* reader = reinterpret_cast<MetadataReader*>(pointer);
    auto* ticket = reinterpret_cast<Ticket*>(ticketPointer);

    // Create Ticket image
    jclass javaTicketImageClass = env->FindClass("com/bfh/ticket/TicketImage");
    jfieldID pathField = env->GetFieldID(javaTicketImageClass, "imagePath", "Ljava/lang/String;");
    auto imagePathAsJavaString = (jstring) env->GetObjectField(javaTicketImage, pathField);
    string imagePath = env->GetStringUTFChars(imagePathAsJavaString, nullptr);
    TicketImage ticketImage(imagePath);

    const Metadata metadata = reader->read(*ticket, ticketImage);

    jclass mapClass = env->FindClass("java/util/HashMap");
    jmethodID mapConstructor = env->GetMethodID(mapClass, "<init>", "()V");
    jobject map = env->NewObject(mapClass, mapConstructor);

    jmethodID putMethod = env->GetMethodID(mapClass, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");

    for (auto const& value : metadata.texts()) {
        env->CallObjectMethod(map, putMethod, env->NewStringUTF(value.first.c_str()), env->NewStringUTF(value.second.c_str()));
    }

    jclass metadataClass = env->FindClass("com/bfh/ticket/Metadata");
    jmethodID metadataConstructor = env->GetMethodID(metadataClass, "<init>", "(Ljava/util/Map;)V");
    return env->NewObject(metadataClass, metadataConstructor, map);
}

/*
 * Class:     com_bfh_ticket_MetadataReader
 * Method:    delete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_bfh_ticket_MetadataReader_delete
        (JNIEnv* env, jobject obj, jlong pointer) {
    auto* nativePtr = reinterpret_cast<MetadataReader*>(pointer);
    delete nativePtr;
}