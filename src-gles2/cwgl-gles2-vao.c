#include "cwgl-gles2-priv.h"

// FIXME: Tentative extension handling
void cwgl_ctx_glGenVertexArray(uintptr_t* id);
void cwgl_ctx_glBindVertexArray(uintptr_t id);

CWGL_API cwgl_VertexArrayObject* 
cwgl_createVertexArray(cwgl_ctx* ctx){
    uintptr_t p;
    GLuint name = 0;
    cwgl_VertexArrayObject* o;
    CTX_ENTER(ctx);
    cwgl_ctx_glGenVertexArray(&p);
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
    cwgl_ctx_glBindVertexArray(name);
    CTX_LEAVE(ctx);
}


