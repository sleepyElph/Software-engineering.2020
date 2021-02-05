#include "mainwindow.h"
#include <QApplication>

// Точка входа в программу
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;// Главное окно приложения
    w.show();// Показать главное окно

    return a.exec();
}
