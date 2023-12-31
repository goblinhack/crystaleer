/*
 * Copyright (C) 2011-2017 goblinhack@gmail.com
 *
 * See the README file for license info for license.
 */

#include "glapi.h"

static void gl_init_fbo(void);

int gl_need_degen_;
float glapi_last_tex_right;
float glapi_last_tex_bottom;
float glapi_last_right;
float glapi_last_bottom;

void gl_init_2d_mode (void)
{
    /*
     * Enable Texture Mapping
     */
    glEnable(GL_TEXTURE_2D);

    /*
     * Enable alpha blending for sprites
     */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    /*
     * Setup our viewport
     */
    glViewport(0, 0, game.video_pix_width,
               game.video_pix_height);

    /*
     * Make sure we're changing the model view and not the projection
     */
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    /*
     * Reset the view
     */
    glLoadIdentity();

    gl_init_fbo();
}

void gl_enter_2d_mode (void)
{
    /*
     * Change to the projection matrix and set our viewing volume.
     */
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();

    /*
     * Reset the view
     */
    glLoadIdentity();

    /*
     * 2D projection
     */
    glOrtho(0,
             game.video_gl_width, game.video_gl_height,
             0, -1200.0, 1200.0);

    /*
     * Make sure we're changing the model view and not the projection
     */
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    /*
     * Reset the view
     */
    glLoadIdentity();
}

void
gl_leave_2d_mode (void)
{
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
}

void gl_enter_2_5d_mode (void)
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();

    glLoadIdentity();

    double scale = 15;
    glOrtho(-scale, 
            scale, 
            -scale * 0.7, 
            scale * 0.7,
            -scale,
            scale);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glLoadIdentity();

    glRotatef(35.264f, 1.0f, 0.0f, 0.0f);
    glRotatef(-45.0f, 0.0f, 1.0f, 0.0f);

#ifdef WIREFRAME
    glPolygonMode(GL_FRONT, GL_LINE); // draw wireframe polygons
    glPolygonMode(GL_BACK, GL_LINE); // draw wireframe polygons
#endif

    glCullFace(GL_BACK); // don't draw back faces
}

void
gl_leave_2_5d_mode (void)
{
    glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
}

static void gl_init_fbo_ (
    GLuint *render_buf_id,
    GLuint *fbo_id,
    GLuint *fbo_tex_id)
{
    GLuint tex_width = game.video_pix_width;
    GLuint tex_height = game.video_pix_height;

    glGenTextures(1, fbo_tex_id);
    glBindTexture(GL_TEXTURE_2D, *fbo_tex_id);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8,
                 tex_width, tex_height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, 0);
    glBindTexture(GL_TEXTURE_2D, 0);

    /*
     * Create a render buffer object.
     */
#ifdef _WIN32
    if (!glFramebufferTexture2D_EXT) {
        SDL_MSG_BOX("glGenRenderbuffers_EXT is not present; fatal");
        DIE("glGenRenderbuffers_EXT is not present; fatal");
    }
#endif

    glGenRenderbuffers_EXT(1, render_buf_id);
    glBindRenderbuffer_EXT(GL_RENDERBUFFER, *render_buf_id);
    glRenderbufferStorage_EXT(GL_RENDERBUFFER, GL_DEPTH_COMPONENT,
                          tex_width, tex_height);
    glBindRenderbuffer_EXT(GL_RENDERBUFFER, 0);

    /*
     * Create a frame buffer object.
     */
    glGenFramebuffers_EXT(1, fbo_id);
    glBindFramebuffer_EXT(GL_FRAMEBUFFER, *fbo_id);

    /*
     * Attach the texture to FBO color attachment point
     */
    glFramebufferTexture2D_EXT(GL_FRAMEBUFFER,        // 1. fbo target: GL_FRAMEBUFFER
                           GL_COLOR_ATTACHMENT0,  // 2. attachment point
                           GL_TEXTURE_2D,         // 3. tex target: GL_TEXTURE_2D
                           *fbo_tex_id,           // 4. tex ID
                           0);                    // 5. mipmap level: 0(base)

    /*
     * Attach the renderbuffer to depth attachment point
     */
    glFramebufferRenderbuffer_EXT(GL_FRAMEBUFFER,      // 1. fbo target: GL_FRAMEBUFFER
                              GL_DEPTH_ATTACHMENT, // 2. attachment point
                              GL_RENDERBUFFER,     // 3. rbo target: GL_RENDERBUFFER
                              *render_buf_id);     // 4. rbo ID

    /*
     * Check FBO status
     */
    GLenum status = glCheckFramebufferStatus_EXT(GL_FRAMEBUFFER);
    if (status != GL_FRAMEBUFFER_COMPLETE) {
        ERR("Failed to create framebuffer");
    }

    // switch back to window-system-provided framebuffer
    glBindFramebuffer_EXT(GL_FRAMEBUFFER, 0);
}

