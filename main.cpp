#include "mainwindow.h"
#include "filepick.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(nullptr, true);
    w.show();
    return a.exec();
}

