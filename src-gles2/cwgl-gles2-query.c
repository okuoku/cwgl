#define CWGL_DECL_ENUMS
#ifdef CWGL_LEVEL_L2
#include "cwgl-gles2-priv.h"

CWGL_API void 
cwgl_Query_release(cwgl_ctx* ctx, cwgl_Query* query){
    if(query){
        CTX_FREE(ctx, Query, query);
    }
}

CWGL_API cwgl_Query* 
cwgl_createQuery(cwgl_ctx* ctx){
    GLuint name = 0;
    cwgl_Query* o;
    CTX_ENTER(ctx);
    glGenQueries(1, &name);
    o = CTX_ALLOC(ctx, Query);
    CTX_SETNAME(ctx, o, name);
    CTX_LEAVE(ctx);
    return o;
}

CWGL_API void 
cwgl_deleteQuery(cwgl_ctx* ctx, cwgl_Query* query){
    GLuint name = 0;
    CTX_ENTER(ctx);
    if(query){
        name = CTX_GETNAME(ctx, query);
    }
    glDeleteQueries(1, &name);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_beginQuery(cwgl_ctx* ctx, cwgl_enum target, cwgl_Query* query){
    GLuint name = 0;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, query);
    glBeginQuery(target, name);
    CTX_LEAVE(ctx);
}

CWGL_API void 
cwgl_endQuery(cwgl_ctx* ctx, cwgl_enum target){
    CTX_ENTER(ctx);
    glEndQuery(target);
    CTX_LEAVE(ctx);
}

CWGL_API cwgl_Query* 
cwgl_getQuery(cwgl_ctx* ctx, cwgl_enum target, cwgl_enum pname){
    GLint name = 0;
    cwgl_Query* o;
    enum selection_e {
        occulusion,
        tfb,
        invalid
    };
    enum selection_e selection;
    switch(target){
        case ANY_SAMPLES_PASSED:
            selection = occulusion;
            break;
        case ANY_SAMPLES_PASSED_CONSERVATIVE:
            selection = occulusion;
            break;
        case TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN:
            selection = tfb;
            break;
        default:
            selection = invalid;
            break;
    }
    if(selection == invalid){
        // FIXME: Set error here
        return 0;
    }else{
        // FIXME: Returns a new query
        CTX_ENTER(ctx);
        glGetQueryiv(target, pname, &name);
        o = CTX_ALLOC(ctx, Query);
        CTX_SETNAME(ctx, o, name);
        CTX_LEAVE(ctx);
        return o;
    }
}

CWGL_API cwgl_query_result 
cwgl_getQueryParameter_u1(cwgl_ctx* ctx, cwgl_Query* query, cwgl_enum pname, uint32_t* out){
    GLenum e;
    GLuint name;
    GLuint res;
    CTX_ENTER(ctx);
    name = CTX_GETNAME(ctx, query);
    while(glGetError()){}
    glGetQueryObjectuiv(name, pname, &res);
    e = glGetError();
    if(e){
        return CWGL_QR_GLERROR;
    }
    CTX_LEAVE(ctx);
    *out = e;
    return CWGL_QR_SUCCESS;
}


#endif
