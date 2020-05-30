#ifndef READINGFORM_H
#define READINGFORM_H
#include <QStyle>
#include <QMessageBox>
#include <QWidget>
#include <QPixmap>
#include <QFileDialog>
#include "mangafiles.h"
#include "json_processing.h"
#include "mainwindow.h"

class MangaFiles;
namespace Ui {
class ReadingForm;
}

class ReadingForm : public QWidget
{
    Q_OBJECT

public:
    explicit ReadingForm(QWidget *parent = nullptr);
    ~ReadingForm();
signals:
    void MainWindow();
private slots:
    void on_prevButton_clicked();
    void on_nextButton_clicked();
    void on_ExitButton_clicked();
private:
    MangaFiles *manga;
    Ui::ReadingForm *ui;
};

#endif // READINGFORM_H
