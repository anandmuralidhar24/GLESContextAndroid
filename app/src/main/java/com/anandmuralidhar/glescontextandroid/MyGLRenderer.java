package com.anandmuralidhar.glescontextandroid;

import android.opengl.GLSurfaceView;
import android.util.Log;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * Created by anand on 10/6/16.
 */


class MyGLRenderer implements GLSurfaceView.Renderer {

    private native void drawFrameNative();
    private native void surfaceCreatedNative();
    private native void surfaceChangedNative(int width, int height);


    public void onSurfaceCreated(GL10 gl, EGLConfig config) {

        // called when the surface is created or recreated
        // create (or recreate) native objects that are required for rendering
        Log.d("GLES", "onSurfaceCreated");
        surfaceCreatedNative();

    }

    public void onDrawFrame(GL10 unused) {

        // called to draw the current frame
        // call the rendering functions in native
        drawFrameNative();

    }

    public void onSurfaceChanged(GL10 unused, int width, int height) {

        // called after surface is created and GLES surface changes size
        // this can typically happen if device orientation changes
        // we need to set GLES viewport to handle the change in size
        Log.d("GLES", "onSurfaceChanged");
        surfaceChangedNative(width, height);

    }

}