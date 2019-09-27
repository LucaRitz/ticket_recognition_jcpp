#include <com_bfh_ticket_Matcher.h>

#include <include/matcher.hpp>
#include <include/ticket.hpp>

using cti::Matcher;
using cti::Ticket;

template <typename T, typename S>
vector<T> convert(JNIEnv* env, jobject list, T(*factory)(JNIEnv*, S&)) {
    jclass javaListClass = env->FindClass("java/util/List");
    jmethodID sizeMethod = env->GetMethodID(javaListClass, "size", "()I");
    int size = env->CallIntMethod(list, sizeMethod);
    jmethodID getMethod = env->GetMethodID(javaListClass, "get", "(I)Lcom/bfh/ticket/Ticket");

    vector<T> vector;
    for (int i = 0; i < size; ++i) {
        jobject javaTicket = env->CallObjectMethod(list, getMethod, i);
        T converted = factory(env, javaTicket);
        vector.push_back(converted);
    }

    return vector;
}

const Ticket* ticketFactory(JNIEnv* env, jobject& javaTicket) {
    jclass javaTicketClass = env->FindClass("com/bfh/ticket/Ticket");

    jmethodID sizeMethod = env->GetMethodID(javaTicketClass, "getName", "()Ljava/lang/String");
    auto nameAsObject = (jstring) env->CallObjectMethod(javaTicket, sizeMethod);
    string cppName = env->GetStringUTFChars(nameAsObject, nullptr);


    return nullptr;
}

/*
 * Class:     com_bfh_ticket_Matcher
 * Method:    train
 * Signature: (JLcom/bfh/ticket/Ticket;)V
 */
JNIEXPORT void JNICALL Java_com_bfh_ticket_Matcher_train__JLcom_bfh_ticket_Ticket_2
(JNIEnv * env, jobject object, jlong pointer, jobject jTicket) {
    auto* matcher = reinterpret_cast<Matcher*>(pointer);
    matcher->train(*ticketFactory(env, jTicket));
}

/*
 * Class:     com_bfh_ticket_Matcher
 * Method:    train
 * Signature: (JLjava/util/List;)V
 */
JNIEXPORT void JNICALL Java_com_bfh_ticket_Matcher_train__JLjava_util_List_2
(JNIEnv* env, jobject object, jlong pointer, jobject jList) {
    auto* matcher = reinterpret_cast<Matcher*>(pointer);
    vector<const Ticket*> ticketsToLearn = convert(env, jList, ticketFactory);
    matcher->train(ticketsToLearn);
}

/*
 * Class:     com_bfh_ticket_Matcher
 * Method:    match
 * Signature: (JLcom/bfh/ticket/TicketImage;)Ljava/util/Optional;
 */
JNIEXPORT jobject JNICALL Java_com_bfh_ticket_Matcher_match
        (JNIEnv *, jobject, jlong, jobject);

/*
 * Class:     com_bfh_ticket_Matcher
 * Method:    delete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_bfh_ticket_Matcher_delete
(JNIEnv *, jobject, jlong);