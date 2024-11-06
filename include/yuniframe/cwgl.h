#ifndef __YUNI_CWGL_H
#define __YUNI_CWGL_H

#ifdef __cplusplus
extern "C" {
#endif
// }

#ifdef CWGL_DLL
/* Win32 DLL */
#ifdef CWGL_SHARED_BUILD
#ifdef _WIN32
#define CWGL_API __declspec(dllexport)
#else
#define CWGL_API __attribute__ ((visibility ("default")))
#endif /* _WIN32 */
#else
#ifdef _WIN32
#define CWGL_API __declspec(dllimport)
#else
#define CWGL_API 
#endif /* _WIN32 */
#endif
#else
/* Generic static-library */
#define CWGL_API
#endif

#include <stdint.h>
#include <stddef.h>

/* Context */
struct cwgl_ctx_s;
typedef struct cwgl_ctx_s cwgl_ctx;

#define CWGL_CTX_FLAG_HAS_ALPHA (1<<0)
#define CWGL_CTX_FLAG_HAS_DEPTH (1<<1)
#define CWGL_CTX_FLAG_HAS_STENCIL (1<<2)
#define CWGL_CTX_FLAG_ANTIALIAS (1<<3)
#define CWGL_CTX_FLAG_PREMULTIPLIEDALPHA  (1<<4)
#define CWGL_CTX_FLAG_PRESERVEDRAWINGBUFFER (1<<5)

enum cwgl_query_result_e {
    CWGL_QR_SUCCESS = 0,
    CWGL_QR_GLERROR = 1,
    CWGL_QR_INSUFFICIENT_BUFFER = 2,
    CWGL_QR_UNIMPLEMENTED = 3,

    /* Type queries */
    CWGL_QR_TYPE_BOOL = 0x10,
    /* Short vectors */
    CWGL_QR_TYPE_I1 = 0x11,
    CWGL_QR_TYPE_I2 = 0x12,
    CWGL_QR_TYPE_I3 = 0x13,
    CWGL_QR_TYPE_I4 = 0x14,
    CWGL_QR_TYPE_F1 = 0x15,
    CWGL_QR_TYPE_F2 = 0x16,
    CWGL_QR_TYPE_F3 = 0x17,
    CWGL_QR_TYPE_F4 = 0x18,
    /* Matrix */
    CWGL_QR_TYPE_M2 = 0x22,
    CWGL_QR_TYPE_M3 = 0x23,
    CWGL_QR_TYPE_M4 = 0x24,
    /* Objects */
    CWGL_QR_TYPE_BUFFER = 0x30,
    CWGL_QR_TYPE_SHADER = 0x31,
    CWGL_QR_TYPE_PROGRAM = 0x32,
    CWGL_QR_TYPE_TEXTURE = 0x33,
    CWGL_QR_TYPE_FRAMEBUFFER = 0x34,
    CWGL_QR_TYPE_RENDERBUFFER = 0x35
};
typedef enum cwgl_query_result_e cwgl_query_result;

#ifdef CWGL_DECL_ENUMS
#include "cwgl_enums.h"
#else
enum cwgl_enum_e{
    CWGL_ENUM_DUMMY = 0x7fffffff
};
#endif

typedef enum cwgl_enum_e cwgl_enum;

enum cwgl_bool_e {
    CWGL_FALSE = 0,
    CWGL_TRUE = 1
};

typedef enum cwgl_bool_e cwgl_bool;

/* Heap Objects */
struct cwgl_string_s;
typedef struct cwgl_string_s cwgl_string;
CWGL_API size_t cwgl_string_size(cwgl_ctx* ctx, cwgl_string* str);
CWGL_API cwgl_query_result cwgl_string_read(cwgl_ctx* ctx, cwgl_string* str, char* buf, size_t buflen);
CWGL_API void cwgl_string_release(cwgl_ctx* ctx, cwgl_string* str);

struct cwgl_Buffer_s;
struct cwgl_Shader_s;
struct cwgl_Program_s;
struct cwgl_Texture_s;
struct cwgl_Framebuffer_s;
struct cwgl_Renderbuffer_s;
struct cwgl_VertexArrayObject_s;

typedef struct cwgl_Buffer_s cwgl_Buffer;
typedef struct cwgl_Shader_s cwgl_Shader;
typedef struct cwgl_Program_s cwgl_Program;
typedef struct cwgl_Texture_s cwgl_Texture;
typedef struct cwgl_Framebuffer_s cwgl_Framebuffer;
typedef struct cwgl_Renderbuffer_s cwgl_Renderbuffer;
typedef struct cwgl_VertexArrayObject_s cwgl_VertexArrayObject;

CWGL_API void cwgl_Buffer_release(cwgl_ctx* ctx, cwgl_Buffer* buffer);
CWGL_API void cwgl_Shader_release(cwgl_ctx* ctx, cwgl_Shader* shader);
CWGL_API void cwgl_Program_release(cwgl_ctx* ctx, cwgl_Program* program);
CWGL_API void cwgl_Texture_release(cwgl_ctx* ctx, cwgl_Texture* texture);
CWGL_API void cwgl_Framebuffer_release(cwgl_ctx* ctx, cwgl_Framebuffer* framebuffer);
CWGL_API void cwgl_Renderbuffer_release(cwgl_ctx* ctx, cwgl_Renderbuffer* renderbuffer);
CWGL_API void cwgl_VertexArrayObject_release(cwgl_ctx* ctx, cwgl_VertexArrayObject* vao);

struct cwgl_UniformLocation_s;
typedef struct cwgl_UniformLocation_s cwgl_UniformLocation;
CWGL_API void cwgl_UniformLocation_release(cwgl_ctx* ctx, cwgl_UniformLocation* uniformlocation);

/* Context, Platform */
CWGL_API int32_t cwgl_getContextAttributes(cwgl_ctx* ctx);
CWGL_API int cwgl_isContextLost(cwgl_ctx* ctx);
CWGL_API cwgl_query_result cwgl_getSupportedExtensions(cwgl_ctx* ctx, cwgl_string** str, size_t buflen, size_t* out_reslen);
//object? getExtension(DOMString name);

/* OpenGL State */
CWGL_API void cwgl_disable(cwgl_ctx* ctx, cwgl_enum cap);
CWGL_API void cwgl_enable(cwgl_ctx* ctx, cwgl_enum cap);

// 2.5 GL Errors
CWGL_API cwgl_enum cwgl_getError(cwgl_ctx* ctx);
// 2.7 Current Vertex State
CWGL_API void cwgl_vertexAttrib1f(cwgl_ctx* ctx, uint32_t indx, float x);
CWGL_API void cwgl_vertexAttrib2f(cwgl_ctx* ctx, uint32_t indx, float x, float y);
CWGL_API void cwgl_vertexAttrib3f(cwgl_ctx* ctx, uint32_t indx, float x, float y, float z);
CWGL_API void cwgl_vertexAttrib4f(cwgl_ctx* ctx, uint32_t indx, float x, float y, float z, float w);
// 2.8 Vertex Arrays
CWGL_API void cwgl_vertexAttribPointer(cwgl_ctx* ctx, uint32_t indx, int32_t size, cwgl_enum type, int normalized, uint32_t stride, uint32_t offset);
CWGL_API void cwgl_enableVertexAttribArray(cwgl_ctx* ctx, uint32_t index);
CWGL_API void cwgl_disableVertexAttribArray(cwgl_ctx* ctx, uint32_t index);
CWGL_API void cwgl_drawArrays(cwgl_ctx* ctx, cwgl_enum mode, int32_t first, uint32_t count);
CWGL_API void cwgl_drawElements(cwgl_ctx* ctx, cwgl_enum mode, uint32_t count, cwgl_enum type, uint32_t offset);
// 2.9 Buffer Objects
CWGL_API void cwgl_bindBuffer(cwgl_ctx* ctx, cwgl_enum target, cwgl_Buffer* buffer);
CWGL_API void cwgl_deleteBuffer(cwgl_ctx* ctx, cwgl_Buffer* buffer);
CWGL_API cwgl_Buffer* cwgl_createBuffer(cwgl_ctx* ctx);
CWGL_API void cwgl_bufferData(cwgl_ctx* ctx, cwgl_enum target, uint32_t size, void* data, cwgl_enum usage);
CWGL_API void cwgl_bufferSubData(cwgl_ctx* ctx, cwgl_enum target, uint32_t offset, void* data, size_t buflen);
// 2.10 Vertex shaders
// 2.10.1 Loading and Creating Shader Source
CWGL_API cwgl_Shader* cwgl_createShader(cwgl_ctx* ctx, cwgl_enum type);
CWGL_API void cwgl_shaderSource(cwgl_ctx* ctx, cwgl_Shader* shader, const char* source, size_t sourcelen);
CWGL_API void cwgl_compileShader(cwgl_ctx* ctx, cwgl_Shader* shader);
CWGL_API void cwgl_deleteShader(cwgl_ctx* ctx, cwgl_Shader* shader);
// 2.10.3 Program Objects
CWGL_API cwgl_Program* cwgl_createProgram(cwgl_ctx* ctx);
CWGL_API void cwgl_attachShader(cwgl_ctx* ctx, cwgl_Program* program, cwgl_Shader* shader);
CWGL_API void cwgl_detachShader(cwgl_ctx* ctx, cwgl_Program* program, cwgl_Shader* shader);
CWGL_API void cwgl_linkProgram(cwgl_ctx* ctx, cwgl_Program* program);
CWGL_API void cwgl_useProgram(cwgl_ctx* ctx, cwgl_Program* program);
CWGL_API void cwgl_deleteProgram(cwgl_ctx* ctx, cwgl_Program* program);
// 2.10.4 Shader Variables
CWGL_API cwgl_query_result cwgl_getActiveAttrib(cwgl_ctx* ctx, cwgl_Program* program, int32_t index, int32_t* out_size, int32_t* type, cwgl_string** name);
CWGL_API int32_t cwgl_getAttribLocation(cwgl_ctx* ctx, cwgl_Program* program, const char* name);
CWGL_API void cwgl_bindAttribLocation(cwgl_ctx* ctx, cwgl_Program* program, uint32_t index, const char* name);
CWGL_API cwgl_UniformLocation* cwgl_getUniformLocation(cwgl_ctx* ctx, cwgl_Program* program, const char* name);
CWGL_API cwgl_query_result cwgl_getActiveUniform(cwgl_ctx* ctx, cwgl_Program* program, int32_t index, int32_t* out_size, int32_t* type, cwgl_string** name);
CWGL_API void cwgl_uniform1f(cwgl_ctx* ctx, cwgl_UniformLocation* location, float x);
CWGL_API void cwgl_uniform1i(cwgl_ctx* ctx, cwgl_UniformLocation* location, int32_t x);
CWGL_API void cwgl_uniform2f(cwgl_ctx* ctx, cwgl_UniformLocation* location, float x, float y);
CWGL_API void cwgl_uniform2i(cwgl_ctx* ctx, cwgl_UniformLocation* location, int32_t x, int32_t y);
CWGL_API void cwgl_uniform3f(cwgl_ctx* ctx, cwgl_UniformLocation* location, float x, float y, float z);
CWGL_API void cwgl_uniform3i(cwgl_ctx* ctx, cwgl_UniformLocation* location, int32_t x, int32_t y, int32_t z);
CWGL_API void cwgl_uniform4f(cwgl_ctx* ctx, cwgl_UniformLocation* location, float x, float y, float z, float w);
CWGL_API void cwgl_uniform4i(cwgl_ctx* ctx, cwgl_UniformLocation* location, int32_t x, int32_t y, int32_t z, int32_t w);
CWGL_API void cwgl_uniform1fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, float* values, size_t count);
CWGL_API void cwgl_uniform1iv(cwgl_ctx* ctx, cwgl_UniformLocation* location, int32_t* values, size_t count);
CWGL_API void cwgl_uniform2fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, float* values, size_t count);
CWGL_API void cwgl_uniform2iv(cwgl_ctx* ctx, cwgl_UniformLocation* location, int32_t* values, size_t count);
CWGL_API void cwgl_uniform3fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, float* values, size_t count);
CWGL_API void cwgl_uniform3iv(cwgl_ctx* ctx, cwgl_UniformLocation* location, int32_t* values, size_t count);
CWGL_API void cwgl_uniform4fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, float* values, size_t count);
CWGL_API void cwgl_uniform4iv(cwgl_ctx* ctx, cwgl_UniformLocation* location, int32_t* values, size_t count);
CWGL_API void cwgl_uniformMatrix2fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, int transpose, float* value, size_t count);
CWGL_API void cwgl_uniformMatrix3fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, int transpose, float* value, size_t count);
CWGL_API void cwgl_uniformMatrix4fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, int transpose, float* value, size_t count);
// 2.10.5 Shader Execution
CWGL_API void cwgl_validateProgram(cwgl_ctx* ctx, cwgl_Program* program);
// 2.12.1 Controlling the Viewport
CWGL_API void cwgl_depthRange(cwgl_ctx* ctx, float zNear, float zFar);
CWGL_API void cwgl_viewport(cwgl_ctx* ctx, int32_t x, int32_t y, int32_t width, int32_t height);

