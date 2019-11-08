#include <com_bfh_ticket_Metadata.h>
#include <include/metadata.hpp>

using cti::Metadata;

/*
 * Class:     com_bfh_ticket_Metadata
 * Method:    getTexts
 * Signature: (J)Ljava/util/Map;
 */
JNIEXPORT jobject JNICALL Java_com_bfh_ticket_Metadata_getTexts
        (JNIEnv* env, jobject obj, jlong pointer) {
    auto* nativePtr = reinterpret_cast<Metadata*>(pointer);

    jclass mapClass = env->FindClass("java/util/HashMap");
    jmethodID constructor = env->GetMethodID(mapClass, "<init>", "()V");
    jobject map = env->NewObject(mapClass, constructor);

    jmethodID putMethod = env->GetMethodID(mapClass, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");

    for (auto const& value : nativePtr->texts()) {
        env->CallObjectMethod(map, putMethod, env->NewStringUTF(value.first.c_str()), env->NewStringUTF(value.second.c_str()));
    }
    return map;
}

/*
 * Class:     com_bfh_ticket_Metadata
 * Method:    delete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_bfh_ticket_Metadata_delete
        (JNIEnv* env, jobject obj, jlong pointer) {
    auto* nativePtr = reinterpret_cast<Metadata*>(pointer);
    delete nativePtr;
}