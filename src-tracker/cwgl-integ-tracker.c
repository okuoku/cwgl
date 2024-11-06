#include <stdlib.h>
#include "cwgl-tracker-priv.h"

void*
cwgl_ctx_platform_get(void* c){
    cwgl_ctx* ctx = (cwgl_ctx*)c;
    return ctx->platform;
}

void*
cwgl_ctx_alloc(void* platform){
    cwgl_ctx* ctx = malloc(sizeof(cwgl_ctx));
    ctx->platform = platform;
    cwgl_integ_ctx_init(ctx);
    return ctx;
}

void
cwgl_ctx_destroy(void* c){
    free(c);
}
