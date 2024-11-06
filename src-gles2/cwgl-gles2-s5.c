#include "cwgl-gles2-priv.h"

// 5.1 Flush and Finish
CWGL_API void 
cwgl_finish(cwgl_ctx* ctx){
    CTX_ENTER(ctx);
    glFinish();
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_flush(cwgl_ctx* ctx){
    CTX_ENTER(ctx);
    glFlush();
    CTX_LEAVE(ctx);
}

// 5.2 Hints
CWGL_API void 
cwgl_hint(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum mode){
    CTX_ENTER(ctx);
    glHint(target, mode);
    CTX_LEAVE(ctx);
}


