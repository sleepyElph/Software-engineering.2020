#ifndef EARTH_H
#define EARTH_H


#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QGraphicsScene>

#include <windows.h>


// Наследуемся от QGraphicsItem
class earth : public QObject ,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit earth(QObject *parent = 0);
    double getRadius();
    double getMas();
   // earth();
    ~earth();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    double mas = 2.9808873577377351511981943427694e-6 *5.972E24;
    double diametr = 50*3.667;
};

#endif // TRIANGLE_H
