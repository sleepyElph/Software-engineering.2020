#ifndef EXPENSE_H
#define EXPENSE_H
#include "base.h"

// Расход:
class Expense : public Base
{
public:    
    Expense(QString itemName, double amount);// Конструктор
};
#endif // EXPENSE_H
