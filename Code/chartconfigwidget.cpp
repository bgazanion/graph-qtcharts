#include "chartconfigwidget.h"

ChartConfigWidget::ChartConfigWidget(QWidget *parent) : QWidget(parent)
{
    m_doubleValidator = new QDoubleValidator();
    m_doubleValidator->setLocale(QLocale::English);

    m_chartView = new QChartView();

    // title
    m_titleLabel = new QLabel();
    m_titleLabel->setText("Title");

    m_titleField = new QLineEdit();
    connect(m_titleField, &QLineEdit::textChanged,
            this, &ChartConfigWidget::setTitle);

    m_titleLayout = new QHBoxLayout();
    m_titleLayout->addWidget(m_titleLabel);
    m_titleLayout->addWidget(m_titleField);


    //------------------------------------------------
    // X field
    //------------------------------------------------

    m_xName = new string();

    m_xNameLabel = new QLabel();
    m_xNameLabel->setText("X field");

    m_xNameBox = new QComboBox();
    m_xNameBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    connect(m_xNameBox, &QComboBox::currentTextChanged,
            this, &ChartConfigWidget::updateChartXField);

    m_xNameLayout = new QHBoxLayout();
    m_xNameLayout->addWidget(m_xNameLabel);
    m_xNameLayout->addWidget(m_xNameBox);
    m_xNameLayout->addStretch();


    //------------------------------------------------
    // X axis
    //------------------------------------------------
    //  -> layout title
    m_xButton = new QToolButton();
    m_xButton->setArrowType(Qt::ArrowType::DownArrow);
    m_xButton->setCheckable(true);
    m_xButton->setChecked(false);
    connect(m_xButton, &QToolButton::clicked, this, &ChartConfigWidget::showHideX);

    m_xLabel = new QLabel();
    m_xLabel->setText("X axis");

    m_xTitleLayout = new QHBoxLayout();
    m_xTitleLayout->addWidget(m_xButton);
    m_xTitleLayout->addWidget(m_xLabel);

    // -> axis title
    m_xAxisTitleLabel = new QLabel();
    m_xAxisTitleLabel->setText("Title");

    m_xAxisTitleContent = new QLineEdit();
    connect(m_xAxisTitleContent, &QLineEdit::textChanged,
            this, &ChartConfigWidget::setXTitle);

    m_xAxisTitleLayout = new QHBoxLayout();
    m_xAxisTitleLayout->addWidget(m_xAxisTitleLabel);
    m_xAxisTitleLayout->addWidget(m_xAxisTitleContent);
    m_xAxisTitleLayout->addStretch(0);

    //  -> grid
    m_xGridLabel = new QLabel();
    m_xGridLabel->setText("Grid");

    m_xGridButton = new QCheckBox();
    connect(m_xGridButton, &QCheckBox::stateChanged, this, &ChartConfigWidget::setXGrid);

    m_xGridLayout = new QHBoxLayout();
    m_xGridLayout->addWidget(m_xGridLabel);
    m_xGridLayout->addWidget(m_xGridButton);
    m_xGridLayout->addStretch(0);

    //  -> range
    m_xRangeLabel = new QLabel();
    m_xRangeLabel->setText("Range");

    m_xMinField = new QLineEdit();
    m_xMinField->setValidator(m_doubleValidator);

    m_xMaxField = new QLineEdit();
    m_xMaxField->setValidator(m_doubleValidator);

    m_xRangeButton = new QPushButton();
    m_xRangeButton->setText("Apply");
    connect(m_xRangeButton, &QPushButton::clicked, this, &ChartConfigWidget::setXRange);

    m_xRangeLayout = new QHBoxLayout();
    m_xRangeLayout->addWidget(m_xRangeLabel);
    m_xRangeLayout->addWidget(m_xMinField);
    m_xRangeLayout->addWidget(m_xMaxField);
    m_xRangeLayout->addWidget(m_xRangeButton);

    //  -> log scale
    m_xLogLabel = new QLabel();
    m_xLogLabel->setText("Log scale");

    m_xLogButton = new QCheckBox();
    connect(m_xLogButton, &QCheckBox::stateChanged, this, &ChartConfigWidget::updateXScale);

    m_xLogBaseLabel = new QLabel();
    m_xLogBaseLabel->setText("base");

    m_xLogBaseButton = new QComboBox();
    m_xLogBaseButton->addItem("10");
    m_xLogBaseButton->addItem("2");
    connect(m_xLogBaseButton,  QOverload<int>::of(&QComboBox::activated),
            this, &ChartConfigWidget::updateXScale);

    m_xLogLayout = new QHBoxLayout();
    m_xLogLayout->addWidget(m_xLogLabel);
    m_xLogLayout->addWidget(m_xLogButton);
    m_xLogLayout->addWidget(m_xLogBaseLabel);
    m_xLogLayout->addWidget(m_xLogBaseButton);
    m_xLogLayout->addStretch(0);

    //  -> general
    m_xContentLayout = new QVBoxLayout();
    m_xContentLayout->addLayout(m_xAxisTitleLayout);
    m_xContentLayout->addLayout(m_xGridLayout);
    m_xContentLayout->addLayout(m_xRangeLayout);
    m_xContentLayout->addLayout(m_xLogLayout);

    m_xDetailWidget = new QWidget();
    m_xDetailWidget->setContentsMargins(20, 0, 0, 0);
    m_xDetailWidget->setLayout(m_xContentLayout);

    m_xMainLayout = new QVBoxLayout();
    m_xMainLayout->addLayout(m_xTitleLayout);
    m_xMainLayout->addWidget(m_xDetailWidget);
    //m_xMainLayout->addStretch();

    //------------------------------------------------
    // Y axis
    //------------------------------------------------
    //  -> title
    m_yButton = new QToolButton();
    m_yButton->setArrowType(Qt::ArrowType::DownArrow);
    m_yButton->setCheckable(true);
    m_yButton->setChecked(false);
    connect(m_yButton, &QToolButton::clicked, this, &ChartConfigWidget::showHideY);

    m_yLabel = new QLabel();
    m_yLabel->setText("Y axis");

    m_yTitleLayout = new QHBoxLayout();
    m_yTitleLayout->addWidget(m_yButton);
    m_yTitleLayout->addWidget(m_yLabel);

    // -> axis title
    m_yAxisTitleLabel = new QLabel();
    m_yAxisTitleLabel->setText("Title");

    m_yAxisTitleContent = new QLineEdit();
    connect(m_yAxisTitleContent, &QLineEdit::textChanged,
            this, &ChartConfigWidget::setYTitle);

    m_yAxisTitleLayout = new QHBoxLayout();
    m_yAxisTitleLayout->addWidget(m_yAxisTitleLabel);
    m_yAxisTitleLayout->addWidget(m_yAxisTitleContent);
    m_yAxisTitleLayout->addStretch(0);

    //  -> grid
    m_yGridLabel = new QLabel();
    m_yGridLabel->setText("Grid");

    m_yGridButton = new QCheckBox();
    connect(m_yGridButton, &QCheckBox::stateChanged, this, &ChartConfigWidget::setYGrid);

    m_yGridLayout = new QHBoxLayout();
    m_yGridLayout->addWidget(m_yGridLabel);
    m_yGridLayout->addWidget(m_yGridButton);
    m_yGridLayout->addStretch(0);

    //  -> range
    m_yRangeLabel = new QLabel();
    m_yRangeLabel->setText("Range");

    m_yMinField = new QLineEdit();
    m_yMinField->setValidator(m_doubleValidator);

    m_yMaxField = new QLineEdit();
    m_yMaxField->setValidator(m_doubleValidator);

    m_yRangeButton = new QPushButton();
    m_yRangeButton->setText("Apply");
    connect(m_yRangeButton, &QPushButton::clicked, this, &ChartConfigWidget::setYRange);

    m_yRangeLayout = new QHBoxLayout();
    m_yRangeLayout->addWidget(m_yRangeLabel);
    m_yRangeLayout->addWidget(m_yMinField);
    m_yRangeLayout->addWidget(m_yMaxField);
    m_yRangeLayout->addWidget(m_yRangeButton);

    //  -> log scale
    m_yLogLabel = new QLabel();
    m_yLogLabel->setText("Log scale");

    m_yLogButton = new QCheckBox();
    connect(m_yLogButton, &QCheckBox::stateChanged, this, &ChartConfigWidget::updateYScale);

    m_yLogBaseLabel = new QLabel();
    m_yLogBaseLabel->setText("base");

    m_yLogBaseButton = new QComboBox();
    m_yLogBaseButton->addItem("10");
    m_yLogBaseButton->addItem("2");
    connect(m_yLogBaseButton,  QOverload<int>::of(&QComboBox::activated),
            this, &ChartConfigWidget::updateYScale);

    m_yLogLayout = new QHBoxLayout();
    m_yLogLayout->addWidget(m_yLogLabel);
    m_yLogLayout->addWidget(m_yLogButton);
    m_yLogLayout->addWidget(m_yLogBaseLabel);
    m_yLogLayout->addWidget(m_yLogBaseButton);
    m_yLogLayout->addStretch(0);

    //  -> general
    m_yContentLayout = new QVBoxLayout();
    m_yContentLayout->addLayout(m_yAxisTitleLayout);
    m_yContentLayout->addLayout(m_yGridLayout);
    m_yContentLayout->addLayout(m_yRangeLayout);
    m_yContentLayout->addLayout(m_yLogLayout);

    m_yDetailWidget = new QWidget();
    m_yDetailWidget->setContentsMargins(20, 0, 0, 0);
    m_yDetailWidget->setLayout(m_yContentLayout);

    m_yMainLayout = new QVBoxLayout();
    m_yMainLayout->addLayout(m_yTitleLayout);
    m_yMainLayout->addWidget(m_yDetailWidget);
    // m_yMainLayout->addStretch();

    // layout
    m_layout = new QVBoxLayout();
    m_layout->addLayout(m_titleLayout);
    m_layout->addLayout(m_xNameLayout);
    m_layout->addLayout(m_xMainLayout);
    m_layout->addLayout(m_yMainLayout);
    m_layout->addStretch(0);

    this->setLayout(m_layout);
}



