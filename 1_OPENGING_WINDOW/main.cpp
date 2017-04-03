#include <iostream>
#include "MyGLWidget.h"

int main()
{
    try
    {
        MyGLWidget app;
        app.show();
    }
    catch (std::exception& e)
    {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }

    return 0;
}
