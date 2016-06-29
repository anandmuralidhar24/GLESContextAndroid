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

package com.anandmuralidhar.glescontextandroid;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.AsyncTask;
import android.os.Bundle;
import android.widget.TextView;

public class GLESContextActivity extends Activity {
    private GLSurfaceView mGLView = null;
    private TextView mTextView = null;
    private native void CreateObjectNative();
    private native void DeleteObjectNative();
    private native String GetGLESVersionNative();
    private native boolean IsInitsDoneNative();

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // call the native constructors to create an object
        CreateObjectNative();

        // layout has only two components, a GLSurfaceView and a TextView
        setContentView(R.layout.gl_context);
        mGLView = (MyGLSurfaceView) findViewById (R.id.gl_surface_view);
        mTextView = (TextView) findViewById(R.id.gles_version_textbox);
    }

    @Override
    protected void onResume() {

        super.onResume();

        // Android suggests that we call onResume on GLSurfaceView
        if (mGLView != null) {
            mGLView.onResume();
        }

        new AsyncDisplayText().execute();
    }

    @Override
    protected void onPause() {

        super.onPause();

        // Android suggests that we call onPause on GLSurfaceView
        if(mGLView != null) {
            mGLView.onPause();
        }
    }

    @Override
    protected void onDestroy() {

        super.onDestroy();

        // We are exiting the activity, let's delete the native objects
        DeleteObjectNative();

    }


    // this task simply waits till all inits are completed in native code
    // then it displays the GLES version on the screen
    class AsyncDisplayText extends AsyncTask<Void, String, Integer> {

        @Override
        // this function executes on a background thread
        // hence we cannot make GL calls or manipulate UI elements here
        protected Integer doInBackground(Void... params) {

            // keep polling to check if native objects are initialized
            while(!IsInitsDoneNative()) {
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
            return 0;
        }

        @Override
        // this function executes on the UI thread and we can modify UI elements
        protected void onPostExecute(Integer result) {

            // GLES version is displayed on the screen
            DisplayGLVersion(GetGLESVersionNative());

        }
    }

    void DisplayGLVersion(String GLVersionInfo) {
        if(mTextView != null) {
            mTextView.setText(GLVersionInfo);
        }
    }

    // load libGLESNative.so since it has all the native functions
    static {
        System.loadLibrary("GLESNative");
    }
}

