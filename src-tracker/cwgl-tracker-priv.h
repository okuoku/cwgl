#ifndef __YUNI_CWGL_TRACKER_PRIV_H
#define __YUNI_CWGL_TRACKER_PRIV_H

#include "cwgl-tracker-integ.h"
#include "cwgl-backend-states.h"

#ifdef __cplusplus
extern "C" {
#endif
// }

/* Context */
void cwgl_priv_check_current(cwgl_ctx* ctx);
cwgl_string* cwgl_priv_alloc_string(cwgl_ctx* ctx, const char* str,
                                      size_t buflen);
cwgl_string* cwgl_priv_string_dup(cwgl_ctx* ctx, cwgl_string* src);
int cwgl_priv_match_sym(cwgl_ctx* ctx, cwgl_string* s, const char* name, int* array_idx_l, int* array_idx_r);
int cwgl_priv_match_symobj(cwgl_ctx* ctx, cwgl_string* s, cwgl_string* t, int* array_idx_l, int* array_idx_r);
struct cwgl_string_s {
    size_t size; /* Includes nul */
    char* str;
};

/* Context */
enum cwgl_objtype_e {
    CWGL_OBJ_CTX = 0x299857,
    CWGL_OBJ_BUFFER,
    CWGL_OBJ_SHADER,
    CWGL_OBJ_PROGRAM,
    CWGL_OBJ_UNIFORMLOCATION,
    CWGL_OBJ_TEXTURE,
    CWGL_OBJ_RENDERBUFFER,
    CWGL_OBJ_FRAMEBUFFER,
    CWGL_OBJ_VAO
};
typedef enum cwgl_objtype_e cwgl_objtype;

struct cwgl_objhdr_s {
    cwgl_objtype type;
    uintptr_t refcnt;
    cwgl_ctx* ctx;
};

typedef struct cwgl_objhdr_s cwgl_objhdr;

struct cwgl_ctx_s {
    cwgl_ctx_tracker_state state;
    cwgl_backend_ctx* backend;
    void* platform;
};

/* Buffer structures */
struct cwgl_Buffer_s {
    cwgl_objhdr hdr;
    cwgl_buffer_state state;
    cwgl_backend_Buffer* backend;
};
struct cwgl_Shader_s {
    cwgl_objhdr hdr;
    cwgl_shader_state state;
    cwgl_backend_Shader* backend;
};
struct cwgl_Program_s {
    cwgl_objhdr hdr;
    cwgl_program_state state;
    cwgl_backend_Program* backend;
};
struct cwgl_UniformLocation_s {
    cwgl_objhdr hdr;
    cwgl_Program* program; /* Back reference */
    uint32_t index;
    uint32_t offset;
    uint32_t age_link;
};

struct cwgl_Texture_s {
    cwgl_objhdr hdr;
    cwgl_texture_state state;
    cwgl_backend_Texture* backend;
};

struct cwgl_Renderbuffer_s {
    cwgl_objhdr hdr;
    cwgl_renderbuffer_state state;
    cwgl_backend_Renderbuffer* backend;
};

struct cwgl_Framebuffer_s {
    cwgl_objhdr hdr;
    cwgl_framebuffer_state state;
    cwgl_backend_Framebuffer* backend;
};

struct cwgl_VertexArrayObject_s {
    cwgl_objhdr hdr;
    cwgl_vao_state state;
    cwgl_vao_attrib_state attrib[CWGL_MAX_VAO_SIZE];
};

/* Initializers */
void cwgl_priv_buffer_init(cwgl_buffer_state* state);
void cwgl_priv_framebuffer_attachment_init(cwgl_framebuffer_attachment_state* state);
void cwgl_priv_renderbuffer_init(cwgl_renderbuffer_state* state);
void cwgl_priv_texture_init(cwgl_texture_state* state);
void cwgl_priv_vao_init(cwgl_vao_state* state, cwgl_vao_attrib_state attrib[CWGL_MAX_VAO_SIZE]);

void cwgl_priv_objhdr_init(cwgl_ctx* ctx, cwgl_objhdr* hdr, cwgl_objtype objtype);
uintptr_t cwgl_priv_objhdr_release(cwgl_objhdr* hdr);
void cwgl_priv_objhdr_retain(cwgl_objhdr* hdr);

/* xref */
void cwgl_priv_buffer_release(cwgl_ctx* ctx, cwgl_Buffer* buffer);
void cwgl_priv_texture_release(cwgl_ctx* ctx, cwgl_Texture* texture);

#define CTX_SET_ERROR(ctx, num) ctx->state.err = num

// {
#ifdef __cplusplus
};
#endif

#endif
