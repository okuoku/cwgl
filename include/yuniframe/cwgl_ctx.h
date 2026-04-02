#ifndef CWGL_CWGL_CTX_H
#define CWGL_CWGL_CTX_H

#ifdef __cplusplus
extern "C" {
#endif
// }

struct cwgl_surface_s;
typedef struct cwgl_surface_s cwgl_surface;

CWGL_API cwgl_ctx* cwgl_init_offscreen0(void);
CWGL_API cwgl_surface* cwgl_surface_create(cwgl_ctx* ctx,
                                           int32_t width, int32_t height, 
                                           /* CWGL_CTX_FLAG_* */
                                           uint32_t flags);

CWGL_API void cwgl_surface_release(cwgl_ctx* ctx, cwgl_surface* s);
CWGL_API void cwgl_surface_set(cwgl_ctx* ctx, cwgl_surface* s);

// {
#ifdef __cplusplus
};
#endif

#endif
