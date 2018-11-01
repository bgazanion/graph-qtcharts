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
#include <string>
#include "datasetwidgetfielditem.h"
#include "dataset.h"

using namespace std;

class DatasetWidget : public QWidget
{
    Q_OBJECT

private:
    // non GUI
    Dataset *m_dataset;
    QList<DatasetWidgetFieldItem*> *m_fieldItems;
    // fixed GUI elements
    QVBoxLayout *m_layout;
    QLabel *m_titleLabel;
    QHBoxLayout *m_titleLayout;
    QToolButton *m_showButton;
    // field details
    QWidget *m_detailWidget;
    QGridLayout *m_fieldsLayout;
    QHBoxLayout *m_subLayout;

public:
    explicit DatasetWidget(QWidget *parent = nullptr);
    void setDataset(Dataset *dataset);
    void update();
    void showHide();

signals:

public slots:
};

#endif // DATASETWIDGET_H
