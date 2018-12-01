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
    Code/chartconfigwidget.cpp \
    Code/curve.cpp \
    Code/curveconfigwidget.cpp \
    Code/curveplotbutton.cpp \
    Code/dataset.cpp \
    Code/datasetwidget.cpp \
    Code/field.cpp \
    Code/datasetwidgetfielditem.cpp \
    Code/importwindow.cpp \
    Code/main.cpp \
    Code/mainwindow.cpp \
    Code/messagewindow.cpp \
    Code/panel.cpp \
    Code/readers.cpp \
    Code/rng.cpp \
    Code/stringlib.cpp

HEADERS += \
    Code/chartconfigwidget.h \
    Code/curve.h \
    Code/curveconfigwidget.h \
    Code/curveplotbutton.h \
    Code/dataset.h \
    Code/datasetwidget.h \
    Code/datasetwidgetfielditem.h \
    Code/field.h \
    Code/importwindow.h \
    Code/mainwindow.h \
    Code/messagewindow.h \
    Code/panel.h \
    Code/readers.h \
    Code/rng.h \
    Code/stringlib.h

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

RESOURCES += \
    ressources.qrc
