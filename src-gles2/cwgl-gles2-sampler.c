#ifdef CWGL_LEVEL_L2
#include "cwgl-gles2-priv.h"

CWGL_API void 
cwgl_Sampler_release(cwgl_ctx* ctx, cwgl_Sampler* sampler){
    if(sampler){
        CTX_FREE(ctx, Sampler, sampler);
    }
}

#endif
