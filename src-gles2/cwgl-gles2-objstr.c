#include "cwgl-gles2-priv.h"
#include <string.h>

cwgl_string* 
cwgl_priv_alloc_string(cwgl_ctx* ctx, const char* str, size_t buflen){
    cwgl_string* r;
    void* buf;
    buf = malloc(buflen);
    r = malloc(sizeof(cwgl_string));
    memcpy(buf, str, buflen);
    r->size = buflen;
    r->str = buf;
    return r;
}

CWGL_API size_t
cwgl_string_size(cwgl_ctx* ctx, cwgl_string* str){
    if(str){
        return str->size;
    }else{
        return 0;
    }
}

CWGL_API cwgl_query_result
cwgl_string_read(cwgl_ctx* ctx, cwgl_string* str, char* buf, size_t buflen){
    const size_t siz = cwgl_string_size(ctx, str);
    if(str){
        if(buflen >= siz){
            memcpy(buf, str->str, siz);
            if(buflen > siz){
                buf[siz] = 0;
            }
            return CWGL_QR_SUCCESS;
        }else{
            return CWGL_QR_INSUFFICIENT_BUFFER;
        }
    }else{
        if(buflen > 0){
            buf[0] = 0;
            return CWGL_QR_SUCCESS;
        }else{
            return CWGL_QR_INSUFFICIENT_BUFFER;
        }
    }
}

CWGL_API void
cwgl_string_release(cwgl_ctx* ctx, cwgl_string* str){
    if(str){
        free(str->str);
        free(str);
    }
}