GLuint render_buf_id1;
GLuint fbo_id1;
GLuint fbo_tex_id1;

GLuint render_buf_id_wid;
GLuint fbo_id_wid;
GLuint fbo_tex_id_wid;

static void gl_init_fbo (void)
{
    gl_init_fbo_(&render_buf_id1, &fbo_id1, &fbo_tex_id1);
    gl_init_fbo_(&render_buf_id_wid, &fbo_id_wid, &fbo_tex_id_wid);
}

/*
 * x and y per element.
 */
#define NUMBER_DIMENSIONS_PER_COORD_2D 2
#define NUMBER_DIMENSIONS_PER_COORD_3D 3

/*
 * r,g,b,a per element
 */
#define NUMBER_COMPONENTS_PER_COLOR 4

const uint32_t NUMBER_BYTES_PER_VERTICE_2D =
                                            sizeof(GLfloat) *
                                            NUMBER_DIMENSIONS_PER_COORD_2D +
                                            sizeof(GLfloat) *
                                            NUMBER_DIMENSIONS_PER_COORD_2D +
                                            sizeof(GLfloat) *
                                            NUMBER_COMPONENTS_PER_COLOR;

const uint32_t NUMBER_BYTES_PER_VERTICE_3D =
                                            sizeof(GLfloat) *
                                            NUMBER_DIMENSIONS_PER_COORD_2D +
                                            sizeof(GLfloat) *
                                            NUMBER_DIMENSIONS_PER_COORD_3D +
                                            sizeof(GLfloat) *
                                            NUMBER_COMPONENTS_PER_COLOR;

const uint32_t NUMBER_FLOATS_PER_VERTICE_2D = NUMBER_BYTES_PER_VERTICE_2D / sizeof(float);
const uint32_t NUMBER_FLOATS_PER_VERTICE_3D = NUMBER_BYTES_PER_VERTICE_3D / sizeof(float);

/*
 * Two arrays, xy and uv.
 */
static float *gl_array_buf;
static float *gl_array_buf_end;

/*
 * Where we are currently up to in writing to these buffers.
 */
GLfloat *bufp;
GLfloat *bufp_end;
int buf_tex;

void blit_init (void)
{
    buf_tex = 0;

    if (gl_array_buf) {
        bufp = gl_array_buf;
        return;
    }

    /*
     * Our array size requirements.
     */
    uint32_t gl_array_size_required;

    /*
     * If the screen size has changed or this is the first run, allocate our
     * buffer if our size requirements have changed.
     */
    gl_array_size_required = 32 * 1024 * 1024;

    gl_array_buf = (TYPEOF(gl_array_buf))
                    myzalloc(gl_array_size_required, "GL xy buffer");

    /*
     * Make the end a bit smaller so we have plenty of headroom.
     */
    gl_array_buf_end =
            (TYPEOF(gl_array_buf_end))
                ((char *)gl_array_buf) +
                ((gl_array_size_required * 2) / 3);

    bufp = gl_array_buf;
    bufp_end = gl_array_buf_end;
}

void blit_fini (void)
{
    if (gl_array_buf) {
        myfree(gl_array_buf);
        gl_array_buf = 0;
    }
}

