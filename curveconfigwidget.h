#ifndef CURVECONFIGWIDGET_H
#define CURVECONFIGWIDGET_H

#include <QWidget>
#include <QColor>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QColorDialog>
#include <QPushButton>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QPalette>
#include <QString>
#include "curve.h"


class CurveConfigWidget : public QWidget
{
    Q_OBJECT
private:
    Curve *m_curve;
    int m_baseWidth;
    int m_height;
    QHBoxLayout *m_layout;
    QLabel *m_widgetTitle;
    QPushButton *m_colorButton;
    QComboBox *m_styleButton;
    QLabel *m_styleText;
    QSpinBox *m_widthButton;
    QLabel *m_widthText;
    Qt::PenStyle m_styleDefArray[5] =
    {
        Qt::PenStyle::SolidLine,
        Qt::PenStyle::DashLine,
        Qt::PenStyle::DotLine,
        Qt::PenStyle::DashDotLine,
        Qt::PenStyle::DashDotDotLine
    };
    QString m_styleStringArray[5] =
    {
        "-",
        "--",
        ".",
        "-.",
        "-.."
    };
    QLabel *m_colorRect;


public:
    explicit CurveConfigWidget(QWidget *parent = nullptr);
    void setCurve(Curve *curve);
    void setColor();
    void setWidth();
    void setStyle();
    Curve* getCurve();

signals:

public slots:
};

#endif // CURVECONFIGWIDGET_H
