    #ifndef Rocket_H
    #define Rocket_H


    #include <QGraphicsItem>
    #include <QPainter>
    #include <QObject>
    #include <QGraphicsScene>

    #include <windows.h>
    #include <cmath>
    #include <QtDebug>

    // Наследуемся от QGraphicsItem
    class Rocket : public QObject ,public QGraphicsItem
    {
        Q_OBJECT

    public slots:

         void slotMoove();


    public:
        double getMas();
        explicit Rocket(QObject *parent = 0);
        explicit Rocket(double angle,double speed,QObject *parent =0);
        double getAngle();


        void delta (double deltaspeed,double deltaax,double deltaay);


        ~Rocket();

    protected:
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    private:


        double mas = 150000;
        double speed;
        double speedX;
        double speedY;
        double angle;

        double rotation =0;



    };

    #endif // TRIANGLE_H
