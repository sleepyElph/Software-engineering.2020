#ifndef FORM_H
#define FORM_H

#include "buy.h"
#include "mytablemodel.h"

#include <QSortFilterProxyModel>
#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget {
    Q_OBJECT
public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

signals:
    void Widget();

private slots:
    void show_cart(MyTableModel &myModel);
    void on_buy_now_clicked();
    void on_back_clicked();
    void onTextChanged(const QString &arg1);
    void on_exit_clicked();

private:
    Ui::Form *ui;
    MyTableModel *myModel1;
    QSortFilterProxyModel *proxy;
};

#endif // FORM_H
