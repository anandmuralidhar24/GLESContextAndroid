# GLESContextAndroid
This project sets up GLES context in Android, creates a native object, and render to the display from the native code with NDK. The rendering call will simply change the screen color to blue. The native code reads the OpenGL ES and GLSL versions that is later displayed on the screen using Java. We also use an AsyncTask to communicate across the GL and UI threads in Android.

A tutorial describing this project is available at:
http://www.anandmuralidhar.com/blog/android/gles-context/
