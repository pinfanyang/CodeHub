#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc,char **argv)
{
       QApplication app(argc,argv);

       QWidget w;
       w.setWindowTitle("主要看气质！");

       QPushButton b;
       b.setText("$_$!!");
       b.setParent(&w);
       //b.show();

       QPushButton b1(&w);
       b1.setText("abc");
       b1.move(100,100);


       w.show();
       app.exec();
       return 0;
}
