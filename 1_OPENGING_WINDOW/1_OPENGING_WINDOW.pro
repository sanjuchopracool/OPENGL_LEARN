TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += SFML_STATIC
SOURCES += main.cpp \
    MyGLWidget.cpp \
    ../Utils/GLWidget.cpp

LIBS +=  -lsfml-graphics -lsfml-window -lsfml-system -lGL -lGLEW

HEADERS += \
    MyGLWidget.h \
    ../Utils/GLWidget.h
