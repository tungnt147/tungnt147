#ifndef CUASO_H
#define CUASO_H
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include <QMessageBox>
#include <mybutton.h>

#include <QPainter>
#include <QMouseEvent>
#include <QFileDialog>

#include <QDebug>

class CuaSo: public QWidget{
    Q_OBJECT

    public:
        CuaSo();
//        virtual void mousePressEvent(QMouseEvent *event);
        virtual void paintEvent(QPaintEvent *event);
        virtual void mouseReleaseEvent(QMouseEvent *event);
        //virtual void mousePressEvent(QMouseEvent *event);
    public slots:
        void thayDoiChieuRong(int chieuRong);
        void moHopThoai();


    signals:
        void kichThuocToiDa();

    private:
        QPushButton *m_nutBam;
        QPushButton *m_nutBam1;
        QLCDNumber *m_lcd;
        QSlider *m_thanhGiaTri;
        bool drawingLeft;
        bool drawingRight;
};

#endif // CUASO_H
