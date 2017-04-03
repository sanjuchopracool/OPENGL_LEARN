#include "OpenGLShader.h"
#include <fstream>
#include <streambuf>

#include <string>
#include <iostream>

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

    std::cout << "Shader :" << str << std::endl;
}

GLuint createShader( OpenGLShader::ShaderType inType )
{
    switch(inType) {
    case OpenGLShader::ShaderType::Vertex:
        return glCreateShader(GL_VERTEX_SHADER);
    case OpenGLShader::ShaderType::Fragment:
        return glCreateShader(GL_FRAGMENT_SHADER);
    default:
        return 0;
    }
}

OpenGLShader::OpenGLShader(OpenGLShader::ShaderType inType, const std::string &inFilePath )
    : mType(inType)
{
    setObject(createShader(mType));
    loadFromFile(inFilePath);
}

OpenGLShader::~OpenGLShader()
{

}

void OpenGLShader::loadFromFile(const std::string &inFilePath)
{
    std::ifstream inFile(inFilePath);
    std::string dataStr;

    inFile.seekg(0, std::ios::end);
    dataStr.reserve(inFile.tellg());
    inFile.seekg(0, std::ios::beg);

    dataStr.assign((std::istreambuf_iterator<char>(inFile)),
               std::istreambuf_iterator<char>());

    const char* data = dataStr.data();
    glShaderSource(mObject, 1, &data, NULL);
    glCompileShader(mObject);
    print_shader_log(mObject);
}
