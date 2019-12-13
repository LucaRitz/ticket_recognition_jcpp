#include <jni.h>
/* Header for class com_bfh_ticket_Matcher */

#ifndef _Included_com_bfh_ticket_Matcher
#define _Included_com_bfh_ticket_Matcher
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_bfh_ticket_Matcher
 * Method:    initialize
 * Signature: (Lcom/bfh/ticket/Algorithm;Lcom/bfh/ticket/MatcherOptions;)J
 */
JNIEXPORT jlong JNICALL Java_com_bfh_ticket_Matcher_initialize
  (JNIEnv *, jobject, jobject, jobject);

/*
 * Class:     com_bfh_ticket_Matcher
 * Method:    train
 * Signature: (JLcom/bfh/ticket/Ticket;)V
 */
JNIEXPORT void JNICALL Java_com_bfh_ticket_Matcher_train__JLcom_bfh_ticket_Ticket_2
  (JNIEnv *, jobject, jlong, jobject);

/*
 * Class:     com_bfh_ticket_Matcher
 * Method:    train
 * Signature: (JLjava/util/List;)V
 */
JNIEXPORT void JNICALL Java_com_bfh_ticket_Matcher_train__JLjava_util_List_2
  (JNIEnv *, jobject, jlong, jobject);

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

#ifdef __cplusplus
}
#endif
#endif
