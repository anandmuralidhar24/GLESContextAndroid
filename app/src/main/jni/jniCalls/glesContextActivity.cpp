/*
 *    Copyright 2016 Anand Muralidhar
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include <jni.h>
#include "glesNative.h"

#ifdef __cplusplus
extern "C" {
#endif

GLESNative *gGlesObject;

JNIEXPORT void JNICALL
Java_com_anandmuralidhar_glescontextandroid_GLESContextActivity_CreateObjectNative(JNIEnv *env,
                                                                                   jobject instance) {
    gGlesObject = new GLESNative();

}

JNIEXPORT void JNICALL
Java_com_anandmuralidhar_glescontextandroid_GLESContextActivity_DeleteObjectNative(JNIEnv *env,
                                                                                   jobject instance) {
    if (gGlesObject != NULL) {
        delete gGlesObject;
    }
    gGlesObject = NULL;
}

JNIEXPORT jboolean JNICALL
Java_com_anandmuralidhar_glescontextandroid_GLESContextActivity_IsInitsDoneNative(JNIEnv *env,
                                                                                  jobject instance) {

    if (gGlesObject == NULL || !gGlesObject->IsInitsDone()) {
        return JNI_FALSE;
    } else {
        return JNI_TRUE;
    }

}


JNIEXPORT jstring JNICALL
Java_com_anandmuralidhar_glescontextandroid_GLESContextActivity_GetGLESVersionNative(JNIEnv *env,
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
