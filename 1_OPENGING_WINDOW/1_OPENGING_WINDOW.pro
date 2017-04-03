TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../Utils
DEFINES += SFML_STATIC
SOURCES += main.cpp \
    MyGLWidget.cpp \
    ../Utils/GLWidget.cpp \
    ../Utils/OpenGLObject.cpp \
    ../Utils/OpenGLShaderProgram.cpp \
    ../Utils/OpenGLShader.cpp

LIBS +=  -lsfml-graphics -lsfml-window -lsfml-system -lGL -lGLEW

HEADERS += \
    MyGLWidget.h \
    ../Utils/GLWidget.h \
    ../Utils/OpenGLObject.h \
    ../Utils/OpenGLShaderProgram.h \
    ../Utils/OpenGLShader.h

DISTFILES += \
    ../Media/Shaders/Shader.frag \
    ../Media/Shaders/Shader.vert
