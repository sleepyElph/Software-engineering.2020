#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPixmap>
#include <QFileDialog>
#include <QDir>
#include <QLayout>
#include <QStyle>
#include <QGridLayout>
#include <QtWidgets>
#include "detailsform.h"
#include "mangafiles.h"
#include "readingform.h"
#include "dialogadddir.h"

class DetailsForm;
class MangaFiles;
class ReadingForm;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_nextPage_clicked();
    void on_prevPage_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_clicked();
    void on_RefreshButton_clicked();
    void on_Details_clicked();
private:
    Ui::MainWindow *ui;
    ReadingForm *readform;
    DialogAddDir *dialadd;
    DetailsForm *detail;
    MangaFiles *manga;
    int required_space;
    void LoadPage(const QString folderPath, int start, int required_space);
    void TryOpenManga();
    void RefreshCheck();
    int currentPage=-1;
    QFileInfoList filelistinfo;
    QFileInfoList dirlistinfo;
    int start=0;
    int numberOfTitles=0;
};


struct DataTransfer{
    static QString folderPath;
    static QString first_title_list_path;
    static QString second_title_list_path;
    static QString third_title_list_path;
    static QString forth_title_list_path;
    static int reading_state;
};
#endif // MAINWINDOW_H
