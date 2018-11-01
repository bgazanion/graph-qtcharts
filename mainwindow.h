#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QChartView>
#include <QVBoxLayout>
#include "curveconfigwidget.h"


using namespace QtCharts;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setChart(QChart *chart);

private:
    Ui::MainWindow *ui;
    QVBoxLayout *m_layout;
    CurveConfigWidget *m_configWidget;
    QChartView *m_chartWidget;
};

#endif // MAINWINDOW_H
