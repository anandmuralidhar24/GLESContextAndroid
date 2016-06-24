#include <jni.h>
#include "gles_native.h"


#ifdef __cplusplus
extern "C" {
#endif

extern GLESNative *gGlesObject;

JNIEXPORT void JNICALL
Java_com_anandmuralidhar_glescontextandroid_MyGLRenderer_drawFrameNative(JNIEnv *env,
                                                                         jobject instance) {

    if (gGlesObject == NULL) {
        return;
    }
    gGlesObject->Render();

}

JNIEXPORT void JNICALL
Java_com_anandmuralidhar_glescontextandroid_MyGLRenderer_surfaceCreatedNative(JNIEnv *env,
                                                                              jobject instance) {

    if (gGlesObject == NULL) {
        return;
    }
    gGlesObject->PerformGLInits();

}

JNIEXPORT void JNICALL
Java_com_anandmuralidhar_glescontextandroid_MyGLRenderer_surfaceChangedNative(JNIEnv *env,
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

