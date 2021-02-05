#ifndef DEFAULTDATA_H
#define DEFAULTDATA_H
#include <QObject>
#include <QList>
#include <QMap>
#include "expense.h"
#include "profit.h"

// Класс с данными по умолчанию:
class DefaultData
{
public:
    DefaultData();//Констуктор
    QList<Base> createDefaultCostsList();//Получить список расходов по умолчанию
    QMap<QString, QList<Base>> createDefaultCostsMap();//Получить словарь расходов по умолчанию
    QList<Base> createDefaultProfitsList();// Получить список доходов по умолчанию
    QMap<QString, QList<Base>> createDefaultProfitsMap();//Получить словарь доходов по умолчанию

private:
    QStringList monthsList; // Список месяцев
};

#endif // DEFAULTDATA_H
