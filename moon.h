#ifndef MOON_H
#define MOON_H
#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QGraphicsScene>

#include <windows.h>
#include <cmath>
// Наследуемся от QGraphicsItem
class Moon : public QObject, public QGraphicsItem
{
    Q_OBJECT

public slots:
    void slotGameTimer();



public:
    explicit Moon(QObject *parent = 0);
    double getMas();
    double getRadius();
   // Moon();
    ~Moon();

protected:
    QRectF boundingRect() const;    /* Определяем виртуальный метод,
                                     * который возвращает область, в которой находится объект
                                     * */
    /* Определяем метод для отрисовки
     * */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    double mas =2.9808873577377351511981943427694e-6*7.3477E22;
    double diametr = 50;
    double angle;
    double orbit = 1700;
    double xx = orbit*cos(0*M_PI/180);
    double yy = orbit*sin(0*M_PI/180);




};

#endif // TRIANGLE_H