void blit_flush (void)
{
    if (gl_array_buf == bufp) {
        return;
    }

    /*
     * Display all the tiles selected above in one blast.
     */
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    static long nvertices;

    nvertices = ((char*)bufp - (char*)gl_array_buf) /
                    NUMBER_BYTES_PER_VERTICE_2D;

    glBindTexture(GL_TEXTURE_2D, buf_tex);

    glTexCoordPointer(
        NUMBER_DIMENSIONS_PER_COORD_2D, // (u,v)
        GL_FLOAT,
        NUMBER_BYTES_PER_VERTICE_2D,
        gl_array_buf);

    glVertexPointer(
        NUMBER_DIMENSIONS_PER_COORD_2D, // (x,y)
        GL_FLOAT,
        NUMBER_BYTES_PER_VERTICE_2D,
        ((char*)gl_array_buf) +
            sizeof(GLfloat) *        // skip (u,v)
            NUMBER_DIMENSIONS_PER_COORD_2D);

    glColorPointer(
        NUMBER_COMPONENTS_PER_COLOR, // (r,g,b,a)
        GL_FLOAT,
        NUMBER_BYTES_PER_VERTICE_2D,
        ((char*)gl_array_buf) +
            sizeof(GLfloat) *        // skip (x,y)
            NUMBER_DIMENSIONS_PER_COORD_2D +
            sizeof(GLfloat) *        // skip (u,v)
            NUMBER_DIMENSIONS_PER_COORD_2D);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, (GLsizei) nvertices);

    glBindTexture(GL_TEXTURE_2D, 0);

    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    blit_init();
}

void blit_flush_3d (void)
{
    if (gl_array_buf == bufp) {
        return;
    }

    /*
     * Display all the tiles selected above in one blast.
     */
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    static long nvertices;

    nvertices = ((char*)bufp - (char*)gl_array_buf) /
                    NUMBER_BYTES_PER_VERTICE_3D;

    glBindTexture(GL_TEXTURE_2D, buf_tex);

    glTexCoordPointer(
        NUMBER_DIMENSIONS_PER_COORD_2D, // (u,v)
        GL_FLOAT,
        NUMBER_BYTES_PER_VERTICE_3D,
        gl_array_buf);

    glVertexPointer(
        NUMBER_DIMENSIONS_PER_COORD_3D, // (x,y)
        GL_FLOAT,
        NUMBER_BYTES_PER_VERTICE_3D,
        ((char*)gl_array_buf) +
            sizeof(GLfloat) *        // skip (u,v)
            NUMBER_DIMENSIONS_PER_COORD_2D);

    glColorPointer(
        NUMBER_COMPONENTS_PER_COLOR, // (r,g,b,a)
        GL_FLOAT,
        NUMBER_BYTES_PER_VERTICE_3D,
        ((char*)gl_array_buf) +
            sizeof(GLfloat) *        // skip (x,y)
            NUMBER_DIMENSIONS_PER_COORD_3D +
            sizeof(GLfloat) *        // skip (u,v)
            NUMBER_DIMENSIONS_PER_COORD_2D);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, (GLsizei) nvertices);

    glBindTexture(GL_TEXTURE_2D, 0);

    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    blit_init();
}

void blit_flush_colored_triangles (void)
{
    if (gl_array_buf == bufp) {
        return;
    }

    /*
     * Display all the tiles selected above in one blast.
     */
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    static long nvertices;

    static const GLsizei stride =
                        sizeof(GLfloat) *
                        NUMBER_DIMENSIONS_PER_COORD_2D +
                        sizeof(GLfloat) *
                        NUMBER_COMPONENTS_PER_COLOR;

    nvertices = ((char*)bufp - (char*)gl_array_buf) / stride;

    glVertexPointer(
        NUMBER_DIMENSIONS_PER_COORD_2D, // (x,y)
        GL_FLOAT,
        stride,
        gl_array_buf);

    glColorPointer(
        NUMBER_COMPONENTS_PER_COLOR, // (r,g,b,a)
        GL_FLOAT,
        stride,
        ((char*)gl_array_buf) +
            sizeof(GLfloat) *        // skip (x,y)
            NUMBER_DIMENSIONS_PER_COORD_2D);

    glDrawArrays(GL_TRIANGLES, 0, (GLsizei) nvertices);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    blit_init();
}

void blit_flush_triangle_fan (void)
{
    if (gl_array_buf == bufp) {
        return;
    }

    /*
     * Display all the tiles selected above in one blast.
     */
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    static long nvertices;

    static const GLsizei stride =
                        sizeof(GLfloat) *
                        NUMBER_DIMENSIONS_PER_COORD_2D +
                        sizeof(GLfloat) *
                        NUMBER_COMPONENTS_PER_COLOR;

    nvertices = ((char*)bufp - (char*)gl_array_buf) / stride;

    glVertexPointer(
        NUMBER_DIMENSIONS_PER_COORD_2D, // (x,y)
        GL_FLOAT,
        stride,
        gl_array_buf);

    glColorPointer(
        NUMBER_COMPONENTS_PER_COLOR, // (r,g,b,a)
        GL_FLOAT,
        stride,
        ((char*)gl_array_buf) +
            sizeof(GLfloat) *        // skip (x,y)
            NUMBER_DIMENSIONS_PER_COORD_2D);

    glDrawArrays(GL_TRIANGLE_FAN, 0, (GLsizei) nvertices);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    blit_init();
}

