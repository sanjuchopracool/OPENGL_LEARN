#include "GLWidget.h"

#include <iostream>
#include <sstream>

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <SFML/Window/Event.hpp>

template <typename T>
std::string toString(const T& value)
{
    std::stringstream stream;
    stream << value;
    return stream.str();
}

const sf::Time GLWidget::TimePerFrame = sf::seconds(1.f/60.f);

GLWidget::GLWidget(const std::string &inTitle,
                   unsigned int inWidth,
                   unsigned int inHeight,
                   sf::ContextSettings inContextSetting,
                   int inStyle)

    : mWindow(sf::VideoMode( inWidth, inHeight),
              inTitle,
              inStyle,
              inContextSetting)
{
    mWindow.setVerticalSyncEnabled(true);
}

GLWidget::~GLWidget()
{
    mWindow.close();
}

void GLWidget::show()
{
    init();
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mRunning)
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;

            processInput();
            update(TimePerFrame);
        }

//        updateStatistics(dt);
        renderWidget();
    }

    mWindow.close();
}

void GLWidget::processInput()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            // end the program
            mRunning = false;
        }
        else if (event.type == sf::Event::Resized)
        {
            // adjust the viewport when the window is resized
            glViewport(0, 0, event.size.width, event.size.height);
        }
    }
}

void GLWidget::update(sf::Time)
{
}

void GLWidget::renderWidget()
{
    mWindow.setView(mWindow.getDefaultView());
    render();
    mWindow.display();
}

void GLWidget::init()
{
}

void GLWidget::render()
{
}

void GLWidget::setupOpengGLProjection()
{
//    // Configure the viewport (the same size as the window)
//    glViewport(0, 0, mWindow.getSize().x, mWindow.getSize().y);
//    // Setup a perspective projection
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    GLfloat ratio = static_cast<float>(mWindow.getSize().x) / mWindow.getSize().y;
//    glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);
}
