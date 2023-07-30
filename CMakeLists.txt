cmake_minimum_required(VERSION 3.12)
project(cwgl C CXX) # FIXME: Enable CXX only if we need SHXM


if(NOT YFRM_CWGL_USE_PLATFORMGLES)
    add_definitions(
        # Use static-link
        -DANGLE_EXPORT=
        -DKHRONOS_STATIC
        #-DEGLAPI=
        #-DGL_API=
        #-DGL_APIENTRY=
        #-DGL_APICALL=
        )
endif()

if(YFRM_BUILD_MODULE)
    add_definitions(
        -DCWGL_DLL
        -DCWGL_SHARED_BUILD
        -DYFRM_DLL
        -DYFRM_SHARED_BUILD
        )
endif()

if(YFRM_CWGL_EXPERIMENTAL_TRACKER)
    include_directories(src-tracker)
    set(cwglsrc
        src-tracker/cwgl-tracker-objstr.c
        src-tracker/cwgl-tracker-priv.h
        src-tracker/cwgl-tracker-s2.c
        src-tracker/cwgl-tracker-s3.c
        src-tracker/cwgl-tracker-s4.c
        src-tracker/cwgl-tracker-s5.c
        src-tracker/cwgl-tracker-s6obj.c
        src-tracker/cwgl-tracker-s6shader.c
        src-tracker/cwgl-tracker-snone.c
        src-tracker/cwgl-tracker-vao.c
        src-tracker/cwgl-tracker-init.c
        )
    add_definitions(-DCWGL_EXPERIMENTAL_TRACKER)

    if(YFRM_CWGL_USE_VULKAN)
        add_definitions(-DCWGL_EXPERIMENTAL_USE_VOLK)
        include_directories(
            ${VULKAN_HEADERS_ROOT}/include)
        include_directories(
            ${VOLK_ROOT}
            )
        include_directories(
            ${SPIRV_TOOLS_ROOT}/include
            ${SPIRV_CROSS_ROOT}
            ${GLSLANG_ROOT}
            ${GLSLANG_ROOT}/glslang/Public
            shxm/include
            )
        list(APPEND cwglsrc
            # Volk
            ${VOLK_ROOT}/volk.c
            # CWGL
            src-vulkan/cwgl-vk-ctx.c
            src-vulkan/cwgl-vk-obj.c
            src-vulkan/cwgl-vk-draw.c
            src-vulkan/cwgl-vk-shader.c
            src-vulkan/cwgl-vk-fb.c
            src-vulkan/cwgl-vk-queue.c
            src-vulkan/cwgl-vk-mipmap.c
            src-vulkan/cwgl-vk-buffer.c
            src-vulkan/cwgl-vk-texture.c
            # SHXM
            # FIXME: Move this into shxm/
            shxm/src/shxm_glslang.cpp
            shxm/src/shxm_linker.c
            shxm/src/shxm_obj.c
            shxm/src/shxm_patcher.c
            shxm/src/shxm_spirv_decomp.c
            shxm/src/shxm_spirv_reader.c
            shxm/src/shxm_spvopt.cpp
            shxm/src/shxm_util_buf.c
            shxm/src/shxm_ms_test0.cpp
            shxm/src/shxm_ms_asm0.c
            )
    else()
        include_directories(src-tgles2)
        list(APPEND cwglsrc
            src-tgles2/cwgl-gles2-ctx.c
            src-tgles2/cwgl-gles2-obj.c
            src-tgles2/cwgl-gles2-draw.c
            src-tgles2/cwgl-gles2-shader.c
            src-tgles2/cwgl-gles2-fb.c
            src-tgles2/cwgl-gles2-queue.c
            src-tgles2/cwgl-gles2-mipmap.c
            src-tgles2/cwgl-gles2-buffer.c
            src-tgles2/cwgl-gles2-texture.c
            )
    endif()
else()
    set(cwglsrc
        src-gles2/cwgl-gles2-objstr.c
        src-gles2/cwgl-gles2-priv.h
        src-gles2/cwgl-gles2-s2.c
        src-gles2/cwgl-gles2-s3.c
        src-gles2/cwgl-gles2-s4.c
        src-gles2/cwgl-gles2-s5.c
        src-gles2/cwgl-gles2-s6obj.c
        src-gles2/cwgl-gles2-s6shader.c
        src-gles2/cwgl-gles2-snone.c
        src-gles2/cwgl-gles2-vao.c
        )
endif()

add_library(cwgl OBJECT ${cwglsrc})

if(CWGL_KHRONOS_HEADER_DIR)
    target_include_directories(cwgl PRIVATE
        ${CWGL_KHRONOS_HEADER_DIR})
endif()

target_include_directories(cwgl PUBLIC include)
if(YFRM_CWGL_USE_ANGLE)
    target_link_libraries(cwgl PUBLIC angle_static)
endif()

