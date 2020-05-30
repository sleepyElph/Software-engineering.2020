#include "garland.h"

Garland::Garland() :Decoration()
{ }

Garland::Garland(QString n, int w, int p, int l)
    : Decoration(n, w, p), length(l)
{ }


Garland::Garland(const Decoration& d) : Decoration(d)
{ }

Garland::Garland(const QJsonObject &object) {
    name = object["name"].toString();
    weight = object["weight"].toInt();
    price = object["price"].toInt();
    length = object["length"].toInt();
}

QString Garland::getText() {
    return QString("%0м").arg(length);
}

Garland::~Garland()
{ }
