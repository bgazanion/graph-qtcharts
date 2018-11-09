#include "curveplotbutton.h"

CurvePlotButton::CurvePlotButton()
{
    m_dataset = new Dataset();
    m_xName = new string();
    m_yName = new string();
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
