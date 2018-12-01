#include "importwindow.h"

ImportWindow::ImportWindow(QWidget *parent) : QMainWindow(parent)
{
    m_width = 600;
    this->setMaximumWidth(m_width);
    this->setMinimumWidth(m_width);

    // lower layout : Apply and Close button
    m_applyButton = new QPushButton();
    m_applyButton->setText("Apply");

    m_closeButton = new QPushButton();
    m_closeButton->setText("Close");
    connect(m_closeButton, &QPushButton::clicked, this, &ImportWindow::close);

    m_lowerLayout = new QHBoxLayout();
    m_lowerLayout->addWidget(m_applyButton);
    m_lowerLayout->addWidget(m_closeButton);

    // import buttons
    m_importCSVButton = new QPushButton();
    m_importCSVButton->setText("Import CSV file");
    connect(m_importCSVButton, &QPushButton::clicked, this, &ImportWindow::importCSV);

    m_importRButton = new QPushButton();
    m_importRButton->setText("Import R file");

    m_buttonLayout = new QGridLayout();
    m_buttonLayout->addWidget(m_importCSVButton, 0, 0);
    m_buttonLayout->addWidget(m_importRButton, 0, 1);

    // status text
    m_statusText = new QTextEdit();
    m_statusText->setReadOnly(true);
    m_statusText->setText("");

    // main layout
    m_mainLayout = new QVBoxLayout();
    m_mainLayout->addLayout(m_buttonLayout);
    m_mainLayout->addWidget(m_statusText);
    m_mainLayout->addLayout(m_lowerLayout);

    m_centralWidget = new QWidget();
    m_centralWidget->setLayout(m_mainLayout);

    // m_mainLayout->
    this->setCentralWidget(m_centralWidget);
}


Dataset* ImportWindow::importCSV()
{
    // open file dialog
    QFileDialog dialog;
    string fileName = dialog.getOpenFileName().toStdString();
    Dataset *dataset = readCSV(fileName);
    return dataset;
}
