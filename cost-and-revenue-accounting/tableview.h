#ifndef TABLEVIEW_H
#define TABLEVIEW_H
#include <QTableView>
#include <QMouseEvent>
// Класс таблицы:
class TableView : public QTableView  // унаследован от класса QTableView
{
public:   
    TableView(QWidget *parent = nullptr);// Конструктор
    void mousePressEvent(QMouseEvent *event); // Переопределение метода нажатия кнопки мыши
};

#endif // TABLEVIEW_H
