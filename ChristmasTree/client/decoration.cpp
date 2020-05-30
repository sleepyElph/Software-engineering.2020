#include "decoration.h"

Decoration::Decoration() {
    name = "";
    weight = 0;
    price = 0;
}

Decoration::Decoration(QString n, int w, int p) {
    name = n;
    weight = w;
    price = p;
}

Decoration::Decoration(const Decoration& d) {
    name = d.name;
    weight = d.weight;
    price = d.price;
}


Decoration::~Decoration() {
}

QString Decoration::getName() {
    return name;
}

QString Decoration::getWeightStr() {
    return QString("%0гр").arg(weight);
}

QString Decoration::getPriceStr() {
    return QString("%0руб").arg(price);
}

int Decoration::getWeight() {
    return weight;
}

int Decoration::getPrice() {
    return price;
}


