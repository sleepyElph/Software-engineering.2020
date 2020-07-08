#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>

#include <earth.h>
#include <moon.h>
#include <qtimer.h>
#include <rocket.h>
#include <cmath>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

private slots:
    void slotDeltamove();

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget      *ui;
    QGraphicsScene  *scene;     // Объявляем графическую сцену
    earth       *earth;       // и объекты
    Rocket *rocket;
    QTimer *timer;
    Moon  *moon;

};

#endif // WIDGET_H