void blit_flush_tex_triangle_fan (void)
{
    if (gl_array_buf == bufp) {
        return;
    }

    /*
     * Display all the tiles selected above in one blast.
     */
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    static long nvertices;

    nvertices = ((char*)bufp - (char*)gl_array_buf) /
                    NUMBER_BYTES_PER_VERTICE_2D;

    glBindTexture(GL_TEXTURE_2D, buf_tex);

    glTexCoordPointer(
        NUMBER_DIMENSIONS_PER_COORD_2D, // (u,v)
        GL_FLOAT,
        NUMBER_BYTES_PER_VERTICE_2D,
        gl_array_buf);

    glVertexPointer(
        NUMBER_DIMENSIONS_PER_COORD_2D, // (x,y)
        GL_FLOAT,
        NUMBER_BYTES_PER_VERTICE_2D,
        ((char*)gl_array_buf) +
            sizeof(GLfloat) *        // skip (x,y)
            NUMBER_DIMENSIONS_PER_COORD_2D);

    glColorPointer(
        NUMBER_COMPONENTS_PER_COLOR, // (r,g,b,a)
        GL_FLOAT,
        NUMBER_BYTES_PER_VERTICE_2D,
        ((char*)gl_array_buf) +
            sizeof(GLfloat) *        // skip (x,y)
            NUMBER_DIMENSIONS_PER_COORD_2D +
            sizeof(GLfloat) *        // skip (u,v)
            NUMBER_DIMENSIONS_PER_COORD_2D);

    glDrawArrays(GL_TRIANGLE_FAN, 0, (GLsizei) nvertices);

    glBindTexture(GL_TEXTURE_2D, 0);

    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    blit_init();
}

void blit_flush_triangle_strip (void)
{
    if (gl_array_buf == bufp) {
        return;
    }

    /*
     * Display all the tiles selected above in one blast.
     */
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    static long nvertices;

    static const GLsizei stride =
                        sizeof(GLfloat) *
                        NUMBER_DIMENSIONS_PER_COORD_2D +
                        sizeof(GLfloat) *
                        NUMBER_COMPONENTS_PER_COLOR;

    nvertices = ((char*)bufp - (char*)gl_array_buf) / stride;

    glVertexPointer(
        NUMBER_DIMENSIONS_PER_COORD_2D, // (x,y)
        GL_FLOAT,
        stride,
        gl_array_buf);

    glColorPointer(
        NUMBER_COMPONENTS_PER_COLOR, // (r,g,b,a)
        GL_FLOAT,
        stride,
        ((char*)gl_array_buf) +
            sizeof(GLfloat) *        // skip (x,y)
            NUMBER_DIMENSIONS_PER_COORD_2D);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, (GLsizei) nvertices);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    blit_init();
}

void blit_flush_triangles (void)
{
    if (gl_array_buf == bufp) {
        return;
    }

    /*
     * Display all the tiles selected above in one blast.
     */
    glEnableClientState(GL_VERTEX_ARRAY);

    static long number_bytes_per_vertice_2d =
                    sizeof(GLfloat) * NUMBER_DIMENSIONS_PER_COORD_2D;

    long nvertices = ((char*)bufp - (char*)gl_array_buf) /
                    number_bytes_per_vertice_2d;

    glBindTexture(GL_TEXTURE_2D, 0);

    glVertexPointer(
        NUMBER_DIMENSIONS_PER_COORD_2D, // (x,y)
        GL_FLOAT,
        0, // stride
        ((char*)gl_array_buf));

    glDrawArrays(GL_TRIANGLES, 0, (GLsizei) nvertices);

    glDisableClientState(GL_VERTEX_ARRAY);

    blit_init();
}

void gl_blitquad (float left, float top, float right, float bottom)
{
    GLfloat xy[4*2];
    GLfloat *xyp = xy;

    Vertex2f(left, top);
    Vertex2f(right, top);
    Vertex2f(left, bottom);
    Vertex2f(right, bottom);

    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(2, GL_FLOAT, 0, xy);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
}

