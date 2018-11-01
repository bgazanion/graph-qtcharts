#include "curve.h"

Curve::Curve()
{
    m_dataset = Dataset();
    m_xFieldName = "";
    m_yFieldName = "";
    m_width = 1;
}

Curve::Curve(Dataset dataset)
{
    m_dataset = dataset;
    m_xFieldName = "";
    m_yFieldName = "";
    m_width = 1;
}


//-----------------------------------------------------------------------------
// set private attributes
//-----------------------------------------------------------------------------
void Curve::setDataset(Dataset &dataset)
{
    m_dataset = dataset;
}

void Curve::setXFieldName(string xFieldName)
{
    m_xFieldName = xFieldName;
}

void Curve::setYFieldName(string yFieldName)
{
    m_yFieldName = yFieldName;
    this->setName(QString::fromStdString(m_yFieldName));
}

void Curve::setWidth(unsigned int width)
{
    m_width = width;
}


//-----------------------------------------------------------------------------
// return private attributes
//-----------------------------------------------------------------------------
Dataset& Curve::getDataset()
{
    return m_dataset;
}

string Curve::getXFieldName()
{
    return m_xFieldName;
}

string Curve::getYFieldName()
{
    return m_yFieldName;
}

unsigned int Curve::getWidth()
{
    return m_width;
}


//-----------------------------------------------------------------------------
// other functions
//-----------------------------------------------------------------------------
void Curve::updateData()
{
    // preliminary checks
    if (m_xFieldName == "")
    {

    }

    std::cout << m_xFieldName << "\n";
    std::cout << m_yFieldName << "\n";

    unsigned int size;
    size = m_dataset.getSize();

    vector<float> xData;
    xData = *(m_dataset.getField(m_xFieldName).getData());

    vector<float> yData;
    yData = *(m_dataset.getField(m_yFieldName).getData());

    double x, y = 0;

    for(unsigned int i=0; i<size; ++i)
    {
        x = static_cast<double>(xData[i]);
        y = static_cast<double>(yData[i]);
        this->append(x, y);
    }
}

