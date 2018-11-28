#ifndef IMPORTWINDOW_H
#define IMPORTWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QWidget>
#include <QTextEdit>
#include <QFileDialog>
#include <string>
#include "readers.h"
#include "dataset.h"

class ImportWindow : public QMainWindow
{
    Q_OBJECT

private:
    QPushButton *m_closeButton;
    QPushButton *m_applyButton;
    QPushButton *m_importCSVButton;
    QPushButton *m_importRButton;
    QVBoxLayout *m_mainLayout;
    QWidget *m_centralWidget;
    QGridLayout *m_buttonLayout;
    QHBoxLayout *m_lowerLayout;
    QTextEdit *m_statusText;
    int m_width;

public:
    explicit ImportWindow(QWidget *parent = nullptr);

signals:

private slots:
    Dataset* importCSV();
};

#endif // IMPORTWINDOW_H
