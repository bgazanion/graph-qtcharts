#include <QApplication>
#include <QChart>
#include <QChartView>
#include <QLineSeries>

#include <iostream>
#include <vector>
#include <string>

#include "mainwindow.h"
#include "field.h"
#include "dataset.h"
#include "rng.h"
#include "stringlib.h"
#include "readers.h"
#include "curve.h"


QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow window;
    window.show();
    return a.exec();

}
