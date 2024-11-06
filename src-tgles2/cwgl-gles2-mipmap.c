#include "cwgl-backend-gles2-priv.h"

int 
cwgl_backend_generateMipmap(cwgl_ctx* ctx, cwgl_enum target){
    /* Apply hints */
    glHint(GL_GENERATE_MIPMAP_HINT,
           ctx->state.glo.GENERATE_MIPMAP_HINT);
    glGenerateMipmap(target);
    return 0;
}
