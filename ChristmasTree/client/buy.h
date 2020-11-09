#ifndef BUY_H
#define BUY_H

#include "decoration.h"

#include <QMap>

class Buy {
public:
    Buy();

    void add(Decoration& decor);
    void remove(Decoration& decor);
    void sell_all();
    QStringList output(int idx);

    QString getQuantity(Decoration& decor);
    int getDecorations();
    int getWeight();
    int getPrice();
    int getCartDifferent();

private:
    QMap <Decoration*, int> decor_buy;
    QStringList cart;
    int decorations;
    int all_weight;
    int all_price;
};

#endif // BUY_H
