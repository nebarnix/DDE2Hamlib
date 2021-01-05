#-------------------------------------------------
#
# Project created by QtCreator 2017-04-18T19:35:21
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DDEIPRotor
TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
         ddecomm.cpp \
    plot.cpp

HEADERS  += mainwindow.h \
      ddecomm.h \
    plot.h

FORMS    += mainwindow.ui

LIBS += -lUSER32

include(C:/qwt-6.1.3/features/qwt.prf)
include(c:/qwtpolar-1.1.1/features/qwtpolar.prf)

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../qwt-6.1.3/lib/ -lqwt
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../qwt-6.1.3/lib/ -lqwtd

#INCLUDEPATH += $$PWD/../../../../../qwt-6.1.3/include
#DEPENDPATH += $$PWD/../../../../../qwt-6.1.3/include



