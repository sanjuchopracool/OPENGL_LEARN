#ifndef OPENGLSHADERPROGRAM_H
#define OPENGLSHADERPROGRAM_H

#include "OpenGLObject.h"

#include <memory>
#include <vector>

class OpenGLShader;
class OpenGLShaderProgram : public OpenGLObject
{
public:
    OpenGLShaderProgram();
    ~OpenGLShaderProgram();

    void attachShader( const OpenGLShader& inShader);
    void link();
    void bind();
};

#endif // OPENGLSHADERPROGRAM_H
