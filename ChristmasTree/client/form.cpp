#include "ui_form.h"
#include "form.h"
#include "buy.h"
#include "mytablemodel.h"

#include <QSortFilterProxyModel>
#include <QMessageBox>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    connect(ui->name, &QLineEdit::textChanged, this, &Form::onTextChanged);
    connect(ui->telephone, &QLineEdit::textChanged, this, &Form::onTextChanged);
    connect(ui->address, &QLineEdit::textChanged, this, &Form::onTextChanged);

    QRegularExpression regExp("^\\+\\d{1}\\-[0-9]{3}\\-[0-9]{3}\\-[0-9]{2}\\-[0-9]{2}$");

    QValidator *validator = new QRegularExpressionValidator(regExp, this);
    ui->telephone->setValidator(validator);

    setWindowFlags(Qt::CustomizeWindowHint);

    ui->date->setMinimumDateTime(QDateTime::currentDateTime());
    ui->buy_now->setEnabled(0);
}

Form::~Form() {
    delete ui;
}

void Form::show_cart(MyTableModel& myModel) {
    ui->buy->setModel(&myModel);
    myModel1 = &myModel;

    ui->buy->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->buy->verticalHeader()->hide();
    ui->buy->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->buy->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->buy->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->buy->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->buy->setFocusPolicy(Qt::NoFocus);

    proxy = new QSortFilterProxyModel(this);
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxy->setSourceModel(&myModel);
    proxy->setFilterKeyColumn(4);
    proxy->setFilterRegExp("^[1-9]+");
    ui->buy->setModel(proxy);
    ui->total->setText("Итог: " + QString::number(myModel.cart_price()) + "руб");
}

void Form::on_buy_now_clicked() {
    QMap <QString, QString> dataPerson;
    dataPerson["name"] =  ui->name->text();
    dataPerson["telephone"] =  ui->telephone->text();
    dataPerson["address"] =  ui->address->text();
    dataPerson["date"] =  ui->date->text();
    QString keyPerson = "Person";
    myModel1->json_cart(dataPerson, keyPerson,
                        "../orders/" + ui->name->text() + " " + ui->telephone->text()  + ".json");

    QMessageBox msgBox;
    msgBox.setWindowTitle("Бам!");
    msgBox.setText("Заказ успешно оформлен!");
    msgBox.setStandardButtons(QMessageBox::Ok);
    int answer = msgBox.exec();
    if (answer)
        close();

}

void Form::on_back_clicked() {
    this->close();
    emit Widget();
}

void Form::onTextChanged(const QString &arg1) {
    Q_UNUSED(arg1);
    if(ui->name->text().isEmpty() || ui->address->text().isEmpty() || ui->telephone->text().isEmpty()){
        ui->buy_now->setEnabled(false);
    } else {
        ui->buy_now->setEnabled(true);
    }
}

void Form::on_exit_clicked() {
    close();
}
