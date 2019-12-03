#include <com_bfh_ticket_TicketMatch.h>

#include <include/ticket.hpp>
#include <include/ticket_image.hpp>
#include <include/text.hpp>
#include <include/bounding_box.hpp>
#include <include/point.hpp>

using cti::Ticket;
using cti::TicketImage;
using cti::Text;
using cti::BoundingBox;
using cti::Point;

const jobject ticketFactory(JNIEnv* env, const Ticket& ticket) {
    jclass javaTicketClass = env->FindClass("com/bfh/ticket/Ticket");
    jmethodID javaTicketConstructor = env->GetMethodID(javaTicketClass, "<init>",
                                                       "(Ljava/lang/String;Lcom/bfh/ticket/TicketImage;Ljava/util/List;)V");

    // Name
    jstring javaName = env->NewStringUTF(ticket.name().c_str());

    // TicketImage
    jclass javaTicketImageClass = env->FindClass("com/bfh/ticket/TicketImage");
    jmethodID javaTicketImageConstructor = env->GetMethodID(javaTicketImageClass, "<init>", "(Ljava/lang/String;)V");
    jobject ticketImage = env->NewObject(javaTicketImageClass, javaTicketImageConstructor,
                                         env->NewStringUTF(""));

    // Texts
    jclass javaListClass = env->FindClass("java/util/ArrayList");
    jmethodID javaListConstructor = env->GetMethodID(javaListClass, "<init>", "()V");
    jmethodID javaListAdd = env->GetMethodID(javaListClass, "add", "(Ljava/lang/Object;)Z");
    jobject javaList = env->NewObject(javaListClass, javaListConstructor);

    jclass javaTextClass = env->FindClass("com/bfh/ticket/Text");
    jmethodID javaTextConstructor = env->GetMethodID(javaTextClass, "<init>",
                                                     "(Ljava/lang/String;Lcom/bfh/ticket/BoundingBox;)V");
    jclass javaBoundingBoxClass = env->FindClass("com/bfh/ticket/BoundingBox");
    jmethodID javaBoundingBoxConstructor = env->GetMethodID(javaBoundingBoxClass, "<init>", "(Lcom/bfh/ticket/Point;Lcom/bfh/ticket/Point;)V");
    jclass javaPointClass = env->FindClass("com/bfh/ticket/Point");
    jmethodID javaPointConstructor = env->GetMethodID(javaPointClass, "<init>", "(II)V");

    for (auto* text : ticket.texts()) {
        jobject pointTopLeft = env->NewObject(javaPointClass, javaPointConstructor,
                                              static_cast<jint>(text->boundingBox().topLeft().x()),
                                              static_cast<jint>(text->boundingBox().topLeft().y()));
        jobject pointBottomRight = env->NewObject(javaPointClass, javaPointConstructor, text->boundingBox().bottomRight().x(),
                                              text->boundingBox().bottomRight().y());
        jobject boundingBox = env->NewObject(javaBoundingBoxClass, javaBoundingBoxConstructor, pointTopLeft,
                                             pointBottomRight);
        jstring javaTextKey = env->NewStringUTF(text->key().c_str());
        jobject javaText = env->NewObject(javaTextClass, javaTextConstructor, javaTextKey, boundingBox);
        env->CallBooleanMethod(javaList, javaListAdd, javaText);
    }

    jobject javaTicket = env->NewObject(javaTicketClass, javaTicketConstructor, javaName, ticketImage, javaList);
    jfieldID pointerField = env->GetFieldID(javaTicketClass, "pointer", "J");
    env->SetLongField(javaTicket, pointerField, reinterpret_cast<jlong>(&ticket));
    return javaTicket;
}

/*
 * Class:     com_bfh_ticket_TicketMatch
 * Method:    getTicket
 * Signature: (J)Lcom/bfh/ticket/Ticket;
 */
JNIEXPORT jobject JNICALL Java_com_bfh_ticket_TicketMatch_getTicket
        (JNIEnv* env, jobject obj, jlong ticketPointer) {
    auto* ticket = reinterpret_cast<Ticket*>(ticketPointer);
    return ticketFactory(env, *ticket);
}