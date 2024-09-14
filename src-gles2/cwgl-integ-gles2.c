void*
cwgl_ctx_platform_get(void* ctx){
    return ctx;
}

void*
cwgl_ctx_alloc(void* platform){
    return platform;
}

void
cwgl_ctx_destroy(void* bogus){
    /* Do nothing */
    (void) bogus;
}
