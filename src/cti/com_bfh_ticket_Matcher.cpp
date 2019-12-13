#include <com_bfh_ticket_Matcher.h>

#include <include/matcher.hpp>
#include <include/ticket.hpp>
#include <include/ticket_image.hpp>
#include <include/text.hpp>
#include <include/bounding_box.hpp>
#include <include/point.hpp>
#include <include/ticket_match.hpp>
#include <include/matching/matching_algorithms.hpp>
#include <include/matching/matching_algorithm.hpp>
#include <include/matching/matching_options.hpp>
#include <include/exception/cti_exception.hpp>
#include <string.h>

#include "helper.hpp"

using cti::Matcher;
using cti::Ticket;
using cti::TicketImage;
using cti::Text;
using cti::BoundingBox;
using cti::Point;
using cti::TicketMatch;
using cti::CtiException;
using cti::MatchingAlgorithms;
using cti::MatchingAlgorithm;
using cti::MatchingOptions;
using cti::java::getAlgorithmName;

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
    const Point cppPointTopLeft(cppTopLeftX, cppTopLeftY);

    // Build CPP Point bottom right
    jint javaBottomRightX = env->CallIntMethod(javaBottomRightPoint, xMethod);
    jint javaBottomRightY = env->CallIntMethod(javaBottomRightPoint, yMethod);
    int cppBottomRightX = (int) javaBottomRightX;
    int cppBottomRightY = (int) javaBottomRightY;
    const Point cppPointBottomRight(cppBottomRightX, cppBottomRightY);

    // Build BoundingBox
    auto* cppBoundingBox = new BoundingBox(cppPointTopLeft, cppPointBottomRight);

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

    jfieldID pathField = env->GetFieldID(javaTicketImageClass, "imagePath", "Ljava/lang/String;");
    auto pathAsJavaString = (jstring) env->GetObjectField(javaTicketImage, pathField);
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

void throwCtiException(JNIEnv* env, const char* message) {
    jclass javaCtiExceptionClass = env->FindClass("com/bfh/ticket/exception/CtiException");
    env->ThrowNew(javaCtiExceptionClass, message);
}

const MatchingOptions readMatcherOptions(JNIEnv* env, jobject& javaOptions) {
    jclass javaMatcherOptionsClass = env->FindClass("com/bfh/ticket/MatcherOptions");
    jmethodID javaGetRatioTestThreshold = env->GetMethodID(javaMatcherOptionsClass, "getRatioTestThreshold", "()D");
    jmethodID javaGetScoreTestThreshold = env->GetMethodID(javaMatcherOptionsClass, "getScoreTestThreshold", "()D");
    jmethodID javaGetScoreThreshold = env->GetMethodID(javaMatcherOptionsClass, "getScoreThreshold", "()D");

    jdouble javaRatioTestThreshold = env->CallDoubleMethod(javaOptions, javaGetRatioTestThreshold);
    jdouble javaScoreTestThreshold = env->CallDoubleMethod(javaOptions, javaGetScoreTestThreshold);
    jdouble javaScoreThreshold = env->CallDoubleMethod(javaOptions, javaGetScoreThreshold);

    auto ratioTestThreshold = static_cast<double>(javaRatioTestThreshold);
    auto scoreTestThreshold = static_cast<double>(javaScoreTestThreshold);
    auto scoreThreshold = static_cast<double>(javaScoreThreshold);

    return MatchingOptions(ratioTestThreshold >= 0 ? ratioTestThreshold : 0.7,
                           scoreTestThreshold >= 0 ? scoreTestThreshold : 0.5,
                           scoreThreshold >= 0 ? scoreThreshold : 25.0);
}

/*
 * Class:     com_bfh_ticket_Matcher
 * Method:    initialize
 * Signature: (Lcom/bfh/ticket/Algorithm;Lcom/bfh/ticket/MatcherOptions;)J
 */
