#-------------------------------------------------
#
# Project created by QtCreator 2018-08-25T23:02:07
#
#-------------------------------------------------

QT       += core gui widgets
QT       += charts

TARGET = graph_app
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        field.cpp \
    dataset.cpp \
    rng.cpp \
    readers.cpp \
    stringlib.cpp \
    curve.cpp \
    curveconfigwidget.cpp \
    datasetwidget.cpp \
    datasetwidgetfielditem.cpp \
    chartconfigwidget.cpp \
    panel.cpp \
    curveplotbutton.cpp

HEADERS += \
        mainwindow.h \
        field.h \
    dataset.h \
    rng.h \
    readers.h \
    stringlib.h \
    curve.h \
    curveconfigwidget.h \
    datasetwidget.h \
    datasetwidgetfielditem.h \
    chartconfigwidget.h \
    panel.h \
    curveplotbutton.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -LC:/Qt/5.11.1/msvc2017_64/lib/ -lQt5Charts
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/Qt/5.11.1/msvc2017_64/lib/ -lQt5Chartsd
else:unix: LIBS += -LC:/Qt/5.11.1/msvc2017_64/lib/ -lQt5Charts

INCLUDEPATH += C:/Qt/5.11.1/msvc2017_64/include
DEPENDPATH += C:/Qt/5.11.1/msvc2017_64/include
