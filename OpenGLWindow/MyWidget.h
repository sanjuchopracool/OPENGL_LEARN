#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <GL/glew.h>
#include <GL/gl.h>

#include <QOpenGLWidget>
class MyWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

private:
    GLuint      texture;
    GLuint      program;
    GLuint      vao;
};

#endif // MYWIDGET_H
