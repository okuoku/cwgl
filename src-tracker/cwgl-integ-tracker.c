#include <stdlib.h>
#include "cwgl-tracker-priv.h"

void*
cwgl_ctx_platform_get(void* c){
    cwgl_ctx_t* ctx = (cwgl_ctx_t*)c;
    return ctx->platform;
}

void*
cwgl_ctx_alloc(void* platform){
    cwgl_ctx_t* ctx = malloc(sizeof(cwgl_ctx_t));
    ctx->platform = platform;
    cwgl_integ_ctx_init(ctx);
    return ctx;
}

void
cwgl_ctx_destroy(void* c){
    free(c);
}
