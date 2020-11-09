#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H

#include "buy.h"
#include "toy.h"
#include "json.h"
#include "garland.h"

#include <QAbstractTableModel>

class MyTableModel: public QAbstractTableModel
{
    Q_OBJECT
public:
    MyTableModel(QObject *parent);

    void add(QString firstColumn);
    void remove(QString firstColumn);
    void json_cart(QMap <QString, QString> &dataPerson, QString keyPeson, QString fileName);

    int cart_size();
    int cart_price();
    Buy* getBuy();

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData( int section, Qt::Orientation orientation, int role ) const;

private:
    Buy* buy;
    Json* js;
    QList <Decoration*> decors;
    QList <QString> cart;
};

#endif // MYTABLEMODEL_H
