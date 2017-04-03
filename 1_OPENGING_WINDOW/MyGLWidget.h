#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <GL/glew.h>
#include <GL/gl.h>

#include <GLWidget.h>
#include <memory>

class OpenGLShaderProgram;
class MyGLWidget : public GLWidget
{
public:
    MyGLWidget();
    ~MyGLWidget();

protected:
    void init();
    void render();

private:
    GLuint      texture;
    GLuint      vao;
    std::unique_ptr<OpenGLShaderProgram> mProgram;
};

#endif // MYGLWIDGET_H
