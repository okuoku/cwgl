#ifdef CWGL_LEVEL_L2
#include "cwgl-gles2-priv.h"

CWGL_API void 
cwgl_Sync_release(cwgl_ctx* ctx, cwgl_Sync* sync){
    if(sync){
        CTX_FREE(ctx, Sync, sync);
    }
}

#endif
