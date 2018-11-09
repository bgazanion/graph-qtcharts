#ifndef CHARTCONFIGWIDGET_H
#define CHARTCONFIGWIDGET_H

#include <QWidget>
#include <QChartView>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QCheckBox>
#include <QPushButton>
#include <QToolButton>
#include <QLocale>
#include <QValueAxis>
#include <QLogValueAxis>
#include <QAbstractAxis>
#include <QAbstractSeries>
#include <QComboBox>
#include <QList>
#include <string>


using namespace QtCharts;
using namespace std;

class ChartConfigWidget : public QWidget
{
    Q_OBJECT

private:
    QChartView *m_chartView;
    // layout
    QVBoxLayout *m_layout;
    // title
    QLabel *m_titleLabel;
    QLineEdit *m_titleField;
    QHBoxLayout *m_titleLayout;

    // X field
    string *m_xName;
    QLabel *m_xNameLabel;
    QComboBox *m_xNameBox;

    // X axis
    //  -> general
    QLabel  *m_xLabel;
    QToolButton *m_xButton;
    QWidget *m_xDetailWidget;
    QVBoxLayout *m_xMainLayout;
    QHBoxLayout *m_xTitleLayout;
    QVBoxLayout *m_xContentLayout;
    //  -> grid
    QHBoxLayout *m_xGridLayout;
    QLabel *m_xGridLabel;
    QCheckBox *m_xGridButton;
    //  -> range
    QHBoxLayout *m_xRangeLayout;
    QLabel *m_xRangeLabel;
    QLineEdit *m_xMinField;
    QLineEdit *m_xMaxField;
    QPushButton *m_xRangeButton;
    // -> log scale
    QHBoxLayout *m_xLogLayout;
    QLabel *m_xLogLabel;
    QCheckBox *m_xLogButton;
    QLabel *m_xLogBaseLabel;
    QComboBox *m_xLogBaseButton;

    // Y axis
    //  -> general
    QLabel  *m_yLabel;
    QToolButton *m_yButton;
    QWidget *m_yDetailWidget;
    QVBoxLayout *m_yMainLayout;
    QHBoxLayout *m_yTitleLayout;
    QVBoxLayout *m_yContentLayout;
    //  -> grid
    QHBoxLayout *m_yGridLayout;
    QLabel *m_yGridLabel;
    QCheckBox *m_yGridButton;
    //  -> range
    QHBoxLayout *m_yRangeLayout;
    QLabel *m_yRangeLabel;
    QLineEdit *m_yMinField;
    QLineEdit *m_yMaxField;
    QPushButton *m_yRangeButton;
    // -> log scale
    QHBoxLayout *m_yLogLayout;
    QLabel *m_yLogLabel;
    QCheckBox *m_yLogButton;
    QLabel *m_yLogBaseLabel;
    QComboBox *m_yLogBaseButton;

    // utils
    QDoubleValidator *m_doubleValidator;



public:
    explicit ChartConfigWidget(QWidget *parent = nullptr);
    ~ChartConfigWidget();
    void setChartView(QChartView *chartView);
    // X
    void showHideX();
    void setXRange();
    void updateXScale();
    void setXGrid();
    // Y
    void showHideY();
    void setYRange();
    void updateYScale();
    void setYGrid();
    // data
    string* getXName();

signals:

public slots:
};

#endif // CHARTCONFIGWIDGET_H
