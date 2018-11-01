#include "datasetwidgetfielditem.h"

DatasetWidgetFieldItem::DatasetWidgetFieldItem(QWidget *parent) : QWidget(parent)
{
    m_fieldNumber = 0;
    m_fieldName = "";

    m_layout = new QHBoxLayout;
    this->setLayout(m_layout);

    m_numberLabel = new QLabel;
    m_layout->addWidget(m_numberLabel);

    m_nameLabel = new QLabel;
    m_layout->addWidget(m_nameLabel);

    m_plotLabel = new QLabel;
    m_plotLabel->setText("plot");
    m_layout->addWidget(m_plotLabel);

    m_plotButton = new QToolButton;
    m_plotButton->setArrowType(Qt::ArrowType::NoArrow);
    m_plotButton->setCheckable(true);
    m_plotButton->setChecked(false);
    connect(m_plotButton, &QToolButton::clicked, this, &DatasetWidgetFieldItem::plot);
    m_layout->addWidget(m_plotButton);
}


void DatasetWidgetFieldItem::plot()
{
    if (m_plotButton->isChecked())
    {
        m_plotButton->setArrowType(Qt::ArrowType::RightArrow);
    }
    else
    {
        m_plotButton->setArrowType(Qt::ArrowType::NoArrow);
    }
}


void DatasetWidgetFieldItem::setFieldNumber(int number)
{
    m_fieldNumber = number;
    m_numberLabel->setText(QString::fromStdString(to_string(m_fieldNumber)));
}


void DatasetWidgetFieldItem::setFieldName(string name)
{
    m_fieldName = name;
    m_nameLabel->setText(QString::fromStdString(m_fieldName));
}
