#ifndef FORMABOUT_H
#define FORMABOUT_H
#include <QWidget>
namespace Ui {
class FormAbout;//Предварительное объявление класса FormAbout
}

class FormAbout : public QWidget//Класс FormAbout нужен для окна
{
    Q_OBJECT //макрос,в котором планируется описать сигналы и/или слоты
public:
    explicit FormAbout(QWidget *parent = nullptr);// Конструктор
    ~FormAbout();// Деструктор

private slots:
    void on_pushButtonClose_clicked();// Обработчик нажатия на кнопку закрыть

private:
    Ui::FormAbout *ui;
};
#endif // FORMABOUT_H
