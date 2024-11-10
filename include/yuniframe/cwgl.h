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
    CWGL_QR_TYPE_RENDERBUFFER = 0x35,

    /* Level 2 */
    CWGL_QR_TYPE_IARRAY = 0x41,
    CWGL_QR_TYPE_U1 = 0x51,
    CWGL_QR_TYPE_U2 = 0x52,
    CWGL_QR_TYPE_U3 = 0x53,
    CWGL_QR_TYPE_U4 = 0x54,
    CWGL_QR_TYPE_M2x3 = 0x61,
    CWGL_QR_TYPE_M2x4 = 0x62,
    CWGL_QR_TYPE_M3x2 = 0x63,
    CWGL_QR_TYPE_M3x4 = 0x64,
    CWGL_QR_TYPE_M4x2 = 0x65,
    CWGL_QR_TYPE_M4x3 = 0x66
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

#ifdef CWGL_LEVEL_L2
struct cwgl_Query_s;
struct cwgl_Sampler_s;
struct cwgl_Sync_s;
struct cwgl_TransformFeedback_s;
#endif

typedef struct cwgl_Buffer_s cwgl_Buffer;
typedef struct cwgl_Shader_s cwgl_Shader;
typedef struct cwgl_Program_s cwgl_Program;
typedef struct cwgl_Texture_s cwgl_Texture;
typedef struct cwgl_Framebuffer_s cwgl_Framebuffer;
typedef struct cwgl_Renderbuffer_s cwgl_Renderbuffer;
typedef struct cwgl_VertexArrayObject_s cwgl_VertexArrayObject;

#ifdef CWGL_LEVEL_L2
typedef struct cwgl_Query_s cwgl_Query;
typedef struct cwgl_Sampler_s cwgl_Sampler;
typedef struct cwgl_Sync_s cwgl_Sync;
typedef struct cwgl_TransformFeedback_s cwgl_TransformFeedback;
#endif

CWGL_API void cwgl_Buffer_release(cwgl_ctx* ctx, cwgl_Buffer* buffer);
CWGL_API void cwgl_Shader_release(cwgl_ctx* ctx, cwgl_Shader* shader);
CWGL_API void cwgl_Program_release(cwgl_ctx* ctx, cwgl_Program* program);
CWGL_API void cwgl_Texture_release(cwgl_ctx* ctx, cwgl_Texture* texture);
CWGL_API void cwgl_Framebuffer_release(cwgl_ctx* ctx, cwgl_Framebuffer* framebuffer);
CWGL_API void cwgl_Renderbuffer_release(cwgl_ctx* ctx, cwgl_Renderbuffer* renderbuffer);
CWGL_API void cwgl_VertexArrayObject_release(cwgl_ctx* ctx, cwgl_VertexArrayObject* vao);