void gl_blitsquare (float left, float top, float right, float bottom)
{
    GLfloat xy[4*2];
    GLfloat *xyp = xy;

    Vertex2f(left, top);
    Vertex2f(right, top);
    Vertex2f(right, bottom);
    Vertex2f(left, bottom);

    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(2, GL_FLOAT, 0, xy);
    glDrawArrays(GL_LINE_LOOP, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
}

void gl_blitline (float left, float top, float right, float bottom)
{
    GLfloat xy[2*2];
    GLfloat *xyp = xy;

    Vertex2f(left, top);
    Vertex2f(right, bottom);

    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(2, GL_FLOAT, 0, xy);
    glDrawArrays(GL_LINES, 0, 2);

    glDisableClientState(GL_VERTEX_ARRAY);
}

void gl_blitline3d (float x1, float y1, float z1,
                    float x2, float y2, float z2)
{
    GLfloat xyz[3*2];
    GLfloat *xyp = xyz;

    Vertex3f(x1, z1, y1);
    Vertex3f(x2, z2, y2);

    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, xyz);
    glDrawArrays(GL_LINES, 0, 2);

    glDisableClientState(GL_VERTEX_ARRAY);
}

void gl_ortho_set (int32_t width, int32_t height)
{
    game.video_gl_width = width;
    game.video_gl_height = height;

    game.xscale = (float)game.video_gl_width / (float)width;
    game.yscale = (float)game.video_gl_height / (float)height;
}

#ifdef _WIN32

HDC hDC;
HGLRC hGLRC;
HPALETTE hPalette;

const char g_szClassName[] = "myWindowClass";

PFNGLCREATEPROGRAMPROC glCreateProgram_EXT;
PFNGLDELETEPROGRAMPROC glDeleteProgram_EXT;
PFNGLISPROGRAMPROC glIsProgram_EXT;
PFNGLCREATESHADERPROC glCreateShader_EXT;
PFNGLDELETESHADERPROC glDeleteShader_EXT;
PFNGLSHADERSOURCEPROC glShaderSource_EXT;
PFNGLCOMPILESHADERPROC glCompileShader_EXT;
PFNGLATTACHSHADERPROC glAttachShader_EXT;
PFNGLDETACHSHADERPROC glDetachShader_EXT;
PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders_EXT;
PFNGLLINKPROGRAMPROC glLinkProgram_EXT;
PFNGLUSEPROGRAMPROC glUseProgram_EXT;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog_EXT;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog_EXT;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation_EXT;
PFNGLUNIFORM1FPROC glUniform1f_EXT;
PFNGLUNIFORM1IPROC glUniform1i_EXT;
PFNGLUNIFORM2FVPROC glUniform2fv_EXT;
PFNGLUNIFORM3FVPROC glUniform3fv_EXT;
PFNGLGENERATEMIPMAPPROC glGenerateMipmap_EXT;
PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers_EXT;
PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers_EXT;
PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer_EXT;
PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers_EXT;
PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers_EXT;
PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer_EXT;
PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage_EXT;
PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer_EXT;
PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D_EXT;
PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus_EXT;
PFNGLGENBUFFERSARBPROC glGenBuffersARB_EXT;
PFNGLBINDBUFFERARBPROC glBindBufferARB_EXT;
PFNGLBUFFERDATAARBPROC glBufferDataARB_EXT;
PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB_EXT;

