#include "MyWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSurfaceFormat format(QSurfaceFormat::DeprecatedFunctions);
    format.setMajorVersion(4);
    format.setMinorVersion(5);
    format.setProfile( QSurfaceFormat::CoreProfile );
    format.setDepthBufferSize(24);
    format.setRenderableType( QSurfaceFormat::RenderableType::OpenGL );
    QSurfaceFormat::setDefaultFormat(format);

    MyWidget w;
    w.setFormat(format);
    w.show();

    return a.exec();
}

