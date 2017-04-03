#include "MyGLWidget.h"

#include <OpenGLShaderProgram.h>
#include <OpenGLShader.h>

MyGLWidget::MyGLWidget()
    : GLWidget( "Sample App", 800, 600 )
{

}

MyGLWidget::~MyGLWidget()
{

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

void MyGLWidget::init()
{
    // initialise glew
    glewInit();

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

    mProgram.reset(new OpenGLShaderProgram());
    mProgram->attachShader(OpenGLShader(OpenGLShader::ShaderType::Vertex, std::string("../Media/Shaders/Shader.vert")));
    mProgram->attachShader(OpenGLShader(OpenGLShader::ShaderType::Fragment, std::string("../Media/Shaders/Shader.frag")));
    mProgram->link();

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

}

void MyGLWidget::render()
{
    static const GLfloat green[] = { 0.0f, 0.25f, 0.0f, 1.0f };
    glClearBufferfv(GL_COLOR, 0, green);

    mProgram->bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