ChartConfigWidget::~ChartConfigWidget()
{
    delete m_doubleValidator;
    delete m_chartView;
    delete m_chartView;
    // layout
    delete m_layout;
    // title
    delete m_titleLabel;
    delete m_titleField;
    delete m_titleLayout;
    // X axis
    //  -> general
    delete m_xLabel;
    delete m_xButton;
    delete m_xDetailWidget;
    delete m_xMainLayout;
    delete m_xTitleLayout;
    delete m_xContentLayout;
    //  -> grid
    delete m_xGridLayout;
    delete m_xGridLabel;
    delete m_xGridButton;
    //  -> range
    delete m_xRangeLayout;
    delete m_xRangeLabel;
    delete m_xMinField;
    delete m_xMaxField;
    delete m_xRangeButton;
    // -> log scale
    delete m_xLogLayout;
    delete m_xLogLabel;
    delete m_xLogButton;
    delete m_xLogBaseButton;
    delete m_xLogBaseLabel;
    // Y axis
    //  -> general
    delete m_yLabel;
    delete m_yButton;
    delete m_yDetailWidget;
    delete m_yMainLayout;
    delete m_yTitleLayout;
    delete m_yContentLayout;
    //  -> grid
    delete m_yGridLayout;
    delete m_yGridLabel;
    delete m_yGridButton;
    //  -> range
    delete m_yRangeLayout;
    delete m_yRangeLabel;
    delete m_yMinField;
    delete m_yMaxField;
    delete m_yRangeButton;
    // -> log scale
    delete m_yLogLayout;
    delete m_yLogLabel;
    delete m_yLogButton;
    delete m_yLogBaseButton;
    delete m_yLogBaseLabel;
    // utils
    delete m_doubleValidator;
}


