#include "buy.h"
#include "decoration.h"
#include "toy.h"
#include "garland.h"

using namespace std;

Buy::Buy() {
    decor_buy.clear();
    decorations = 0;
    all_weight = 0;
    all_price = 0;
}

void Buy::add(Decoration &decor) {
    decor_buy[&decor] = decor_buy[&decor] + 1;
    decorations++;
    all_price += (decor.getPrice());
    all_weight += (decor.getWeight());
}

void Buy::remove(Decoration &decor) {
    for (auto iter =  decor_buy.begin(); iter !=  decor_buy.end(); iter++) {
        if (iter.key() == &decor) {
            decorations--;
            all_price -= iter.key()->getPrice();
            all_weight -= iter.key()->getWeight();
            if (iter.value() != 0) iter.value()--;
            if (iter.value() == 0) {
                decor_buy.erase(iter);
                break;
            }
        }
    }
}

void Buy::sell_all() {
    decor_buy.clear();
    decorations = 0;
    all_price = 0;
    all_weight = 0;
}

QString Buy::getQuantity(Decoration &decor) {
    for (auto iter =  decor_buy.begin(); iter !=  decor_buy.end(); iter++) {
        if (iter.key() == &decor) return  (QString::number(iter.value()));
    }
    return "0";
}

QStringList Buy::output(int idx) {
    int position = 0;
    cart.clear();
    for (auto iter =  decor_buy.begin(); iter !=  decor_buy.end(); iter++) {
        if (position == idx) {
            cart.push_back(iter.key()->getName());
            cart.push_back(QString::number(iter.value()));
        }
        position++;
    }
    return cart;
}


int Buy::getWeight() {
    return all_weight;
}

int Buy::getDecorations() {
    return decorations;
}

int Buy::getPrice() {
    return all_price;
}


int Buy::getCartDifferent() {
    return decor_buy.size();
}
