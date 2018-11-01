#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QChartView>
#include <QVBoxLayout>
#include <QList>
#include "curveconfigwidget.h"


using namespace QtCharts;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QVBoxLayout *m_layout;
    QVBoxLayout *m_curveConfigLayout;
    QList<CurveConfigWidget*> *m_curveConfigWidgets;
    QChartView *m_chartWidget;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setChart(QChart *chart);
    void addCurve(Curve *curve);
    void removeCurve(Curve *curve);


};

#endif // MAINWINDOW_H
