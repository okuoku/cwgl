#ifndef __YUNI_CWGL_GLES2_PRIV_H
#define __YUNI_CWGL_GLES2_PRIV_H

#ifdef CWGL_LEVEL_L2
#include <GLES3/gl3.h>
#else /* L1 */
#include <GLES2/gl2.h>
#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2ext.h>
#endif
#include <yuniframe/cwgl.h>

/* Context */
void cwgl_priv_check_current(cwgl_ctx* ctx);
cwgl_string* cwgl_priv_alloc_string(cwgl_ctx* ctx, const char* str,
                                      size_t buflen);
struct cwgl_string_s {
    size_t size; /* Includes nul */
    char* str;
};

#define CTX_ENTER(ctx) cwgl_priv_check_current(ctx)
#define CTX_LEAVE(ctx)


/* Buffer structures */
struct cwgl_Buffer_s {
    int name;
};
struct cwgl_Shader_s {
    int name;
};
struct cwgl_Program_s {
    int name;
};
struct cwgl_UniformLocation_s {
    int name;
};

struct cwgl_Texture_s {
    int name;
};

struct cwgl_Renderbuffer_s {
    int name;
};

struct cwgl_Framebuffer_s {
    int name;
};

struct cwgl_VertexArrayObject_s {
    int name;
};

#ifdef CWGL_LEVEL_L2
struct cwgl_Query_s{
    int name;
};

struct cwgl_Sampler_s{
    int name;
};

struct cwgl_Sync_s{
    void* sync;
};

struct cwgl_TransformFeedback_s{
    int name;
};
#endif

/* Buffer allocation */
#include <stdlib.h>

#define CTX_ALLOC(ctx, type) \
    malloc(sizeof(cwgl_ ## type))

#define CTX_FREE(ctx, type, p) \
    free(p)

#define CTX_SETNAME(ctx, p, id) \
    p->name = id

#define CTX_GETNAME(ctx, p) \
    p->name

#ifdef CWGL_LEVEL_L2
#define CTX_SETSYNC(ctx, p, id) \
    p->sync = id

#define CTX_GETSYNC(ctx, p) \
    p->sync
#endif

#endif
