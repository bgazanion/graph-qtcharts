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
    /*
    QApplication a(argc, argv);
    MainWindow window;
    */

    //-- init RNG
    initRNG();

    //-- debug "field"
    /*
    Field f1;
    f1.print();

    Field f2;
    f2.setName("time");
    std::vector<float> v = {1, 5, 3, 8, 5, 7, 8, 54, 8, 5};
    f2.setSize(static_cast<unsigned int>(v.size()));
    f2.setData(&v);
    f2.print();

    Field f3;
    f3.setSize(12);
    f3.randomize(0., 1.);
    f3.print();
    */

    //-- debug "dataset"
    /*
    Dataset dataset;
    int size = 20;
    dataset.setSize(size);
    for (int i=0; i<10; i++)
    {
        Field tmpField;
        tmpField.setSize( static_cast<unsigned int>(size) );
        tmpField.randomize(0., 1.);
        dataset.addField(tmpField);
    }
    dataset.printInfo();
    */

    //-- debug stringlib
    /*
    std::vector<std::string> testStr = { "zaekazjkjkl,adeaz,dazdazd,dzadz",
                                        "yoman",
                                        "",
                                        ",,,,,,,",
                                        "yrgre,",
                                        ",erzerez"
                                       };
    for (std::string t : testStr)
    {
        std::cout << "string tested: " << '"' << t << '"' << "\n";
        for (std::size_t index : findAll(t, ','))
        {
            std::cout << index << "\n";
        }
        for (std::string str : split(t, ','))
        {
            std::cout << "'" << str << "'" << "\n";
        }
        std::cout << std::endl;
    }
    */

    //-- debug CSV reader
    /*
    std::string fileName = "D:\\Prog\\datasets\\Rdatasets\\aids_cut_nice.csv";
    // std::string fileName = "D:\\Prog\\datasets\\Rdatasets\\cps1_short.csv";
    Dataset data = readCSV(fileName);
    data.printInfo();
    */

    //-- debug charts
    /*
    QApplication a(argc, argv);

    QLineSeries *series = new QLineSeries();

    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    MainWindow window;
    window.setChart(chart);
    window.resize(400, 300);
    window.show();
    */


    //-- debug curve
    //  CSV file
    /*
    QApplication a(argc, argv);
    std::string fileName = "D:\\Prog\\datasets\\Rdatasets\\aids_cut_nice.csv";
    Dataset data = readCSV(fileName);
    data.printInfo();
    Curve *curve = new Curve(data);
    curve->setXFieldName("\"\"");
    curve->setYFieldName("\"delay\"");
    */

    //  R dataset
    /*
    QApplication a(argc, argv);
    std::string fileName = "D:\\Prog\\datasets\\Rdatasets\\cps1_short.csv";
    Dataset data = readR(fileName);
    data.printInfo();
    Curve *curve = new Curve(data);
    curve->setXFieldName("age");
    curve->setYFieldName("re75");

    curve->updateData();

    QChart *chart = new QChart();
    chart->addSeries(curve);
    chart->createDefaultAxes();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    MainWindow window;
    window.setChart(chart);
    //window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
    return a.exec();
    */



    //-- debug curve V2
    QApplication a(argc, argv);
    MainWindow window;

    std::string fileName = "D:\\Prog\\datasets\\Rdatasets\\cps1_short.csv";

    Dataset data = readR(fileName);
    data.printInfo();
    window.addDataset(&data);

    Curve *curve1 = new Curve(data);
    curve1->setXFieldName("age");
    curve1->setYFieldName("re75");
    curve1->updateData();

    window.addCurve(curve1);


    Curve *curve2 = new Curve(data);
    curve2->setXFieldName("age");
    curve2->setYFieldName("re74");
    curve2->updateData();

    window.addCurve(curve2);

    window.removeCurve(curve1);

    /*
    QChart *chart = new QChart();
    chart->addSeries(curve);
    chart->createDefaultAxes();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    MainWindow window;
    window.setChart(chart);
    //window.setCentralWidget(chartView);
    */

    window.resize(400, 300);
    window.show();
    return a.exec();


    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    */



}
