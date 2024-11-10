#include "cwgl-gles2-priv.h"
#include <stdlib.h>
#include <string.h>

// 2.5 GL Errors
CWGL_API cwgl_enum
cwgl_getError(cwgl_ctx* ctx){
    cwgl_enum r;
    CTX_ENTER(ctx);
    r = (cwgl_enum)glGetError();
    CTX_LEAVE(ctx);
    return r;
}

// 2.7 Current Vertex State
CWGL_API void 
cwgl_vertexAttrib1f(cwgl_ctx* ctx, uint32_t indx, float x){
    CTX_ENTER(ctx);
    glVertexAttrib1f(indx, x);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_vertexAttrib2f(cwgl_ctx* ctx, uint32_t indx, float x, float y){
    CTX_ENTER(ctx);
    glVertexAttrib2f(indx, x, y);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_vertexAttrib3f(cwgl_ctx* ctx, uint32_t indx, float x, float y, float z){
    CTX_ENTER(ctx);
    glVertexAttrib3f(indx, x, y, z);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_vertexAttrib4f(cwgl_ctx* ctx, uint32_t indx, 
                    float x, float y, float z, float w){
    CTX_ENTER(ctx);
    glVertexAttrib4f(indx, x, y, z, w);
    CTX_LEAVE(ctx);
}

#ifdef CWGL_LEVEL_L2
CWGL_API void 
cwgl_vertexAttribI4i(cwgl_ctx* ctx, uint32_t indx, int32_t x, int32_t y, 
                    int32_t z, int32_t w){
    CTX_ENTER(ctx);
    glVertexAttribI4i(indx, x, y, z, w);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_vertexAttribI4ui(cwgl_ctx* ctx, uint32_t indx, uint32_t x, uint32_t y, 
                     uint32_t z, uint32_t w){

    CTX_ENTER(ctx);
    glVertexAttribI4ui(indx, x, y, z, w);
    CTX_LEAVE(ctx);
}
#endif

// 2.8 Vertex Arrays
CWGL_API void 
cwgl_vertexAttribPointer(cwgl_ctx* ctx, uint32_t indx, 
                         int32_t size, cwgl_enum type, int normalized, 
                         uint32_t stride, uint32_t offset){
    CTX_ENTER(ctx);
    // FIXME: Check we're binding some array buffer now
    //        https://www.khronos.org/registry/webgl/specs/latest/1.0/#6.2
    glVertexAttribPointer(indx, size, type, normalized,
                          stride, (void*)(uintptr_t)offset);
    CTX_LEAVE(ctx);
}

#ifdef CWGL_LEVEL_L2
CWGL_API void 
cwgl_vertexAttribIPointer(cwgl_ctx* ctx, uint32_t indx, int32_t size, 
                          cwgl_enum type, uint32_t stride, uint32_t offset){
    CTX_ENTER(ctx);
    glVertexAttribIPointer(indx, size, type, stride, (void*)(uintptr_t)offset);
    CTX_LEAVE(ctx);
}
#endif

CWGL_API void 
cwgl_enableVertexAttribArray(cwgl_ctx* ctx, uint32_t index){
    CTX_ENTER(ctx);
    glEnableVertexAttribArray(index);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_disableVertexAttribArray(cwgl_ctx* ctx, uint32_t index){
    CTX_ENTER(ctx);
    glDisableVertexAttribArray(index);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_drawArrays(cwgl_ctx* ctx, cwgl_enum mode, 
                int32_t first, uint32_t count){
    CTX_ENTER(ctx);
    glDrawArrays(mode, first, count);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_drawElements(cwgl_ctx* ctx, cwgl_enum mode, 
                  uint32_t count, cwgl_enum type, uint32_t offset){
    CTX_ENTER(ctx);
    // FIXME: Check we're binding some array buffer now
    //        https://www.khronos.org/registry/webgl/specs/latest/1.0/#6.2
    glDrawElements(mode, count, type, (void*)(uintptr_t)offset);
    CTX_LEAVE(ctx);
}

#ifdef CWGL_LEVEL_L2
CWGL_API void 
cwgl_vertexAttribDivisor(cwgl_ctx* ctx, uint32_t index, uint32_t divisor){
    CTX_ENTER(ctx);
    glVertexAttribDivisor(index, divisor);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_drawArraysInstanced(cwgl_ctx* ctx, cwgl_enum mode, int32_t first, 
                         uint32_t count, uint32_t instancecount){
    CTX_ENTER(ctx);
    glDrawArraysInstanced(mode, first, count, instancecount);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_drawElementsInstanced(cwgl_ctx* ctx, cwgl_enum mode, uint32_t count, 
                           cwgl_enum type, uint32_t offset, 
                           uint32_t instancecount){
    CTX_ENTER(ctx);
    glDrawElementsInstanced(mode, count, type, (void*)(uintptr_t)offset, 
                            instancecount);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_drawRangeElements(cwgl_ctx* ctx, cwgl_enum mode, uint32_t start, 
                       uint32_t end, uint32_t count, cwgl_enum type, 
                       uint32_t offset){
    CTX_ENTER(ctx);
    glDrawRangeElements(mode, start, end, count, type,
                        (void*)(uintptr_t)offset);
    CTX_LEAVE(ctx);
}
#endif


// 2.9 Buffer Objects
CWGL_API void 
cwgl_bindBuffer(cwgl_ctx* ctx, cwgl_enum target, cwgl_Buffer* buffer){
    GLuint name;
    CTX_ENTER(ctx);
    if(buffer){
        name = CTX_GETNAME(ctx, buffer);
    }else{
        name = 0;
    }
    glBindBuffer(target, name);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_deleteBuffer(cwgl_ctx* ctx, cwgl_Buffer* buffer){
    GLuint name;
    CTX_ENTER(ctx);
    if(buffer){
        name = CTX_GETNAME(ctx, buffer);
        glDeleteBuffers(1, &name);
    }
    CTX_LEAVE(ctx);
}

CWGL_API cwgl_Buffer* 
cwgl_createBuffer(cwgl_ctx* ctx){
    GLuint name = 0;
    cwgl_Buffer* b;
    CTX_ENTER(ctx);
    glGenBuffers(1, &name);
    b = CTX_ALLOC(ctx, Buffer);
    CTX_SETNAME(ctx, b, name);
    CTX_LEAVE(ctx);
    return b;
}

CWGL_API void
cwgl_Buffer_release(cwgl_ctx* ctx, cwgl_Buffer* buffer){
    //CTX_ENTER(ctx);
    if(buffer){
        CTX_FREE(ctx, Buffer, buffer);
    }
    //CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_bufferData(cwgl_ctx* ctx, cwgl_enum target, 
                uint32_t size, void* data, cwgl_enum usage){
    CTX_ENTER(ctx);
    glBufferData(target, size, data, usage);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_bufferSubData(cwgl_ctx* ctx, cwgl_enum target, 
                   uint32_t offset, void* data, size_t buflen){
    CTX_ENTER(ctx);
    glBufferSubData(target, offset, buflen, data);
    CTX_LEAVE(ctx);
}

#ifdef CWGL_LEVEL_L2
CWGL_API void 
cwgl_copyBufferSubData(cwgl_ctx* ctx, cwgl_enum readtarget, 
                       cwgl_enum writetarget, uint32_t readoffset, 
                       uint32_t writeoffset, uint32_t size){
}

CWGL_API void 
cwgl_getBufferSubData(cwgl_ctx* ctx, cwgl_enum target, uint32_t srcoffset, 
                      void* out, size_t length){
    void* p;
    CTX_ENTER(ctx);
    p = glMapBufferRange(target, srcoffset, length, GL_MAP_READ_BIT);
    if(! p){
        abort();
    }
    memcpy(out, p, length);
    (void)glUnmapBuffer(target);
    CTX_LEAVE(ctx);
}
#endif

// 2.10.1 Loading and Creating Shader Source
CWGL_API cwgl_Shader* 
cwgl_createShader(cwgl_ctx* ctx, cwgl_enum type){
    GLuint name;
    cwgl_Shader* r;
    CTX_ENTER(ctx);
    name = glCreateShader(type);
    if(name){
        r = CTX_ALLOC(ctx, Shader);
        CTX_SETNAME(ctx, r, name);
    }else{
        r = NULL;
    }
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API void
cwgl_Shader_release(cwgl_ctx* ctx, cwgl_Shader* shader){
    //CTX_ENTER(ctx);
    if(shader){
        CTX_FREE(ctx, Shader, shader);
    }
    //CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_shaderSource(cwgl_ctx* ctx, cwgl_Shader* shader, const char* source,
                  size_t sourcelen){
    GLuint name;
    const GLint len = sourcelen;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, shader);
    glShaderSource(name, 1, &source, &len);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_compileShader(cwgl_ctx* ctx, cwgl_Shader* shader){
    GLuint name;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, shader);
    glCompileShader(name);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_deleteShader(cwgl_ctx* ctx, cwgl_Shader* shader){
    GLuint name;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, shader);
    glDeleteShader(name);
    CTX_LEAVE(ctx);
}

// 2.10.3 Program Objects
CWGL_API cwgl_Program* 
cwgl_createProgram(cwgl_ctx* ctx){
    GLuint name;
    cwgl_Program* r;
    CTX_ENTER(ctx);
    name = glCreateProgram();
    if(name){
        r = CTX_ALLOC(ctx, Program);
        CTX_SETNAME(ctx, r, name);
    }else{
        r = NULL;
    }
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API void
cwgl_Program_release(cwgl_ctx* ctx, cwgl_Program* program){
    //CTX_ENTER(ctx);
    if(program){
        CTX_FREE(ctx, Program, program);
    }
    //CTX_LEAVE(ctx);
}


CWGL_API void 
cwgl_attachShader(cwgl_ctx* ctx, cwgl_Program* program, 
                  cwgl_Shader* shader){
    GLuint namep;
    GLuint names;
    CTX_ENTER(ctx);
    namep = CTX_GETNAME(ctx, program);
    names = CTX_GETNAME(ctx, shader);
    glAttachShader(namep,names);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_detachShader(cwgl_ctx* ctx, cwgl_Program* program, 
                  cwgl_Shader* shader){
    GLuint namep;
    GLuint names;
    CTX_ENTER(ctx);
    namep = CTX_GETNAME(ctx, program);
    names = CTX_GETNAME(ctx, shader);
    glDetachShader(namep,names);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_linkProgram(cwgl_ctx* ctx, cwgl_Program* program){
    GLuint name;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, program);
    glLinkProgram(name);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_useProgram(cwgl_ctx* ctx, cwgl_Program* program){
    GLuint name;
    CTX_ENTER(ctx);
    if(program){
        name = CTX_GETNAME(ctx, program);
        glUseProgram(name);
    }else{
        glUseProgram(0);
    }
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_deleteProgram(cwgl_ctx* ctx, cwgl_Program* program){
    GLuint name;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, program);
    glDeleteProgram(name);
    CTX_LEAVE(ctx);
}

// 2.10.4 Shader Variables
CWGL_API cwgl_query_result
cwgl_getActiveAttrib(cwgl_ctx* ctx, cwgl_Program* program, 
                     int32_t index, int32_t* out_size, 
                     int32_t* type, cwgl_string** name){
    GLuint tname;
    GLsizei length;
    GLint tsize;
    GLenum ttype;
    GLenum e;
    char namebuf[1024];
    CTX_ENTER(ctx);
    tname = CTX_GETNAME(ctx, program);
    while(glGetError()){}
    glGetActiveAttrib(tname, index, 1024, &length, &tsize, &ttype, namebuf);
    e = glGetError();
    if(e){
        return CWGL_QR_GLERROR;
    }
    *out_size = tsize;
    *type = ttype;
    *name = cwgl_priv_alloc_string(ctx, namebuf, length);
    CTX_LEAVE(ctx);
    // FIXME: Implement this
    return CWGL_QR_SUCCESS;
}

CWGL_API int32_t 
cwgl_getAttribLocation(cwgl_ctx* ctx, cwgl_Program* program, 
                       const char* name){
    GLuint namep;
    int32_t r;
    CTX_ENTER(ctx);
    namep = CTX_GETNAME(ctx, program);
    r = glGetAttribLocation(namep, name);
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API void 
cwgl_bindAttribLocation(cwgl_ctx* ctx, cwgl_Program* program, 
                        uint32_t index, const char* name){
    GLuint namep;
    CTX_ENTER(ctx);
    namep = CTX_GETNAME(ctx, program);
    glBindAttribLocation(namep, index, name);
    CTX_LEAVE(ctx);
}

CWGL_API cwgl_UniformLocation* 
cwgl_getUniformLocation(cwgl_ctx* ctx, cwgl_Program* program, 
                        const char* name){
    GLint nameu;
    GLuint namep;
    cwgl_UniformLocation* r;
    CTX_ENTER(ctx);
    namep = CTX_GETNAME(ctx, program);
    nameu = glGetUniformLocation(namep, name);
    if(nameu == -1){
        r = NULL;
    }else{
        r = CTX_ALLOC(ctx, UniformLocation);
        CTX_SETNAME(ctx, r, nameu);
    }
    CTX_LEAVE(ctx);
    return r;
}

CWGL_API void
cwgl_UniformLocation_release(cwgl_ctx* ctx, cwgl_UniformLocation* u){
    //CTX_ENTER(ctx);
    if(u){
        CTX_FREE(ctx, UniformLocation, u);
    }
    //CTX_LEAVE(ctx);
}

CWGL_API cwgl_query_result 
cwgl_getActiveUniform(cwgl_ctx* ctx, cwgl_Program* program, 
                      int32_t index, int32_t* out_size, int32_t* out_type, 
                      cwgl_string** name){
    cwgl_string* r;
    char namebuf[320]; // In WebGL, it should be <256
    GLuint namep;
    GLint size = 0;
    GLenum type = 0;
    GLsizei namelength = 0;
    CTX_ENTER(ctx);
    namep = CTX_GETNAME(ctx, program);
    glGetActiveUniform(namep, index, sizeof(namebuf), &namelength,
                       &size, &type, namebuf);
    r = cwgl_priv_alloc_string(ctx, namebuf, namelength + 1);
    *out_size = size;
    *out_type = type;
    *name = r;
    CTX_LEAVE(ctx);
    return CWGL_QR_SUCCESS;
}

CWGL_API void 
cwgl_uniform1f(cwgl_ctx* ctx, cwgl_UniformLocation* location, float x){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform1f(loc, x);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform1i(cwgl_ctx* ctx, cwgl_UniformLocation* location, int32_t x){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform1i(loc, x);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform2f(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
               float x, float y){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform2f(loc, x, y);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform2i(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
               int32_t x, int32_t y){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform2i(loc, x, y);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform3f(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
               float x, float y, float z){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform3f(loc, x, y, z);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform3i(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
               int32_t x, int32_t y, int32_t z){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform3i(loc, x, y, z);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform4f(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
               float x, float y, float z, float w){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform4f(loc, x, y, z, w);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform4i(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
               int32_t x, int32_t y, int32_t z, int32_t w){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform4i(loc, x, y, z, w);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform1fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                float* values, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform1fv(loc, count, values);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform1iv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                int32_t* values, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform1iv(loc, count, values);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform2fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                float* values, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform2fv(loc, count, values);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform2iv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                int32_t* values, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform2iv(loc, count, values);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform3fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                float* values, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform3fv(loc, count, values);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform3iv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                int32_t* values, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform3iv(loc, count, values);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform4fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                float* values, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform4fv(loc, count, values);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform4iv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                int32_t* values, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform4iv(loc, count, values);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniformMatrix2fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                      int transpose, float* value, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniformMatrix2fv(loc, count, transpose, value);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniformMatrix3fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                      int transpose, float* value, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniformMatrix3fv(loc, count, transpose, value);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniformMatrix4fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                      int transpose, float* value, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniformMatrix4fv(loc, count, transpose, value);
    CTX_LEAVE(ctx);
}

#ifdef CWGL_LEVEL_L2
CWGL_API void 
cwgl_uniform1ui(cwgl_ctx* ctx, cwgl_UniformLocation* location, uint32_t x){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform1ui(loc, x);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform2ui(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                uint32_t x, uint32_t y){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform2ui(loc, x, y);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform3ui(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                uint32_t x, uint32_t y, uint32_t z){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform3ui(loc, x, y, z);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform4ui(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                uint32_t x, uint32_t y, uint32_t z, uint32_t w){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform4ui(loc, x, y, z, w);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform1uiv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                 uint32_t* values, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform1uiv(loc, count, values);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform2uiv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                 uint32_t* values, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform2uiv(loc, count, values);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform3uiv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                 uint32_t* values, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform3uiv(loc, count, values);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniform4uiv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                 uint32_t* values, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniform4uiv(loc, count, values);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniformMatrix2x3fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                      int transpose, float* value, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniformMatrix2x3fv(loc, count, transpose, value);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniformMatrix2x4fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                      int transpose, float* value, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniformMatrix2x4fv(loc, count, transpose, value);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniformMatrix3x2fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                      int transpose, float* value, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniformMatrix3x2fv(loc, count, transpose, value);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniformMatrix3x4fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                      int transpose, float* value, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniformMatrix3x4fv(loc, count, transpose, value);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniformMatrix4x2fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                      int transpose, float* value, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniformMatrix4x2fv(loc, count, transpose, value);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_uniformMatrix4x3fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, 
                      int transpose, float* value, size_t count){
    GLint loc;
    CTX_ENTER(ctx);
    loc = CTX_GETNAME(ctx, location);
    glUniformMatrix4x3fv(loc, count, transpose, value);
    CTX_LEAVE(ctx);
}
#endif

// 2.10.5 Shader Execution
CWGL_API void 
cwgl_validateProgram(cwgl_ctx* ctx, cwgl_Program* program){
    GLuint namep;
    CTX_ENTER(ctx);
    namep = CTX_GETNAME(ctx, program);
    glValidateProgram(namep);
    CTX_LEAVE(ctx);
}

#ifdef CWGL_LEVEL_L2
CWGL_API int32_t cwgl_getFragDataLocation(cwgl_ctx* ctx, cwgl_Program* program,
                                          const char* name){
    GLuint pname;
    GLint res;
    CTX_ENTER(ctx);
    pname = CTX_GETNAME(ctx, program);
    res = glGetFragDataLocation(pname, name);
    CTX_LEAVE(ctx);
    return res;
}
#endif

// 2.12.1 Controlling the Viewport
CWGL_API void 
cwgl_depthRange(cwgl_ctx* ctx, float zNear, float zFar){
    CTX_ENTER(ctx);
    glDepthRangef(zNear, zFar);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_viewport(cwgl_ctx* ctx, 
              int32_t x, int32_t y, int32_t width, int32_t height){
    CTX_ENTER(ctx);
    glViewport(x, y, width, height);
    CTX_LEAVE(ctx);
}

