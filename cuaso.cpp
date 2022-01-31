#include <cuaso.h>

int a = 5;
CuaSo::CuaSo(){
    drawingLeft = false;
    drawingRight = false;
    setFixedSize(500, 500);
    m_nutBam = new QPushButton("Quit", this);
    m_nutBam1 = new MyButton("QuiT", this);
    m_nutBam1->setFont(QFont("Comic Sans MS", 14));
    m_nutBam1->setCursor(Qt::PointingHandCursor);
    m_nutBam->setGeometry(300,100,100,30);
    m_nutBam->setFont(QFont("Comic Sans MS", 14));
    m_nutBam->setCursor(Qt::PointingHandCursor);

    m_lcd = new QLCDNumber(this);
    m_lcd->setSegmentStyle(QLCDNumber::Flat);
    m_lcd->move(100, 100);

    m_thanhGiaTri = new QSlider(Qt::Horizontal, this);
    m_thanhGiaTri->setRange(200, 500);
    m_thanhGiaTri->setGeometry(10, 60, 150, 20);

    QObject::connect(m_thanhGiaTri,
                     SIGNAL(valueChanged(int)),
                     m_lcd,
                     SLOT(display(int))) ;
    QObject::connect(m_thanhGiaTri,
                     SIGNAL(valueChanged(int)),
                     this,
                     SLOT(thayDoiChieuRong(int)));
    QObject::connect(this,
                     SIGNAL(kichThuocToiDa()),
                     qApp,
                     SLOT(quit()));
    QObject::connect(m_nutBam,
                     SIGNAL(clicked()),
                     this,
                     SLOT(moHopThoai()));
}

void CuaSo::thayDoiChieuRong(int chieuRong){
    setFixedSize(chieuRong, 500);
    if (chieuRong == 500){
        emit kichThuocToiDa();
    }
}

void CuaSo::moHopThoai(){
    qDebug() << "MOUSE PRESS!";
    int traLoi = QMessageBox::question(this,
                             "MessageBox",
                             "Hello guys",
                             QMessageBox::Yes | QMessageBox::No);
    if (traLoi == QMessageBox::Yes){
            QMessageBox::information(this,
                                     "Trả lời", "Why yes");
        }else if (traLoi == QMessageBox::No){
            QMessageBox::information(this,
                                     "Trả lời", "Why no");
    }
}




//void CuaSo::mousePressEvent(QMouseEvent *event){
//    if (event->button() == Qt::LeftButton)
//    {
//        drawingLeft = true;
//        this->update();
//    }
//    else{
//        drawingRight = true;
//        QWidget::mousePressEvent(event);
//    }

//}

void CuaSo::paintEvent(QPaintEvent *event)
{
    if(drawingLeft == true){
        QPainter linePainter(this);
        linePainter.drawLine(QPoint(50, 60), QPoint(100, 100));
    }
    if(drawingRight == true){
        QPainter linePainter(this);
        linePainter.drawLine(QPoint(100, 100), QPoint(150, 150));
    }
}

void CuaSo::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        drawingLeft = false;
        drawingRight = false;
    }
    if (event->button() == Qt::RightButton)
    {
        drawingRight = true;
    }
}

void QWidget::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::RightButton)
        {
            this->update();
        }
}
