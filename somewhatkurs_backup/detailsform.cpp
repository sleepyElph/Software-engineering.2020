#include "detailsform.h"
#include "ui_detailsform.h"

DetailsForm::DetailsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetailsForm)
{
    ui->setupUi(this);
    ui->lineEdit->setText(DataTransfer::folderPath);
}

DetailsForm::~DetailsForm()
{
    delete ui;
}

void DetailsForm::on_pushButton_clicked()
{
    QString newpath = QFileDialog::getExistingDirectory(this, tr("Image folder"));
    ui->lineEdit->setText(newpath);
}

void DetailsForm::on_pushButton_2_clicked()
{
     DataTransfer::folderPath=ui->lineEdit->text();
     if(DataTransfer::folderPath.isEmpty()){
         DataTransfer::folderPath="D:/qt 4 sem/build-somewhatkurs-Desktop_Qt_5_12_5_MinGW_32_bit-Debug/mangabig";
     }
}
