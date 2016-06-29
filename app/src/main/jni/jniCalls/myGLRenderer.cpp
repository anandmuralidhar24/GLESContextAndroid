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

extern GLESNative *gGlesObject;

JNIEXPORT void JNICALL
Java_com_anandmuralidhar_glescontextandroid_MyGLRenderer_DrawFrameNative(JNIEnv *env,
                                                                         jobject instance) {

    if (gGlesObject == NULL) {
        return;
    }
    gGlesObject->Render();

}

JNIEXPORT void JNICALL
Java_com_anandmuralidhar_glescontextandroid_MyGLRenderer_SurfaceCreatedNative(JNIEnv *env,
                                                                              jobject instance) {

    if (gGlesObject == NULL) {
        return;
    }
    gGlesObject->PerformGLInits();

}

JNIEXPORT void JNICALL
Java_com_anandmuralidhar_glescontextandroid_MyGLRenderer_SurfaceChangedNative(JNIEnv *env,
                                                                              jobject instance,
                                                                              jint width,
                                                                              jint height) {

    if (gGlesObject == NULL) {
        return;
    }
    gGlesObject->SetViewport(width, height);

}

#ifdef __cplusplus
}
#endif

