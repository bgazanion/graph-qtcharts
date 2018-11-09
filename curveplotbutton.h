#ifndef CURVEPLOTBUTTON_H
#define CURVEPLOTBUTTON_H

#include <QToolButton>
#include <string>
#include "dataset.h"

using namespace std;

class CurvePlotButton : public QToolButton
{
    Q_OBJECT

private:
    Dataset *m_dataset;
    string *m_xName;
    string *m_yName;

public:
    CurvePlotButton();
    void setDataset(Dataset *dataset);
    void setXName(string *xName);
    void setYName(string *yName);
    Dataset* getDataset();
    string* getXName();
    string* getYName();

signals:
    void buttonClicked(Dataset *dataset, string *xName, string *yName);

private slots:
    void handleClick()
    {
        emit(buttonClicked(m_dataset, m_xName, m_yName));
    }
};

#endif // CURVEPLOTBUTTON_H
