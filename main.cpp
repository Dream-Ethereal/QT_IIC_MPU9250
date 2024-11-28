#include <QApplication>
#include "mainwindow.h"
#include <QDebug>
#include "CH341DLL.H"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
