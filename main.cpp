#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"

#include <QtQml>
//#include "qlmsensors.h"
#include "signalcanvas.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<QLmSensors>("sensors", 1, 0, "QLmSensors");
    qmlRegisterType<QSensorItem>("sensors", 1, 0, "QSensorItem");
    qmlRegisterType<QSensorSample>("sensors", 1, 0, "QSensorSample");
    qmlRegisterType<SignalCanvas>("sensors", 1, 0, "SignalCanvas");

    QtQuick2ApplicationViewer viewer;

    QSurfaceFormat format = viewer.format();

    qDebug() << "OpenGL v" << format.majorVersion() << "." << format.minorVersion();

    format.setSamples(16);
    viewer.setFormat(format);

    viewer.setTitle("pwnsensor alpha-3");
    viewer.setMainQmlFile(QStringLiteral("qml/pwnsensor/main.qml"));
    viewer.showExpanded();



    return app.exec();
}
