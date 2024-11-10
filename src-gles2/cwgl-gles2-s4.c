#include "cwgl-gles2-priv.h"

// 4.1.2 Scissor Test
CWGL_API void
cwgl_scissor(cwgl_ctx* ctx, 
             int32_t x, int32_t y, uint32_t width, uint32_t height){
    CTX_ENTER(ctx);
    glScissor(x, y, width, height);
    CTX_LEAVE(ctx);
}

// 4.1.3 Multisample Fragment Operations
CWGL_API void 
cwgl_sampleCoverage(cwgl_ctx* ctx, float value, int invert){
    CTX_ENTER(ctx);
    glSampleCoverage(value, invert);
    CTX_LEAVE(ctx);
}

// 4.1.4 Stencil Test
CWGL_API void 
cwgl_stencilFunc(cwgl_ctx* ctx, 
                 cwgl_enum func, int32_t ref, uint32_t mask){
    CTX_ENTER(ctx);
    glStencilFunc(func, ref, mask);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_stencilFuncSeparate(cwgl_ctx* ctx, 
                         cwgl_enum face, cwgl_enum func, 
                         int32_t ref, uint32_t mask){
    CTX_ENTER(ctx);
    glStencilFuncSeparate(face, func, ref, mask);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_stencilOp(cwgl_ctx* ctx, 
               cwgl_enum fail, cwgl_enum zfail, cwgl_enum zpass){
    CTX_ENTER(ctx);
    glStencilOp(fail, zfail, zpass);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_stencilOpSeparate(cwgl_ctx* ctx,
                       cwgl_enum face, cwgl_enum fail, 
                       cwgl_enum zfail, cwgl_enum zpass){
    CTX_ENTER(ctx);
    glStencilOpSeparate(face, fail, zfail, zpass);
    CTX_LEAVE(ctx);
}

// 4.1.5 Depth Buffer Test
CWGL_API void 
cwgl_depthFunc(cwgl_ctx* ctx, cwgl_enum func){
    CTX_ENTER(ctx);
    glDepthFunc(func);
    CTX_LEAVE(ctx);
}

// 4.1.6 Blending
CWGL_API void 
cwgl_blendEquation(cwgl_ctx* ctx, cwgl_enum mode){
    CTX_ENTER(ctx);
    glBlendEquation(mode);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_blendEquationSeparate(cwgl_ctx* ctx,
                           cwgl_enum modeRGB, cwgl_enum modeAlpha){
    CTX_ENTER(ctx);
    glBlendEquationSeparate(modeRGB, modeAlpha);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_blendFuncSeparate(cwgl_ctx* ctx, cwgl_enum srcRGB, cwgl_enum dstRGB, cwgl_enum srcAlpha, cwgl_enum dstAlpha){
    CTX_ENTER(ctx);
    glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_blendFunc(cwgl_ctx* ctx, cwgl_enum sfactor, cwgl_enum dfactor){
    CTX_ENTER(ctx);
    glBlendFunc(sfactor, dfactor);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_blendColor(cwgl_ctx* ctx, 
                float red, float green, float blue, float alpha){
    CTX_ENTER(ctx);
    glBlendColor(red, green, blue, alpha);
    CTX_LEAVE(ctx);
}

// 4.2.2 Fine Control of Buffer Updates
CWGL_API void 
cwgl_colorMask(cwgl_ctx* ctx, int red, int green, int blue, int alpha){
    CTX_ENTER(ctx);
    glColorMask(red, green, blue, alpha);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_depthMask(cwgl_ctx* ctx, int flag){
    CTX_ENTER(ctx);
    glDepthMask(flag);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_stencilMask(cwgl_ctx* ctx, uint32_t mask){
    CTX_ENTER(ctx);
    glStencilMask(mask);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_stencilMaskSeparate(cwgl_ctx* ctx, cwgl_enum face, uint32_t mask){
    CTX_ENTER(ctx);
    glStencilMaskSeparate(face, mask);
    CTX_LEAVE(ctx);
}


// 4.2.3 Clearing the Buffers
CWGL_API void 
cwgl_clear(cwgl_ctx* ctx, uint32_t mask){
    CTX_ENTER(ctx);
    glClear(mask);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_clearColor(cwgl_ctx* ctx, 
                float red, float green, float blue, float alpha){
    CTX_ENTER(ctx);
    glClearColor(red, green, blue, alpha);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_clearDepth(cwgl_ctx* ctx, float depth){
    CTX_ENTER(ctx);
    glClearDepthf(depth);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_clearStencil(cwgl_ctx* ctx, int32_t s){
    CTX_ENTER(ctx);
    glClearStencil(s);
    CTX_LEAVE(ctx);
}

#ifdef CWGL_LEVEL_L2
CWGL_API void 
cwgl_drawBuffers(cwgl_ctx* ctx, cwgl_enum* buffers, size_t count){
    CTX_ENTER(ctx);
    glDrawBuffers(count, buffers);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_clearBufferiv(cwgl_ctx* ctx, cwgl_enum buffer, int32_t drawbuffer, 
                   const int32_t* value, size_t count){
    CTX_ENTER(ctx);
    glClearBufferiv(buffer, drawbuffer, value);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_clearBufferuiv(cwgl_ctx* ctx, cwgl_enum buffer, int32_t drawbuffer, 
                    const uint32_t* value, size_t count){
    CTX_ENTER(ctx);
    glClearBufferuiv(buffer, drawbuffer, value);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_clearBufferfv(cwgl_ctx* ctx, cwgl_enum buffer, int32_t drawbuffer, 
                   const float* value, size_t count){
    CTX_ENTER(ctx);
    glClearBufferfv(buffer, drawbuffer, value);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_clearBufferfi(cwgl_ctx* ctx, cwgl_enum buffer, int32_t drawbuffer, float depth, int32_t stencil){
    CTX_ENTER(ctx);
    glClearBufferfi(buffer, drawbuffer, depth, stencil);
    CTX_LEAVE(ctx);
}
#endif

// 4.3.1 Reading Pixels
CWGL_API void 
cwgl_readPixels(cwgl_ctx* ctx, int32_t x, int32_t y, uint32_t width, uint32_t height, cwgl_enum format, cwgl_enum type, void* buf, size_t buflen){
    CTX_ENTER(ctx);
    glReadPixels(x, y, width, height, format, type, buf);
    CTX_LEAVE(ctx);
}

// 4.4.1 Binding and Managing Framebuffer Objects
CWGL_API void 
cwgl_bindFramebuffer(cwgl_ctx* ctx, 
                     cwgl_enum target, cwgl_Framebuffer* framebuffer){
    GLuint name;
    CTX_ENTER(ctx);
    if(framebuffer){
        name = CTX_GETNAME(ctx, framebuffer);
    }else{
        name = 0;
    }
    glBindFramebuffer(target, name);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_deleteFramebuffer(cwgl_ctx* ctx, cwgl_Framebuffer* framebuffer){
    GLuint name;
    CTX_ENTER(ctx);
    if(framebuffer){
        name = CTX_GETNAME(ctx, framebuffer);
        glDeleteFramebuffers(1, &name);
    }
    CTX_LEAVE(ctx);
}

CWGL_API cwgl_Framebuffer* 
cwgl_createFramebuffer(cwgl_ctx* ctx){
    GLuint name;
    cwgl_Framebuffer* f;
    CTX_ENTER(ctx);
    glGenFramebuffers(1, &name);
    f = CTX_ALLOC(ctx, Framebuffer);
    CTX_SETNAME(ctx, f, name);
    CTX_LEAVE(ctx);
    return f;
}

CWGL_API void
cwgl_Framebuffer_release(cwgl_ctx* ctx, cwgl_Framebuffer* framebuffer){
    //CTX_ENTER(ctx);
    if(framebuffer){
        CTX_FREE(ctx, Framebuffer, framebuffer);
    }
    //CTX_LEAVE(ctx);
}

#ifdef CWGL_LEVEL_L2
CWGL_API void 
cwgl_blitFramebuffer(cwgl_ctx* ctx, int32_t srcx0, int32_t srcy0, 
                     int32_t srcx1, int32_t srcy1, int32_t dstx0, 
                     int32_t dsty0, int32_t dstx1, int32_t dsty1, 
                     uint32_t mask, cwgl_enum filter){
    CTX_ENTER(ctx);
    glBlitFramebuffer(srcx0, srcy0, srcx1, srcy1, dstx0, dsty0, dstx1, dsty1,
                      mask, filter);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_framebufferTextureLayer(cwgl_ctx* ctx, cwgl_enum target, 
                             cwgl_enum attachment, cwgl_Texture* texture, 
                             int32_t level, int32_t layer){
    GLuint name;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, texture);
    glFramebufferTextureLayer(target, attachment, name, level, layer);
    CTX_LEAVE(ctx);
}

CWGL_API void cwgl_invalidateFramebuffer(cwgl_ctx* ctx, cwgl_enum target, 
                                         cwgl_enum* attachments, size_t count){
    CTX_ENTER(ctx);
    glInvalidateFramebuffer(target, count, attachments);
    CTX_LEAVE(ctx);
}

CWGL_API void cwgl_invalidateSubFramebuffer(cwgl_ctx* ctx, cwgl_enum target, 
                                            cwgl_enum* attachments, 
                                            size_t count, int32_t x, 
                                            int32_t y, uint32_t width, 
                                            uint32_t height){
    CTX_ENTER(ctx);
    glInvalidateSubFramebuffer(target, count, attachments, x, y, width, height);
    CTX_LEAVE(ctx);
}

CWGL_API void cwgl_readBuffer(cwgl_ctx* ctx, cwgl_enum src){
    CTX_ENTER(ctx);
    glReadBuffer(src);
    CTX_LEAVE(ctx);
}
#endif

// 4.4.3 Renderbuffer Objects
CWGL_API void 
cwgl_bindRenderbuffer(cwgl_ctx* ctx, cwgl_enum target, 
                      cwgl_Renderbuffer* renderbuffer){
    GLuint name;
    CTX_ENTER(ctx);
    if(renderbuffer){
        name = CTX_GETNAME(ctx, renderbuffer);
    }else{
        name = 0;
    }
    glBindRenderbuffer(target, name);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_deleteRenderbuffer(cwgl_ctx* ctx, cwgl_Renderbuffer* renderbuffer){
    GLuint name;
    CTX_ENTER(ctx);
    if(renderbuffer){
        name = CTX_GETNAME(ctx, renderbuffer);
        glDeleteRenderbuffers(1, &name);
    }
    CTX_LEAVE(ctx);
}

CWGL_API cwgl_Renderbuffer* 
cwgl_createRenderbuffer(cwgl_ctx* ctx){
    GLuint name = 0;
    cwgl_Renderbuffer* r;
    CTX_ENTER(ctx);
    glGenRenderbuffers(1, &name);
    r = CTX_ALLOC(ctx, Renderbuffer);
    CTX_SETNAME(ctx, r, name);
    CTX_LEAVE(ctx);
    return r;

}

CWGL_API void
cwgl_Renderbuffer_release(cwgl_ctx* ctx, cwgl_Renderbuffer* renderbuffer){
    //CTX_ENTER(ctx);
    if(renderbuffer){
        CTX_FREE(ctx, Renderbuffer, renderbuffer);
    }
    //CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_renderbufferStorage(cwgl_ctx* ctx, 
                         cwgl_enum target, cwgl_enum internalformat, 
                         uint32_t width, uint32_t height){
    CTX_ENTER(ctx);
    glRenderbufferStorage(target, internalformat, width, height);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_framebufferRenderbuffer(cwgl_ctx* ctx, cwgl_enum target, 
                             cwgl_enum attachment, 
                             cwgl_enum renderbuffertarget, 
                             cwgl_Renderbuffer* renderbuffer){
    GLuint name;
    CTX_ENTER(ctx);
    if(renderbuffer){
        name = CTX_GETNAME(ctx, renderbuffer);
    }else{
        name = 0;
    }
    glFramebufferRenderbuffer(target, attachment, renderbuffertarget, name);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_framebufferTexture2D(cwgl_ctx* ctx, cwgl_enum target, 
                          cwgl_enum attachment, cwgl_enum textarget, 
                          cwgl_Texture* texture, int32_t level){
    GLuint name;
    CTX_ENTER(ctx);
    if(texture){
        name = CTX_GETNAME(ctx, texture);
    }else{
        name = 0;
    }
    glFramebufferTexture2D(target, attachment, textarget, name, level);
    CTX_LEAVE(ctx);
}

#ifdef CWGL_LEVEL_L2
CWGL_API void 
cwgl_renderbufferStorageMultisample(cwgl_ctx* ctx, cwgl_enum target, 
                                    uint32_t samples, cwgl_enum internalformat,
                                    uint32_t width, uint32_t height){
    CTX_ENTER(ctx);
    glRenderbufferStorageMultisample(target, samples, internalformat, width,
                                     height);
    CTX_LEAVE(ctx);
}
#endif


// 4.4.5 Framebuffer Completeness
CWGL_API cwgl_enum 
cwgl_checkFramebufferStatus(cwgl_ctx* ctx, cwgl_enum target){
    cwgl_enum e;
    CTX_ENTER(ctx);
    e = glCheckFramebufferStatus(target);
    CTX_LEAVE(ctx);
    return e;
}

