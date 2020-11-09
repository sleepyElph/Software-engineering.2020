#include "readingform.h"
#include "ui_readingform.h"

ReadingForm::ReadingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReadingForm)
{
    ui->setupUi(this);
    this->setFixedWidth(725);
    this->setFixedHeight(1020);
    manga= new MangaFiles;
    ui->label->setFixedWidth(625);
    ui->label->setFixedHeight(902);
    if(!manga->FirstPage().isNull()){
        ui->label->setPixmap(manga->FirstPage());
        ui->label->setScaledContents(true);
    }
    else{
         QMessageBox::warning(this,"Ошибка","Похоже что директория манги была удалена, вернитесь в меню и обновите список доступной манги");
    }
    ui->label_2->setText(QString::number(manga->GetPage()+1));
    ui->label_3->setText(QString::number(manga->GetTotalPages()));
    Json_processing n;
    QVector<QString> toui=n.NameProd();
    if(toui.size()>0) ui->label_6->setText(toui.at(0));
    if(toui.size()>1) ui->label_8->setText(toui.at(1));
}

ReadingForm::~ReadingForm()
{
    delete ui;
}

void ReadingForm::on_prevButton_clicked()
{
    if (manga->GetPage()>0){
        ui->label->setPixmap(manga->PrevPage());
        ui->label->setScaledContents(true);
        ui->label_2->setText(QString::number(manga->GetPage()+1));
    }
}

void ReadingForm::on_nextButton_clicked()
{
    if (manga->GetPage()<manga->GetTotalPages()-1){
        ui->label->setPixmap(manga->NextPage());
        ui->label->setScaledContents(true);
        ui->label_2->setText(QString::number(manga->GetPage()+1));
    }
}

void ReadingForm::on_ExitButton_clicked()
{
    this->close();
    emit MainWindow();
}
