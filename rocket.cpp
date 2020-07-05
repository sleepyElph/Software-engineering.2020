#include "rocket.h"

void Rocket::slotMoove()
{
    if(GetAsyncKeyState('A')){
         angle-=1;

    }
      if(GetAsyncKeyState('D')){
         angle +=1;// Поворачиваем объект

      }
      if(GetAsyncKeyState('W')){
          speed+=0.01;

      }
      if(GetAsyncKeyState('S')){

         speed-=0.01;

      }
      speedX = speed*cos(angle*M_PI/180);
      speedY = speed*sin(angle*M_PI/180);

    setPos(mapToParent(speedX,speedY));
}

double Rocket::getMas()
{
    return  mas;
}

Rocket::Rocket(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

Rocket::Rocket(double angle, double speed, QObject *parent)
{
   this->angle = angle;
   this->speed=speed;
   speedX = speed*cos(angle*M_PI/180);
   speedY = speed*sin(angle*M_PI/180);
   // qDebug()<<speedX<<" "<<speedY;
}

double Rocket::getAngle()
{
    return angle;
}

void Rocket::delta(double deltaspeed, double deltaax,double deltaay)
{
     qDebug()<<deltaspeed;
     double dx = deltaspeed*deltaax;
     double dy = deltaspeed*deltaay;
     speedX+=dx/500;
     speedY+=dy/500;
     speed = sqrt(speedX*speedX+speedY*speedY);
     angle = abs(asin(speedY/speed)*180/M_PI);\
     if(speedX<0&& speedY<0){
         angle= 90 - angle;
         angle= - angle;
         angle -=90;
         //angle -= 90;
     }
     if(speedX<0 && speedY>0){
         angle = 90-angle;
         angle+=90;
     }
     if (speedX>0&& speedY<0){
        angle = - angle;
     }

}

Rocket::~Rocket()
{

}

QRectF Rocket::boundingRect() const
{
    return QRectF(-20,-20,40,40);   // Ограничиваем область, в которой лежит треугольник
}

void Rocket::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        QPolygon polygon;   // Используем класс полигона, чтобы отрисовать треугольник
        // Помещаем координаты точек в полигональную модель
       // polygon << QPoint(0,-40) << QPoint(25,40) << QPoint(-25,40);
        painter->setBrush(Qt::black);     // Устанавливаем кисть, которой будем отрисовывать объект
        // painter->drawPolygon(polygon);
        painter->drawEllipse(-10,-10,20,20);// Рисуем треугольник по полигональной модели
        Q_UNUSED(option);
        Q_UNUSED(widget);

}


















