#ifdef CWGL_LEVEL_L2
#include "cwgl-gles2-priv.h"

#include <stdlib.h>

CWGL_API void 
cwgl_TransformFeedback_release(cwgl_ctx* ctx, cwgl_TransformFeedback* tfb){
    if(tfb){
        CTX_FREE(ctx, TransformFeedback, tfb);
    }
}

CWGL_API cwgl_TransformFeedback* 
cwgl_createTransformFeedback(cwgl_ctx* ctx){
    GLuint name = 0;
    cwgl_TransformFeedback* o;
    CTX_ENTER(ctx);
    glGenTransformFeedbacks(1, &name);
    o = CTX_ALLOC(ctx, TransformFeedback);
    CTX_SETNAME(ctx, o, name);
    CTX_LEAVE(ctx);
    return o;
}

CWGL_API void 
cwgl_deleteTransformFeedback(cwgl_ctx* ctx, cwgl_TransformFeedback* tf){
    GLuint name = 0;
    CTX_ENTER(ctx);
    if(tf){
        name = CTX_GETNAME(ctx, tf);
        glDeleteTransformFeedbacks(1, &name);
    }
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_bindTransformFeedback(cwgl_ctx* ctx, cwgl_enum target, 
                           cwgl_TransformFeedback* tf){
    GLuint name = 0;
    CTX_ENTER(ctx);
    if(tf){
        name = CTX_GETNAME(ctx, tf);
    }else{
        name = 0; /* Default object */
    }
    glBindTransformFeedback(target, name);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_beginTransformFeedback(cwgl_ctx* ctx, cwgl_enum primitivemode){
    CTX_ENTER(ctx);
    glBeginTransformFeedback(primitivemode);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_endTransformFeedback(cwgl_ctx* ctx){
    CTX_ENTER(ctx);
    glEndTransformFeedback();
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_transformFeedbackVaryings(cwgl_ctx* ctx, cwgl_Program* program, 
                               cwgl_string** varyings, size_t varyingcount, 
                               cwgl_enum buffermode){
    abort();
}

CWGL_API void 
cwgl_getTransformFeedbackVarying(cwgl_ctx* ctx, cwgl_Program* program, 
                                 uint32_t index){
    abort();
}

CWGL_API void 
cwgl_pauseTransformFeedback(cwgl_ctx* ctx){
    CTX_ENTER(ctx);
    glPauseTransformFeedback();
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_resumeTransformFeedback(cwgl_ctx* ctx){
    CTX_ENTER(ctx);
    glResumeTransformFeedback();
    CTX_LEAVE(ctx);
}
#endif
