#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QChartView>
#include <QVBoxLayout>
#include <QList>
#include "curveconfigwidget.h"
#include "datasetwidget.h"


using namespace QtCharts;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QHBoxLayout *m_layout;
    QVBoxLayout *m_curvesLayout;
    QVBoxLayout *m_curveConfigLayout;
    QList<CurveConfigWidget*> *m_curveConfigWidgets;
    QVBoxLayout *m_datasetsLayout;
    QChartView *m_chartWidget;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setChart(QChart *chart);
    void addCurve(Curve *curve);
    void removeCurve(Curve *curve);
    void addDataset(Dataset *dataset);


};

#endif // MAINWINDOW_H