void ChartConfigWidget::setChartView(QChartView *chartView)
{
    m_chartView = chartView;
}



void ChartConfigWidget::updateXFields(QList<string> list)
{
    m_xNameBox->clear();
    for (string element : list)
    {
        m_xNameBox->addItem(QString::fromStdString(element));
    }

}


void ChartConfigWidget::setTitle()
{
    m_chartView->chart()->setTitle(m_titleField->text());
}


void ChartConfigWidget::updateChartXField()
{
    m_xName->assign(m_xNameBox->currentText().toStdString());
    emit(xFieldChanged());
}


void ChartConfigWidget::showHideX()
{
    if (m_xButton->isChecked())
    {
        m_xButton->setArrowType(Qt::ArrowType::RightArrow);
        m_xDetailWidget->hide();
    }
    else
    {
        m_xButton->setArrowType(Qt::ArrowType::DownArrow);
        m_xDetailWidget->show();
    }
}


void ChartConfigWidget::setXRange()
{
    if (m_chartView->chart()->axisX() != nullptr)
    {
        QVariant min = m_xMinField->text();
        m_chartView->chart()->axisX()->setMin(min);

        QVariant max = m_xMaxField->text();
        m_chartView->chart()->axisX()->setMax(max);
    }
}


void ChartConfigWidget::updateXScale()
{
    // get series of the chart
    QList<QAbstractSeries*> series = m_chartView->chart()->series();

    // detach series from existing axis
    for (QAbstractSeries *seriesItem : series)
    {
        seriesItem->detachAxis(m_chartView->chart()->axisX());
    }

    // delete existing axis
    delete m_chartView->chart()->axisX();

    // create new axis with appropriate type and add it to chart
    if (m_xLogButton->isChecked())
    {
        // log scale
        QLogValueAxis *axis = new QLogValueAxis();
        int baseIndex = m_xLogBaseButton->currentIndex();
        double base;
        if (baseIndex==0)
        {
            base = 10;
            axis->setMinorTickCount(9);
        }
        else
        {
            base = 2;
        }
        axis->setBase(base);
        axis->setLabelFormat("%d");
        m_chartView->chart()->setAxisX(axis);
    }
    else
    {
        // regular scale
        QValueAxis *axis = new QValueAxis();
        m_chartView->chart()->setAxisX(axis);
    }

    // attach series to new axis
    for (QAbstractSeries *seriesItem : series)
    {
        seriesItem->attachAxis(m_chartView->chart()->axisX());
    }

    // set xrange
    this->setXRange();
}


