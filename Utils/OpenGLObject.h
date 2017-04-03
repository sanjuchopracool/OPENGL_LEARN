#ifndef OPENGLOBJECT_H
#define OPENGLOBJECT_H

#include <boost/noncopyable.hpp>

#include <GL/glew.h>
#include <GL/gl.h>

class OpenGLObject : private boost::noncopyable
{
public:
    void setObject(GLuint inObject);
    GLuint getObject() const;

protected:
    GLuint  mObject = 0;
};

#endif // OPENGLOBJECT_H
