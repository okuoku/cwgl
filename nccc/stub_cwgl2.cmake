nccc_api(cwgl_Query_release
    IN ptr ptr
    OUT)
nccc_api(cwgl_Sampler_release
    IN ptr ptr
    OUT)
nccc_api(cwgl_Sync_release
    IN ptr ptr
    OUT)
nccc_api(cwgl_TransformFeedback_release
    IN ptr ptr
    OUT)

nccc_api(cwgl_vertexAttribI4i
    IN ptr u32 s32 s32 s32 s32
    OUT)

nccc_api(cwgl_vertexAttribI4ui
    IN ptr u32 u32 u32 u32 u32
    OUT)

nccc_api(cwgl_vertexAttribIPointer
    IN ptr u32 s32 u32 u32 u32
    OUT)


nccc_api(cwgl_vertexAttribDivisor
    IN ptr u32 u32
    OUT)

nccc_api(cwgl_drawArraysInstanced
    IN ptr u32 s32 u32 u32
    OUT)

nccc_api(cwgl_drawElementsInstanced
    IN ptr u32 u32 u32 u32 u32
    OUT)

nccc_api(cwgl_drawRangeElements
    IN ptr u32 u32 u32 u32 u32 u32
    OUT)


nccc_api(cwgl_copyBufferSubData
    IN ptr u32 u32 u32 u32 u32
    OUT)

nccc_api(cwgl_getBufferSubData
    IN ptr u32 u32 ptr u64
    OUT)


nccc_api(cwgl_uniform1ui
    IN ptr ptr u32
    OUT)

nccc_api(cwgl_uniform2ui
    IN ptr ptr u32 u32
    OUT)

nccc_api(cwgl_uniform3ui
    IN ptr ptr u32 u32 u32
    OUT)

nccc_api(cwgl_uniform4ui
    IN ptr ptr u32 u32 u32 u32
    OUT)

nccc_api(cwgl_uniform1uiv
    IN ptr ptr ptr u64
    OUT)

nccc_api(cwgl_uniform2uiv
    IN ptr ptr ptr u64
    OUT)

nccc_api(cwgl_uniform3uiv
    IN ptr ptr ptr u64
    OUT)

nccc_api(cwgl_uniform4uiv
    IN ptr ptr ptr u64
    OUT)

nccc_api(cwgl_uniformMatrix2x3fv
    IN ptr ptr s32 ptr u64
    OUT)

nccc_api(cwgl_uniformMatrix2x4fv
    IN ptr ptr s32 ptr u64
    OUT)

nccc_api(cwgl_uniformMatrix3x2fv
    IN ptr ptr s32 ptr u64
    OUT)

nccc_api(cwgl_uniformMatrix3x4fv
    IN ptr ptr s32 ptr u64
    OUT)

nccc_api(cwgl_uniformMatrix4x2fv
    IN ptr ptr s32 ptr u64
    OUT)

nccc_api(cwgl_uniformMatrix4x3fv
    IN ptr ptr s32 ptr u64
    OUT)


nccc_api(cwgl_getFragDataLocation
    IN ptr ptr ptr
    OUT s32)


nccc_api(cwgl_texStorage2D
    IN ptr u32 s32 u32 u32 u32
    OUT)

nccc_api(cwgl_texStorage3D
    IN ptr u32 s32 u32 u32 u32 u32
    OUT)

nccc_api(cwgl_texImage2D_buffer
    IN ptr u32 s32 u32 u32 u32 s32 u32 u32 u32
    OUT)

nccc_api(cwgl_texImage3D
    IN ptr u32 s32 u32 u32 u32 u32 s32 u32 u32 ptr u64
    OUT)

nccc_api(cwgl_texImage3D_buffer
    IN ptr u32 s32 u32 u32 u32 u32 s32 u32 u32 u32
    OUT)

nccc_api(cwgl_texSubImage2D_buffer
    IN ptr u32 s32 s32 s32 u32 u32 u32 u32 u32
    OUT)

nccc_api(cwgl_texSubImage3D
    IN ptr u32 s32 s32 s32 s32 u32 u32 u32 u32 u32 ptr u64
    OUT)

