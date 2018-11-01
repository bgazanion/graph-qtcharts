#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // curve layout
    m_curvesLayout = new QVBoxLayout();

    m_curveConfigLayout = new QVBoxLayout();
    m_curvesLayout->addLayout(m_curveConfigLayout);

    m_curveConfigWidgets = new QList<CurveConfigWidget*>;

    m_chartWidget = new QChartView();
    m_chartWidget->setRenderHint(QPainter::Antialiasing);
    m_curvesLayout->addWidget(m_chartWidget);

    // dataset layout
    m_datasetsLayout = new QVBoxLayout();

    // global layout
    m_layout = new QHBoxLayout();
    m_layout->addLayout(m_datasetsLayout);
    m_layout->addLayout(m_curvesLayout);
    ui->centralWidget->setLayout(m_layout);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addCurve(Curve *curve)
{
    // add curve to chart
    QChart *chart = m_chartWidget->chart();
    chart->addSeries(curve);
    chart->createDefaultAxes();

    // create curve widget
    CurveConfigWidget *configWidget = new CurveConfigWidget();
    configWidget->setCurve(curve);
    m_curveConfigWidgets->append(configWidget);
    m_curveConfigLayout->addWidget(configWidget);
}


void MainWindow::removeCurve(Curve *curve)
{
    // remove curve from chart
    QChart *chart = m_chartWidget->chart();
    chart->removeSeries(curve);
    chart->createDefaultAxes();

    // remove curve widget
    int curveIndex = 0;
    for (CurveConfigWidget *configWidget : *m_curveConfigWidgets)
    {
        if(configWidget->getCurve()==curve)
            break;
        else
            curveIndex++;
    }

    // CurveConfigWidget *widget = (*m_curveConfigWidgets)[curveIndex];
    delete (*m_curveConfigWidgets)[curveIndex];
    m_curveConfigWidgets->removeAt(curveIndex);
}


void MainWindow::addDataset(Dataset *dataset)
{
    DatasetWidget *widget = new DatasetWidget();
    widget->setDataset(dataset);
    widget->update();
    m_datasetsLayout->addWidget(widget);
}

