#ifdef CWGL_LEVEL_L2
#include "cwgl-gles2-priv.h"

CWGL_API void 
cwgl_Sampler_release(cwgl_ctx* ctx, cwgl_Sampler* sampler){
    if(sampler){
        CTX_FREE(ctx, Sampler, sampler);
    }
}

CWGL_API cwgl_Sampler* 
cwgl_createSampler(cwgl_ctx* ctx){
    GLuint name = 0;
    cwgl_Sampler* o;
    CTX_ENTER(ctx);
    glGenSamplers(1, &name);
    o = CTX_ALLOC(ctx, Sampler);
    CTX_SETNAME(ctx, o, name);
    CTX_LEAVE(ctx);
    return o;
}

CWGL_API void 
cwgl_deleteSampler(cwgl_ctx* ctx, cwgl_Sampler* sampler){
    GLuint name = 0;
    CTX_ENTER(ctx);
    if(sampler){
        name = CTX_GETNAME(ctx, sampler);
        glDeleteSamplers(1, &name);
    }
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_bindSampler(cwgl_ctx* ctx, uint32_t unit, cwgl_Sampler* sampler){
    GLuint name = 0;
    CTX_ENTER(ctx);
    if(sampler){
        name = CTX_GETNAME(ctx, sampler);
    }else{
        name = 0;
    }
    glBindSampler(unit, name);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_samplerParameteri(cwgl_ctx* ctx, cwgl_Sampler* sampler, cwgl_enum pname, 
                       int32_t param){
    GLuint name = 0;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, sampler);
    glSamplerParameteri(name, pname, param);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_samplerParameterf(cwgl_ctx* ctx, cwgl_Sampler* sampler, cwgl_enum pname,
                       float param){
    GLuint name = 0;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, sampler);
    glSamplerParameterf(name, pname, param);
    CTX_LEAVE(ctx);
}

CWGL_API cwgl_query_result 
cwgl_getSamplerParameter_i1(cwgl_ctx* ctx, cwgl_Sampler* sampler, 
                            cwgl_enum pname, int32_t* out){
    GLuint name = 0;
    GLint res;
    GLint e;
    CTX_ENTER(ctx);
    while(glGetError()){}
    name = CTX_GETNAME(ctx, sampler);
    glGetSamplerParameteriv(name, pname, &res);
    e = glGetError();
    CTX_LEAVE(ctx);
    if(e){
        return CWGL_QR_GLERROR;
    }
    *out = res;
    return CWGL_QR_SUCCESS;
}

CWGL_API cwgl_query_result 
cwgl_getSamplerParameter_f1(cwgl_ctx* ctx, cwgl_Sampler* sampler, 
                            cwgl_enum pname, float* out){
    GLuint name = 0;
    GLfloat res;
    GLint e;
    CTX_ENTER(ctx);
    while(glGetError()){}
    name = CTX_GETNAME(ctx, sampler);
    glGetSamplerParameterfv(name, pname, &res);
    e = glGetError();
    CTX_LEAVE(ctx);
    if(e){
        return CWGL_QR_GLERROR;
    }
    *out = res;
    return CWGL_QR_SUCCESS;
}


#endif