static void gl_ext_load (void)
{
    glCreateProgram_EXT =
        (TYPEOF(glCreateProgram_EXT))
        wglGetProcAddress("glCreateProgram");
    if (!glCreateProgram_EXT) {
        SDL_MSG_BOX("glCreateProgram failed to find OpenGL extension");
    }


    glDeleteProgram_EXT =
        (TYPEOF(glDeleteProgram_EXT)) wglGetProcAddress("glDeleteProgram");
    if (!glDeleteProgram_EXT) {
        SDL_MSG_BOX("glDeleteProgram failed to find OpenGL extension");
    }


    glIsProgram_EXT =
        (TYPEOF(glIsProgram_EXT)) wglGetProcAddress("glIsProgram");
    if (!glIsProgram_EXT) {
        SDL_MSG_BOX("glIsProgram failed to find OpenGL extension");
    }


    glCreateShader_EXT =
        (TYPEOF(glCreateShader_EXT)) wglGetProcAddress("glCreateShader");
    if (!glCreateShader_EXT) {
        SDL_MSG_BOX("glCreateShader failed to find OpenGL extension");
    }


    glDeleteShader_EXT =
        (TYPEOF(glDeleteShader_EXT)) wglGetProcAddress("glDeleteShader");
    if (!glDeleteShader_EXT) {
        SDL_MSG_BOX("glDeleteShader failed to find OpenGL extension");
    }


    glShaderSource_EXT =
        (TYPEOF(glShaderSource_EXT)) wglGetProcAddress("glShaderSource");
    if (!glShaderSource_EXT) {
        SDL_MSG_BOX("glShaderSource failed to find OpenGL extension");
    }


    glCompileShader_EXT =
        (TYPEOF(glCompileShader_EXT)) wglGetProcAddress("glCompileShader");
    if (!glCompileShader_EXT) {
        SDL_MSG_BOX("glCompileShader failed to find OpenGL extension");
    }


    glAttachShader_EXT =
        (TYPEOF(glAttachShader_EXT)) wglGetProcAddress("glAttachShader");
    if (!glAttachShader_EXT) {
        SDL_MSG_BOX("glAttachShader failed to find OpenGL extension");
    }


    glDetachShader_EXT =
        (TYPEOF(glDetachShader_EXT)) wglGetProcAddress("glDetachShader");
    if (!glDetachShader_EXT) {
        SDL_MSG_BOX("glDetachShader failed to find OpenGL extension");
    }


    glGetAttachedShaders_EXT =
        (TYPEOF(glGetAttachedShaders_EXT)) wglGetProcAddress("glGetAttachedShaders");
    if (!glGetAttachedShaders_EXT) {
        SDL_MSG_BOX("glGetAttachedShaders failed to find OpenGL extension");
    }


    glLinkProgram_EXT =
        (TYPEOF(glLinkProgram_EXT)) wglGetProcAddress("glLinkProgram");
    if (!glLinkProgram_EXT) {
        SDL_MSG_BOX("glLinkProgram failed to find OpenGL extension");
    }


    glUseProgram_EXT =
        (TYPEOF(glUseProgram_EXT)) wglGetProcAddress("glUseProgram");
    if (!glUseProgram_EXT) {
        SDL_MSG_BOX("glUseProgram failed to find OpenGL extension");
    }


    glGetShaderInfoLog_EXT =
        (TYPEOF(glGetShaderInfoLog_EXT)) wglGetProcAddress("glGetShaderInfoLog");
    if (!glGetShaderInfoLog_EXT) {
        SDL_MSG_BOX("glGetShaderInfoLog failed to find OpenGL extension");
    }


    glGetProgramInfoLog_EXT =
        (TYPEOF(glGetProgramInfoLog_EXT)) wglGetProcAddress("glGetProgramInfoLog");
    if (!glGetProgramInfoLog_EXT) {
        SDL_MSG_BOX("glGetProgramInfoLog failed to find OpenGL extension");
    }


    glGetUniformLocation_EXT =
        (TYPEOF(glGetUniformLocation_EXT)) wglGetProcAddress("glGetUniformLocation");
    if (!glGetUniformLocation_EXT) {
        SDL_MSG_BOX("glGetUniformLocation failed to find OpenGL extension");
    }


    glUniform1f_EXT =
        (TYPEOF(glUniform1f_EXT)) wglGetProcAddress("glUniform1f");
    if (!glUniform1f_EXT) {
        SDL_MSG_BOX("glUniform1f failed to find OpenGL extension");
    }


    glUniform1i_EXT =
        (TYPEOF(glUniform1i_EXT)) wglGetProcAddress("glUniform1i");
    if (!glUniform1i_EXT) {
        SDL_MSG_BOX("glUniform1i failed to find OpenGL extension");
    }


    glUniform2fv_EXT =
        (TYPEOF(glUniform2fv_EXT)) wglGetProcAddress("glUniform2fv");
    if (!glUniform2fv_EXT) {
        SDL_MSG_BOX("glUniform2fv failed to find OpenGL extension");
    }


    glUniform3fv_EXT =
        (TYPEOF(glUniform3fv_EXT)) wglGetProcAddress("glUniform3fv");
    if (!glUniform3fv_EXT) {
        SDL_MSG_BOX("glUniform3fv failed to find OpenGL extension");
    }


    glGenerateMipmap_EXT =
        (TYPEOF(glGenerateMipmap_EXT)) wglGetProcAddress("glGenerateMipmap");
    if (!glGenerateMipmap_EXT) {
        SDL_MSG_BOX("glGenerateMipmap failed to find OpenGL extension");
    }


    glGenFramebuffers_EXT =
        (TYPEOF(glGenFramebuffers_EXT)) wglGetProcAddress("glGenFramebuffers");
    if (!glGenFramebuffers_EXT) {
        SDL_MSG_BOX("glGenFramebuffers failed to find OpenGL extension");
    }


    glDeleteFramebuffers_EXT =
        (TYPEOF(glDeleteFramebuffers_EXT)) wglGetProcAddress("glDeleteFramebuffers");
    if (!glDeleteFramebuffers_EXT) {
        SDL_MSG_BOX("glDeleteFramebuffers failed to find OpenGL extension");
    }


    glBindFramebuffer_EXT =
        (TYPEOF(glBindFramebuffer_EXT)) wglGetProcAddress("glBindFramebuffer");
    if (!glBindFramebuffer_EXT) {
        SDL_MSG_BOX("glBindFramebuffer failed to find OpenGL extension");
    }


    glGenRenderbuffers_EXT =
        (TYPEOF(glGenRenderbuffers_EXT)) wglGetProcAddress("glGenRenderbuffers");
    if (!glGenRenderbuffers_EXT) {
        SDL_MSG_BOX("glGenRenderbuffers failed to find OpenGL extension");
    }


    glDeleteRenderbuffers_EXT =
        (TYPEOF(glDeleteRenderbuffers_EXT)) wglGetProcAddress("glDeleteRenderbuffers");
    if (!glDeleteRenderbuffers_EXT) {
        SDL_MSG_BOX("glDeleteRenderbuffers failed to find OpenGL extension");
    }


    glBindRenderbuffer_EXT =
        (TYPEOF(glBindRenderbuffer_EXT)) wglGetProcAddress("glBindRenderbuffer");
    if (!glBindRenderbuffer_EXT) {
        SDL_MSG_BOX("glBindRenderbuffer failed to find OpenGL extension");
    }


    glRenderbufferStorage_EXT =
        (TYPEOF(glRenderbufferStorage_EXT)) wglGetProcAddress("glRenderbufferStorage");
    if (!glRenderbufferStorage_EXT) {
        SDL_MSG_BOX("glRenderbufferStorage failed to find OpenGL extension");
    }


    glFramebufferRenderbuffer_EXT =
        (TYPEOF(glFramebufferRenderbuffer_EXT)) wglGetProcAddress("glFramebufferRenderbuffer");
    if (!glFramebufferRenderbuffer_EXT) {
        SDL_MSG_BOX("glFramebufferRenderbuffer failed to find OpenGL extension");
    }


    glFramebufferTexture2D_EXT =
        (TYPEOF(glFramebufferTexture2D_EXT)) wglGetProcAddress("glFramebufferTexture2D");
    if (!glFramebufferTexture2D_EXT) {
        SDL_MSG_BOX("glFramebufferTexture2D failed to find OpenGL extension");
    }

    glGenBuffersARB_EXT =
        (TYPEOF(glGenBuffersARB_EXT)) wglGetProcAddress("glGenBuffersARB");
    if (!glGenBuffersARB_EXT) {
        SDL_MSG_BOX("glGenBuffersARB failed to find OpenGL extension");
    }

    glBindBufferARB_EXT =
        (TYPEOF(glBindBufferARB_EXT)) wglGetProcAddress("glBindBufferARB");
    if (!glBindBufferARB_EXT) {
        SDL_MSG_BOX("glBindBufferARB failed to find OpenGL extension");
    }

    glDeleteBuffersARB_EXT =
        (TYPEOF(glDeleteBuffersARB_EXT)) wglGetProcAddress("glDeleteBuffersARB");
    if (!glDeleteBuffersARB_EXT) {
        SDL_MSG_BOX("glDeleteBuffersARB failed to find OpenGL extension");
    }

    glDeleteBuffersARB_EXT =
        (TYPEOF(glDeleteBuffersARB_EXT)) wglGetProcAddress("glDeleteBuffersARB");
    if (!glDeleteBuffersARB_EXT) {
        SDL_MSG_BOX("glDeleteBuffersARB failed to find OpenGL extension");
    }
}

