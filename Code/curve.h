#ifndef CURVE_H
#define CURVE_H

#include <QLineSeries>
#include <QScatterSeries>
#include <QXYSeries>
#include <QColor>
#include <QString>
#include <string>
#include <iostream>

#include "dataset.h"

using namespace std;

class Curve : public QtCharts::QLineSeries
{
private:
    Dataset m_dataset;
    string m_xFieldName;
    string m_yFieldName;
    unsigned int m_width;

public:
    Curve();
    Curve(Dataset dataset);

    // set private attributes
    void setDataset(Dataset &dataset);
    void setXFieldName(string xFieldName);
    void setYFieldName(string yFieldName);
    void setWidth(unsigned int width);

    // return private attributes
    Dataset& getDataset();
    string getXFieldName();
    string getYFieldName();
    unsigned int getWidth();

    // other functions
    void updateData();
};

#endif // SERIES_H
