#include "OpenGLObject.h"

#include <stdexcept>
void OpenGLObject::setObject(GLuint inObject)
{
    mObject = inObject;
    if( 0 == mObject )
        throw std::runtime_error("Failed to create OpenGL object!");
}

GLuint OpenGLObject::getObject() const
{
    return mObject;
}