nccc_api(cwgl_texSubImage3D_buffer
    IN ptr u32 s32 s32 s32 s32 u32 u32 u32 u32 u32 u32
    OUT)

nccc_api(cwgl_copyTexSubImage3D
    IN ptr u32 s32 u32 u32 u32 s32 u32 u32 u32
    OUT)

nccc_api(cwgl_compressedTexImage2D_buffer
    IN ptr u32 s32 u32 u32 u32 u32 u32 u32
    OUT)

nccc_api(cwgl_compressedTexImage3D
    IN ptr u32 s32 u32 u32 u32 u32 s32 u32 ptr u64
    OUT)

nccc_api(cwgl_compressedTexImage3D_buffer
    IN ptr u32 s32 u32 u32 u32 u32 s32 u32 u32
    OUT)

nccc_api(cwgl_compressedTexSubImage3D
    IN ptr u32 s32 s32 s32 s32 u32 u32 u32 u32 u32 ptr u64
    OUT)

nccc_api(cwgl_compressedTexSubImage3D_buffer
    IN ptr u32 s32 s32 s32 s32 u32 u32 u32 u32 u32 u32
    OUT)



nccc_api(cwgl_drawBuffers
    IN ptr ptr u64
    OUT)

nccc_api(cwgl_clearBufferiv
    IN ptr u32 s32 ptr u64
    OUT)

nccc_api(cwgl_clearBufferuiv
    IN ptr u32 s32 ptr u64
    OUT)

nccc_api(cwgl_clearBufferfv
    IN ptr u32 s32 ptr u64
    OUT)

nccc_api(cwgl_clearBufferfi
    IN ptr u32 s32 f32 s32
    OUT)


nccc_api(cwgl_readPixels_buffer
    IN ptr s32 s32 u32 u32 u32 u32 u32
    OUT)


nccc_api(cwgl_blitFramebuffer
    IN ptr s32 s32 s32 s32 s32 s32 s32 s32 u32 u32
    OUT)

nccc_api(cwgl_framebufferTextureLayer
    IN ptr u32 u32 ptr s32 s32
    OUT)

nccc_api(cwgl_invalidateFramebuffer
    IN ptr u32 ptr u64
    OUT)

nccc_api(cwgl_invalidateSubFramebuffer
    IN ptr u32 ptr u64 s32 s32 u32 u32
    OUT)

nccc_api(cwgl_readBuffer
    IN ptr u32
    OUT)


nccc_api(cwgl_renderbufferStorageMultisample
    IN ptr u32 u32 u32 u32 u32
    OUT)


nccc_api(cwgl_getIndexedParameter_i1
    IN ptr u32 u32 ptr
    OUT u32)

nccc_api(cwgl_getIndexedParameter_Buffer
    IN ptr u32 u32 ptr
    OUT u32)


nccc_api(cwgl_getTexParameter_f1
    IN ptr u32 u32 ptr
    OUT u32)


nccc_api(cwgl_getInternalformatParameter_iarray
    IN ptr u32 u32 u32 ptr u64
    OUT u32)



nccc_api(cwgl_getVertexAttrib_i4
    IN ptr u32 u32 ptr ptr ptr ptr
    OUT u32)

nccc_api(cwgl_getVertexAttrib_u4
    IN ptr u32 u32 ptr ptr ptr ptr
    OUT u32)


nccc_api(cwgl_getUniform_u1
    IN ptr ptr ptr ptr
    OUT u32)

nccc_api(cwgl_getUniform_u2
    IN ptr ptr ptr ptr ptr
    OUT u32)

nccc_api(cwgl_getUniform_u3
    IN ptr ptr ptr ptr ptr ptr
    OUT u32)

nccc_api(cwgl_getUniform_u4
    IN ptr ptr ptr ptr ptr ptr ptr
    OUT u32)

nccc_api(cwgl_getUniform_m2x3
    IN ptr ptr ptr ptr
    OUT u32)

nccc_api(cwgl_getUniform_m2x4
    IN ptr ptr ptr ptr
    OUT u32)

nccc_api(cwgl_getUniform_m3x2
    IN ptr ptr ptr ptr
    OUT u32)

