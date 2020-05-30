#include "dialogadddir.h"
#include "ui_dialogadddir.h"
#include "mainwindow.h"

DialogAddDir::DialogAddDir(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogAddDir)
{
    ui->setupUi(this);
}

DialogAddDir::~DialogAddDir()
{
    delete ui;
}

void DialogAddDir::on_pushButton_clicked()
{
    copyFromPath = QFileDialog::getExistingDirectory(this, tr("Image folder"));
    ui->lineEdit->setText(copyFromPath);
    copyFromPath=ui->lineEdit->text();
}

void DialogAddDir::on_pushButton_2_clicked()
{
    Json_processing w;
    w.AddNewManga(copyFromPath,ui->author_edit->text(),ui->prod_edit->text());
    this->destroy();
}

