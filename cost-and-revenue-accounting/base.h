#ifndef BASE_H
#define BASE_H
#include <QString>
// Базовый класс для классов дохода и расхода
class Base
{

public:
    Base(QString itemName, double amount);//Конструктор
    QString getItemName() const; //Получить название статьи расходов или доходов
    double getAmount() const; //Получить сумму
    void setAmount(double value);//Установить сумму

private:

    QString itemName;//Статья дохода или расхода
    double amount; //Сумма денег по этой статье
};
#endif // BASE_H
