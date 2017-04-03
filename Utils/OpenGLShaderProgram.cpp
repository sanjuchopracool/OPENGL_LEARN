#include "OpenGLShaderProgram.h"

#include "OpenGLShader.h"

OpenGLShaderProgram::OpenGLShaderProgram()
{
    setObject(glCreateProgram());
}

OpenGLShaderProgram::~OpenGLShaderProgram()
{
    glDeleteProgram(mObject);
}

void OpenGLShaderProgram::attachShader(const OpenGLShader &inShader)
{
    glAttachShader(mObject, inShader.getObject());
}

void OpenGLShaderProgram::link()
{
    glLinkProgram(mObject);
}

void OpenGLShaderProgram::bind()
{
    glUseProgram(mObject);
}
