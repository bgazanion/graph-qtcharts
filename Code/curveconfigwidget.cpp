#include "curveconfigwidget.h"

CurveConfigWidget::CurveConfigWidget(QWidget *parent) : QWidget(parent)
{
    // non GUI attributes
    m_curve = new Curve();
    m_height = 25;
    m_baseWidth = 80;

    // layout
    m_layout = new QHBoxLayout();
    this->setLayout(m_layout);

    // widget title
    m_widgetTitle = new QLabel();
    m_layout->addWidget(m_widgetTitle);
    m_layout->addSpacing(0);

    // color
    m_colorButton = new QPushButton();
    m_colorButton->setMaximumWidth(m_baseWidth);
    m_colorButton->setMinimumWidth(m_baseWidth);
    m_colorButton->setMaximumHeight(m_height);
    m_colorButton->setText("Set color");
    connect(m_colorButton, &QPushButton::clicked, this, &CurveConfigWidget::setColor);
    m_layout->addWidget(m_colorButton);

    m_colorRect = new QLabel();
    m_colorRect->setText("  ");
    m_colorRect->setPalette(QColor(0, 0, 255));
    m_colorRect->setAutoFillBackground(true);
    m_colorRect->setMaximumWidth(m_height);
    m_colorRect->setMinimumWidth(m_height);
    m_colorRect->setMaximumHeight(m_height);
    m_layout->addWidget(m_colorRect);

    // style
    m_styleText = new QLabel();
    m_styleText->setText("Style");
    m_styleText->setMaximumWidth(static_cast<int>(0.4*m_baseWidth));
    m_styleText->setMinimumWidth(static_cast<int>(0.4*m_baseWidth));
    m_styleText->setMaximumHeight(m_height);
    m_layout->addWidget(m_styleText);

    m_styleButton = new QComboBox();
    m_styleButton->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    m_styleButton->setMaximumHeight(m_height);
    for (QString linestyleIcon : m_styleIconsArray)
    {
        QIcon icon;
        // icon.addPixmap(QPixmap(":/Icons/linestyle_line"));
        icon.addPixmap(QPixmap(linestyleIcon));
        m_styleButton->addItem(icon, "");
    }
    m_styleButton->setIconSize(QSize(90, 20));
    connect(m_styleButton, QOverload<int>::of(&QComboBox::activated), this, &CurveConfigWidget::setStyle);
    m_layout->addWidget(m_styleButton);

    // width
    m_widthText = new QLabel();
    m_widthText->setText("Width");
    m_widthText->setMaximumWidth(static_cast<int>(0.4*m_baseWidth));
    m_widthText->setMinimumWidth(static_cast<int>(0.4*m_baseWidth));
    m_widthText->setMaximumHeight(m_height);
    m_layout->addWidget(m_widthText);

    m_widthButton = new QSpinBox();
    m_widthButton->setValue(1);
    m_widthButton->setMaximumWidth(static_cast<int>(0.7*m_baseWidth));
    m_widthButton->setMinimumWidth(static_cast<int>(0.7*m_baseWidth));
    m_widthButton->setMaximumHeight(m_height);
    connect(m_widthButton, QOverload<int>::of(&QSpinBox::valueChanged), this, &CurveConfigWidget::setWidth);
    m_layout->addWidget(m_widthButton);
}


void CurveConfigWidget::setCurve(Curve *curve)
{
    m_curve = curve;
    m_widgetTitle->setText(QString::fromStdString(m_curve->getYFieldName()));
    m_colorRect->setPalette(curve->color());
}


void CurveConfigWidget::setColor()
{
    const QColor color = QColorDialog::getColor();
    if (color.isValid())
    {
        // update color displayed in the widget
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


Curve* CurveConfigWidget::getCurve()
{
    return m_curve;
}
