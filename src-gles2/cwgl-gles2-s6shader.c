#include "cwgl-gles2-priv.h"
#include <stdlib.h>

// 6.1.8 Shader and Program Queries
CWGL_API int 
cwgl_isShader(cwgl_ctx* ctx, cwgl_Shader* shader){
    int r;
    GLuint name;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, shader);
    r = glIsShader(name);
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getShaderParameter_i1(cwgl_ctx* ctx, cwgl_Shader* shader, 
                           cwgl_enum pname, int32_t* x){
    cwgl_query_result r;
    GLint i;
    GLuint name;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, shader);
    glGetShaderiv(name, pname, &i);
    *x = i;
    r = CWGL_QR_SUCCESS;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API int 
cwgl_isProgram(cwgl_ctx* ctx, cwgl_Program* program){
    int r;
    GLuint name;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, program);
    r = glIsProgram(name);
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getProgramParameter_i1(cwgl_ctx* ctx, cwgl_Program* program, 
                            cwgl_enum pname, int32_t* x){
    cwgl_query_result r;
    GLint i;
    GLuint name;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, program);
    glGetProgramiv(name, pname, &i);
    *x = i;
    r = CWGL_QR_SUCCESS;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getAttachedShaders(cwgl_ctx* ctx, cwgl_Program* program, 
                        cwgl_Shader** vertex_shader, 
                        cwgl_Shader** fragment_shader){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_string* 
cwgl_getProgramInfoLog(cwgl_ctx* ctx, cwgl_Program* program){
    cwgl_string* r;
    GLuint name;
    GLsizei len = 0;
    GLsizei maxlen = (512*1024);
    void* buf = malloc(maxlen);
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, program);
    glGetProgramInfoLog(name, maxlen, &len, buf);
    CTX_LEAVE(ctx);
    if(len == 0){
        free(buf);
        return NULL;
    }else{
        r = cwgl_priv_alloc_string(ctx, buf, len + 1);
        free(buf);
        return r;
    }
}

CWGL_API cwgl_string* 
cwgl_getShaderInfoLog(cwgl_ctx* ctx, cwgl_Shader* shader){
    cwgl_string* r;
    GLuint name;
    GLsizei len = 0;
    GLsizei maxlen = (512*1024);
    void* buf = malloc(maxlen);
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, shader);
    glGetShaderInfoLog(name, maxlen, &len, buf);
    CTX_LEAVE(ctx);
    if(len == 0){
        free(buf);
        return NULL;
    }else{
        r = cwgl_priv_alloc_string(ctx, buf, len + 1);
        free(buf);
        return r;
    }
}

CWGL_API cwgl_string* 
cwgl_getShaderSource(cwgl_ctx* ctx, cwgl_Shader* shader){
    // FIXME: Implement this
    return NULL;
}

