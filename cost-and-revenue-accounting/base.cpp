#include "base.h"

Base::Base(QString itemName, double amount)//Конструктор
{
    this->itemName = itemName;//Статья дохода или расхода
    this->amount = amount;//Сумма денег по этой статье
}


QString Base::getItemName() const//Получить название статьи расходов или доходов
{
    return itemName;
}

double Base::getAmount() const // Получить сумму
{
    return amount;
}

void Base::setAmount(double value)//Установить сумму
{
    amount = value;
}
