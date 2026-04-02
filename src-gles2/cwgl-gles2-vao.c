#include "cwgl-gles2-priv.h"

// FIXME: Tentative extension handling
// FIXME: Remove _2 when we adopt change on Yuniframe
void cwgl_ctx_glGenVertexArray_2(cwgl_ctx* ctx, uintptr_t* id);
void cwgl_ctx_glBindVertexArray_2(cwgl_ctx* ctx, uintptr_t id);

CWGL_API cwgl_VertexArrayObject* 
cwgl_createVertexArray(cwgl_ctx* ctx){
    uintptr_t p;
    GLuint name = 0;
    cwgl_VertexArrayObject* o;
    CTX_ENTER(ctx);
    cwgl_ctx_glGenVertexArray_2(ctx, &p);
    name = p;
    o = CTX_ALLOC(ctx, VertexArrayObject);
    CTX_SETNAME(ctx, o, name);
    CTX_LEAVE(ctx);
    return o;
}


CWGL_API void 
cwgl_bindVertexArray(cwgl_ctx* ctx, cwgl_VertexArrayObject* obj){
    GLuint name;
    CTX_ENTER(ctx);
    if(obj){
        name = CTX_GETNAME(ctx, obj);
    }else{
        name = 0;
    }
    cwgl_ctx_glBindVertexArray_2(ctx, name);
    CTX_LEAVE(ctx);
}


