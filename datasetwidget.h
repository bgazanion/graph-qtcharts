#ifndef DATASETWIDGET_H
#define DATASETWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QString>
#include <QWidget>
#include <QToolButton>
#include <QCheckBox>
#include <QList>
#include <QPushButton>
#include <string>
#include <iostream>
#include "datasetwidgetfielditem.h"
#include "dataset.h"

using namespace std;

class DatasetWidget : public QWidget
{
    Q_OBJECT

private:
    // non GUI
    int m_width;
    Dataset *m_dataset;
    QList<DatasetWidgetFieldItem*> *m_fieldItems;
    // fixed GUI elements
    QVBoxLayout *m_layout;
    QLabel *m_titleLabel;
    QHBoxLayout *m_titleLayout;
    QToolButton *m_showButton;
    QPushButton *m_deleteButton;

    // field details
    QWidget *m_detailWidget;
    QVBoxLayout *m_fieldsLayout;
    QHBoxLayout *m_subLayout;

public:
    explicit DatasetWidget(QWidget *parent = nullptr);
    void setDataset(Dataset *dataset);
    void update();
    void showHide();
    QList<DatasetWidgetFieldItem*>* getFieldItems();
    QPushButton* getDeleteButton();
    Dataset* getDataset();

signals:
    void deleteSignal(DatasetWidget *datasetWidget);

private slots:
    void handleDeleteClick()
    {
        cout << "emitting signal..." << endl;
        emit(deleteSignal(this));
        cout << "...done" << endl;
    }
};

#endif // DATASETWIDGET_H
