#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QChartView>
#include <QVBoxLayout>
#include <QList>
#include <QFrame>
#include <string>
#include <QSignalMapper>
#include "curveconfigwidget.h"
#include "datasetwidget.h"
#include "chartconfigwidget.h"
#include "panel.h"
#include "curveplotbutton.h"
#include <iostream>


using namespace QtCharts;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QHBoxLayout *m_layout;
    // curves configuration
    QVBoxLayout *m_curvesLayout;
    QVBoxLayout *m_curveConfigLayout;
    QVBoxLayout *m_curvesListLayout;
    QList<CurveConfigWidget*> *m_curveConfigWidgets;
    Panel *m_curvesConfigPanel;
    // datasets
    QVBoxLayout *m_datasetsLayout;
    QVBoxLayout *m_datasetsInnerLayout;
    Panel *m_datasetsPanel;
    // chart
    QChartView *m_chartWidget;
    Panel *m_chartPanel;
    // chart configuration
    ChartConfigWidget *m_chartConfigWidget;
    Panel *m_chartConfigPanel;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setChart(QChart *chart);
    void addCurve(Curve *curve);
    void removeCurve(Curve *curve);
    void addDataset(Dataset *dataset);

signals:

private slots:
    void addCurveFromUI(Dataset *dataset, string *xName, string *yName);
};

#endif // MAINWINDOW_H
