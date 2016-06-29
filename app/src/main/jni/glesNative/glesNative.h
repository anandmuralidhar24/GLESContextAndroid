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

#ifndef GLESCONTEXTANDROID_GLES_CONTEXT_H
#define GLESCONTEXTANDROID_GLES_CONTEXT_H


#include "myLogger.h"
#include <sstream>
#include <iostream>
#include <GLES2/gl2.h>
#include "gl3stub.h"
#include <stdio.h>
#include <string>

class GLESNative {
public:
    GLESNative();
    void    PerformGLInits();
    void    Render();
    void    SetViewport(int width, int height);
    bool    IsInitsDone(){return initsDone;}
    std::string GetGLESVersionInfo() {return glesVersionInfo;}

private:
    bool    initsDone;
    std::string glesVersionInfo;
};

#endif //GLESCONTEXTANDROID_GLES_CONTEXT_H
