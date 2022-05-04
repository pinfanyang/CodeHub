#ifndef MYMAINWIDGET_H
#define MYMAINWIDGET_H

#include <QWidget>
#include <QPushButton>


class MyMainWidget : public QWidget
{
    Q_OBJECT

public:
    MyMainWidget(QWidget *parent = 0);
    ~MyMainWidget();



private:
    QPushButton b1;
    QPushButton *b2;
};

#endif // MYMAINWIDGET_H
