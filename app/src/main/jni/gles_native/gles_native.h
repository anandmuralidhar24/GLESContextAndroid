//
// Created by anand on 17/6/16.
//

#ifndef GLESCONTEXTANDROID_GLES_CONTEXT_H
#define GLESCONTEXTANDROID_GLES_CONTEXT_H

#include "my_logger.h"
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