// 3.4 Line Segments
CWGL_API void cwgl_lineWidth(cwgl_ctx* ctx, float width);
// 3.5 Polygons
CWGL_API void cwgl_frontFace(cwgl_ctx* ctx, cwgl_enum mode);
CWGL_API void cwgl_cullFace(cwgl_ctx* ctx, cwgl_enum mode);
// 3.5.2 Depth offset
CWGL_API void cwgl_polygonOffset(cwgl_ctx* ctx, float factor, float units);
// 3.6.1 Pixel Storage Modes
CWGL_API void cwgl_pixelStorei(cwgl_ctx* ctx, cwgl_enum pname, int32_t param);
// 3.7 Texturing
CWGL_API void cwgl_activeTexture(cwgl_ctx* ctx, cwgl_enum texture);
// 3.7.1 Texture Image Specification
CWGL_API void cwgl_texImage2D(cwgl_ctx* ctx, cwgl_enum target, int32_t level, cwgl_enum internalformat, uint32_t width, uint32_t height, int32_t border, cwgl_enum format, cwgl_enum type, const void* buf, size_t buflen);
// 3.7.2 Alternate Texture Image Specification Commands
CWGL_API void cwgl_copyTexImage2D(cwgl_ctx* ctx, cwgl_enum target, int32_t level, cwgl_enum internalformat, int32_t x, int32_t y, uint32_t width, uint32_t height, int32_t border);
CWGL_API void cwgl_texSubImage2D(cwgl_ctx* ctx, cwgl_enum target, int32_t level, int32_t xoffset, int32_t yoffset, uint32_t width, uint32_t height, cwgl_enum format, cwgl_enum type, const void* buf, size_t buflen);
CWGL_API void cwgl_copyTexSubImage2D(cwgl_ctx* ctx, cwgl_enum target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t x, int32_t y, uint32_t width, uint32_t height);
// 3.7.3 Compressed Texture Images
CWGL_API void cwgl_compressedTexImage2D(cwgl_ctx* ctx, cwgl_enum target, int32_t level, cwgl_enum internalformat, uint32_t width, uint32_t height, int32_t border, const void* buf, size_t buflen);
CWGL_API void cwgl_compressedTexSubImage2D(cwgl_ctx* ctx, cwgl_enum target, int32_t level, int32_t xoffset, int32_t yoffset, uint32_t width, uint32_t height, cwgl_enum format, const void* buf, size_t buflen);
// 3.7.4 Texture Parameters
CWGL_API void cwgl_texParameterf(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum pname, float param);
CWGL_API void cwgl_texParameteri(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum pname, int32_t param);
// 3.7.11 Mipmap Generation
CWGL_API void cwgl_generateMipmap(cwgl_ctx* ctx, cwgl_enum target);
// 3.7.13 Texture Objects
CWGL_API void cwgl_bindTexture(cwgl_ctx* ctx, cwgl_enum target, cwgl_Texture* texture);
CWGL_API void cwgl_deleteTexture(cwgl_ctx* ctx, cwgl_Texture* texture);
CWGL_API cwgl_Texture* cwgl_createTexture(cwgl_ctx* ctx);

