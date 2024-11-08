#ifdef CWGL_LEVEL_L2
#include "cwgl-gles2-priv.h"

CWGL_API void 
cwgl_TransformFeedback_release(cwgl_ctx* ctx, cwgl_TransformFeedback* tfb){
    if(tfb){
        CTX_FREE(ctx, TransformFeedback, tfb);
    }
}

#endif
