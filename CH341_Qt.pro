QT += core gui
DEFINES += QT_DLL QWT_DLL
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MPU9250_Tool

CONFIG += c++11

INCLUDEPATH += $$PWD
LIBS += $$PWD\CH341DLL.DLL
#LIBS += -L"D:\Qt\5.5\mingw492_32\lib" -lqwtd
LIBS += -L"D:\Qt\5.5\mingw492_32\lib" -lqwt
INCLUDEPATH += D:\Qt\5.5\mingw492_32\include\Qwt

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    IICConnection.cpp

HEADERS += \
    CH341DLL.H \
    mainwindow.h \ 
    IICConnection.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
