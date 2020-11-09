#ifndef DETAILSFORM_H
#define DETAILSFORM_H
#include <QWidget>
#include <QFileDialog>
#include "mainwindow.h"

namespace Ui {
class DetailsForm;
}

class DetailsForm : public QWidget
{
    Q_OBJECT

public:
    explicit DetailsForm(QWidget *parent = nullptr);
    ~DetailsForm();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::DetailsForm *ui;
};

#endif // DETAILSFORM_H