JNIEXPORT jlong JNICALL Java_com_bfh_ticket_Matcher_initialize
        (JNIEnv* env, jobject object, jobject javaAlgorithm, jobject javaOptions) {
    const char* nativeAlgorithmString = getAlgorithmName(env, javaAlgorithm);

    const MatchingOptions options = readMatcherOptions(env, javaOptions);
    MatchingAlgorithm* matchingAlgorithm = nullptr;
    if (strcmp("SIFT", nativeAlgorithmString) == 0) {
        matchingAlgorithm = MatchingAlgorithms::sift(options).release();
    } else if (strcmp("ORB", nativeAlgorithmString) == 0) {
        matchingAlgorithm = MatchingAlgorithms::orb(options).release();
    }

    if (matchingAlgorithm != nullptr) {
        auto* matcher = new Matcher(*matchingAlgorithm);
        return (jlong) matcher;
    }

    return jlong(-1);
}

/*
 * Class:     com_bfh_ticket_Matcher
 * Method:    train
 * Signature: (JLcom/bfh/ticket/Ticket;)V
 */
JNIEXPORT void JNICALL Java_com_bfh_ticket_Matcher_train__JLcom_bfh_ticket_Ticket_2
(JNIEnv * env, jobject object, jlong pointer, jobject jTicket) {
    auto* matcher = reinterpret_cast<Matcher*>(pointer);
    try {
        matcher->train(*ticketFactory(env, jTicket));
    } catch(CtiException& exc) {
        throwCtiException(env, exc.what());
    }
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
    try {
        convert(env, jList, ticketFactory, *ticketsToLearn);
        matcher->train(*ticketsToLearn);
    } catch(CtiException& exc) {
        throwCtiException(env, exc.what());
    }
}

/*
 * Class:     com_bfh_ticket_Matcher
 * Method:    untrain
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_bfh_ticket_Matcher_untrain
        (JNIEnv* env, jobject object, jlong pointer, jlong ticketPointer) {
    auto* matcher = reinterpret_cast<Matcher*>(pointer);
    auto* ticket = reinterpret_cast<Ticket*>(ticketPointer);
    matcher->untrain(*ticket);
}

jobject createOptionalFrom(JNIEnv* env, jobject* value) {
    jclass javaOptionalClass = env->FindClass("java/util/Optional");

    if (value) {
        jmethodID ofMethod = env->GetStaticMethodID(javaOptionalClass, "of", "(Ljava/lang/Object;)Ljava/util/Optional;");
        return env->CallStaticObjectMethod(javaOptionalClass, ofMethod, *value);
    } else {
        jmethodID emptyMethod = env->GetStaticMethodID(javaOptionalClass, "empty", "()Ljava/util/Optional;");
        return env->CallStaticObjectMethod(javaOptionalClass, emptyMethod);
    }
}

/*
 * Class:     com_bfh_ticket_Matcher
 * Method:    match
 * Signature: (JLcom/bfh/ticket/TicketImage;)Ljava/util/Optional;
 */
JNIEXPORT jobject JNICALL Java_com_bfh_ticket_Matcher_match
        (JNIEnv* env, jobject obj, jlong pointer, jobject javaTicketImage) {
    jclass javaTicketImageClass = env->FindClass("com/bfh/ticket/TicketImage");

    // Create Ticket image
    jfieldID pathField = env->GetFieldID(javaTicketImageClass, "imagePath", "Ljava/lang/String;");
    auto imagePathAsJavaString = (jstring) env->GetObjectField(javaTicketImage, pathField);
    string imagePath = env->GetStringUTFChars(imagePathAsJavaString, nullptr);
    const TicketImage ticketImage(imagePath);

    // Do matching
    auto* matcher = reinterpret_cast<Matcher*>(pointer);
    std::optional<const TicketMatch> optional = matcher->match(ticketImage);

    // Create TicketMatch
    if (optional) {
        jclass javaTicketMatchClass = env->FindClass("com/bfh/ticket/TicketMatch");
        jmethodID constructor = env->GetMethodID(javaTicketMatchClass, "<init>", "(J)V");
        jobject javaTicketMatch = env->NewObject(javaTicketMatchClass, constructor,
                                                 reinterpret_cast<jlong>(&optional.value().ticket()));
        return createOptionalFrom(env, &javaTicketMatch);
    } else {
        return createOptionalFrom(env, nullptr);
    }
}

/*
 * Class:     com_bfh_ticket_Matcher
 * Method:    delete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_bfh_ticket_Matcher_delete(JNIEnv* env, jobject object, jlong pointer) {
    auto* nativePtr = reinterpret_cast<Matcher*>(pointer);
    delete nativePtr;
}