#ifndef DECORATION_H
#define DECORATION_H

#include <QString>

class Decoration {
public:
    Decoration();
    Decoration(QString n, int w, int p);
    Decoration(const Decoration& d);

    virtual ~Decoration() = 0;

    QString getName();
    QString getWeightStr();
    QString getPriceStr();
    int getWeight();
    int getPrice();

    virtual QString getText() = 0;

protected:
    QString name;
    int weight;
    int price;
};

#endif // DECORATION_H
