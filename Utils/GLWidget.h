#ifndef GL_WIDGET_HPP
#define GL_WIDGET_HPP

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

class GLWidget
{
public:
    GLWidget( const std::string& inTitle,
              unsigned int inWidth,
              unsigned int inHeight,
              sf::ContextSettings inContextSetting = sf::ContextSettings(24, 8, 4, 4, 5),
              int inStyle = sf::Style::Default);

    virtual ~GLWidget();


    void					show();


protected:
    virtual void			processInput();
    virtual void            update(sf::Time dt);

    virtual void            init();
    virtual void            render();

private:
    virtual void            setupOpengGLProjection();
    virtual void        	renderWidget();
private:

    static const sf::Time	TimePerFrame;
    sf::RenderWindow		mWindow;
    bool                    mRunning = true;
};

#endif // GL_WIDGET_HPP
