#include "cwgl-backend-gles2-priv.h"

int 
cwgl_backend_finish(cwgl_ctx* ctx){
    glFinish();
    return 0;
}

int 
cwgl_backend_flush(cwgl_ctx* ctx){
    glFlush();
    return 0;
}


