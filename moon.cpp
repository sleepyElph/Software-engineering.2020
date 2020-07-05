#include "moon.h"

void Moon::slotGameTimer()
{

    angle+=1/516.6;
    if (angle >= 360){
        angle = 0; }

    //setPos()
    setPos(mapToParent(orbit*cos(angle*M_PI/180)-xx,yy-orbit*sin(angle*M_PI/180)));
    xx= orbit*cos(angle*M_PI/180);
    yy =orbit*sin(angle*M_PI/180);



}

Moon::Moon(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    angle =0;
}

double Moon::getMas()
{
    return  mas;
}

double Moon::getRadius()
{
    return  diametr/2;
}

Moon::~Moon()
{

}

QRectF Moon::boundingRect() const
{
    return QRectF(-25,-40,50,80);   // Ограничиваем область, в которой лежит треугольник
}

void Moon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


       // QPolygon polygon;   // Используем класс полигона, чтобы отрисовать треугольник
       // Помещаем координаты точек в полигональную модель
       // polygon << QPoint(0,-40) << QPoint(25,40) << QPoint(-25,40);
        painter->setBrush(Qt::red);     // Устанавливаем кисть, которой будем отрисовывать объект
       // painter->drawPolygon(polygon);
        painter->drawEllipse(-diametr/2,-diametr/2,diametr,diametr);// Рисуем треугольник по полигональной модели
        Q_UNUSED(option);
        Q_UNUSED(widget);
}
