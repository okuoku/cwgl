#ifndef __YUNI_CWGL_TRACKER_INTEG_H
#define __YUNI_CWGL_TRACKER_INTEG_H

#define CWGL_DECL_ENUMS
#include "yuniframe/cwgl.h"
#include "cwgl-tracker-states.h"

#ifdef __cplusplus
extern "C" {
#endif
// }

int cwgl_integ_ctx_init(cwgl_ctx* ctx);
int cwgl_integ_program_setup(cwgl_ctx* ctx, cwgl_Program* program,
                         uint32_t n_uniform, uint32_t n_attribute);

// {
#ifdef __cplusplus
};
#endif

#endif