nccc_api(cwgl_getUniform_m3x4
    IN ptr ptr ptr ptr
    OUT u32)

nccc_api(cwgl_getUniform_m4x2
    IN ptr ptr ptr ptr
    OUT u32)

nccc_api(cwgl_getUniform_m4x3
    IN ptr ptr ptr ptr
    OUT u32)



# Query
nccc_api(cwgl_createQuery
    IN ptr 
    OUT ptr)

nccc_api(cwgl_deleteQuery
    IN ptr ptr
    OUT)

nccc_api(cwgl_beginQuery
    IN ptr u32 ptr
    OUT)

nccc_api(cwgl_endQuery
    IN ptr u32
    OUT)

nccc_api(cwgl_getQuery
    IN ptr u32 u32
    OUT ptr)

nccc_api(cwgl_getQueryParameter_u1
    IN ptr ptr u32 ptr
    OUT u32)

# Sampler
nccc_api(cwgl_createSampler
    IN ptr 
    OUT ptr)

nccc_api(cwgl_deleteSampler
    IN ptr ptr
    OUT)

nccc_api(cwgl_bindSampler
    IN ptr u32 ptr
    OUT)

nccc_api(cwgl_samplerParameteri
    IN ptr ptr u32 s32
    OUT)

nccc_api(cwgl_samplerParameterf
    IN ptr ptr u32 f32
    OUT)

nccc_api(cwgl_getSamplerParameter_i1
    IN ptr ptr u32 ptr
    OUT)

nccc_api(cwgl_getSamplerParameter_f1
    IN ptr ptr u32 ptr
    OUT)

# Sync
nccc_api(cwgl_fenceSync
    IN ptr  u32 u32
    OUT ptr)

nccc_api(cwgl_deleteSync
    IN ptr ptr
    OUT)

nccc_api(cwgl_clientWaitSync
    IN ptr ptr u32 u32
    OUT u32)

nccc_api(cwgl_waitSync
    IN ptr ptr u32 u32
    OUT)

nccc_api(cwgl_getSyncParameter_i1
    IN ptr ptr u32 ptr
    OUT u32)

# Transform feedback
nccc_api(cwgl_createTransformFeedback
    IN ptr 
    OUT ptr)

nccc_api(cwgl_deleteTransformFeedback
    IN ptr ptr 
    OUT)

nccc_api(cwgl_bindTransformFeedback
    IN ptr u32 ptr 
    OUT)

nccc_api(cwgl_beginTransformFeedback
    IN ptr u32
    OUT)

nccc_api(cwgl_endTransformFeedback
    IN ptr 
    OUT)

nccc_api(cwgl_transformFeedbackVaryings
    IN ptr ptr ptr u64 u32
    OUT)

nccc_api(cwgl_getTransformFeedbackVarying
    IN ptr ptr u32
    OUT)

nccc_api(cwgl_pauseTransformFeedback
    IN ptr 
    OUT)

nccc_api(cwgl_resumeTransformFeedback
    IN ptr 
    OUT)

# UBO
nccc_api(cwgl_bindBufferBase
    IN ptr u32 u32 ptr
    OUT)

nccc_api(cwgl_bindBufferRange
    IN ptr u32 u32 ptr u32 u32
    OUT)

nccc_api(cwgl_getUniformIndices
    IN ptr ptr ptr u64 ptr
    OUT)

nccc_api(cwgl_getActiveUniforms_iarray
    IN ptr ptr ptr u64 u32 ptr
    OUT u32)

nccc_api(cwgl_getUniformBlockIndex
    IN ptr ptr ptr
    OUT u32)

nccc_api(cwgl_getActiveUniformBlockParameter_i1
    IN ptr ptr u32 u32 ptr
    OUT u32)

nccc_api(cwgl_getActiveUniformBlockParameter_iarray
    IN ptr ptr u32 u32 ptr u32 ptr
    OUT u32)

nccc_api(cwgl_getActiveUniformBlockName
    IN ptr ptr u32 
    OUT ptr)

nccc_api(cwgl_uniformBlockBinding
    IN ptr ptr u32  u32
    OUT)