CWGL_API cwgl_query_result 
cwgl_getShaderPrecisionFormat(cwgl_ctx* ctx, cwgl_enum shadertype, 
                              cwgl_enum precisiontype, 
                              int32_t* rangeMin, int32_t* rangeMax, 
                              int32_t* precision){
    cwgl_query_result r;
    GLint range[2];
    GLint prec;
    CTX_ENTER(ctx);
    glGetShaderPrecisionFormat(shadertype, precisiontype, range, &prec);
    r = CWGL_QR_SUCCESS;
    CTX_LEAVE(ctx);
    *rangeMin = range[0];
    *rangeMax = range[1];
    *precision = prec;
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getVertexAttrib_i1(cwgl_ctx* ctx, uint32_t index, 
                        cwgl_enum pname, int32_t* x){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getVertexAttrib_f4(cwgl_ctx* ctx, uint32_t index, 
                        cwgl_enum pname, 
                        float* x, float* y, float* z, float* w){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

#ifdef CWGL_LEVEL_L2
CWGL_API cwgl_query_result 
cwgl_getVertexAttrib_i4(cwgl_ctx* ctx, uint32_t index, cwgl_enum pname, 
                        int32_t* x, int32_t* y, int32_t* z, int32_t* w){
    /* UNIMPL */
    abort();
}

CWGL_API cwgl_query_result 
cwgl_getVertexAttrib_u4(cwgl_ctx* ctx, uint32_t index, cwgl_enum pname, 
                        uint32_t* x, uint32_t* y, uint32_t* z, uint32_t* w){
    /* UNIMPL */
    abort();
}
#endif

CWGL_API cwgl_query_result 
cwgl_getVertexAttrib_Buffer(cwgl_ctx* ctx, uint32_t index, 
                            cwgl_enum pname, cwgl_Buffer** buffer){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API uint32_t 
cwgl_getVertexAttribOffset(cwgl_ctx* ctx, uint32_t index, cwgl_enum pname){
    void* rr = NULL;
    uint32_t r;
    CTX_ENTER(ctx);
    glGetVertexAttribPointerv(index, pname, &rr);
    r = (uint32_t)(uintptr_t)rr;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getUniform_i1(cwgl_ctx* ctx, cwgl_Program* program, 
                   cwgl_UniformLocation* location, int32_t* x){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getUniform_i2(cwgl_ctx* ctx, cwgl_Program* program, 
                   cwgl_UniformLocation* location, int32_t* x, int32_t* y){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getUniform_i3(cwgl_ctx* ctx, cwgl_Program* program, 
                   cwgl_UniformLocation* location, 
                   int32_t* x, int32_t* y, int32_t* z){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getUniform_i4(cwgl_ctx* ctx, cwgl_Program* program, 
                   cwgl_UniformLocation* location, 
                   int32_t* x, int32_t* y, int32_t* z, int32_t* w){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getUniform_f1(cwgl_ctx* ctx, cwgl_Program* program, 
                   cwgl_UniformLocation* location, float* x){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getUniform_f2(cwgl_ctx* ctx, cwgl_Program* program, 
                   cwgl_UniformLocation* location, float* x, float* y){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getUniform_f3(cwgl_ctx* ctx, cwgl_Program* program, 
                   cwgl_UniformLocation* location, 
                   float* x, float* y, float* z){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getUniform_f4(cwgl_ctx* ctx, cwgl_Program* program, 
                   cwgl_UniformLocation* location, 
                   float* x, float* y, float* z, float* w){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getUniform_m2(cwgl_ctx* ctx, cwgl_Program* program, 
                   cwgl_UniformLocation* location, float* x){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getUniform_m3(cwgl_ctx* ctx, cwgl_Program* program, 
                   cwgl_UniformLocation* location, float* x){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API cwgl_query_result 
cwgl_getUniform_m4(cwgl_ctx* ctx, cwgl_Program* program, 
                   cwgl_UniformLocation* location, float* x){
    abort();
    cwgl_query_result r;
    CTX_ENTER(ctx);
    r = CWGL_QR_UNIMPLEMENTED;
    CTX_LEAVE(ctx);
    return r;
}

#ifdef CWGL_LEVEL_L2
CWGL_API cwgl_query_result 
cwgl_getUniform_u1(cwgl_ctx* ctx, cwgl_Program* program, 
                   cwgl_UniformLocation* location, uint32_t* x){
    /* UNIMPL */
    abort();
}

CWGL_API cwgl_query_result 
cwgl_getUniform_u2(cwgl_ctx* ctx, cwgl_Program* program, 
                   cwgl_UniformLocation* location, uint32_t* x, uint32_t* y){
    /* UNIMPL */
    abort();
}

CWGL_API cwgl_query_result 
cwgl_getUniform_u3(cwgl_ctx* ctx, cwgl_Program* program, 
                   cwgl_UniformLocation* location, uint32_t* x, uint32_t* y, 
                   uint32_t* z){
    /* UNIMPL */
    abort();
}

CWGL_API cwgl_query_result 
cwgl_getUniform_u4(cwgl_ctx* ctx, cwgl_Program* program, 
                   cwgl_UniformLocation* location, uint32_t* x, uint32_t* y, 
                   uint32_t* z, uint32_t* w){
    /* UNIMPL */
    abort();
}

CWGL_API cwgl_query_result 
cwgl_getUniform_m2x3(cwgl_ctx* ctx, cwgl_Program* program, 
                     cwgl_UniformLocation* location, float* x){
    /* UNIMPL */
    abort();
}

CWGL_API cwgl_query_result 
cwgl_getUniform_m2x4(cwgl_ctx* ctx, cwgl_Program* program, 
                     cwgl_UniformLocation* location, float* x){
    /* UNIMPL */
    abort();
}

CWGL_API cwgl_query_result 
cwgl_getUniform_m3x2(cwgl_ctx* ctx, cwgl_Program* program, 
                     cwgl_UniformLocation* location, float* x){
    /* UNIMPL */
    abort();
}

CWGL_API cwgl_query_result 
cwgl_getUniform_m3x4(cwgl_ctx* ctx, cwgl_Program* program, 
                     cwgl_UniformLocation* location, float* x){
    /* UNIMPL */
    abort();
}

CWGL_API cwgl_query_result 
cwgl_getUniform_m4x2(cwgl_ctx* ctx, cwgl_Program* program, 
                     cwgl_UniformLocation* location, float* x){
    /* UNIMPL */
    abort();
}

CWGL_API cwgl_query_result 
cwgl_getUniform_m4x3(cwgl_ctx* ctx, cwgl_Program* program, 
                     cwgl_UniformLocation* location, float* x){
    /* UNIMPL */
    abort();
}
#endif