static void
setupPixelFormat(HDC hDC)
{
    PIXELFORMATDESCRIPTOR pfd = {
        sizeof(PIXELFORMATDESCRIPTOR),  /* size */
        1,                              /* version */
        PFD_SUPPORT_OPENGL |
        PFD_DRAW_TO_WINDOW |
        PFD_DOUBLEBUFFER,               /* support double-buffering */
        PFD_TYPE_RGBA,                  /* color type */
        16,                             /* prefered color depth */
        0, 0, 0, 0, 0, 0,               /* color bits (ignored) */
        0,                              /* no alpha buffer */
        0,                              /* alpha bits (ignored) */
        0,                              /* no accumulation buffer */
        0, 0, 0, 0,                     /* accum bits (ignored) */
        16,                             /* depth buffer */
        0,                              /* no stencil buffer */
        0,                              /* no auxiliary buffers */
        PFD_MAIN_PLANE,                 /* main layer */
        0,                              /* reserved */
        0, 0, 0,                        /* no layer, visible, damage masks */
    };
    int pixelFormat;

    pixelFormat = ChoosePixelFormat(hDC, &pfd);
    if (pixelFormat == 0) {
        MessageBox(WindowFromDC(hDC), "ChoosePixelFormat failed.", "Error",
                MB_ICONERROR | MB_OK);
        exit(1);
    }

    if (SetPixelFormat(hDC, pixelFormat, &pfd) != TRUE) {
        MessageBox(WindowFromDC(hDC), "SetPixelFormat failed.", "Error",
                MB_ICONERROR | MB_OK);
        exit(1);
    }
}

