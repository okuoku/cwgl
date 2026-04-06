cmake_minimum_required(VERSION 3.12)
project(cwgl C CXX) # FIXME: Enable CXX only if we need SHXM

if(NOT CMAKE_CXX_STANDARD)
    # For SHXM
    set(CMAKE_CXX_STANDARD 17)
endif()

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
        src-tracker/cwgl-integ-tracker.c
        )
    add_definitions(-DCWGL_EXPERIMENTAL_TRACKER)

    if(YFRM_CWGL_USE_VULKAN)
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
        if(APPLE)
            # On Apple platforms, we'll use MoltenVk that includes
            # Vulkan entrypoints
            add_definitions(-DCWGL_USE_STATIC_VULKAN)
        else()
            # On other platforms, we link against platform Vulkan dynamically
            list(APPEND cwglsrc ${VOLK_ROOT}/volk.c)
            add_definitions(-DCWGL_EXPERIMENTAL_USE_VOLK)
        endif()
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
    if(YFRM_CWGL_USE_ANGLE OR CWGL_LEVEL_L2)
        # ANGLE always exports GLES3
        add_definitions(-DCWGL_LEVEL_L2)
    endif()
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
        src-gles2/cwgl-integ-gles2.c
        # L2
        src-gles2/cwgl-gles2-query.c
        src-gles2/cwgl-gles2-sampler.c
        src-gles2/cwgl-gles2-sync.c
        src-gles2/cwgl-gles2-tfb.c
        src-gles2/cwgl-gles2-ubo.c
        )
endif()

if(CWGL_USE_EGL_CTX)
    add_definitions(-DCWGL_USE_EGL_CTX)
    list(APPEND cwglsrc
        src-egl/cwgl-egl-ctx.c
    )
endif()

if(CWGL_BUILD_MODULE)
    add_library(cwgl SHARED ${cwglsrc})
    if(APPLE)
        # Configure dyld
        set_target_properties(cwgl
            PROPERTIES
            PREFIX ""
            SUFFIX ".dylib"
            MACOSX_RPATH ON
            BUILD_RPATH "@loader_path"
            INSTALL_RPATH "@loader_path"
            BUILD_WITH_INSTALL_RPATH ON)
        set(libname "cwgl.dylib")
    else()
        set(libname "libcwgl.so")
    endif()
    if(NCCC_DEBUG_NODE_MODULES)
        add_custom_command(TARGET cwgl POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            "$<TARGET_FILE:cwgl>"
            "${NCCC_DEBUG_NODE_MODULES}/${libname}")
    endif()

    target_link_libraries(cwgl PRIVATE
        EGL GLESv2)
else()
    # OBJECT by default for static link
    add_library(cwgl OBJECT ${cwglsrc})
endif()

if(CWGL_KHRONOS_HEADER_DIR)
    target_include_directories(cwgl PRIVATE
        ${CWGL_KHRONOS_HEADER_DIR})
endif()

target_include_directories(cwgl PUBLIC include)
if(YFRM_CWGL_USE_ANGLE)
    target_link_libraries(cwgl PUBLIC angle_static)
endif()

