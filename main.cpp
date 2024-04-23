#include "filepick.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //runs FilePick instead of main function since that lets me change something in the main function on the FilePick screen
    //that something being which structure is initialized on startup, pretty important stuff
    FilePick f;
    f.exec();
    return a.exec();
}