static void
setupPalette(HDC hDC)
{
    int pixelFormat = GetPixelFormat(hDC);
    PIXELFORMATDESCRIPTOR pfd;
    LOGPALETTE* pPal;
    int paletteSize;

    DescribePixelFormat(hDC, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

    if (pfd.dwFlags & PFD_NEED_PALETTE) {
        paletteSize = 1 << pfd.cColorBits;
    } else {
        return;
    }

    pPal = (LOGPALETTE*)
        malloc(sizeof(LOGPALETTE) + paletteSize * sizeof(PALETTEENTRY));
    pPal->palVersion = 0x300;
    pPal->palNumEntries = paletteSize;

    /* build a simple RGB color palette */
    {
        int redMask = (1 << pfd.cRedBits) - 1;
        int greenMask = (1 << pfd.cGreenBits) - 1;
        int blueMask = (1 << pfd.cBlueBits) - 1;
        int i;

        for (i=0; i<paletteSize; ++i) {
            pPal->palPalEntry[i].peRed =
                    (((i >> pfd.cRedShift) & redMask) * 255) / redMask;
            pPal->palPalEntry[i].peGreen =
                    (((i >> pfd.cGreenShift) & greenMask) * 255) / greenMask;
            pPal->palPalEntry[i].peBlue =
                    (((i >> pfd.cBlueShift) & blueMask) * 255) / blueMask;
            pPal->palPalEntry[i].peFlags = 0;
        }
    }

    hPalette = CreatePalette(pPal);
    free(pPal);

    if (hPalette) {
        SelectPalette(hDC, hPalette, FALSE);
        RealizePalette(hDC);
    }
}

static LRESULT APIENTRY
WndProc(
    HWND hWnd,
    UINT message,
    WPARAM wParam,
    LPARAM lParam)
{
    return DefWindowProc(hWnd, message, wParam, lParam);
}

void gl_ext_init (void)
{
    WNDCLASSEX wc;
    HWND hwnd;

    HINSTANCE hInstance = GetModuleHandle(0);

    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return;
    }

    hwnd = CreateWindowEx(
                        WS_EX_CLIENTEDGE,
                        g_szClassName,
                        "crystaleer startup",
                        WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
                        NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return;
    }

    ShowWindow(hwnd, 0);
    UpdateWindow(hwnd);

    /* initialize OpenGL rendering */

    hDC = GetDC(hwnd);
    setupPixelFormat(hDC);
    setupPalette(hDC);
    hGLRC = wglCreateContext(hDC);
    wglMakeCurrent(hDC, hGLRC);

    gl_ext_load();

    /* finish OpenGL rendering */
    if (hGLRC) {
        wglMakeCurrent(NULL, NULL);
        wglDeleteContext(hGLRC);
    }

    if (hPalette) {
        DeleteObject(hPalette);
    }

    ReleaseDC(hwnd, hDC);
}
#else
void gl_ext_init (void)
{
}
#endif
