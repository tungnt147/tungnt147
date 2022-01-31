#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QDebug>

#include <QPainter>
class MyButton: public QPushButton{
    public:
        MyButton(const QString &text, QWidget *parent = Q_NULLPTR);
        virtual void mousePressEvent(QMouseEvent *event);
        virtual void mouseReleaseEvent(QMouseEvent *event);
        virtual void mouseMoveEvent(QMouseEvent *event);
        virtual void paintEvent(QPaintEvent* event);
    private:
        bool rePaint;
};


#endif // MYBUTTON_H
