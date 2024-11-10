#ifdef CWGL_LEVEL_L2
#include "cwgl-gles2-priv.h"
#include <stdlib.h>

CWGL_API void 
cwgl_bindBufferBase(cwgl_ctx* ctx, cwgl_enum target, uint32_t index, 
                    cwgl_Buffer* buffer){
    GLuint name;
    CTX_ENTER(ctx);
    if(buffer){
        name = CTX_GETNAME(ctx, buffer);
    }else{
        /* FIXME: ??? */
        name = 0;
    }
    glBindBufferBase(target, index, name);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_bindBufferRange(cwgl_ctx* ctx, cwgl_enum target, uint32_t index, 
                     cwgl_Buffer* buffer, uint32_t offset, uint32_t size){
    GLuint name;
    CTX_ENTER(ctx);
    if(buffer){
        name = CTX_GETNAME(ctx, buffer);
    }else{
        /* FIXME: ??? */
        name = 0;
    }
    glBindBufferRange(target, index, name, offset, size);
    CTX_LEAVE(ctx);
}

#if 0
static char**
gennamelist(cwgl_string** names, size_t namecount){
    size_t i;
    size_t totalbufsize;
    char* outbuf;
    char* startcharbuf;
    char* p;
    char** namep;
    size_t strsize;
    cwgl_query_result r;
    /* Pass1: collect name size */
    totalbufsize = sizeof(char*) * namecount; /* Initial */
    for(i=0;i!=namecount;i++){
        totalbufsize += cwgl_string_size(0, names[i]);
    }
    outbuf = malloc(totalbufsize);
    if(! outbuf){
        abort();
    }
    namep = outbuf;
    startcharbuf = &outbuf[sizeof(char*) * namecount];
    /* Pass2: Fill namelist */
    p = startcharbuf;
    for(i=0;i!=namecount;i++){
        namep[i] = p;
        r = cwgl_string_read(0, names[i], p, outbuf + totalbufsize - p);
        if(r != CWGL_QR_SUCCESS){
            abort();
        }
    }
    return outbuf;
}

static void
freenamelist(void* lst){
    free(lst);
}
#endif

CWGL_API void
cwgl_getUniformIndices(cwgl_ctx* ctx, cwgl_Program* program, 
                       const char** uniformnames, size_t namecount, 
                       uint32_t* out){
    GLuint name;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, program);
    glGetUniformIndices(name, namecount, uniformnames, out);
    CTX_LEAVE(ctx);
}

CWGL_API cwgl_query_result 
cwgl_getActiveUniforms_iarray(cwgl_ctx* ctx, cwgl_Program* program, 
                              uint32_t* indices, size_t indicecount, 
                              cwgl_enum pname, int32_t* out){
    GLuint name;
    GLuint e;
    CTX_ENTER(ctx);
    while(glGetError()){}
    name = CTX_GETNAME(ctx, program);
    glGetActiveUniformsiv(name, indicecount, indices, pname, out);
    e = glGetError();
    CTX_LEAVE(ctx);
    if(e){
        return CWGL_QR_GLERROR;
    }
    return CWGL_QR_SUCCESS;
}

CWGL_API uint32_t 
cwgl_getUniformBlockIndex(cwgl_ctx* ctx, cwgl_Program* program, 
                          const char* uniformblockname){
    GLuint name;
    GLuint res;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, program);
    res = glGetUniformBlockIndex(name, uniformblockname);
    CTX_LEAVE(ctx);
    return res;
}

CWGL_API cwgl_query_result 
cwgl_getActiveUniformBlockParameter_i1(cwgl_ctx* ctx, cwgl_Program* program, 
                                       uint32_t uniformblockindex, 
                                       cwgl_enum pname, int32_t* out){
    GLuint name;
    GLint res;
    GLint e;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, program);
    while(glGetError()){}
    glGetActiveUniformBlockiv(name, uniformblockindex, pname, &res);
    e = glGetError();
    CTX_LEAVE();
    if(e){
        return CWGL_QR_GLERROR;
    }
    *out = res;
    return CWGL_QR_SUCCESS;
}

CWGL_API cwgl_query_result 
cwgl_getActiveUniformBlockParameter_iarray(cwgl_ctx* ctx, 
                                           cwgl_Program* program, 
                                           uint32_t uniformblockindex, 
                                           cwgl_enum pname, int32_t* out, 
                                           uint32_t outcount, 
                                           int32_t* resultcount){
    GLuint name;
    GLint e;
    int32_t active_uniforms;
    cwgl_query_result pass1result;
    /* 0x8A42 = UNIFORM_BLOCK_ACTIVE_UNIFORMS */
    pass1result = cwgl_getActiveUniformBlockParameter_i1(ctx, program,
                                                         uniformblockindex,
                                                         0x8a42,
                                                         &active_uniforms);
    if(pass1result != CWGL_QR_SUCCESS){
        return pass1result;
    }
    if(resultcount){
        *resultcount = active_uniforms;
    }
    if(! out){
        return CWGL_QR_SUCCESS;
    }
    if(outcount < (uint32_t)active_uniforms){
        return CWGL_QR_INSUFFICIENT_BUFFER;
    }
    CTX_ENTER(ctx);
    if(pname == 0x8A43 /* UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES */){
        while(glGetError()){}
        name = CTX_GETNAME(ctx, program);
        glGetActiveUniformBlockiv(name, uniformblockindex, pname, out);
    }else{
        abort();
    }
    CTX_LEAVE(ctx);
    if(e){
        return CWGL_QR_GLERROR;
    }
    return CWGL_QR_SUCCESS;
}

CWGL_API cwgl_string* 
cwgl_getActiveUniformBlockName(cwgl_ctx* ctx, cwgl_Program* program, 
                               uint32_t uniformblockindex){
    char buf[1024];
    GLuint name;
    GLsizei len;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, program);
    len = 0;
    glGetActiveUniformBlockName(name, uniformblockindex, 1024, &len, buf);
    CTX_LEAVE(ctx);
    if(! len){
        return 0;
    }
    return cwgl_priv_alloc_string(ctx, buf, len + 1);
}

CWGL_API void 
cwgl_uniformBlockBinding(cwgl_ctx* ctx, cwgl_Program* program, 
                         uint32_t uniformblockindex, 
                         uint32_t uniformblockbinding){
    GLuint name;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, program);
    glUniformBlockBinding(name, uniformblockindex, uniformblockbinding);
    CTX_LEAVE(ctx);
}
#endif
