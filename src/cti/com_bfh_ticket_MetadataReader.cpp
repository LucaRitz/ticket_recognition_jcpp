#include <com_bfh_ticket_MetadataReader.h>

#include <include/metadata_reader.hpp>
#include <include/metadata.hpp>
#include <include/ticket.hpp>
#include <include/ticket_image.hpp>

using cti::MetadataReader;
using cti::Metadata;
using cti::Ticket;
using cti::TicketImage;

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

    const Metadata* const metadata = reader->read(*ticket, ticketImage);

    jclass metadataClass = env->FindClass("com/bfh/ticket/Metadata");
    jmethodID constructor = env->GetMethodID(metadataClass, "<init>", "(J)V");
    return env->NewObject(metadataClass, constructor, reinterpret_cast<jlong>(metadata));
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