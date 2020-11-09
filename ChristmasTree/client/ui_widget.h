/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *title;
    QPushButton *continue_2;
    QTableView *buy;
    QPushButton *exit;
    QPushButton *toys;
    QPushButton *garlands;
    QPushButton *remove;
    QPushButton *add;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(998, 612);
        Widget->setMinimumSize(QSize(998, 612));
        Widget->setMaximumSize(QSize(998, 612));
        Widget->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));
        title = new QLabel(Widget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(0, 0, 1001, 81));
        title->setStyleSheet(QString::fromUtf8("background-color: #408da9;\n"
"vertical-align: middle;\n"
"qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"color: white; \n"
"font: 22pt \"Ocean Sans Std Bold SemiExt\";\n"
"padding: 10px;"));
        continue_2 = new QPushButton(Widget);
        continue_2->setObjectName(QString::fromUtf8("continue_2"));
        continue_2->setGeometry(QRect(0, 550, 1001, 71));
        continue_2->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"color:white; \n"
"background-color:#9bcfe4;  \n"
"border: none; \n"
"font: 20pt \"Ocean Sans Std Bold SemiExt\";\n"
"} \n"
"QPushButton:checked { \n"
"background-color:#408da9;\n"
"border: none; \n"
"}\n"
"QPushButton:hover{ \n"
"background-color: #408da9; \n"
"border-style: \n"
"outset; \n"
"}\n"
"QPushButton:disabled{ \n"
"background: gray; \n"
"}"));
        buy = new QTableView(Widget);
        buy->setObjectName(QString::fromUtf8("buy"));
        buy->setGeometry(QRect(260, 90, 731, 451));
        buy->setStyleSheet(QString::fromUtf8("QHeaderView::section:horizontal {\n"
"color: white; \n"
"border: none; \n"
"font: 12pt;\n"
"background-color: #9bcfe4;\n"
"\n"
"}\n"
"QTableView::item:selected:active {\n"
"background: #9bcfe4;\n"
"border: 1px solid transparent;\n"
"color: white;\n"
"}\n"
"\n"
"QTableView {\n"
"background-color: white;\n"
"font: 12pt \"DejaVu Serif\";\n"
"color: #408da9;\n"
" }"));
        buy->setAutoScroll(true);
        buy->setEditTriggers(QAbstractItemView::NoEditTriggers);
        exit = new QPushButton(Widget);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(980, 0, 21, 21));
        exit->setStyleSheet(QString::fromUtf8("background-color: #434f42; \n"
"background: transparent;\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/exit.svg"), QSize(), QIcon::Normal, QIcon::Off);
        exit->setIcon(icon);
        exit->setIconSize(QSize(26, 26));
        toys = new QPushButton(Widget);
        toys->setObjectName(QString::fromUtf8("toys"));
        toys->setGeometry(QRect(0, 90, 251, 41));
        toys->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"color:white; \n"
"background-color:#9bcfe4;  \n"
"border: none; \n"
"font: 12pt \"Ocean Sans Std Bold SemiExt\";\n"
"} \n"
"QPushButton:checked { \n"
"background-color:#408da9;\n"
"border: none; \n"
"}\n"
"QPushButton:hover{ \n"
"background-color: #408da9; \n"
"border-style: \n"
"outset; \n"
"}"));
        toys->setCheckable(false);
        garlands = new QPushButton(Widget);
        garlands->setObjectName(QString::fromUtf8("garlands"));
        garlands->setGeometry(QRect(0, 140, 251, 41));
        garlands->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"color:white; \n"
"background-color:#9bcfe4;  \n"
"border: none; \n"
"font: 12pt \"Ocean Sans Std Bold SemiExt\";\n"
"} \n"
"QPushButton:checked { \n"
"background-color:#408da9;\n"
"border: none; \n"
"}\n"
"QPushButton:hover{ \n"
"background-color: #408da9; \n"
"border-style: \n"
"outset; \n"
"}"));
        garlands->setCheckable(false);
        garlands->setChecked(false);
        garlands->setAutoRepeat(false);
        remove = new QPushButton(Widget);
        remove->setObjectName(QString::fromUtf8("remove"));
        remove->setGeometry(QRect(0, 280, 251, 41));
        remove->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"color:white; \n"
"background-color:#9bcfe4;  \n"
"border: none; \n"
"font: 12pt \"Ocean Sans Std Bold SemiExt\";\n"
"} \n"
"QPushButton:checked { \n"
"background-color:#408da9;\n"
"border: none; \n"
"}\n"
"QPushButton:hover{ \n"
"background-color: #408da9; \n"
"border-style: \n"
"outset; \n"
"}"));
        add = new QPushButton(Widget);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(0, 230, 251, 41));
        add->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"color:white; \n"
"background-color:#9bcfe4;  \n"
"border: none; \n"
"font: 12pt \"Ocean Sans Std Bold SemiExt\";\n"
"} \n"
"QPushButton:checked { \n"
"background-color:#408da9;\n"
"border: none; \n"
"}\n"
"QPushButton:hover{ \n"
"background-color: #408da9; \n"
"border-style: \n"
"outset; \n"
"}"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        title->setText(QApplication::translate("Widget", "ChristmasTree", nullptr));
        continue_2->setText(QApplication::translate("Widget", "CONTINUE", nullptr));
        exit->setText(QString());
        toys->setText(QApplication::translate("Widget", "Toys", nullptr));
        garlands->setText(QApplication::translate("Widget", "Garlands", nullptr));
        remove->setText(QApplication::translate("Widget", "Remove", nullptr));
        add->setText(QApplication::translate("Widget", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
