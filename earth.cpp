#include "earth.h"

earth::earth(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

double earth::getRadius()
{
    return  diametr/2;
}

double earth::getMas()
{
    return mas;
}

earth::~earth()
{

}

QRectF earth::boundingRect() const
{
    return QRectF(-150,-150,300,300);   // Ограничиваем область, в которой лежит объект
}

void earth::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{



        painter->setBrush(Qt::red);     // Устанавливаем кисть, которой будем отрисовывать объект

        painter->drawEllipse(-diametr/2,-diametr/2,diametr,diametr);
        Q_UNUSED(option);
        Q_UNUSED(widget);

}
