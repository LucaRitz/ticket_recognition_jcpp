#include <com_bfh_ticket_Matcher.h>

#include <include/matcher.hpp>
#include <include/ticket.hpp>
#include <include/ticket_image.hpp>
#include <include/text.hpp>
#include <include/bounding_box.hpp>
#include <include/point.hpp>
#include <string>

using cti::Matcher;
using cti::Ticket;
using cti::TicketImage;
using cti::Text;
using cti::BoundingBox;
using cti::Point;

template <typename T, typename S>
void convert(JNIEnv* env, jobject list, T(*factory)(JNIEnv*, S&), vector<T>& vector) {
    jclass javaListClass = env->FindClass("java/util/List");
    jmethodID sizeMethod = env->GetMethodID(javaListClass, "size", "()I");
    jint size = env->CallIntMethod(list, sizeMethod);
    jmethodID getMethod = env->GetMethodID(javaListClass, "get", "(I)Ljava/lang/Object;");

    for (jint i = 0; i < size; ++i) {
        jobject javaObject = env->CallObjectMethod(list, getMethod, i);
        T converted = factory(env, javaObject);
        vector.push_back(converted);
    }
}

const Text* textFactory(JNIEnv* env, jobject& javaText) {
    jclass javaTextClass = env->FindClass("com/bfh/ticket/Text");

    // Key
    jmethodID nameMethod = env->GetMethodID(javaTextClass, "getKey", "()Ljava/lang/String;");
    auto keyAsJavaString = (jstring) env->CallObjectMethod(javaText, nameMethod);
    string cppKey = env->GetStringUTFChars(keyAsJavaString, nullptr);

    // BoundingBox
    jmethodID boundingBoxMethod = env->GetMethodID(javaTextClass, "getBoundingBox", "()Lcom/bfh/ticket/BoundingBox;");
    jobject javaBoundingBox = env->CallObjectMethod(javaText, boundingBoxMethod);
    jclass javaBoundingBoxClass = env->FindClass("com/bfh/ticket/BoundingBox");

    // Point
    jmethodID pointTopLeftMethod = env->GetMethodID(javaBoundingBoxClass, "getTopLeft", "()Lcom/bfh/ticket/Point;");
    jobject javaTopLeftPoint =  env->CallObjectMethod(javaBoundingBox, pointTopLeftMethod);

    jmethodID pointBottomRightMethod = env->GetMethodID(javaBoundingBoxClass, "getBottomRight", "()Lcom/bfh/ticket/Point;");
    jobject javaBottomRightPoint =  env->CallObjectMethod(javaBoundingBox, pointBottomRightMethod);

    jclass javaPointClass = env->FindClass("com/bfh/ticket/Point");
    jmethodID xMethod = env->GetMethodID(javaPointClass, "getX", "()I");
    jmethodID yMethod = env->GetMethodID(javaPointClass, "getY", "()I");

    // Build CPP Point top left
    jint javaTopLeftX = env->CallIntMethod(javaTopLeftPoint, xMethod);
    jint javaTopLeftY = env->CallIntMethod(javaTopLeftPoint, yMethod);
    int cppTopLeftX = (int) javaTopLeftX;
    int cppTopLeftY = (int) javaTopLeftY;
    auto* cppPointTopLeft = new Point(cppTopLeftX, cppTopLeftY);

    // Build CPP Point bottom right
    jint javaBottomRightX = env->CallIntMethod(javaBottomRightPoint, xMethod);
    jint javaBottomRightY = env->CallIntMethod(javaBottomRightPoint, yMethod);
    int cppBottomRightX = (int) javaBottomRightX;
    int cppBottomRightY = (int) javaBottomRightY;
    auto* cppPointBottomRight = new Point(cppBottomRightX, cppBottomRightY);

    // Build BoundingBox
    auto* cppBoundingBox = new BoundingBox(*cppPointTopLeft, *cppPointBottomRight);

    // Build Text
    auto* cppText = new Text(cppKey, *cppBoundingBox);

    return cppText;
}

const Ticket* ticketFactory(JNIEnv* env, jobject& javaTicket) {
    jclass javaTicketClass = env->FindClass("com/bfh/ticket/Ticket");

    // Name
    jmethodID nameMethod = env->GetMethodID(javaTicketClass, "getName", "()Ljava/lang/String;");
    auto nameAsObject = (jstring) env->CallObjectMethod(javaTicket, nameMethod);
    string cppName = env->GetStringUTFChars(nameAsObject, nullptr);

    // TicketImage
    jmethodID ticketImageMethod = env->GetMethodID(javaTicketClass, "getImage", "()Lcom/bfh/ticket/TicketImage;");
    jobject javaTicketImage = env->CallObjectMethod(javaTicket, ticketImageMethod);
    jclass javaTicketImageClass = env->FindClass("com/bfh/ticket/TicketImage");
    jmethodID pathMethod = env->GetMethodID(javaTicketImageClass, "getImagePath", "()Ljava/lang/String;");
    auto pathAsJavaString = (jstring) env->CallObjectMethod(javaTicketImage, pathMethod);
    string path = env->GetStringUTFChars(pathAsJavaString, nullptr);
    auto* ticketImage = new TicketImage(path);

    // Text
    jmethodID textMethod = env->GetMethodID(javaTicketClass, "getTexts", "()Ljava/util/List;");
    jobject javaTextList = env->CallObjectMethod(javaTicket, textMethod);
    auto* texts = new vector<const Text*>;
    convert(env, javaTextList, textFactory, *texts);

    Ticket* ticket = new Ticket(cppName, *ticketImage, *texts);
    jfieldID pointerField = env->GetFieldID(javaTicketClass, "pointer", "J");
    env->SetLongField(javaTicket, pointerField, reinterpret_cast<jlong>(ticket));
    return ticket;
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
    auto* ticketsToLearn = new vector<const Ticket*>;
    convert(env, jList, ticketFactory, *ticketsToLearn);
    matcher->train(*ticketsToLearn);
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
JNIEXPORT void JNICALL Java_com_bfh_ticket_Matcher_delete(JNIEnv* env, jobject object, jlong pointer) {
    auto* nativePtr = reinterpret_cast<Matcher*>(pointer);
    delete nativePtr;
}