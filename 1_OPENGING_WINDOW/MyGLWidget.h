#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <GL/glew.h>
#include <GL/gl.h>

#include "../Utils/GLWidget.h"

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
    GLuint      program;
    GLuint      vao;
};

#endif // MYGLWIDGET_H
