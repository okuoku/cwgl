#include "cwgl-gles2-priv.h"

/* OpenGL State */
CWGL_API void 
cwgl_disable(cwgl_ctx* ctx, cwgl_enum cap){
    CTX_ENTER(ctx);
    glDisable(cap);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_enable(cwgl_ctx* ctx, cwgl_enum cap){
    CTX_ENTER(ctx);
    glEnable(cap);
    CTX_LEAVE(ctx);
}

