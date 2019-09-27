#include <com_bfh_ticket_TicketMatch.h>
#include <include/ticket_match.hpp>

using cti::TicketMatch;

JNIEXPORT jstring JNICALL Java_com_bfh_ticket_TicketMatch_getName
        (JNIEnv * env, jobject object, jlong pointer) {
    auto* nativePtr = reinterpret_cast<TicketMatch*>(pointer);
    return env->NewStringUTF(nativePtr->name().c_str());
}

JNIEXPORT void JNICALL Java_com_bfh_ticket_TicketMatch_delete
        (JNIEnv * env, jobject object, jlong pointer) {
    auto* nativePtr = reinterpret_cast<TicketMatch*>(pointer);
    delete nativePtr;
}