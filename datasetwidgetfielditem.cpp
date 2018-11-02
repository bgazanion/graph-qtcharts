#include "datasetwidgetfielditem.h"

DatasetWidgetFieldItem::DatasetWidgetFieldItem(QFrame *parent) : QFrame(parent)
{
    m_fieldNumber = 0;
    m_fieldName = "";

    m_layout = new QHBoxLayout;
    m_layout->setContentsMargins(5, 0, 5, 0);
    m_layout->setSpacing(10);
    // this->setFrameStyle(QFrame::Plain);
    // this->setStyleSheet("border:1px solid rgb(0, 0, 0); background: solid rgb(100, 100, 100);");
    this->setStyleSheet("background: solid rgb(220, 220, 220);");
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


void DatasetWidgetFieldItem::setNameLabelWidth(int length)
{
    m_nameLabel->setMaximumWidth(length);
    m_nameLabel->setMinimumWidth(length);
}


int DatasetWidgetFieldItem::getNameLabelWidth()
{
    // return m_nameLabel->geometry().width();
    return m_nameLabel->fontMetrics().boundingRect(m_nameLabel->text()).width();
}
