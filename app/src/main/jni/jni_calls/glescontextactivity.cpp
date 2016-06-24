//
// Created by anand on 17/6/16.
//

#include <jni.h>
#include "gles_native.h"

#ifdef __cplusplus
extern "C" {
#endif

GLESNative *gGlesObject;

JNIEXPORT void JNICALL
Java_com_anandmuralidhar_glescontextandroid_GLESContextActivity_createObjectNative(JNIEnv *env,
                                                                                   jobject instance) {
    gGlesObject = new GLESNative();

}

JNIEXPORT void JNICALL
Java_com_anandmuralidhar_glescontextandroid_GLESContextActivity_deleteObjectNative(JNIEnv *env,
                                                                                   jobject instance) {
    if (gGlesObject != NULL) {
        delete gGlesObject;
    }
    gGlesObject = NULL;
}

JNIEXPORT jboolean JNICALL
Java_com_anandmuralidhar_glescontextandroid_GLESContextActivity_isInitsDoneNative(JNIEnv *env,
                                                                                  jobject instance) {

    if (gGlesObject == NULL || !gGlesObject->IsInitsDone()) {
        return JNI_FALSE;
    } else {
        return JNI_TRUE;
    }

}


JNIEXPORT jstring JNICALL
Java_com_anandmuralidhar_glescontextandroid_GLESContextActivity_getGLESVersionNative(JNIEnv *env,
                                                                                     jobject instance) {

    std::string retValue = "";
    if (gGlesObject == NULL) {
        return env->NewStringUTF(retValue.c_str());
    }
    retValue = gGlesObject->GetGLESVersionInfo();
    return env->NewStringUTF(retValue.c_str());
}

#ifdef __cplusplus
}
#endif
