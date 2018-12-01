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
    m_curvesConfigPanel->setFixedWidth(600);
    m_curvesConfigPanel->setFixedHeight(200);

    m_curveConfigWidgets = new QList<CurveConfigWidget*>;

    // curves display (chart view)
    m_chartWidget = new QChartView();
    m_chartWidget->setRenderHint(QPainter::Antialiasing);
    m_chartWidget->chart()->legend()->setVisible(false);

    m_chartPanel = new Panel();
    m_chartPanel->setContentWidget(m_chartWidget);
    m_chartPanel->setFixedWidth(600);
    m_chartPanel->setFixedHeight(400);


    // curves layout
    m_curvesLayout = new QVBoxLayout();
    m_curvesLayout->addWidget(m_curvesConfigPanel);
    m_curvesLayout->addWidget(m_chartPanel);
    m_curvesLayout->addStretch();


    // dataset frame
    m_datasetsList = {};
    m_datasetWidgets = new QList<DatasetWidget*>;

    m_datasetsLayout = new QVBoxLayout();

    m_datasetsInnerLayout = new QVBoxLayout();
    m_datasetsLayout->addLayout(m_datasetsInnerLayout);
    m_datasetsLayout->addStretch();

    m_datasetsPanel = new Panel();
    m_datasetsPanel->setContentLayout(m_datasetsLayout);
    m_datasetsPanel->setTitle("Datasets");
    m_datasetsPanel->setFixedHeight(600);
    m_datasetsPanel->setFixedWidth(400);

    // chart config layout
    m_chartConfigWidget = new ChartConfigWidget();
    m_chartConfigWidget->setChartView(m_chartWidget);
    connect(m_chartConfigWidget,
            SIGNAL(xFieldChanged()),
            this,
            SLOT(updateChartXField()));

    m_chartConfigPanel = new Panel();
    m_chartConfigPanel->setContentWidget(m_chartConfigWidget);
    m_chartConfigPanel->setTitle("Chart settings");
    m_datasetsPanel->setFixedHeight(600);
    m_chartConfigPanel->setFixedWidth(350);

    // global layout
    m_layout = new QHBoxLayout();
    m_layout->addWidget(m_datasetsPanel);
    m_layout->addLayout(m_curvesLayout);
    m_layout->addWidget(m_chartConfigPanel);
    ui->centralWidget->setLayout(m_layout);

    // Menu
    m_importCSVAction = new QAction("Import CSV dataset", this);
    connect(m_importCSVAction, &QAction::triggered, this, &MainWindow::importCSV);

    m_importRAction = new QAction("Import R dataset", this);
    connect(m_importRAction, &QAction::triggered, this, &MainWindow::importR);

    m_importMenu = menuBar()->addMenu("Import");
    m_importMenu->addAction(m_importCSVAction);
    m_importMenu->addAction(m_importRAction);
}