#ifdef CWGL_LEVEL_L2
CWGL_API void cwgl_Query_release(cwgl_ctx* ctx, cwgl_Query* query);
CWGL_API void cwgl_Sampler_release(cwgl_ctx* ctx, cwgl_Sampler* sampler);
CWGL_API void cwgl_Sync_release(cwgl_ctx* ctx, cwgl_Sync* sync);
CWGL_API void cwgl_TransformFeedback_release(cwgl_ctx* ctx, cwgl_TransformFeedback* transformfeedback);
#endif

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
#ifdef CWGL_LEVEL_L2
// WebGL2 3.7.8 Uniforms and attributes
CWGL_API void cwgl_vertexAttrib4i(cwgl_ctx* ctx, uint32_t indx, int32_t x, int32_t y, int32_t z, int32_t w);
CWGL_API void cwgl_vertexAttrib4ui(cwgl_ctx* ctx, uint32_t indx, uint32_t x, uint32_t y, uint32_t z, uint32_t w);
CWGL_API void cwgl_vertexAttrib4iv(cwgl_ctx* ctx, uint32_t indx, int32_t* x, size_t count);
CWGL_API void cwgl_vertexAttrib4uiv(cwgl_ctx* ctx, uint32_t indx, uint32_t* x, size_t count);
#endif
// 2.8 Vertex Arrays
CWGL_API void cwgl_vertexAttribPointer(cwgl_ctx* ctx, uint32_t indx, int32_t size, cwgl_enum type, int normalized, uint32_t stride, uint32_t offset);
#ifdef CWGL_LEVEL_L2
// WebGL2 3.7.8 Uniforms and attributes
CWGL_API void cwgl_vertexAttribIPointer(cwgl_ctx* ctx, uint32_t indx, int32_t size, cwgl_enum type, uint32_t stride, uint32_t offset);
#endif
CWGL_API void cwgl_enableVertexAttribArray(cwgl_ctx* ctx, uint32_t index);
CWGL_API void cwgl_disableVertexAttribArray(cwgl_ctx* ctx, uint32_t index);
CWGL_API void cwgl_drawArrays(cwgl_ctx* ctx, cwgl_enum mode, int32_t first, uint32_t count);
CWGL_API void cwgl_drawElements(cwgl_ctx* ctx, cwgl_enum mode, uint32_t count, cwgl_enum type, uint32_t offset);
#ifdef CWGL_LEVEL_L2
CWGL_API void cwgl_vertexAttribDivisor(cwgl_ctx* ctx, uint32_t index, uint32_t divisor);
CWGL_API void cwgl_drawArraysInstanced(cwgl_ctx* ctx, cwgl_enum mode, int32_t first, uint32_t count, uint32_t instancecount);
CWGL_API void cwgl_drawElementsInstanced(cwgl_ctx* ctx, cwgl_enum mode, uint32_t count, cwgl_enum type, uint32_t offset, uint32_t instancecount);
CWGL_API void cwgl_drawRangeElements(cwgl_ctx* ctx, cwgl_enum mode, uint32_t start, uint32_t end, uint32_t count, cwgl_enum type, uint32_t offset);
#endif
// 2.9 Buffer Objects
CWGL_API void cwgl_bindBuffer(cwgl_ctx* ctx, cwgl_enum target, cwgl_Buffer* buffer);
CWGL_API void cwgl_deleteBuffer(cwgl_ctx* ctx, cwgl_Buffer* buffer);
CWGL_API cwgl_Buffer* cwgl_createBuffer(cwgl_ctx* ctx);
CWGL_API void cwgl_bufferData(cwgl_ctx* ctx, cwgl_enum target, uint32_t size, void* data, cwgl_enum usage);
CWGL_API void cwgl_bufferSubData(cwgl_ctx* ctx, cwgl_enum target, uint32_t offset, void* data, size_t buflen);
#ifdef CWGL_LEVEL_L2
// WebGL2 3.7.3 Buffer objects
CWGL_API void cwgl_copyBufferSubData(cwgl_ctx* ctx, cwgl_enum readtarget, cwgl_enum writetarget, uint32_t readoffset, uint32_t writeoffset, uint32_t size);
CWGL_API void cwgl_getBufferSubData(cwgl_ctx* ctx, cwgl_enum target, uint32_t srcoffset, void* out, size_t length);
#endif
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
#ifdef CWGL_LEVEL_L2
// WebGL2 3.7.8 Uniforms and attributes
CWGL_API void cwgl_uniform1ui(cwgl_ctx* ctx, cwgl_UniformLocation* location, uint32_t x);
CWGL_API void cwgl_uniform2ui(cwgl_ctx* ctx, cwgl_UniformLocation* location, uint32_t x, uint32_t y);
CWGL_API void cwgl_uniform3ui(cwgl_ctx* ctx, cwgl_UniformLocation* location, uint32_t x, uint32_t y, uint32_t z);
CWGL_API void cwgl_uniform4ui(cwgl_ctx* ctx, cwgl_UniformLocation* location, uint32_t x, uint32_t y, uint32_t z, uint32_t w);
CWGL_API void cwgl_uniform1uiv(cwgl_ctx* ctx, cwgl_UniformLocation* location, uint32_t* values, size_t count);
CWGL_API void cwgl_uniform2uiv(cwgl_ctx* ctx, cwgl_UniformLocation* location, uint32_t* values, size_t count);
CWGL_API void cwgl_uniform3uiv(cwgl_ctx* ctx, cwgl_UniformLocation* location, uint32_t* values, size_t count);
CWGL_API void cwgl_uniform4uiv(cwgl_ctx* ctx, cwgl_UniformLocation* location, uint32_t* values, size_t count);
CWGL_API void cwgl_uniformMatrix2x3fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, int transpose, float* value, size_t count);
CWGL_API void cwgl_uniformMatrix2x4fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, int transpose, float* value, size_t count);
CWGL_API void cwgl_uniformMatrix3x2fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, int transpose, float* value, size_t count);
CWGL_API void cwgl_uniformMatrix3x4fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, int transpose, float* value, size_t count);
CWGL_API void cwgl_uniformMatrix4x2fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, int transpose, float* value, size_t count);
CWGL_API void cwgl_uniformMatrix4x3fv(cwgl_ctx* ctx, cwgl_UniformLocation* location, int transpose, float* value, size_t count);
#endif
// 2.10.5 Shader Execution
CWGL_API void cwgl_validateProgram(cwgl_ctx* ctx, cwgl_Program* program);
#ifdef CWGL_LEVEL_L2
// WebGL2 3.7.7 Programs and Shaders
CWGL_API void cwgl_getFragDataLocation(cwgl_ctx* ctx, cwgl_Program* program, const char* name);
#endif
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
#ifdef CWGL_LEVEL_L2
CWGL_API void cwgl_texStorage2D(cwgl_ctx* ctx, cwgl_enum target, int32_t levels, cwgl_enum internalformat, uint32_t width, uint32_t height);
CWGL_API void cwgl_texStorage3D(cwgl_ctx* ctx, cwgl_enum target, int32_t levels, cwgl_enum internalformat, uint32_t width, uint32_t height, uint32_t depth);
CWGL_API void cwgl_texImage2D_buffer(cwgl_ctx* ctx, cwgl_enum target, int32_t level, cwgl_enum internalformat, uint32_t width, uint32_t height, uint32_t depth, int32_t border, cwgl_enum format, cwgl_enum type, uint32_t offset);
CWGL_API void cwgl_texImage3D(cwgl_ctx* ctx, cwgl_enum target, int32_t level, cwgl_enum internalformat, uint32_t width, uint32_t height, uint32_t depth, int32_t border, cwgl_enum format, cwgl_enum type, const void* buf, size_t buflen);
CWGL_API void cwgl_texImage3D_buffer(cwgl_ctx* ctx, cwgl_enum target, int32_t level, cwgl_enum internalformat, uint32_t width, uint32_t height, uint32_t depth, int32_t border, cwgl_enum format, cwgl_enum type, uint32_t offset);
CWGL_API void cwgl_texSubImage2D_buffer(cwgl_ctx* ctx, cwgl_enum target, int32_t level, int32_t xoffset, int32_t yoffset, uint32_t width, uint32_t height, cwgl_enum format, cwgl_enum type, uint32_t offset);
CWGL_API void cwgl_texSubImage3D(cwgl_ctx* ctx, cwgl_enum target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, uint32_t width, uint32_t height, uint32_t depth, cwgl_enum format, cwgl_enum type, const void* buf, size_t buflen);
CWGL_API void cwgl_texSubImage3D_buffer(cwgl_ctx* ctx, cwgl_enum target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, uint32_t width, uint32_t height, uint32_t depth, cwgl_enum format, cwgl_enum type, uint32_t offset);
CWGL_API void cwgl_copyTexSubImage3D(cwgl_ctx* ctx, cwgl_enum target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, int32_t x, int32_t y, uint32_t width, uint32_t height);
CWGL_API void cwgl_compressedTexImage2D_buffer(cwgl_ctx* ctx, cwgl_enum target, int32_t level, cwgl_enum internalformat, uint32_t width, uint32_t height, int32_t border, uint32_t imagesize, uint32_t offset);
CWGL_API void cwgl_compressedTexImage3D(cwgl_ctx* ctx, cwgl_enum target, int32_t level, cwgl_enum internalformat, uint32_t width, uint32_t height, uint32_t depth, int32_t border,uint32_t imagesize, const void* buf, size_t buflen);
CWGL_API void cwgl_compressedTexImage3D_buffer(cwgl_ctx* ctx, cwgl_enum target, int32_t level, cwgl_enum internalformat, uint32_t width, uint32_t height, int32_t border, uint32_t imagesize, uint32_t offset);
CWGL_API void cwgl_compressedTexSubImage3D(cwgl_ctx* ctx, cwgl_enum target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, uint32_t width, uint32_t height, uint32_t depth, uint32_t imagesize, cwgl_enum format, const void* buf, size_t buflen);
CWGL_API void cwgl_compressedTexSubImage3D_buffer(cwgl_ctx* ctx, cwgl_enum target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, uint32_t width, uint32_t height, uint32_t depth, uint32_t imagesize, cwgl_enum format, uint32_t offset);
#endif
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
#ifdef CWGL_LEVEL_L2
// WebGL2 3.7.11 Multiple render targets
CWGL_API void cwgl_drawBuffers(cwgl_ctx* ctx, cwgl_enum* buffers, size_t count);
CWGL_API void cwgl_clearBufferiv(cwgl_ctx* ctx, cwgl_enum buffer, int32_t drawbuffer, const int32_t* value, size_t count);
CWGL_API void cwgl_clearBufferuiv(cwgl_ctx* ctx, cwgl_enum buffer, int32_t drawbuffer, const uint32_t* value, size_t count);
CWGL_API void cwgl_clearBufferfv(cwgl_ctx* ctx, cwgl_enum buffer, int32_t drawbuffer, const float* value, size_t count);
CWGL_API void cwgl_clearBufferfi(cwgl_ctx* ctx, cwgl_enum buffer, int32_t drawbuffer, float depth, int32_t stencil);
#endif
// 4.3.1 Reading Pixels
CWGL_API void cwgl_readPixels(cwgl_ctx* ctx, int32_t x, int32_t y, uint32_t width, uint32_t height, cwgl_enum format, cwgl_enum type, void* buf, size_t buflen);
#ifdef CWGL_LEVEL_L2
// WebGL2 3.7.10 Reading back pixels
CWGL_API void cwgl_readPixels_buffer(cwgl_ctx* ctx, int32_t x, int32_t y, uint32_t width, uint32_t height, cwgl_enum format, cwgl_enum type, uint32_t offset);
#endif
// 4.4.1 Binding and Managing Framebuffer Objects
CWGL_API void cwgl_bindFramebuffer(cwgl_ctx* ctx, cwgl_enum target, cwgl_Framebuffer* framebuffer);
CWGL_API void cwgl_deleteFramebuffer(cwgl_ctx* ctx, cwgl_Framebuffer* framebuffer);
CWGL_API cwgl_Framebuffer* cwgl_createFramebuffer(cwgl_ctx* ctx);
#ifdef CWGL_LEVEL_L2
// WebGL2 3.7.4 Framebuffer objects
CWGL_API void cwgl_blitFramebuffer(cwgl_ctx* ctx, int32_t srcx0, int32_t srcy0, int32_t srcx1, int32_t srcy1, int32_t dstx0, int32_t dsty0, int32_t dstx1, int32_t dsty1, uint32_t mask /* ??? */, cwgl_enum filter);
CWGL_API void cwgl_framebufferTextureLayer(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum attachment, cwgl_Texture* texture, int32_t level, int32_t layer);
CWGL_API void cwgl_invalidateFramebuffer(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum* attachments, size_t count);
CWGL_API void cwgl_invalidateSubFramebuffer(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum* attachments, size_t count, int32_t x, int32_t y, uint32_t width, uint32_t height);
CWGL_API void cwgl_readBuffer(cwgl_ctx* ctx, cwgl_enum src);
#endif
// 4.4.3 Renderbuffer Objects
CWGL_API void cwgl_bindRenderbuffer(cwgl_ctx* ctx, cwgl_enum target, cwgl_Renderbuffer* renderbuffer);
CWGL_API void cwgl_deleteRenderbuffer(cwgl_ctx* ctx, cwgl_Renderbuffer* renderbuffer);
CWGL_API cwgl_Renderbuffer* cwgl_createRenderbuffer(cwgl_ctx* ctx);
CWGL_API void cwgl_renderbufferStorage(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum internalformat, uint32_t width, uint32_t height);
CWGL_API void cwgl_framebufferRenderbuffer(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum attachment, cwgl_enum renderbuffertarget, cwgl_Renderbuffer* renderbuffer);
CWGL_API void cwgl_framebufferTexture2D(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum attachment, cwgl_enum textarget, cwgl_Texture* texture, int32_t level);
#ifdef CWGL_LEVEL_L2
// WebGL2 3.7.5 Renderbuffer objects
CWGL_API void cwgl_renderbufferStorageMultisample(cwgl_ctx* ctx, cwgl_enum target, uint32_t samples, cwgl_enum internalformat, uint32_t width, uint32_t height);
#endif
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
#ifdef CWGL_LEVEL_L2
// WebGL2 3.7.6 Texture objects
CWGL_API cwgl_query_result cwgl_getTexParameter_f1(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum pname, float* x);
#endif
CWGL_API cwgl_query_result cwgl_getBufferParameter_i1(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum pname, int32_t* x);
CWGL_API cwgl_query_result cwgl_getFramebufferAttachmentParameter_i1(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum attachment, cwgl_enum pname, int32_t* x);
CWGL_API cwgl_query_result cwgl_getFramebufferAttachmentParameter_Renderbuffer(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum attachment, cwgl_enum pname, cwgl_Renderbuffer** renderbuffer);
CWGL_API cwgl_query_result cwgl_getFramebufferAttachmentParameter_Texture(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum attachment, cwgl_enum pname, cwgl_Texture** texture);
CWGL_API cwgl_query_result cwgl_getRenderbufferParameter_i1(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum pname, int32_t* x);
#ifdef CWGL_LEVEL_L2
// WebGL2 3.7.5 Renderbuffer objects
CWGL_API cwgl_query_result cwgl_getInternalformatParameter_iarray(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum internalformat, cwgl_enum pname, int32_t* out, size_t bufcount);
#endif
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
#ifdef CWGL_LEVEL_L2
// WebGL2 3.7.8 Uniforms and attributes
CWGL_API cwgl_query_result cwgl_getVertexAttrib_i4(cwgl_ctx* ctx, uint32_t index, cwgl_enum pname, int32_t* x, int32_t* y, int32_t* z, int32_t* w);
CWGL_API cwgl_query_result cwgl_getVertexAttrib_u4(cwgl_ctx* ctx, uint32_t index, cwgl_enum pname, uint32_t* x, uint32_t* y, uint32_t* z, uint32_t* w);
#endif
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
#ifdef CWGL_LEVEL_L2
// WebGL2 3.7.8 Uniforms and attributes
CWGL_API cwgl_query_result cwgl_getUniform_u1(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, uint32_t* x);
CWGL_API cwgl_query_result cwgl_getUniform_u2(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, uint32_t* x, uint32_t* y);
CWGL_API cwgl_query_result cwgl_getUniform_u3(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, uint32_t* x, uint32_t* y, uint32_t* z);
CWGL_API cwgl_query_result cwgl_getUniform_u4(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, uint32_t* x, uint32_t* y, uint32_t* z, uint32_t* w);
CWGL_API cwgl_query_result cwgl_getUniform_m2x3(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, float* x);
CWGL_API cwgl_query_result cwgl_getUniform_m2x4(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, float* x);
CWGL_API cwgl_query_result cwgl_getUniform_m3x2(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, float* x);
CWGL_API cwgl_query_result cwgl_getUniform_m3x4(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, float* x);
CWGL_API cwgl_query_result cwgl_getUniform_m4x2(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, float* x);
CWGL_API cwgl_query_result cwgl_getUniform_m4x3(cwgl_ctx* ctx, cwgl_Program* program, cwgl_UniformLocation* location, float* x);
#endif

