#ifdef CWGL_USE_EGL_CTX
#include "EGL/egl.h"
#define EGL_EGLEX_PROTOTYPES
#include "EGL/eglext.h"

#include <stdlib.h>
#include <stdio.h>

/* FIXME: Move this to gles2 */
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include "cwgl-egl-ctx_priv.h"
#include "yuniframe/cwgl.h"
#include "yuniframe/cwgl_ctx.h"

struct cwgl_surface_s {
    EGLSurface egl_surf;
    EGLContext egl_ctx;
};

void 
cwgl_priv_check_current(cwgl_ctx* ctx){
}

void 
cwgl_ctx_glGenVertexArray_2(cwgl_ctx* ctx, uintptr_t* id){
}

void 
cwgl_ctx_glBindVertexArray_2(cwgl_ctx* ctx, uintptr_t id){
}

static void
xabort(const char* str){
    fprintf(stderr, "%s\n", str);
    abort();
}

static void
cb_egl_debug(EGLenum error, const char* command,
             EGLint messageType,
             EGLLabelKHR threadLabel,
             EGLLabelKHR objectLabel,
             const char* message){
    fprintf(stderr,
            "Error: %x, With command %s, Type: %d,"
            "Thread: %s, Object: %s, Message: %s.",
            error, command, messageType, (const char*)threadLabel, 
            (const char*)objectLabel, message);
}

static void
cb_gles_debug(GLenum source, GLenum type, GLuint id,
    GLenum severity, GLsizei length, const GLchar *message,
    const void *userParam){
    (void)source;
    (void)userParam;

    fprintf(stderr,
            "[GL] type=0x%x id=%u severity=0x%x: %.*s\n",
            type, id, severity,
            (int)length,
            message ? message : "");
}

static void
init_egl_debug(void){
    PFNEGLDEBUGMESSAGECONTROLKHRPROC ptr_eglDebugMessageControl =
        (PFNEGLDEBUGMESSAGECONTROLKHRPROC)
        eglGetProcAddress("eglDebugMessageControlKHR");

    if(ptr_eglDebugMessageControl){
        const EGLAttrib dattr[] = {
            EGL_DEBUG_MSG_WARN_KHR, EGL_TRUE,
            EGL_DEBUG_MSG_INFO_KHR, EGL_TRUE,
            EGL_NONE
        };
        (void) ptr_eglDebugMessageControl(cb_egl_debug, dattr);
    }
}

static void
init_gles_debug(void){
    PFNGLDEBUGMESSAGECALLBACKKHRPROC pglDebugMessageCallbackKHR =
        (PFNGLDEBUGMESSAGECALLBACKKHRPROC)
        eglGetProcAddress("glDebugMessageCallbackKHR");

    PFNGLDEBUGMESSAGECONTROLKHRPROC pglDebugMessageControlKHR =
        (PFNGLDEBUGMESSAGECONTROLKHRPROC)
        eglGetProcAddress("glDebugMessageControlKHR");

    if (!pglDebugMessageCallbackKHR || !pglDebugMessageControlKHR) {
        fprintf(stderr, "GL_KHR_debug seems not available for the ctx\n");
        return;
    }

    glEnable(GL_DEBUG_OUTPUT_KHR);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS_KHR);

    pglDebugMessageControlKHR(GL_DONT_CARE,
                              GL_DONT_CARE,
                              GL_DONT_CARE,
                              0, NULL,
                              GL_TRUE);

    pglDebugMessageCallbackKHR(cb_gles_debug, NULL);
    fprintf(stderr, "debug message init.\n");
}


/* pBuffer context */
CWGL_API cwgl_ctx*
cwgl_init_offscreen0(void){
    EGLBoolean b;
    EGLint major, minor;
    EGLDisplay disp;
    major = minor = 0;
    cwgl_ctx* ctx;

    ctx = malloc(sizeof(cwgl_ctx));
    if(! ctx){
        return 0;
    }

    disp = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if(disp == EGL_NO_DISPLAY){
        xabort("no display");
    }
    b = eglInitialize(disp, &major, &minor);
    if(! b){
        xabort("Failed to initialize EGL");
    }
    b = eglBindAPI(EGL_OPENGL_ES_API);
    if(! b){
        xabort("No GLES API");
    }

    ctx->egl_disp = disp;
    ctx->egl_ctx = EGL_NO_CONTEXT;

    init_egl_debug();
    init_gles_debug();

    return ctx;
}

CWGL_API cwgl_surface*
cwgl_surface_create(cwgl_ctx* ctx,
                    int32_t width, int32_t height,
                    uint32_t flags){
    EGLBoolean b;
    cwgl_surface* s;


    // Init
    const EGLint cfgattr[] = {
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
        EGL_DEPTH_SIZE, 24,
        EGL_STENCIL_SIZE, 8,
        EGL_NONE
    };

    EGLConfig config = 0;
    EGLint num_configs = 0;

    s = malloc(sizeof(cwgl_surface));
    if(!s){
        xabort("nomem");
    }

    b = eglChooseConfig(ctx->egl_disp,
                        cfgattr, &config, 1, &num_configs);
    if(! b){
        xabort("noconfig");
    }

    const EGLint cattr[] = {
        EGL_CONTEXT_CLIENT_VERSION, 3,
        /* FIXME: Make it controllable */
        EGL_CONTEXT_FLAGS_KHR, EGL_CONTEXT_OPENGL_DEBUG_BIT_KHR,
        EGL_NONE
    };

    if(ctx->egl_ctx == EGL_NO_CONTEXT){
        // Create context as well
        ctx->egl_ctx = eglCreateContext(ctx->egl_disp,
                                        config,
                                        EGL_NO_CONTEXT,
                                        cattr);
        if(ctx->egl_ctx == EGL_NO_CONTEXT){
            xabort("Failed to create context");
        }
    }

    const EGLint sattr[] = {
        EGL_WIDTH, width,
        EGL_HEIGHT, height,
        EGL_NONE
    };


    s->egl_surf = eglCreatePbufferSurface(ctx->egl_disp,
                                          config,
                                          sattr);
    if(s->egl_surf == EGL_NO_SURFACE){
        xabort("Failed to create pbuffer surface");
    }


    return s;
}

CWGL_API void
cwgl_surface_release(cwgl_ctx* ctx, cwgl_surface* s){
    free(s);
}

CWGL_API void
cwgl_surface_set(cwgl_ctx* ctx, cwgl_surface* s){
    EGLBoolean b;
    b = eglMakeCurrent(ctx->egl_disp,
                       ctx->egl_surf,
                       ctx->egl_surf,
                       ctx->egl_ctx);
    if(! b){
        xabort("Failed to set current context");
    }
}

#endif