MainWindow::~MainWindow()
{
    delete ui;
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


void MainWindow::addCurveFromUI(CurvePlotButton *curvePlotButton)
{
    // create curve
    Curve *curve = new Curve();
    curve->setDataset( *(curvePlotButton->getDataset()) );
    curve->setXFieldName( *(curvePlotButton->getXName()) );
    curve->setYFieldName( *(curvePlotButton->getYName()) );
    curve->updateData();

    // add curve to button structure
    curvePlotButton->setCurve(curve);

    // add curve to chart
    QChart *chart = m_chartWidget->chart();
    chart->addSeries(curve);
    chart->createDefaultAxes();
    m_chartConfigWidget->setXGrid();
    m_chartConfigWidget->setYGrid();
    m_chartConfigWidget->setXTitle();
    m_chartConfigWidget->setYTitle();

    // create curve widget
    CurveConfigWidget *configWidget = new CurveConfigWidget();
    configWidget->setCurve(curve);
    m_curveConfigWidgets->append(configWidget);
    m_curvesListLayout->addWidget(configWidget);

    // add curve widget to button structure
    curvePlotButton->setCurveConfigWidget(configWidget);
}


void MainWindow::removeCurveFromUI(CurvePlotButton *curvePlotButton)
{
    // remove curve from chart
    QChart *chart = m_chartWidget->chart();
    chart->removeSeries(curvePlotButton->getCurve());

    // delete curve config widget
    delete curvePlotButton->getCurveConfigWidget();
    curvePlotButton->removeCurveConfigWidget();

    // delete curve
    delete curvePlotButton->getCurve();
    curvePlotButton->removeCurve();
}


void MainWindow::addDataset(Dataset *dataset)
{
    DatasetWidget *widget = new DatasetWidget();
    widget->setDataset(dataset);
    widget->update();
    m_datasetsInnerLayout->addWidget(widget);

    // build connection for field items display button
    for (DatasetWidgetFieldItem* fieldItem : *widget->getFieldItems())
    {
        // pass infos to button
        fieldItem->getButton()->setDataset(dataset);
        fieldItem->getButton()->setXName(m_chartConfigWidget->getXName());
        fieldItem->getButton()->setYName(fieldItem->getName());

        connect(fieldItem->getButton(),
                SIGNAL(buttonClicked(CurvePlotButton*)),
                this,
                SLOT(showHideCurve(CurvePlotButton*)));
    }

    // build connection for dataset widget delete button
    connect(widget,
            SIGNAL(deleteSignal(DatasetWidget*)),
            this,
            SLOT(removeDataset(DatasetWidget*)));

    // add dataset to private list
    m_datasetsList.append(dataset);

    // add dataset widget to private list
    m_datasetWidgets->append(widget);

    // update list of fields
    m_chartConfigWidget->updateXFields(listFields());
}


QList<string> MainWindow::listFields()
{
    QList<string> output;
    for (Dataset* dataset : m_datasetsList)
    {
        for (string name : dataset->getNames())
        {
            output.append(name);
        }
    }

    return output;
}


void MainWindow::showHideCurve(CurvePlotButton *curvePlotButton)
{
    if (curvePlotButton->isChecked())
    {
        // update button icon
        curvePlotButton->setArrowType(Qt::ArrowType::RightArrow);

        // plot curve
        addCurveFromUI(curvePlotButton);
    }
    else
    {
        // update button icon
        curvePlotButton->setArrowType(Qt::ArrowType::NoArrow);

        // remove curve
        removeCurveFromUI(curvePlotButton);
    }
}


void MainWindow::importCSV()
{
    // open file dialog
    QFileDialog dialog;
    string fileName = dialog.getOpenFileName().toStdString();
    Dataset *dataset = readCSV(fileName);
    if (dataset != nullptr)
    {
        addDataset(dataset);
    }
}


void MainWindow::importR()
{
    // open file dialog
    QFileDialog dialog;
    string fileName = dialog.getOpenFileName().toStdString();
    Dataset *dataset = readR(fileName);
    if (dataset != nullptr)
    {
        addDataset(dataset);
    }
}


void MainWindow::removeDataset(DatasetWidget *datasetWidget)
{
    // remove dataset from list of datasets
    m_datasetsList.removeOne(datasetWidget->getDataset());

    // delete dataset
    delete datasetWidget->getDataset();

    // remove dataset widget from list of datasets widgets
    m_datasetWidgets->removeOne(datasetWidget);

    // delete dataset widget
    datasetWidget->deleteLater();

    // update list of fields
    m_chartConfigWidget->updateXFields(listFields());
}


void MainWindow::updateChartXField()
{
    string xName = *(m_chartConfigWidget->getXName());

    // update current curves
    for (CurveConfigWidget *configWidget : *m_curveConfigWidgets)
    {
        Curve *curve = configWidget->getCurve();

        // check the curve's dataset has a field nammed $xName
        if (curve->getDataset().hasFieldNammed(xName))
        {
            // update curve
            curve->setXFieldName(xName);
            curve->updateData();
        }
        else
        {
            // remove curve
            removeCurve(curve);
        }
    }

    // update plot buttons in the dataset widget
    for (DatasetWidget *datasetWidget : *m_datasetWidgets)
    {
        // find if fields of the dataset can be plotted
        // ie: has the dataset a field nammed $xName ?
        Dataset *dataset = datasetWidget->getDataset();
        if (dataset->hasFieldNammed(xName))
        {
            // activate plot button of fields widgets
            for (DatasetWidgetFieldItem *fieldItem : *(datasetWidget->getFieldItems()))
            {
                fieldItem->getButton()->setEnabled(true);
            }
        }
        else
        {
            // deactivate plot button of fields widgets
            for (DatasetWidgetFieldItem *fieldItem : *(datasetWidget->getFieldItems()))
            {
                fieldItem->getButton()->setEnabled(false);
            }
        }
    }
}

