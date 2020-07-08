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
    return QRectF(-25,-40,50,80);   // Ограничиваем область, в которой лежит объект
}

void Moon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{



        painter->setBrush(Qt::red);     // Устанавливаем кисть, которой будем отрисовывать объект

        painter->drawEllipse(-diametr/2,-diametr/2,diametr,diametr);// Рисуем
        Q_UNUSED(option);
        Q_UNUSED(widget);
}
