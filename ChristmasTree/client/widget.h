#ifndef WIDGET_H
#define WIDGET_H

#include "decoration.h"
#include "form.h"
#include "mytablemodel.h"

#include <QWidget>
#include <QSortFilterProxyModel>
#include <QList>

QT_BEGIN_NAMESPACE

namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_toys_clicked();
    void on_garlands_clicked();
    void on_continue_2_clicked();
    void on_buy_clicked(const QModelIndex &index);
    void on_add_clicked();
    void on_remove_clicked();
    void on_exit_clicked();

signals:
    void show_cart(MyTableModel& myModel);

private:
    Ui::Widget *ui;
    Form* form;
    MyTableModel* myModel;
    QSortFilterProxyModel *proxy;
    void is_cartEmpty();
    int buttonType = 1;
};
#endif // WIDGET_H
