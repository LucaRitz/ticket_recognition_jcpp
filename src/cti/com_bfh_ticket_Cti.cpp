#include <com_bfh_ticket_Cti.h>
#include <cti.hpp>

JNIEXPORT void JNICALL Java_com_bfh_ticket_Cti_hello (JNIEnv* env, jobject obj, jstring path) {
    cti::Cti cti;
    char* nativePath = const_cast<char*>(env->GetStringUTFChars(path, nullptr));
    cti.hello(nativePath);
}

JNIEXPORT jstring JNICALL Java_com_bfh_ticket_Cti_helloWorld (JNIEnv* env, jobject obj) {
    cti::Cti cti;
    return env->NewStringUTF(cti.helloWorld().c_str());
}