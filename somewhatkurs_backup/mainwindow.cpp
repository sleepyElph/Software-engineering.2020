#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "main.cpp"

QString DataTransfer::first_title_list_path="0";
QString DataTransfer::second_title_list_path="0";
QString DataTransfer::third_title_list_path="0";
QString DataTransfer::forth_title_list_path="0";
QString DataTransfer::folderPath="D:/qt 4 sem/build-somewhatkurs-Desktop_Qt_5_12_5_MinGW_32_bit-Debug/mangabig";
int DataTransfer::reading_state=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedWidth(760);
    this->setFixedHeight(1020);
    ui->label_2->clear();
    ui->label_3->clear();
    ui->label_4->clear();
    ui->label_5->clear();
    ui->pushButton_2->setText("");
    ui->pushButton_3->setText("");
    ui->pushButton_4->setText("");
    ui->pushButton_5->setText("");
    Json_processing n;
    n.Inicialization();
    RefreshCheck();
    manga= new MangaFiles;
    ui->label_2->setFixedWidth(284);
    ui->label_2->setFixedHeight(410);
    ui->label_3->setFixedWidth(284);
    ui->label_3->setFixedHeight(410);
    ui->label_4->setFixedWidth(284);
    ui->label_4->setFixedHeight(410);
    ui->label_5->setFixedWidth(284);
    ui->label_5->setFixedHeight(410);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadPage(const QString folderPath, int start, int required_space){
    QDir dir(folderPath);
    numberOfTitles=dir.entryInfoList(QDir::AllDirs | QDir::NoDotAndDotDot).count();
    ui->label_2->clear();
    ui->label_3->clear();
    ui->label_4->clear();
    ui->label_5->clear();
    ui->pushButton_2->setText("");
    ui->pushButton_3->setText("");
    ui->pushButton_4->setText("");
    ui->pushButton_5->setText("");
    std::tuple<QVector<QPixmap>,QVector<QString>> ref (manga->TestVar(folderPath,start,required_space));
    std::get<0>(ref);
    QVector<QPixmap> p0 = std::get<0>(ref);
    QVector<QString> str0 = std::get<1>(ref);
    if(str0.size()>0) ui->pushButton_2->setText(str0.at(0));
    if(str0.size()>1) ui->pushButton_3->setText(str0.at(1));
    if(str0.size()>2) ui->pushButton_4->setText(str0.at(2));
    if(str0.size()>3) ui->pushButton_5->setText(str0.at(3));
    if(p0.size()>0) ui->label_2->setPixmap(p0.at(0));
    ui->label_2->setScaledContents(true);
    if(p0.size()>1) ui->label_3->setPixmap(p0.at(1));
    ui->label_3->setScaledContents(true);
    if(p0.size()>2) ui->label_4->setPixmap(p0.at(2));
    ui->label_4->setScaledContents(true);
    if(p0.size()>3) ui->label_5->setPixmap(p0.at(3));
    ui->label_5->setScaledContents(true);
}

void MainWindow::on_nextPage_clicked()
{
    if(numberOfTitles!=0){
        if ((start+8)<=numberOfTitles){         //загрузка в ячейки меню по количеству остатка из 4ех на странице
            start+=4;
            required_space=4;
            LoadPage(DataTransfer::folderPath,start,4);
        }
        else{
            if ((start+7)<=numberOfTitles){
                start+=4;
                required_space=3;
                LoadPage(DataTransfer::folderPath,start,3);
            }
            else{
                if ((start+6)<=numberOfTitles){
                    start+=4;
                    required_space=2;
                    LoadPage(DataTransfer::folderPath,start,2);
                }
                else{
                    if ((start+5)<=numberOfTitles){
                        required_space=1;
                        start+=4;
                        LoadPage(DataTransfer::folderPath,start,1);
                    }
                }
            }
        }
    }
}

void MainWindow::on_prevPage_clicked()
{
    if( numberOfTitles!=0){
        if ((start-4)>=0){
            start-=4;
            LoadPage(DataTransfer::folderPath,start,4);
        }
        required_space=4;
    }
}

void MainWindow::TryOpenManga(){
    try {
        readform= new ReadingForm();
        connect(readform,&ReadingForm::MainWindow,this,&MainWindow::show);
        QRect screenGeometry = QApplication::desktop()->screenGeometry();
        int x = (screenGeometry.width()-readform->width()) / 2;
        int y = (screenGeometry.height()-readform->height()) / 2-30;
        readform->move(x, y);
        readform->show();
        this->close();
    } catch (int excep) {
        QMessageBox::warning(this,"Alarm","Чета мне нехорошо...");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(DataTransfer::first_title_list_path!="0"){
        DataTransfer::reading_state=1;
        TryOpenManga();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if (required_space>1&&DataTransfer::second_title_list_path!="0"){
        DataTransfer::reading_state=2;
        TryOpenManga();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if (required_space>2&&DataTransfer::third_title_list_path!="0"){
        DataTransfer::reading_state=3;
        TryOpenManga();
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if (required_space>3&&DataTransfer::forth_title_list_path!="0"){
        DataTransfer::reading_state=4;
        TryOpenManga();
    }
}

void MainWindow::on_pushButton_clicked()
{
    dialadd= new DialogAddDir();
    dialadd->show();
}

void MainWindow::RefreshCheck(){
    QDir dir(DataTransfer::folderPath);
    int checkTitle=dir.entryInfoList(QDir::AllDirs | QDir::NoDotAndDotDot).count();
    if (checkTitle==1){
        LoadPage(DataTransfer::folderPath,0,1);
    }else{
        if(checkTitle==2){
            LoadPage(DataTransfer::folderPath,0,2);
        }else{
            if (checkTitle==3){
                LoadPage(DataTransfer::folderPath,0,3);
            }else{
                if(checkTitle>=4){
                    LoadPage(DataTransfer::folderPath,0,4);
                }
            }
        }
    }
}

void MainWindow::on_RefreshButton_clicked()
{
    RefreshCheck();
}

void MainWindow::on_Details_clicked()
{
    detail = new DetailsForm();
    detail->show();
}
