#ifndef CWGL_EGL_CTX_PRIV_H
#define CWGL_EGL_CTX_PRIV_H

#include "EGL/egl.h"

struct cwgl_ctx_s {
    EGLDisplay egl_disp;
    EGLSurface egl_surf;
    EGLContext egl_ctx;
    EGLConfig egl_cfg;
};

#endif