#ifdef CWGL_LEVEL_L2
// WebGL2 3.7.12 Query objects
CWGL_API cwgl_Query* cwgl_createQuery(cwgl_ctx* ctx);
CWGL_API void cwgl_deleteQuery(cwgl_ctx* ctx, cwgl_Query* query);
CWGL_API void cwgl_beginQuery(cwgl_ctx* ctx, cwgl_enum target, cwgl_Query* query);
CWGL_API void cwgl_endQuery(cwgl_ctx* ctx, cwgl_enum target);
CWGL_API cwgl_Query* cwgl_getQuery(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum pname);
CWGL_API cwgl_query_result cwgl_getQueryParameter_u1(cwgl_ctx* ctx, cwgl_Query* query, cwgl_enum pname, uint32_t* out);

// WebGL2 3.7.13 Sampler objects
CWGL_API cwgl_Sampler* cwgl_createSampler(cwgl_ctx* ctx);
CWGL_API void cwgl_deleteSampler(cwgl_ctx* ctx, cwgl_Sampler* sampler);
CWGL_API void cwgl_bindSampler(cwgl_ctx* ctx, uint32_t unit, cwgl_Sampler* sampler);
CWGL_API void cwgl_samplerParameteri(cwgl_ctx* ctx, cwgl_Sampler* sampler, cwgl_enum pname, int32_t param);
CWGL_API void cwgl_samplerParameterf(cwgl_ctx* ctx, cwgl_Sampler* sampler, cwgl_enum pname, float param);
CWGL_API cwgl_query_result cwgl_getSamplerParameter_i1(cwgl_ctx* ctx, cwgl_Sampler* sampler, cwgl_enum pname, int32_t* out);
CWGL_API cwgl_query_result cwgl_getSamplerParameter_f1(cwgl_ctx* ctx, cwgl_Sampler* sampler, cwgl_enum pname, float* out);

