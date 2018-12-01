#ifndef CURVEPLOTBUTTON_H
#define CURVEPLOTBUTTON_H

#include <QToolButton>
#include <string>
#include "dataset.h"
#include "curve.h"
#include "curveconfigwidget.h"

using namespace std;

class CurvePlotButton : public QToolButton
{
    Q_OBJECT

private:
    Dataset *m_dataset;
    string *m_xName;
    string *m_yName;
    Curve *m_curve;
    CurveConfigWidget *m_curveConfigWidget;

public:
    CurvePlotButton();
    void setDataset(Dataset *dataset);
    void setXName(string *xName);
    void setYName(string *yName);
    void setCurve(Curve *curve);
    void setCurveConfigWidget(CurveConfigWidget *widget);
    Dataset* getDataset();
    string* getXName();
    string* getYName();
    Curve* getCurve();
    CurveConfigWidget* getCurveConfigWidget();
    void removeCurve();
    void removeCurveConfigWidget();

signals:
    // void buttonClicked(Dataset *dataset, string *xName, string *yName);
    void buttonClicked(CurvePlotButton *button);

private slots:
    void handleClick()
    {
        //emit(buttonClicked(m_dataset, m_xName, m_yName));
        emit(buttonClicked(this));
    }
};

#endif // CURVEPLOTBUTTON_H
