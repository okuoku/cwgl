#ifndef __YUNI_SHXM_PRIVATE_H
#define __YUNI_SHXM_PRIVATE_H

#include <stdint.h>
#include "shxm.h"

#ifdef __cplusplus
extern "C" {
#endif
// }

struct shxm_ctx_s {
    int dummy;
};

#define SHXM_MAX_PHASE 2
struct shxm_slot_s {
    cwgl_var_type type;
    const char* name;
    int id[SHXM_MAX_PHASE];
    // FIXME: Signedness for WebGL2
    int array_length; /* zero for non arrays */
};

typedef struct shxm_slot_s shxm_slot;

struct shxm_uniform_s {
    shxm_slot* slot;
    unsigned int offset;
    unsigned int size;
};

typedef struct shxm_uniform_s shxm_uniform;

struct shxm_opaque_s {
    shxm_slot* slot;
    unsigned int binding;
    int phase;
};
typedef struct shxm_opaque_s shxm_opaque;

#define SHXM_LOCATION_BUILTIN -1
struct shxm_attribute_s {
    shxm_slot* slot;
    int location;
    unsigned int offset; /* For input register */
    unsigned int size; /* For input register */
};

typedef struct shxm_attribute_s shxm_attribute;

struct shxm_shader_s {
    int refcnt;
    shxm_shader_stage type;
    char* source; /* GLSL Source */
    unsigned int source_len;
    uint32_t* ir; /* SPIR-V IR (Unpatched) */
    unsigned int ir_len;
};
typedef struct shxm_shader_s shxm_shader;

#define SHXM_MAX_SLOTS 512
#define SHXM_MAX_INPUTS 256
#define SHXM_MAX_OUTPUTS 256
#define SHXM_MAX_VARYINGS 256
#define SHXM_MAX_UNIFORMS 256
#define SHXM_MAX_UNUSED 256
struct shxm_program_s {
    /* Pre-link fields */
    shxm_shader* vertex_shader;
    shxm_shader* fragment_shader;

    /* Post-link fields */
    unsigned int slot_count;
    unsigned int uniform_count;
    unsigned int uniform_size;
    unsigned int input_count;
    unsigned int input_register_size;
    unsigned int output_count;
    unsigned int varying_count;
    unsigned int unused_count;
    unsigned int opaque_count;

    /* Patched IR */
    uint32_t* vertex_ir;
    unsigned int vertex_ir_len;
    uint32_t* fragment_ir;
    unsigned int fragment_ir_len;

    /* Field data */
    shxm_slot slot[SHXM_MAX_SLOTS];
    shxm_uniform uniform[SHXM_MAX_UNIFORMS];
    shxm_attribute input[SHXM_MAX_INPUTS];
    shxm_attribute output[SHXM_MAX_OUTPUTS];
    shxm_attribute varying[SHXM_MAX_VARYINGS];
    shxm_attribute unused[SHXM_MAX_UNUSED];
    shxm_opaque opaque[SHXM_MAX_UNIFORMS];
};

enum shxm_varusage_e {
    UNKNOWN,
    INPUT,
    OUTPUT,
    UNIFORM,
    UNIFORM_CONSTANT
};

typedef enum shxm_varusage_e shxm_varusage;

struct shxm_spirv_ent_s {
    int offs; /* SPIR-V Location */
    int op;
    int name; /* OpName location */
    int chain; /* Decoration chain start location */
    int width;
    int is_signed;
    int array_length; /* zero for non arrays */
    int element_type_id;
    shxm_varusage varusage;
    cwgl_var_type type;
};

typedef struct shxm_spirv_ent_s shxm_spirv_ent;

struct shxm_spirv_intr_s {
    unsigned int* chain;
    shxm_spirv_ent* ent;
    unsigned int ent_count;
    int entrypoint; /* ID for entrypoint */
    int entrypoint_loc; /* OpEntryPoint location */
    int preamble_end; /* First OpName location */
    int defs_start;
    int defs_end;
    int int32_type_id;
    /* main() related */
    int float32_type_id;
    int void_type_id;
    int voidfunc_type_id;
};

typedef struct shxm_spirv_intr_s shxm_spirv_intr;

struct shxm_util_buf_s;
typedef struct shxm_util_buf_s shxm_util_buf;

/* Private: Patcher */
int
shxm_private_patch_spirv(shxm_ctx* ctx, shxm_program* prog,
                         shxm_spirv_intr* intr, int phase);

/* Private: SPIR-V parser */
shxm_spirv_intr* shxm_private_read_spirv(uint32_t* ir, int len);

/* Private: Decompiler */
void shxm_private_decomp_spirv(uint32_t* spirv, int len);
void shxm_private_spirv_dis(int* spirv, int len); // shxm_glslang.cpp

/* Private: Optimizer */
int shxm_private_spvopt_run(uint32_t* ir, int len,
                            uint32_t** out_ir, int* out_len);

/* Private: Buf */
shxm_util_buf* shxm_private_util_buf_new(int siz);
void shxm_private_util_buf_release(shxm_util_buf* buf);
int shxm_private_util_buf_write_raw(shxm_util_buf* buf, uint32_t* obj,
                                    int count);
int shxm_private_util_buf_write_op(shxm_util_buf* buf, uint32_t* obj,
                                   int count);
int shxm_private_util_buf_size(shxm_util_buf* buf);
uint32_t* shxm_private_util_buf_ptr(shxm_util_buf* buf);
int shxm_private_util_buf_merge(shxm_util_buf* dest, 
                                shxm_util_buf* src);
int shxm_private_util_buf_dup(shxm_util_buf* buf,
                              uint32_t** out_obj,
                              int* out_count);
void shxm_private_util_buf_clearnop(shxm_util_buf* buf);

/* Private: minishade0 */
void shxm_ms_test0(int phase, uint32_t* ir, int len);

// {
#ifdef __cplusplus
};
#endif

#endif