// WebGL2 3.7.14 Sync objects
CWGL_API cwgl_Sync* cwgl_fenceSync(cwgl_ctx* ctx);
CWGL_API void cwgl_deleteSync(cwgl_ctx* ctx, cwgl_Sync* sync);
CWGL_API cwgl_enum cwgl_clientWaitSync(cwgl_ctx* ctx, cwgl_Sync* sync, uint32_t flags, uint32_t timeout);
CWGL_API void cwgl_waitSync(cwgl_ctx* ctx, cwgl_Sync* sync, uint32_t flags, uint32_t timeout);
CWGL_API cwgl_query_result cwgl_getSyncParameter_i1(cwgl_ctx* ctx, cwgl_Sync* sync, cwgl_enum pname);

// WebGL2 3.7.15 Transform feedback
CWGL_API cwgl_TransformFeedback* cwgl_createTransformFeedback(cwgl_ctx* ctx);
CWGL_API void cwgl_deleteTransformFeedback(cwgl_ctx* ctx, cwgl_TransformFeedback* tf);
CWGL_API void cwgl_bindTransformFeedback(cwgl_ctx* ctx, cwgl_enum target, cwgl_TransformFeedback* tf);
CWGL_API void cwgl_beginTransformFeedback(cwgl_ctx* ctx, cwgl_enum primitivemode);
CWGL_API void cwgl_endTransformFeedback(cwgl_ctx* ctx);
CWGL_API void cwgl_transformFeedbackVarying(cwgl_ctx* ctx, cwgl_Program* program, uint32_t index);
CWGL_API void cwgl_pauseTransformFeedback(cwgl_ctx* ctx);
CWGL_API void cwgl_resumeTransformFeedback(cwgl_ctx* ctx);

