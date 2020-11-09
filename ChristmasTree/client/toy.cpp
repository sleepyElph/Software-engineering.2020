#include "toy.h"

Toy::Toy() :Decoration()
{ }

Toy::Toy(QString n, int w, int p, QString f)
    : Decoration(n, w, p), form(f)
{ }

Toy::Toy(const Decoration& d) : Decoration(d)
{ }

Toy::Toy(const QJsonObject &object) {
    name = object["name"].toString();
    weight = object["weight"].toInt();
    price = object["price"].toInt();
    form = object["form"].toString();
}

QString Toy::getText() {
    return form;
}

Toy::~Toy()
{ }



