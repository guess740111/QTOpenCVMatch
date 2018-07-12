#include <QApplication>
#include <QQmlApplicationEngine>
#include "matchmainwindows.h"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    MatchMainWindows MainUi;

    return app.exec();
}
