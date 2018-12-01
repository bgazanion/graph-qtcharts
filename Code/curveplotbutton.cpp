#include "curveplotbutton.h"

CurvePlotButton::CurvePlotButton()
{
    m_dataset = new Dataset();
    m_xName = new string();
    m_yName = new string();
    m_curve = new Curve();
    m_curveConfigWidget = new CurveConfigWidget();
    connect(this, SIGNAL(clicked()), this, SLOT(handleClick()));
}


void CurvePlotButton::setDataset(Dataset *dataset)
{
    m_dataset = dataset;
}


void CurvePlotButton::setXName(string *xName)
{
    m_xName = xName;
}


void CurvePlotButton::setYName(string *yName)
{
    m_yName = yName;
}


void CurvePlotButton::setCurve(Curve *curve)
{
    m_curve = curve;
}


void CurvePlotButton::setCurveConfigWidget(CurveConfigWidget *widget)
{
    m_curveConfigWidget = widget;
}


Dataset* CurvePlotButton::getDataset()
{
    return m_dataset;
}


string* CurvePlotButton::getXName()
{
    return m_xName;
}


string* CurvePlotButton::getYName()
{
    return m_yName;
}


Curve* CurvePlotButton::getCurve()
{
    return m_curve;
}


CurveConfigWidget* CurvePlotButton::getCurveConfigWidget()
{
    return m_curveConfigWidget;
}


void CurvePlotButton::removeCurve()
{
    m_curve = nullptr;
}


void CurvePlotButton::removeCurveConfigWidget()
{
    m_curveConfigWidget = nullptr;
}
