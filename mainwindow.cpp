#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // curves config
    m_curvesListLayout = new QVBoxLayout();

    m_curveConfigLayout = new QVBoxLayout();
    m_curveConfigLayout->addLayout(m_curvesListLayout);
    m_curveConfigLayout->addStretch();

    m_curvesConfigPanel = new Panel();
    m_curvesConfigPanel->setContentLayout(m_curveConfigLayout);
    m_curvesConfigPanel->setTitle("Curves settings");
    m_curvesConfigPanel->setFixedWidth(400);
    m_curvesConfigPanel->setFixedHeight(200);

    m_curveConfigWidgets = new QList<CurveConfigWidget*>;

    // curves display (chart view)
    m_chartWidget = new QChartView();
    m_chartWidget->setRenderHint(QPainter::Antialiasing);

    m_chartPanel = new Panel();
    m_chartPanel->setContentWidget(m_chartWidget);
    m_chartPanel->setFixedWidth(600);
    m_chartPanel->setFixedHeight(600);


    // curves layout
    m_curvesLayout = new QVBoxLayout();
    m_curvesLayout->addWidget(m_curvesConfigPanel);
    m_curvesLayout->addWidget(m_chartPanel);
    m_curvesLayout->addStretch();


    // dataset frame
    m_datasetsLayout = new QVBoxLayout();

    m_datasetsInnerLayout = new QVBoxLayout();
    m_datasetsLayout->addLayout(m_datasetsInnerLayout);
    m_datasetsLayout->addStretch();

    m_datasetsPanel = new Panel();
    m_datasetsPanel->setContentLayout(m_datasetsLayout);
    m_datasetsPanel->setTitle("Datasets");
    m_datasetsPanel->setFixedHeight(800);
    m_datasetsPanel->setFixedWidth(400);

    // chart config layout
    m_chartConfigWidget = new ChartConfigWidget();
    m_chartConfigWidget->setChartView(m_chartWidget);

    m_chartConfigPanel = new Panel();
    m_chartConfigPanel->setContentWidget(m_chartConfigWidget);
    m_chartConfigPanel->setTitle("Chart settings");
    m_datasetsPanel->setFixedHeight(800);
    m_chartConfigPanel->setFixedWidth(350);

    // global layout
    m_layout = new QHBoxLayout();
    m_layout->addWidget(m_datasetsPanel);
    m_layout->addLayout(m_curvesLayout);
    m_layout->addWidget(m_chartConfigPanel);
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
    m_chartConfigWidget->setXGrid();
    m_chartConfigWidget->setYGrid();

    // create curve widget
    CurveConfigWidget *configWidget = new CurveConfigWidget();
    configWidget->setCurve(curve);
    m_curveConfigWidgets->append(configWidget);
    m_curvesListLayout->addWidget(configWidget);
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

    delete (*m_curveConfigWidgets)[curveIndex];
    m_curveConfigWidgets->removeAt(curveIndex);
}


void MainWindow::addDataset(Dataset *dataset)
{
    DatasetWidget *widget = new DatasetWidget();
    widget->setDataset(dataset);
    widget->update();
    m_datasetsInnerLayout->addWidget(widget);
}

