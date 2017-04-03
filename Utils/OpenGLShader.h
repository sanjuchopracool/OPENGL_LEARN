#ifndef OPENGLSHADER_H
#define OPENGLSHADER_H

#include "OpenGLObject.h"

#include <string>

class OpenGLShader : public OpenGLObject
{
public:

    enum class ShaderType : unsigned char
    {
        Vertex,
        Fragment,
    };

    OpenGLShader( ShaderType inType = ShaderType::Vertex, const std::string &inFilePath = std::string() );
    ~OpenGLShader();

    void loadFromFile(const std::string &inFilePath);

private:
    ShaderType mType;
};

#endif // OPENGLSHADER_H