// WebGL2 3.7.16 Uniform Buffer objects
CWGL_API void cwgl_bindBufferBase(cwgl_ctx* ctx, cwgl_enum target, uint32_t index, cwgl_Buffer* buffer);
CWGL_API void cwgl_bindBufferRange(cwgl_ctx* ctx, cwgl_enum target, uint32_t index, cwgl_Buffer* buffer, uint32_t offset, uint32_t size);
CWGL_API cwgl_query_result cwgl_getIndexedParameter_i1(cwgl_ctx* ctx, cwgl_enum target, uint32_t index, int32_t* out);
CWGL_API cwgl_query_result cwgl_getIndexedParameter_Buffer(cwgl_ctx* ctx, cwgl_enum target, uint32_t index, cwgl_Buffer** out);
CWGL_API cwgl_query_result cwgl_getUniformIndices_iarray(cwgl_ctx* ctx, cwgl_Program* program, cwgl_string** uniformnames, size_t namecount, int32_t* out, uint32_t outcount, int32_t* resultcount);
CWGL_API cwgl_query_result cwgl_getActiveUniforms_iarray(cwgl_ctx* ctx, cwgl_Program* program, uint32_t* indices, size_t indicecount, cwgl_enum pname, int32_t* out, uint32_t outcount, int32_t* resultcount);
CWGL_API uint32_t cwgl_getUniformBlockIndex(cwgl_ctx* ctx, cwgl_Program* program, cwgl_string* uniformblockname);
CWGL_API cwgl_query_result cwgl_getActiveUniformBlockParameter_i1(cwgl_ctx* ctx, cwgl_Program* program, uint32_t uniformblockindex, cwgl_enum pname, int32_t* out);
CWGL_API cwgl_query_result cwgl_getActiveUniformBlockParameter_iarray(cwgl_ctx* ctx, cwgl_Program* program, uint32_t uniformblockindex, cwgl_enum pname, int32_t* out, uint32_t outcount, int32_t* resultcount);
CWGL_API cwgl_string* cwgl_getActiveUniformBlockName(cwgl_ctx* ctx, cwgl_Program* program, uint32_t uniformblockindex);
CWGL_API void cwgl_uniformBlockBinding(cwgl_ctx* ctx, cwgl_Program* program, uint32_t uniformblockindex, uint32_t uniformblockbinding);
#endif

// OES_vertex_array_object
// WebGL2 3.7.17 Vertex Array objects
CWGL_API cwgl_VertexArrayObject* cwgl_createVertexArray(cwgl_ctx* ctx);
CWGL_API void cwgl_bindVertexArray(cwgl_ctx* ctx, cwgl_VertexArrayObject* obj);
CWGL_API void cwgl_deleteVertexArray(cwgl_ctx* ctx, cwgl_VertexArrayObject* obj);

// {
#ifdef __cplusplus
};
#endif

#endif
