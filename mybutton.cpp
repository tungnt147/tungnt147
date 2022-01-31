#include <mybutton.h>

MyButton::MyButton(const QString &text, QWidget *parent) :
        QPushButton(text, parent)
    {
        rePaint = false;
    }

void MyButton::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "MOUSE PRESS!";
    QPushButton::mousePressEvent(event);
    rePaint = true;
    this->update();
}

void MyButton::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "MOUSE RELEASE!";
    QPushButton::mouseReleaseEvent(event);
    rePaint = false;
}

void MyButton::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "MOUSE MOVE!";
    QPushButton::mouseMoveEvent(event);
}

void MyButton::paintEvent(QPaintEvent* event)
{
        qDebug() << "Paint event!";
        QImage image;
        image.load(":/new/images/astralis.png");
        QPainter painter(this);
        painter.drawImage(QPoint(0, 0), image);

}

