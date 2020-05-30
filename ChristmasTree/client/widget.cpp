#include "ui_widget.h"
#include "widget.h"
#include "mytablemodel.h"

#include <QSortFilterProxyModel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint);

    form = new Form();

    connect(form, &Form::Widget, this, &Widget::show);
    connect(this,SIGNAL(show_cart(MyTableModel&)),form,SLOT(show_cart(MyTableModel&)));

    myModel = new MyTableModel(ui->buy);
    ui->buy->setModel(myModel);
    proxy = new QSortFilterProxyModel(this);
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxy->setSourceModel(myModel);
    proxy->setFilterKeyColumn(1);

    ui->buy->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->buy->verticalHeader()->hide();
    ui->buy->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->buy->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->buy->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->buy->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->continue_2->setEnabled(0);
}

Widget::~Widget() {
    delete ui;
}

void Widget::on_toys_clicked() {
    proxy->setFilterRegExp("^[а-яА-Я]+$");
    ui->buy->setModel(proxy);
}

void Widget::on_garlands_clicked() {
    proxy->setFilterRegExp("^[0-9]+");
    ui->buy->setModel(proxy);
}

void Widget::on_buy_clicked(const QModelIndex &index) {
    QModelIndexList select = ui->buy->selectionModel()->selectedRows();
    if (buttonType == 1) {
        myModel->add(ui->buy->model()->index(index.row(), 0, index.parent()).data().toString());
    } else myModel->remove(ui->buy->model()->index(index.row(), 0, index.parent()).data().toString());
    is_cartEmpty();
}

void Widget::on_continue_2_clicked() {
    emit show_cart(*myModel);
    form->show();
    this->close();
}

void Widget::is_cartEmpty() {
    ui->continue_2->setEnabled(myModel->cart_size());
}

void Widget::on_add_clicked() {
    buttonType = 1;
}

void Widget::on_remove_clicked() {
    buttonType = 0;
}

void Widget::on_exit_clicked() {
    close();
}
