#include "curveconfigwidget.h"

CurveConfigWidget::CurveConfigWidget(QWidget *parent) : QWidget(parent)
{
    // non GUI attributes
    m_curve = new Curve();

    // layout
    m_layout = new QHBoxLayout();
    this->setLayout(m_layout);

    // widget title
    m_widgetTitle = new QLabel();
    m_layout->addWidget(m_widgetTitle);

    // color
    m_colorButton = new QPushButton();
    m_colorButton->setPalette(QColor(0, 0, 255));
    m_colorButton->setText("Set color");
    connect(m_colorButton, &QPushButton::clicked, this, &CurveConfigWidget::setColor);
    m_layout->addWidget(m_colorButton);

    m_colorRect = new QLabel();
    m_colorRect->setText("  ");
    m_colorRect->setPalette(QColor(0, 0, 255));
    m_colorRect->setAutoFillBackground(true);
    //m_colorRect->repaint(0, 0, 1000, 1000);
    m_layout->addWidget(m_colorRect);

    // style
    m_styleText = new QLabel();
    m_styleText->setText("Style");
    m_layout->addWidget(m_styleText);

    m_styleButton = new QComboBox();
    for (QString indexStyle : m_styleStringArray)
    {
        m_styleButton->addItem(indexStyle);
    }
    connect(m_styleButton, QOverload<int>::of(&QComboBox::activated), this, &CurveConfigWidget::setStyle);
    m_layout->addWidget(m_styleButton);

    // width
    m_widthText = new QLabel();
    m_widthText->setText("Width");
    m_layout->addWidget(m_widthText);

    m_widthButton = new QSpinBox();
    m_widthButton->setValue(1);
    connect(m_widthButton, QOverload<int>::of(&QSpinBox::valueChanged), this, &CurveConfigWidget::setWidth);
    m_layout->addWidget(m_widthButton);
}


void CurveConfigWidget::setCurve(Curve *curve)
{
    m_curve = curve;
    m_widgetTitle->setText(QString::fromStdString(m_curve->getYFieldName()));
}


void CurveConfigWidget::setColor()
{
    const QColor color = QColorDialog::getColor();
    if (color.isValid())
    {
        //m_color = color;

        // update color displayed in the widget
        m_colorButton->setPalette(QPalette(color));
        m_colorButton->setAutoFillBackground(true);

        m_colorRect->setPalette(color);

        // update curve color
        m_curve->setColor(color);
    }
}


void CurveConfigWidget::setWidth()
{
    int width = m_widthButton->value();
    QPen newPen(m_curve->pen());
    newPen.setWidth(width);
    m_curve->setPen(newPen);
}


void CurveConfigWidget::setStyle()
{
    int index = m_styleButton->currentIndex();
    QPen newPen(m_curve->pen());
    newPen.setStyle(m_styleDefArray[index]);
    m_curve->setPen(newPen);
}
