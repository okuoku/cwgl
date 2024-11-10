#include <string.h>
#include "cwgl-gles2-priv.h"
#include <stdlib.h>

// 6.1.1 Simple Queries
CWGL_API cwgl_query_result
cwgl_getParameter_b1(cwgl_ctx* ctx, cwgl_enum pname, int32_t* x){
    GLboolean b4[4] = { 0 };
    cwgl_query_result r;
    CTX_ENTER(ctx);
    glGetBooleanv(pname, b4);
    *x = b4[0];
    r = CWGL_QR_SUCCESS;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getParameter_b4(cwgl_ctx* ctx, cwgl_enum pname, 
                     int32_t* x, int32_t* y, int32_t* z, int32_t* w){
    GLboolean b4[4] = { 0 };
    cwgl_query_result r;
    CTX_ENTER(ctx);
    glGetBooleanv(pname, b4);
    *x = b4[0];
    *y = b4[1];
    *z = b4[2];
    *w = b4[3];
    r = CWGL_QR_SUCCESS;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result
cwgl_getParameter_i1(cwgl_ctx* ctx, cwgl_enum pname, int32_t* x){
    GLint i4[4] = { 0 };
    cwgl_query_result r;
    CTX_ENTER(ctx);
    glGetIntegerv(pname, i4);
    *x = i4[0];
    r = CWGL_QR_SUCCESS;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getParameter_i2(cwgl_ctx* ctx, cwgl_enum pname, 
                     int32_t* x, int32_t* y){
    GLint i4[4] = { 0 };
    cwgl_query_result r;
    CTX_ENTER(ctx);
    glGetIntegerv(pname, i4);
    *x = i4[0];
    *y = i4[1];
    r = CWGL_QR_SUCCESS;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getParameter_i4(cwgl_ctx* ctx, cwgl_enum pname, 
                     int32_t* x, int32_t* y, int32_t* z, int32_t* w){
    GLint i4[4] = { 0 };
    cwgl_query_result r;
    CTX_ENTER(ctx);
    glGetIntegerv(pname, i4);
    *x = i4[0];
    *y = i4[1];
    *z = i4[2];
    *w = i4[3];
    r = CWGL_QR_SUCCESS;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getParameter_f1(cwgl_ctx* ctx, cwgl_enum pname, float* x){
    cwgl_query_result r;
    float f4[4] = {0.0,0.0,0.0,0.0};
    CTX_ENTER(ctx);
    glGetFloatv(pname, f4);
    *x = f4[0];
    r = CWGL_QR_SUCCESS;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result
cwgl_getParameter_f2(cwgl_ctx* ctx, cwgl_enum pname, float* x, float* y){
    cwgl_query_result r;
    float f4[4] = {0.0,0.0,0.0,0.0};
    CTX_ENTER(ctx);
    glGetFloatv(pname, f4);
    *x = f4[0];
    *y = f4[1];
    r = CWGL_QR_SUCCESS;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getParameter_f4(cwgl_ctx* ctx, cwgl_enum pname, 
                     float* x, float* y, float* z, float* w){
    cwgl_query_result r;
    float f4[4] = {0.0,0.0,0.0,0.0};
    CTX_ENTER(ctx);
    glGetFloatv(pname, f4);
    *x = f4[0];
    *y = f4[1];
    *z = f4[2];
    *w = f4[3];
    r = CWGL_QR_SUCCESS;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getParameter_str(cwgl_ctx* ctx, cwgl_enum pname, cwgl_string** str){
    const char* res;
    size_t xlen;
    cwgl_string* out;
    cwgl_query_result r;
    CTX_ENTER(ctx);
    res = glGetString(pname);
    if(!res){
        r = CWGL_QR_GLERROR;
    }else{
        xlen = strlen(res);
        out = cwgl_priv_alloc_string(ctx, res, xlen + 1);
        *str = out;
        r = CWGL_QR_SUCCESS;
    }
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getParameter_Buffer(cwgl_ctx* ctx, cwgl_enum pname, 
                         cwgl_Buffer** buffer){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getParameter_Program(cwgl_ctx* ctx, cwgl_enum pname, 
                          cwgl_Program** program){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getParameter_Framebuffer(cwgl_ctx* ctx, cwgl_enum pname, 
                              cwgl_Framebuffer** framebuffer){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getParameter_Renderbuffer(cwgl_ctx* ctx, cwgl_enum pname, 
                               cwgl_Renderbuffer** renderbuffer){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getParameter_Texture(cwgl_ctx* ctx, cwgl_enum pname, 
                          cwgl_Texture** texture){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

#ifdef CWGL_LEVEL_L2
CWGL_API cwgl_query_result
cwgl_getIndexedParameter_i1(cwgl_ctx* ctx, cwgl_enum pname, uint32_t index,
                            int32_t* x){
    GLint i4[4] = { 0 };
    cwgl_query_result r;
    CTX_ENTER(ctx);
    glGetIntegeri_v(pname, index, i4);
    *x = i4[0];
    r = CWGL_QR_SUCCESS;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getIndexedParameter_Buffer(cwgl_ctx* ctx, cwgl_enum pname, uint32_t index,
                                cwgl_Buffer** buffer){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}
#endif

CWGL_API int 
cwgl_isEnabled(cwgl_ctx* ctx, cwgl_enum cap){
    int r;
    CTX_ENTER(ctx);
    r = glIsEnabled(cap);
    CTX_LEAVE(ctx);
    return r;
}

// 6.1.3 Enumerated Queries
CWGL_API cwgl_query_result 
cwgl_getTexParameter_i1(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum pname,
                        int32_t* x){
    GLint i4[4] = { 0 };
    cwgl_query_result r;
    CTX_ENTER(ctx);
    glGetTexParameteriv(target, pname, i4);
    *x = i4[0];
    r = CWGL_QR_SUCCESS;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getBufferParameter_i1(cwgl_ctx* ctx, cwgl_enum target, 
                           cwgl_enum pname, int32_t* x){
    GLint i4[4] = { 0 };
    cwgl_query_result r;
    CTX_ENTER(ctx);
    glGetBufferParameteriv(target, pname, i4);
    *x = i4[0];
    r = CWGL_QR_SUCCESS;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getFramebufferAttachmentParameter_i1(cwgl_ctx* ctx, cwgl_enum target,
                                          cwgl_enum attachment, 
                                          cwgl_enum pname, int32_t* x){
    GLint i4[4] = { 0 };
    cwgl_query_result r;
    CTX_ENTER(ctx);
    glGetFramebufferAttachmentParameteriv(target, attachment, pname, i4);
    *x = i4[0];
    r = CWGL_QR_SUCCESS;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getFramebufferAttachmentParameter_Renderbuffer(cwgl_ctx* ctx, 
                                                    cwgl_enum target, 
                                                    cwgl_enum attachment, 
                                                    cwgl_enum pname, 
                                                    cwgl_Renderbuffer** renderbuffer){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getFramebufferAttachmentParameter_Texture(cwgl_ctx* ctx, 
                                               cwgl_enum target, 
                                               cwgl_enum attachment, 
                                               cwgl_enum pname, 
                                               cwgl_Texture** texture){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getRenderbufferParameter_i1(cwgl_ctx* ctx, cwgl_enum target, 
                                 cwgl_enum pname, int32_t* x){
    GLint i4[4] = { 0 };
    cwgl_query_result r;
    CTX_ENTER(ctx);
    glGetRenderbufferParameteriv(target, pname, i4);
    *x = i4[0];
    r = CWGL_QR_SUCCESS;
    CTX_LEAVE(ctx);
    return r;
}

#ifdef CWGL_LEVEL_L2
CWGL_API cwgl_query_result 
cwgl_getInternalformatParameter_iarray(cwgl_ctx* ctx, cwgl_enum target, 
                                       cwgl_enum internalformat, 
                                       cwgl_enum pname, int32_t* out, 
                                       size_t bufcount){
    /* UNIMPLEMENTED */
    abort();
}
#endif

// 6.1.4 Texture Queries
CWGL_API int 
cwgl_isTexture(cwgl_ctx* ctx, cwgl_Texture* texture){
    int r;
    GLuint name;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, texture);
    r = glIsTexture(name);
    CTX_LEAVE(ctx);
    return r;
}

// 6.1.6 Buffer Object Queries
CWGL_API int 
cwgl_isBuffer(cwgl_ctx* ctx, cwgl_Buffer* buffer){
    int r;
    GLuint name;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, buffer);
    r = glIsBuffer(name);
    CTX_LEAVE(ctx);
    return r;
}

// 6.1.7 Framebuffer Object and Renderbuffer Queries
CWGL_API int 
cwgl_isFramebuffer(cwgl_ctx* ctx, cwgl_Framebuffer* framebuffer){
    int r;
    GLuint name;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, framebuffer);
    r = glIsFramebuffer(name);
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API int 
cwgl_isRenderbuffer(cwgl_ctx* ctx, cwgl_Renderbuffer* renderbuffer){
    int r;
    GLuint name;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, renderbuffer);
    r = glIsRenderbuffer(name);
    CTX_LEAVE(ctx);
    return r;
}
