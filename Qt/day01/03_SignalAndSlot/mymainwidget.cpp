#include "mymainwidget.h"
#include <QPushButton>

MyMainWidget::MyMainWidget(QWidget *parent)
    : QWidget(parent)
{
     b1.setParent(this);
     b1.setText("close");
     b1.move(100,100);

     b2 = new QPushButton(this);
     b2->setText("abc");

     connect(&b1,&QPushButton::pressed,this,&MyMainWidget::close);
}

MyMainWidget::~MyMainWidget()
{

}
