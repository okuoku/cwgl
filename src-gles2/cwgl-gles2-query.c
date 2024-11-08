#ifdef CWGL_LEVEL_L2
#include "cwgl-gles2-priv.h"

CWGL_API void 
cwgl_Query_release(cwgl_ctx* ctx, cwgl_Query* query){
    if(query){
        CTX_FREE(ctx, Query, query);
    }
}

#endif
