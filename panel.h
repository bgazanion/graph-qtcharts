#ifndef PANEL_H
#define PANEL_H

#include <QFrame>
#include <QString>
#include <QLabel>
#include <QScrollArea>
#include <QWidget>
#include <QLayout>

class Panel : public QFrame
{
private:
    int m_width;
    int m_height;
    QLabel *m_titleLabel;
    QScrollArea *m_scrollArea;
    QVBoxLayout *m_layout;
    QWidget *m_layoutContainer;

public:
    Panel();
    void setTitle(QString title);
    void setContentWidget(QWidget *widget);
    void setContentLayout(QLayout *layout);
};

#endif // PANEL_H
