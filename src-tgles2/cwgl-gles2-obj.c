#include "cwgl-backend-gles2-priv.h"

#include <stdlib.h>
#include <stdio.h>

int 
cwgl_backend_ctx_init(cwgl_ctx* ctx){
    cwgl_backend_ctx* c;
    c = malloc(sizeof(cwgl_backend_ctx));
    ctx->backend = c;
    return 0;
}

int 
cwgl_backend_Buffer_init(cwgl_ctx* ctx, cwgl_Buffer* buffer){
    GLuint name;
    cwgl_backend_Buffer* b;
    b = malloc(sizeof(cwgl_backend_Buffer));
    if(b){
        glGenBuffers(1, &name);
        b->name = name;
    }
    buffer->backend = b;
    return 0;
}
int 
cwgl_backend_Shader_init(cwgl_ctx* ctx, cwgl_Shader* shader){
    GLuint name;
    cwgl_backend_Shader* s;
    s = malloc(sizeof(cwgl_backend_Shader));
    if(s){
        if(shader->state.SHADER_TYPE == VERTEX_SHADER){
            name = glCreateShader(GL_VERTEX_SHADER);
        }else{
            name = glCreateShader(GL_FRAGMENT_SHADER);
        }
        s->name = name;
    }
    shader->backend = s;
    return 0;
}
int 
cwgl_backend_Program_init(cwgl_ctx* ctx, cwgl_Program* program){
    GLuint name;
    cwgl_backend_Program* p;
    p = malloc(sizeof(cwgl_backend_Program));
    if(p){
        name = glCreateProgram();
        p->name = name;
        p->attached_vs = 0;
        p->attached_fs = 0;
    }
    program->backend = p;
    return 0;
}
int 
cwgl_backend_Texture_init(cwgl_ctx* ctx, cwgl_Texture* texture){
    GLuint name;
    cwgl_backend_Texture* t;
    t = malloc(sizeof(cwgl_backend_Texture));
    if(t){
        glGenTextures(1, &name);
        t->name = name;
    }
    texture->backend = t;
    return 0;
}
int 
cwgl_backend_Renderbuffer_init(cwgl_ctx* ctx, 
                               cwgl_Renderbuffer* renderbuffer){
    GLuint name;
    cwgl_backend_Renderbuffer* r;
    r = malloc(sizeof(cwgl_backend_Renderbuffer));
    if(r){
        glGenRenderbuffers(1, &name);
        r->name = name;
    }
    renderbuffer->backend = r;
    return 0;
}
int 
cwgl_backend_Framebuffer_init(cwgl_ctx* ctx, 
                              cwgl_Framebuffer* framebuffer){
    GLuint name;
    cwgl_backend_Framebuffer* f;
    f = malloc(sizeof(cwgl_backend_Framebuffer));
    if(f){
        glGenFramebuffers(1, &name);
        f->name = name;
    }
    framebuffer->backend = f;
    return 0;
}

int 
cwgl_backend_ctx_release(cwgl_ctx* ctx){
    free(ctx->backend);
    ctx->backend = NULL;
    return 0;
}
int 
cwgl_backend_Buffer_release(cwgl_ctx* ctx, cwgl_Buffer* buffer){
    glDeleteBuffers(1, &buffer->backend->name);
    free(buffer->backend);
    buffer->backend = NULL;
    return 0;
}
int 
cwgl_backend_Shader_release(cwgl_ctx* ctx, cwgl_Shader* shader){
    glDeleteShader(shader->backend->name);
    free(shader->backend);
    shader->backend = NULL;
    return 0;
}
int 
cwgl_backend_Program_release(cwgl_ctx* ctx, cwgl_Program* program){
    glDeleteProgram(program->backend->name);
    free(program->backend);
    program->backend = NULL;
    return 0;
}
int 
cwgl_backend_Texture_release(cwgl_ctx* ctx, cwgl_Texture* texture){
    glDeleteTextures(1, &texture->backend->name);
    free(texture->backend);
    texture->backend = NULL;
    return 0;
}
int 
cwgl_backend_Renderbuffer_release(cwgl_ctx* ctx, 
                                  cwgl_Renderbuffer* renderbuffer){
    glDeleteRenderbuffers(1, &renderbuffer->backend->name);
    free(renderbuffer->backend);
    renderbuffer->backend = NULL;
    return 0;
}
int 
cwgl_backend_Framebuffer_release(cwgl_ctx* ctx, 
                                 cwgl_Framebuffer* framebuffer){
    glDeleteFramebuffers(1, &framebuffer->backend->name);
    free(framebuffer->backend);
    framebuffer->backend = NULL;
    return 0;
}

