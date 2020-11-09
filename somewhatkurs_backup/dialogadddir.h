#ifndef DIALOGADDDIR_H
#define DIALOGADDDIR_H
#include <QWidget>
#include <QPixmap>
#include <QFileDialog>
#include <QDir>

namespace Ui {
class DialogAddDir;
}

class DialogAddDir : public QWidget
{
    Q_OBJECT

public:
    explicit DialogAddDir(QWidget *parent = nullptr);
    ~DialogAddDir();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::DialogAddDir *ui;
    QString copyFromPath;
};

#endif // DIALOGADDDIR_H
