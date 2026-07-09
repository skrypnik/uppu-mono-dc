#include <QGuiApplication>

#include <engine/ApplicationEngine.h>

int main( int argc, char* argv[] )
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Q_INIT_RESOURCE( SimDS );
    // Q_INIT_RESOURCE( UI );

    using namespace Enercom;

    ApplicationEngine engine;
    engine.initializeEngine();

    return QGuiApplication::exec();
}