// 4.1.2 Scissor Test
CWGL_API void cwgl_scissor(cwgl_ctx* ctx, int32_t x, int32_t y, uint32_t width, uint32_t height);
// 4.1.3 Multisample Fragment Operations
CWGL_API void cwgl_sampleCoverage(cwgl_ctx* ctx, float value, int invert);
// 4.1.4 Stencil Test
CWGL_API void cwgl_stencilFunc(cwgl_ctx* ctx, cwgl_enum func, int32_t ref, uint32_t mask);
CWGL_API void cwgl_stencilFuncSeparate(cwgl_ctx* ctx, cwgl_enum face, cwgl_enum func, int32_t ref, uint32_t mask);
CWGL_API void cwgl_stencilOp(cwgl_ctx* ctx, cwgl_enum fail, cwgl_enum zfail, cwgl_enum zpass);
CWGL_API void cwgl_stencilOpSeparate(cwgl_ctx* ctx, cwgl_enum face, cwgl_enum fail, cwgl_enum zfail, cwgl_enum zpass);
// 4.1.5 Depth Buffer Test
CWGL_API void cwgl_depthFunc(cwgl_ctx* ctx, cwgl_enum func);
// 4.1.6 Blending
CWGL_API void cwgl_blendEquation(cwgl_ctx* ctx, cwgl_enum mode);
CWGL_API void cwgl_blendEquationSeparate(cwgl_ctx* ctx, cwgl_enum modeRGB, cwgl_enum modeAlpha);
CWGL_API void cwgl_blendFuncSeparate(cwgl_ctx* ctx, cwgl_enum srcRGB, cwgl_enum dstRGB, cwgl_enum srcAlpha, cwgl_enum dstAlpha);
CWGL_API void cwgl_blendFunc(cwgl_ctx* ctx, cwgl_enum sfactor, cwgl_enum dfactor);
CWGL_API void cwgl_blendColor(cwgl_ctx* ctx, float red, float green, float blue, float alpha);
// 4.2.2 Fine Control of Buffer Updates
CWGL_API void cwgl_colorMask(cwgl_ctx* ctx, int red, int green, int blue, int alpha);
CWGL_API void cwgl_depthMask(cwgl_ctx* ctx, int flag);
CWGL_API void cwgl_stencilMask(cwgl_ctx* ctx, uint32_t mask);
CWGL_API void cwgl_stencilMaskSeparate(cwgl_ctx* ctx, cwgl_enum face, uint32_t mask);
// 4.2.3 Clearing the Buffers
CWGL_API void cwgl_clear(cwgl_ctx* ctx, uint32_t mask);
CWGL_API void cwgl_clearColor(cwgl_ctx* ctx, float red, float green, float blue, float alpha);
CWGL_API void cwgl_clearDepth(cwgl_ctx* ctx, float depth);
CWGL_API void cwgl_clearStencil(cwgl_ctx* ctx, int32_t s);
// 4.3.1 Reading Pixels
CWGL_API void cwgl_readPixels(cwgl_ctx* ctx, int32_t x, int32_t y, uint32_t width, uint32_t height, cwgl_enum format, cwgl_enum type, void* buf, size_t buflen);
// 4.4.1 Binding and Managing Framebuffer Objects
CWGL_API void cwgl_bindFramebuffer(cwgl_ctx* ctx, cwgl_enum target, cwgl_Framebuffer* framebuffer);
CWGL_API void cwgl_deleteFramebuffer(cwgl_ctx* ctx, cwgl_Framebuffer* framebuffer);
CWGL_API cwgl_Framebuffer* cwgl_createFramebuffer(cwgl_ctx* ctx);
// 4.4.3 Renderbuffer Objects
CWGL_API void cwgl_bindRenderbuffer(cwgl_ctx* ctx, cwgl_enum target, cwgl_Renderbuffer* renderbuffer);
CWGL_API void cwgl_deleteRenderbuffer(cwgl_ctx* ctx, cwgl_Renderbuffer* renderbuffer);
CWGL_API cwgl_Renderbuffer* cwgl_createRenderbuffer(cwgl_ctx* ctx);
CWGL_API void cwgl_renderbufferStorage(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum internalformat, uint32_t width, uint32_t height);
CWGL_API void cwgl_framebufferRenderbuffer(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum attachment, cwgl_enum renderbuffertarget, cwgl_Renderbuffer* renderbuffer);
CWGL_API void cwgl_framebufferTexture2D(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum attachment, cwgl_enum textarget, cwgl_Texture* texture, int32_t level);
// 4.4.5 Framebuffer Completeness
CWGL_API cwgl_enum cwgl_checkFramebufferStatus(cwgl_ctx* ctx, cwgl_enum target);

