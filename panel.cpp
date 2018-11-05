#include "panel.h"

Panel::Panel()
{
    m_width = 100;
    m_height = 100;
    m_titleLabel = new QLabel();

    m_layoutContainer = new QWidget();

    m_scrollArea = new QScrollArea();
    m_scrollArea->setWidgetResizable(true);
    // m_scrollArea->setSizeAdjustPolicy(QScrollArea::)
    m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    /*
    m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    */

    m_layout = new QVBoxLayout();
    m_layout->addWidget(m_titleLabel);
    m_layout->addWidget(m_scrollArea);

    this->setLayout(m_layout);
    this->setFrameStyle(Qt::SolidLine);
}


void Panel::setTitle(QString title)
{
    m_titleLabel->setText(title);
}


void Panel::setContentWidget(QWidget *widget)
{
    // add widget to content, and hide unnecessary layout container
    m_scrollArea->setWidget(widget);
    // m_layout->addWidget(widget);
    // m_layout->addStretch();
}


void Panel::setContentLayout(QLayout *layout)
{
    m_layoutContainer->setLayout(layout);
    m_scrollArea->setWidget(m_layoutContainer);
    // m_layout->addWidget(m_layoutContainer);
    // m_layout->addWidget(m_scrollArea);
    // m_layout->addStretch();
}
