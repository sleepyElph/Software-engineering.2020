#ifndef GARLAND_H
#define GARLAND_H

#include "decoration.h"

#include <QJsonObject>

class Garland :public Decoration {
public:
    Garland();
    Garland(QString n, int w, int p, int l);
    Garland(const Decoration& d);
    Garland(const QJsonObject & object);

    virtual ~Garland();

    QString getText() override;

private:
    int length;
};

#endif // GARLAND_H