// 5.1 Flush and Finish
CWGL_API void cwgl_finish(cwgl_ctx* ctx);
CWGL_API void cwgl_flush(cwgl_ctx* ctx);
// 5.2 Hints
CWGL_API void cwgl_hint(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum mode);

// 6.1.1 Simple Queries
CWGL_API cwgl_query_result cwgl_getParameter_b1(cwgl_ctx* ctx, cwgl_enum pname, int32_t* x);
CWGL_API cwgl_query_result cwgl_getParameter_b4(cwgl_ctx* ctx, cwgl_enum pname, int32_t* x, int32_t* y, int32_t* z, int32_t* w);
CWGL_API cwgl_query_result cwgl_getParameter_i1(cwgl_ctx* ctx, cwgl_enum pname, int32_t* x);
CWGL_API cwgl_query_result cwgl_getParameter_i2(cwgl_ctx* ctx, cwgl_enum pname, int32_t* x, int32_t* y);
CWGL_API cwgl_query_result cwgl_getParameter_i4(cwgl_ctx* ctx, cwgl_enum pname, int32_t* x, int32_t* y, int32_t* z, int32_t* w);
CWGL_API cwgl_query_result cwgl_getParameter_f1(cwgl_ctx* ctx, cwgl_enum pname, float* x);
CWGL_API cwgl_query_result cwgl_getParameter_f2(cwgl_ctx* ctx, cwgl_enum pname, float* x, float* y);
CWGL_API cwgl_query_result cwgl_getParameter_f4(cwgl_ctx* ctx, cwgl_enum pname, float* x, float* y, float* z, float* w);
CWGL_API cwgl_query_result cwgl_getParameter_str(cwgl_ctx* ctx, cwgl_enum pname, cwgl_string** str);
CWGL_API cwgl_query_result cwgl_getParameter_Buffer(cwgl_ctx* ctx, cwgl_enum pname, cwgl_Buffer** buffer);
CWGL_API cwgl_query_result cwgl_getParameter_Program(cwgl_ctx* ctx, cwgl_enum pname, cwgl_Program** program);
CWGL_API cwgl_query_result cwgl_getParameter_Framebuffer(cwgl_ctx* ctx, cwgl_enum pname, cwgl_Framebuffer** framebuffer);
CWGL_API cwgl_query_result cwgl_getParameter_Renderbuffer(cwgl_ctx* ctx, cwgl_enum pname, cwgl_Renderbuffer** renderbuffer);
CWGL_API cwgl_query_result cwgl_getParameter_Texture(cwgl_ctx* ctx, cwgl_enum pname, cwgl_Texture** texture);
CWGL_API int cwgl_isEnabled(cwgl_ctx* ctx, cwgl_enum cap);
// 6.1.3 Enumerated Queries
CWGL_API cwgl_query_result cwgl_getTexParameter_i1(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum pname, int32_t* x);
CWGL_API cwgl_query_result cwgl_getBufferParameter_i1(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum pname, int32_t* x);
CWGL_API cwgl_query_result cwgl_getFramebufferAttachmentParameter_i1(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum attachment, cwgl_enum pname, int32_t* x);
CWGL_API cwgl_query_result cwgl_getFramebufferAttachmentParameter_Renderbuffer(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum attachment, cwgl_enum pname, cwgl_Renderbuffer** renderbuffer);
CWGL_API cwgl_query_result cwgl_getFramebufferAttachmentParameter_Texture(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum attachment, cwgl_enum pname, cwgl_Texture** texture);
CWGL_API cwgl_query_result cwgl_getRenderbufferParameter_i1(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum pname, int32_t* x);
// 6.1.4 Texture Queries
CWGL_API int cwgl_isTexture(cwgl_ctx* ctx, cwgl_Texture* texture);
// 6.1.6 Buffer Object Queries
CWGL_API int cwgl_isBuffer(cwgl_ctx* ctx, cwgl_Buffer* buffer);
// 6.1.7 Framebuffer Object and Renderbuffer Queries
CWGL_API int cwgl_isFramebuffer(cwgl_ctx* ctx, cwgl_Framebuffer* framebuffer);
CWGL_API int cwgl_isRenderbuffer(cwgl_ctx* ctx, cwgl_Renderbuffer* renderbuffer);
// 6.1.8 Shader and Program Queries
CWGL_API int cwgl_isShader(cwgl_ctx* ctx, cwgl_Shader* shader);
CWGL_API cwgl_query_result cwgl_getShaderParameter_i1(cwgl_ctx* ctx, cwgl_Shader* shader, cwgl_enum pname, int32_t* x);
CWGL_API int cwgl_isProgram(cwgl_ctx* ctx, cwgl_Program* program);
CWGL_API cwgl_query_result cwgl_getProgramParameter_i1(cwgl_ctx* ctx, cwgl_Program* program, cwgl_enum pname, int32_t* x);
CWGL_API cwgl_query_result cwgl_getAttachedShaders(cwgl_ctx* ctx, cwgl_Program* program, cwgl_Shader** vertex_shader, cwgl_Shader** fragment_shader);
CWGL_API cwgl_string* cwgl_getProgramInfoLog(cwgl_ctx* ctx, cwgl_Program* program);
CWGL_API cwgl_string* cwgl_getShaderInfoLog(cwgl_ctx* ctx, cwgl_Shader* shader);
CWGL_API cwgl_string* cwgl_getShaderSource(cwgl_ctx* ctx, cwgl_Shader* shader);
CWGL_API cwgl_query_result cwgl_getShaderPrecisionFormat(cwgl_ctx* ctx, cwgl_enum shadertype, cwgl_enum precisiontype, int32_t* rangeMin, int32_t* rangeMax, int32_t* precision);
CWGL_API cwgl_query_result cwgl_getVertexAttrib_i1(cwgl_ctx* ctx, uint32_t index, cwgl_enum pname, int32_t* x);
CWGL_API cwgl_query_result cwgl_getVertexAttrib_f4(cwgl_ctx* ctx, uint32_t index, cwgl_enum pname, float* x, float* y, float* z, float* w);
CWGL_API cwgl_query_result cwgl_getVertexAttrib_Buffer(cwgl_ctx* ctx, uint32_t index, cwgl_enum pname, cwgl_Buffer** buffer);
CWGL_API uint32_t cwgl_getVertexAttribOffset(cwgl_ctx* ctx, uint32_t index, cwgl_enum pname);
CWGL_API cwgl_query_result cwgl_getUniform_i1(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, int32_t* x);
CWGL_API cwgl_query_result cwgl_getUniform_i2(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, int32_t* x, int32_t* y);
CWGL_API cwgl_query_result cwgl_getUniform_i3(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, int32_t* x, int32_t* y, int32_t* z);
CWGL_API cwgl_query_result cwgl_getUniform_i4(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, int32_t* x, int32_t* y, int32_t* z, int32_t* w);
CWGL_API cwgl_query_result cwgl_getUniform_f1(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, float* x);
CWGL_API cwgl_query_result cwgl_getUniform_f2(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, float* x, float* y);
CWGL_API cwgl_query_result cwgl_getUniform_f3(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, float* x, float* y, float* z);
CWGL_API cwgl_query_result cwgl_getUniform_f4(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, float* x, float* y, float* z, float* w);
CWGL_API cwgl_query_result cwgl_getUniform_m2(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, float* x);
CWGL_API cwgl_query_result cwgl_getUniform_m3(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, float* x);
CWGL_API cwgl_query_result cwgl_getUniform_m4(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, float* x);

// OES_vertex_array_object
CWGL_API cwgl_VertexArrayObject* cwgl_createVertexArray(cwgl_ctx* ctx);
CWGL_API void cwgl_bindVertexArray(cwgl_ctx* ctx, cwgl_VertexArrayObject* obj);
CWGL_API void cwgl_deleteVertexArray(cwgl_ctx* ctx, cwgl_VertexArrayObject* obj);

// {
#ifdef __cplusplus
};
#endif

#endif
