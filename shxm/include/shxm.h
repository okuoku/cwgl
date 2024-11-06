#ifndef __YUNI_SHXM_H
#define __YUNI_SHXM_H

#ifdef __cplusplus
extern "C" {
#endif
// }

#define SHXM_API

// FIXME: Move to CWGL
enum cwgl_var_type_e {
    /* Init */
    CWGL_VAR_UNKNOWN = 0,

    /* Scalar */
    CWGL_VAR_FLOAT,
    CWGL_VAR_FLOAT_VEC2,
    CWGL_VAR_FLOAT_VEC3,
    CWGL_VAR_FLOAT_VEC4,
    CWGL_VAR_INT,
    CWGL_VAR_INT_VEC2,
    CWGL_VAR_INT_VEC3,
    CWGL_VAR_INT_VEC4,
    CWGL_VAR_BOOL,
    CWGL_VAR_BOOL_VEC2,
    CWGL_VAR_BOOL_VEC3,
    CWGL_VAR_BOOL_VEC4,
    CWGL_VAR_FLOAT_MAT2,
    CWGL_VAR_FLOAT_MAT3,
    CWGL_VAR_FLOAT_MAT4,

    /* Samplers */
    CWGL_VAR_SAMPLER_2D,
    CWGL_VAR_SAMPLER_CUBE,

    /* Virtual */
    CWGL_VAR_STRUCT,
    CWGL_VAR_ARRAY,
    CWGL_VAR_VOID,

    /* Dummy */
    CWGL_VAR_DUMMY = 0x7fffffff
};
typedef enum cwgl_var_type_e cwgl_var_type;

enum shxm_shader_stage_e {
    SHXM_SHADER_STAGE_FRAGMENT,
    SHXM_SHADER_STAGE_VERTEX
};
typedef enum shxm_shader_stage_e shxm_shader_stage;

struct shxm_ctx_s;
struct shxm_shader_s;
struct shxm_program_s;
typedef struct shxm_ctx_s shxm_ctx;
typedef struct shxm_shader_s shxm_shader;
typedef struct shxm_program_s shxm_program;

SHXM_API shxm_ctx* shxm_init(void);

SHXM_API shxm_shader* shxm_shader_create(shxm_ctx* ctx, shxm_shader_stage type);
SHXM_API void shxm_shader_release(shxm_ctx* ctx, shxm_shader* sh);
SHXM_API shxm_program* shxm_program_create(shxm_ctx* ctx);
SHXM_API void shxm_program_release(shxm_ctx* ctx, shxm_program* prog);

SHXM_API void shxm_shader_source(shxm_ctx* ctx, shxm_shader* sh,
                                 const char* src /* Copied */,
                                 unsigned int len);
SHXM_API int shxm_shader_compile(shxm_ctx* ctx, shxm_shader* sh);

SHXM_API void shxm_program_attach(shxm_ctx* ctx, shxm_program* prog, shxm_shader* sh);
SHXM_API int shxm_program_detach(shxm_ctx* ctx, shxm_program* prog, shxm_shader* sh);

SHXM_API int shxm_program_link(shxm_ctx* ctx, shxm_program* prog);


// {
#ifdef __cplusplus
};
#endif

#endif