void ChartConfigWidget::setXGrid()
{
    if (m_chartView->chart()->axisX() != nullptr)
    {
        if (m_xGridButton->isChecked())
            m_chartView->chart()->axisX()->setGridLineVisible(true);
        else
            m_chartView->chart()->axisX()->setGridLineVisible(false);
    }
}


void ChartConfigWidget::setXTitle()
{
    if (m_chartView->chart()->axisX() != nullptr)
    {
        m_chartView->chart()->axisX()->setTitleText(m_xAxisTitleContent->text());
    }
}


void ChartConfigWidget::showHideY()
{
    if (m_yButton->isChecked())
    {
        m_yButton->setArrowType(Qt::ArrowType::RightArrow);
        m_yDetailWidget->hide();
    }
    else
    {
        m_yButton->setArrowType(Qt::ArrowType::DownArrow);
        m_yDetailWidget->show();
    }
}


void ChartConfigWidget::setYRange()
{
    if (m_chartView->chart()->axisY() != nullptr)
    {
        QVariant min = m_yMinField->text();
        m_chartView->chart()->axisY()->setMin(min);

        QVariant max = m_yMaxField->text();
        m_chartView->chart()->axisY()->setMax(max);
    }
}


void ChartConfigWidget::updateYScale()
{
    // get series of the chart
    QList<QAbstractSeries*> series = m_chartView->chart()->series();

    // detach series from existing axis
    for (QAbstractSeries *seriesItem : series)
    {
        seriesItem->detachAxis(m_chartView->chart()->axisY());
    }

    // delete existing axis
    delete m_chartView->chart()->axisY();

    // create new axis with appropriate type and add it to chart
    if (m_yLogButton->isChecked())
    {
        // log scale
        QLogValueAxis *axis = new QLogValueAxis();
        int baseIndex = m_yLogBaseButton->currentIndex();
        double base;
        if (baseIndex==0)
        {
            base = 10;
            axis->setMinorTickCount(9);
        }
        else
        {
            base = 2;
        }
        axis->setBase(base);
        axis->setLabelFormat("%d");
        m_chartView->chart()->setAxisY(axis);
    }
    else
    {
        // regular scale
        QValueAxis *axis = new QValueAxis();
        m_chartView->chart()->setAxisY(axis);
    }

    // attach series to new axis
    for (QAbstractSeries *seriesItem : series)
    {
        seriesItem->attachAxis(m_chartView->chart()->axisY());
    }

    // set yrange
    this->setYRange();
}


void ChartConfigWidget::setYGrid()
{
    if (m_chartView->chart()->axisY() != nullptr)
    {
        if (m_yGridButton->isChecked())
            m_chartView->chart()->axisY()->setGridLineVisible(true);
        else
            m_chartView->chart()->axisY()->setGridLineVisible(false);
    }
}


void ChartConfigWidget::setYTitle()
{
    if (m_chartView->chart()->axisY() != nullptr)
    {
        m_chartView->chart()->axisY()->setTitleText(m_yAxisTitleContent->text());
    }
}


string* ChartConfigWidget::getXName()
{
    return m_xName;

}
