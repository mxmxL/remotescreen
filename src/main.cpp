#include <QApplication>
#include <QDebug>
#include <QTextCodec>

#include "common.h"

#include "remotescreenwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    app.setWindowIcon(QIcon(":/images/logo.png"));
    RemoteScreenWindow win;
    win.show();

    return app.exec();
}

