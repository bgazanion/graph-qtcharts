#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_layout = new QVBoxLayout();

    m_configWidget = new CurveConfigWidget();
    m_layout->addWidget(m_configWidget);

    m_chartWidget = new QChartView();
    m_layout->addWidget(m_chartWidget);

    ui->centralWidget->setLayout(m_layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setChart(QChart *chart)
{
    m_chartWidget->setChart(chart);
    m_configWidget->setCurve(static_cast<Curve*>(chart->series()[0]));
}
