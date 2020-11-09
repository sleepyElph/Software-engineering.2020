#include "mytablemodel.h"

#include <QModelIndex>
#include <QModelIndexList>
#include <QSortFilterProxyModel>

MyTableModel::MyTableModel(QObject *parent):
    QAbstractTableModel(parent){
        buy = new Buy();
        decors = js->parse();
    }


    int MyTableModel::rowCount(const QModelIndex &parent) const {
        Q_UNUSED(parent);
        return decors.length();
    }
    int MyTableModel::columnCount(const QModelIndex &parent) const {
        Q_UNUSED(parent);
        return 5;
    }

    QVariant MyTableModel::data(const QModelIndex &index, int role) const {
        if (role == Qt::DisplayRole) {
            switch (index.column()) {
            case 0:
                return decors[index.row()]->getName();
            case 1:
                return decors[index.row()]->getText();
            case 2:
                return decors[index.row()]->getWeightStr();
            case 3:
                return decors[index.row()]->getPriceStr();
            case 4:
                return buy->getQuantity(*decors[index.row()]);
            }
        }
        return QVariant();
    }

    QVariant MyTableModel::headerData( int section, Qt::Orientation orientation, int role ) const {
        if( role != Qt::DisplayRole ) {
            return QVariant();
        }
        if( orientation == Qt::Vertical ) {
            return section;
        }
        switch( section ) {
        case 0:
            return QString("Наименование");
        case 1:
            return QString("Дополнительно");
        case 2:
            return QString("Вес");
        case 3:
            return QString("Цена");
        case 4:
            return QString("Кол-во");
        }
        return QVariant();
    }

    void MyTableModel::add(QString firstColumn) {
        for (int i = 0; i < decors.length(); i++) {
            if (decors[i]->getName() == firstColumn) {
                buy->add(*decors[i]);
                break;
            }
        }
    }

    void MyTableModel::remove(QString firstColumn) {
        for (int i = 0; i < decors.length(); i++) {
            if (decors[i]->getName() == firstColumn) {
                buy->remove(*decors[i]);
                break;
            }
        }
    }

    void MyTableModel::json_cart(QMap <QString, QString> &dataPerson, QString keyPeson,QString fileName) {
        QMap <QString, int> dataBuy;
        for (int i = 0; i < buy->getCartDifferent(); i++) {
            cart = buy->output(i);
            dataBuy[cart[0]] = cart[1].toInt();
        }
        js->json_cart(keyPeson, dataPerson, "Buy", dataBuy, fileName, buy->getPrice());
    }

    int MyTableModel::cart_size(){
        if (buy->getDecorations() == 0) return 0;
        else return 1;
    }

    int MyTableModel::cart_price(){
        return buy->getPrice();
    }

    Buy* MyTableModel::getBuy(){
        return buy;
    }
