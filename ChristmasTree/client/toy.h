#ifndef TOY_H
#define TOY_H

#include "decoration.h"

#include <QJsonObject>

/**
 * @brief The Toy class
 */
class Toy : public Decoration {
public:
    Toy();
    Toy(QString n, int w, int p, QString f);
    Toy(const Decoration& d);
    Toy(const QJsonObject & object);

    virtual ~Toy();

    QString getText() override;

private:
    QString form;
};

#endif // TOY_H
