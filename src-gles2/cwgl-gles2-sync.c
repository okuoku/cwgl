#ifdef CWGL_LEVEL_L2
#include "cwgl-gles2-priv.h"

CWGL_API void 
cwgl_Sync_release(cwgl_ctx* ctx, cwgl_Sync* sync){
    if(sync){
        CTX_FREE(ctx, Sync, sync);
    }
}

CWGL_API cwgl_Sync* 
cwgl_fenceSync(cwgl_ctx* ctx, cwgl_enum condition, uint32_t flags){
    GLsync obj;
    cwgl_Sync* sync;
    CTX_ENTER(ctx);
    obj = glFenceSync(condition, flags);
    if(!obj){
        CTX_LEAVE(ctx);
        return 0;
    }
    sync = CTX_ALLOC(ctx, Sync);
    CTX_SETSYNC(ctx, sync, obj);
    CTX_LEAVE(ctx);
    return sync;
}

CWGL_API void 
cwgl_deleteSync(cwgl_ctx* ctx, cwgl_Sync* sync){
    GLsync obj;
    CTX_ENTER(ctx);
    obj = CTX_GETSYNC(ctx, sync);
    glDeleteSync(obj);
    CTX_LEAVE(ctx);
}

CWGL_API cwgl_enum 
cwgl_clientWaitSync(cwgl_ctx* ctx, cwgl_Sync* sync, uint32_t flags, 
                    uint32_t timeout){
    GLsync obj;
    cwgl_enum res = (cwgl_enum)-1;
    CTX_ENTER(ctx);
    obj = CTX_GETSYNC(ctx, sync);
    res = glClientWaitSync(obj, flags, timeout);
    CTX_LEAVE(ctx);
    return res;
}

CWGL_API void 
cwgl_waitSync(cwgl_ctx* ctx, cwgl_Sync* sync, uint32_t flags, 
              uint32_t reserved){
    GLsync obj;
    (void)reserved;
    CTX_ENTER(ctx);
    obj = CTX_GETSYNC(ctx, sync);
    glWaitSync(obj, flags, GL_TIMEOUT_IGNORED);
    CTX_LEAVE(ctx);
}

CWGL_API cwgl_query_result 
cwgl_getSyncParameter_i1(cwgl_ctx* ctx, cwgl_Sync* sync, cwgl_enum pname,
                         int32_t* out){
    GLsync obj;
    GLint res;
    GLint e;
    CTX_ENTER(ctx);
    obj = CTX_GETSYNC(ctx, sync);
    while(glGetError()){}
    glGetSynciv(obj, pname, sizeof(GLint), 0, &res);
    e = glGetError();
    CTX_LEAVE(ctx);
    if(e){
        return CWGL_QR_GLERROR;
    }
    *out = res;
    return CWGL_QR_SUCCESS;
}
#endif
