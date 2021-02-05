#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTableView>
#include <QHBoxLayout>
#include <QLabel>
#include "tablemodel.h"
#include "comboboxitemdelegate.h"
#include "formabout.h"

namespace Ui {
class MainWindow;// Предварительное объявление класса MainWindow в пространстве имён Ui
}

// Класс главного окна:
class MainWindow : public QMainWindow  // унаследован от класса QMainWindow
{
    Q_OBJECT //макрос,в котором планируется описать сигналы и/или слоты
public:
    explicit MainWindow(QWidget *parent = nullptr);// Конструктор
    ~MainWindow(); // Деструктор

private slots:
    void on_actionExit_triggered();//Выход
    void on_actionOpen_triggered();//Открытие файла
    void on_actionSave_triggered();//Сохранение файла
    void on_actionAbout_triggered(); //Обработчик события выбора пункта главного меню Справка

private:
    Ui::MainWindow *ui;
    FormAbout *formAbout;

    TableModel *tableModelCosts;//Модель данных для таблицы расходов
    ComboBoxItemDelegate *cbidCosts; //Выпадающий список для выбора названия месяца для таблицы расходов
    TableModel *tableModelIncome;//Модель данных для таблицы доходов
    ComboBoxItemDelegate *cbidIncome;//Выпадающий список для выбора названия месяца для таблицы доходов

    QString fileName; // Имя файла

    QHBoxLayout *statusBarLayout; // Статусная строка
    QWidget *statusBarContainer;

    QLabel *statusBarLabel;// Текстовая метка в статусной строке

    // Метод для настройки таблиц
    void setupTable(
        QTableView *tableView,  // виджет таблицы
        TableModel **tableModel,  // модель данных таблицы
        QString tableTitle,  // заголовок таблицы
        ComboBoxItemDelegate **cbid,  // объект для выбора месяца
        QMap<QString, QList<Base>> itemList  // данные для модели данных таблицы
    );
};

#endif // MAINWINDOW_H
