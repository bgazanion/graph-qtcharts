#include "datasetwidget.h"

DatasetWidget::DatasetWidget(QWidget *parent) : QWidget(parent)
{
    // non GUI members
    m_width = 300;
    m_dataset = new Dataset();
    m_fieldItems = new QList<DatasetWidgetFieldItem*>;

    // GUI first level : title
    m_titleLayout = new QHBoxLayout();

    m_showButton = new QToolButton();
    m_showButton->setArrowType(Qt::ArrowType::DownArrow);
    m_showButton->setCheckable(true);
    m_showButton->setChecked(false);
    connect(m_showButton, &QToolButton::clicked, this, &DatasetWidget::showHide);
    m_titleLayout->addWidget(m_showButton);

    m_titleLabel = new QLabel();
    m_titleLayout->addWidget(m_titleLabel);

    // GUI second level : fields details (foldable)
    m_subLayout = new QHBoxLayout();
    m_subLayout->addSpacing(20);

    m_fieldsLayout = new QVBoxLayout();
    m_subLayout->addLayout(m_fieldsLayout);

    m_subLayout->addStretch(0);

    m_detailWidget = new QWidget();
    m_detailWidget->setLayout(m_subLayout);

    // GUI main
    m_layout = new QVBoxLayout();
    this->setLayout(m_layout);
    this->setMinimumWidth(m_width);
    this->setMaximumWidth(m_width);
    m_layout->addLayout(m_titleLayout);
    m_layout->addWidget(m_detailWidget);
    // m_layout->addStretch(0);
}


void DatasetWidget::setDataset(Dataset* dataset)
{
    m_dataset = dataset;
}


void DatasetWidget::update()
{
    // set title
    QString title = QString::fromStdString(m_dataset->getTitle());
    m_titleLabel->setText(title);

    // set fields names
    int fieldNumber = 0;
    for (string fieldName : m_dataset->getNames())
    {
        // field number
        fieldNumber++;

        // create field item
        DatasetWidgetFieldItem *fieldItem = new DatasetWidgetFieldItem;
        fieldItem->setFieldName(fieldName);
        fieldItem->setFieldNumber(fieldNumber);

        // add field item in structures (layout & list)
        m_fieldItems->append(fieldItem);
        m_fieldsLayout->addWidget(fieldItem);
    }

    // update size of widgets name labels
    int maxNameLabelSize = 0;
    int nameLabelSize;
    for (DatasetWidgetFieldItem* widget : *m_fieldItems)
    {
        nameLabelSize = widget->getNameLabelWidth();
        if (nameLabelSize > maxNameLabelSize)
            maxNameLabelSize = nameLabelSize;
    }
    for (DatasetWidgetFieldItem* widget : *m_fieldItems)
    {
        widget->setNameLabelWidth(maxNameLabelSize);
    }
}


void DatasetWidget::showHide()
{
    if (m_showButton->isChecked())
    {
        m_showButton->setArrowType(Qt::ArrowType::RightArrow);
        m_detailWidget->hide();
    }
    else
    {
        m_showButton->setArrowType(Qt::ArrowType::DownArrow);
        m_detailWidget->show();
    }
}
