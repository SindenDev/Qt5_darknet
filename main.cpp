#include "qcvdetectfilter.h"
#include "cfgproperty.h"
#include "darknet.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QLibrary>
#include <QFile>


using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

//    QLibrary mylib("/home/kh/darknet/libdarknet.so");


    CfgProperty *cfgProprty = new CfgProperty;

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<QCvDetectFilter>("com.amin.classes", 1, 0, "CvDetectFilter");
    qRegisterMetaType<QList<QRect>>("QList<QRect>");

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("cfgproperty",cfgProprty);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
