#ifndef TABLEMODEL_H
#define TABLEMODEL_H
#include <QAbstractTableModel>
#include <QMap>
#include "base.h"
#include "indexes.h"

// Модель данных для таблицы:
class TableModel : public QAbstractTableModel  // унаследовано от QAbstractTableModel
{
    Q_OBJECT //макрос,в котором планируется описать сигналы и/или слоты

public:    
    explicit TableModel(QObject *parent = nullptr, QString tableTitle = "");// Конструктор
    QJsonObject getDataAsJsonObject();// Получение данных в виде экземпляра класса QJsonObject
    void setDataFromJsonObject(QJsonObject jsonObj);//Установка данных из экземпляра класса QJsonObject
    void setItemList(QMap<QString, QList<Base>> itemList); //Установка данных из словаря типа QMap<QString, QList<Base>>

    // Переопределение методов табличной модели данных
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;//Количество строк
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;// Количество столбцов
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;// Данные
    // Элементы можно менять
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;
    // Флаги
    Qt::ItemFlags flags(const QModelIndex& index) const override;

private:
    QString tableTitle;// Заголовок таблицы
    QString selectedMonth;// Выбранный месяц
    QMap<QString, QList<Base>> itemList;// Данные
    double getTotalForMonth(QString monthName) const;// Метод для подсчёта итога за месяц
};

#endif // TABLEMODEL_H
