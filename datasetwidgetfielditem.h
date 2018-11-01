#ifndef DATASETWIDGETFIELDITEM_H
#define DATASETWIDGETFIELDITEM_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QToolButton>
#include <QString>
#include <string>

using namespace std;

class DatasetWidgetFieldItem : public QWidget
{
    Q_OBJECT

private:
    QHBoxLayout *m_layout;
    QLabel *m_numberLabel;
    QLabel *m_nameLabel;
    QLabel *m_plotLabel;
    QToolButton *m_plotButton;
    string m_fieldName;
    int m_fieldNumber;

public:
    explicit DatasetWidgetFieldItem(QWidget *parent = nullptr);
    void plot();
    void setFieldNumber(int number);
    void setFieldName(string name);

signals:

public slots:
};

#endif // DATASETWIDGETFIELDITEM_H
