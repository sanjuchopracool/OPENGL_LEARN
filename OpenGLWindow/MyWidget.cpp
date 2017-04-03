#include "MyWidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

MyWidget::~MyWidget()
{
    glDeleteProgram(program);
    glDeleteVertexArrays(1, &vao);
    glDeleteTextures(1, &texture);
}
void generate_texture(float * data, int width, int height)
{
    int x, y;

    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            data[(y * width + x) * 4 + 0] = (float)((x & y) & 0xFF) / 255.0f;
            data[(y * width + x) * 4 + 1] = (float)((x | y) & 0xFF) / 255.0f;
            data[(y * width + x) * 4 + 2] = (float)((x ^ y) & 0xFF) / 255.0f;
            data[(y * width + x) * 4 + 3] = 1.0f;
        }
    }
}

static const char * vs_source[] =
{
    "#version 420 core                                                              \n"
    "                                                                               \n"
    "void main(void)                                                                \n"
    "{                                                                              \n"
    "    const vec4 vertices[] = vec4[](vec4( 0.75, -0.75, 0.5, 1.0),               \n"
    "                                   vec4(-0.75, -0.75, 0.5, 1.0),               \n"
    "                                   vec4( 0.75,  0.75, 0.5, 1.0));              \n"
    "                                                                               \n"
    "    gl_Position = vertices[gl_VertexID];                                       \n"
    "}                                                                              \n"
};

static const char * fs_source[] =
{
    "#version 420 core                                                              \n"
    "                                                                               \n"
    "uniform sampler2D s;                                                           \n"
    "                                                                               \n"
    "out vec4 color;                                                                \n"
    "                                                                               \n"
    "void main(void)                                                                \n"
    "{                                                                              \n"
    "    color = texture(s, gl_FragCoord.x*gl_FragCoord.y / textureSize(s, 0));                   \n"
    "}                                                                              \n"
};
#include <string>
static void print_shader_log(GLuint shader)
{
    std::string str;
    GLint len;

    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
    if (len != 0)
    {
        str.resize(len);
        glGetShaderInfoLog(shader, len, NULL, &str[0]);
    }

#ifdef _WIN32
    OutputDebugStringA(str.c_str());
#endif
}
void MyWidget::initializeGL()
{
    makeCurrent();
    glewInit();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Generate a name for the texture
    glGenTextures(1, &texture);

    // Now bind it to the context using the GL_TEXTURE_2D binding point
    glBindTexture(GL_TEXTURE_2D, texture);

    // Specify the amount of storage we want to use for the texture
    glTexStorage2D(GL_TEXTURE_2D,   // 2D texture
                   8,               // 8 mipmap levels
                   GL_RGBA32F,      // 32-bit floating-point RGBA data
                   256, 256);       // 256 x 256 texels

    // Define some data to upload into the texture
    float * data = new float[256 * 256 * 4];

    // generate_texture() is a function that fills memory with image data
    generate_texture(data, 256, 256);

    // Assume the texture is already bound to the GL_TEXTURE_2D target
    glTexSubImage2D(GL_TEXTURE_2D,  // 2D texture
                    0,              // Level 0
                    0, 0,           // Offset 0, 0
                    256, 256,       // 256 x 256 texels, replace entire image
                    GL_RGBA,        // Four channel data
                    GL_FLOAT,       // Floating point data
                    data);          // Pointer to data

    // Free the memory we allocated before - \GL now has our data
    delete [] data;

    program = glCreateProgram();

    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, vs_source, NULL);
    glCompileShader(vs);

    print_shader_log(vs);

    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, fs_source, NULL);
    glCompileShader(fs);

    print_shader_log(fs);

    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);


    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
}

void MyWidget::paintGL()
{
    static const GLfloat green[] = { 0.0f, 0.25f, 0.0f, 1.0f };
    glClearBufferfv(GL_COLOR, 0, green);

    glUseProgram(program);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void MyWidget::resizeGL(int width, int height)
{
    makeCurrent();
    int side = qMin(width, height);
    glViewport(0, 0, width, height);
}
