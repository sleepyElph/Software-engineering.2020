#include "widget.h"
#include "ui_widget.h"
const double G=6.67e-11;


void Widget::slotDeltamove()
{

       double dist = sqrt(pow(rocket->x()-earth->x(),2)+pow(rocket->y()-earth->y(),2));
       double aangle = (earth->x()-rocket->x())/dist;
       double aangley = (earth->y()-rocket->y())/dist;
       double F= (rocket->getMas()*G*earth->getMas())/pow(dist*1000,2);
       double dist2 = sqrt(pow(rocket->x()-moon->x(),2)+pow(rocket->y()-moon->y(),2));
       double aangle2 = (moon->x()-rocket->x())/dist2;
       double aangley2 = (moon->y()-rocket->y())/dist2;
       double F2= (rocket->getMas()*G*moon->getMas())/pow(dist2*1000,2);


   if (pow(rocket->x()-earth->x(),2)+pow((rocket->y()-earth->y()),2)<=pow(earth->getRadius(),2)){

       rocket->setPos(-earth->getRadius()*aangle,-earth->getRadius()*aangley);
       rocket->delta(-F/400,aangle,aangley);


   }else{
       rocket->delta(F/1000,aangle,aangley);
       rocket->delta(F2/100,aangle2,aangley2);

   }
   if (pow(rocket->x()-moon->x(),2)+pow((rocket->y()-moon->y()),2)<=pow(moon->getRadius(),2)){

       rocket->setPos(moon->x()-moon->getRadius()*aangle2,moon->y()-moon->getRadius()*aangley2);
      rocket->delta(-F/1,aangle2,aangley2);
   }else{
       rocket->delta(F/1000,aangle,aangley);
       rocket->delta(F2/200,aangle2,aangley2);
   }

}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(1920,1080);          // Задаем размеры виджета, то есть окна
    this->setFixedSize(1920,1080);    // Фиксируем размеры виджета

    scene = new QGraphicsScene();     // Инициализируем графическую сцену

    ui->graphicsView->setScene(scene);        // Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Устанавливаем сглаживание
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  // Отключаем скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  // Отключаем скроллбар по горизонтали

    scene->setSceneRect(-30000,-30000,60000,60000);  // Устанавливаем область графической сцены
    ui->graphicsView->scale(0.6,0.6);
     // Добавляем вертикальную линию через центр



}

    Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    earth = new class earth();        // Инициализируем
    moon = new  Moon();
    scene->addItem(earth);

    scene->addItem(moon);     // Добавляем на сцену
    earth->setPos(0,0);
    moon->setPos(1700,0);
    scene->addLine(-250,0,250,0,QPen(Qt::black));   // Добавляем горизонтальную линию через центр
    scene->addLine(0,-250,0,250,QPen(Qt::black));
    rocket = new Rocket(ui->lineAngle->text().toDouble(),ui->lineEdit->text().toDouble());
    timer = new QTimer();


      scene->addItem(rocket);
      rocket->setPos(0,-25*3.667);
      connect(timer, &QTimer::timeout, moon, &Moon::slotGameTimer);
      connect(timer, &QTimer::timeout,this, &Widget::slotDeltamove);
      connect(timer, &QTimer::timeout,rocket,&Rocket::slotMoove);


      timer->start(10);
      ui->pushButton->blockSignals(true);
      ui->lineEdit->setReadOnly(true);
      ui->lineAngle->setReadOnly(true);

}
