//
// Created by anand on 11/6/16.
//

#ifndef GLESNATIVEANDROID_My_LOGGER_H
#define GLESNATIVEANDROID_My_LOGGER_H

#include <android/log.h>

#define LOG_TAG "GLESContextAndroid"
#define  MyLOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define  MyLOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define  MyLOGV(...)  __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG,__VA_ARGS__)
#define  MyLOGI(...)  __android_log_print(ANDROID_LOG_INFO   , LOG_TAG,__VA_ARGS__)
#define  MyLOGW(...)  __android_log_print(ANDROID_LOG_WARN   , LOG_TAG,__VA_ARGS__)
#define  MyLOGF(...)  __android_log_print(ANDROID_LOG_FATAL   , LOG_TAG,__VA_ARGS__)
#define  MyLOGSIMPLE(...)

#endif //GLESNATIVEANDROID_My_LOGGER_H
