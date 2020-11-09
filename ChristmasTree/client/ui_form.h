/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *title;
    QPushButton *exit;
    QPushButton *buy_now;
    QLabel *label_5;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLineEdit *name;
    QLineEdit *telephone;
    QLineEdit *address;
    QDateTimeEdit *date;
    QPushButton *back;
    QTableView *buy;
    QLabel *total;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(998, 612);
        Form->setMinimumSize(QSize(998, 612));
        Form->setMaximumSize(QSize(998, 612));
        Form->setStyleSheet(QString::fromUtf8("background-color: white;"));
        title = new QLabel(Form);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(0, 0, 1001, 81));
        title->setStyleSheet(QString::fromUtf8("background-color: #408da9;\n"
"vertical-align: middle;\n"
"qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"color: white; \n"
"font: 22pt \"Ocean Sans Std Bold SemiExt\";\n"
"padding: 10px;"));
        exit = new QPushButton(Form);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(980, 0, 21, 21));
        exit->setStyleSheet(QString::fromUtf8("background-color: #434f42; \n"
"background: transparent;\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/exit.svg"), QSize(), QIcon::Normal, QIcon::Off);
        exit->setIcon(icon);
        exit->setIconSize(QSize(26, 26));
        buy_now = new QPushButton(Form);
        buy_now->setObjectName(QString::fromUtf8("buy_now"));
        buy_now->setGeometry(QRect(0, 540, 1001, 81));
        buy_now->setStyleSheet(QString::fromUtf8("QPushButton { \n"
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
"\n"
"QPushButton:disabled{ \n"
"background: gray; \n"
"}\n"
""));
        label_5 = new QLabel(Form);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 380, 1001, 31));
        label_5->setStyleSheet(QString::fromUtf8("color:white; \n"
"font: 12pt \"DejaVu Serif\";\n"
"qproperty-alignment: 'AlignVCenter | AlignCenter';\n"
"background-color: #408da9;\n"
"border: none; "));
        layoutWidget = new QWidget(Form);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 420, 971, 121));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        name = new QLineEdit(layoutWidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setStyleSheet(QString::fromUtf8("font: 12pt \"DejaVu Serif\";\n"
"color: #408da9;\n"
"border: 1px solid #408da9; "));
        name->setMaxLength(15);

        formLayout->setWidget(0, QFormLayout::SpanningRole, name);

        telephone = new QLineEdit(layoutWidget);
        telephone->setObjectName(QString::fromUtf8("telephone"));
        telephone->setStyleSheet(QString::fromUtf8("font: 12pt \"DejaVu Serif\";\n"
"color: #408da9;\n"
"border: 1px solid #408da9; "));
        telephone->setMaxLength(32767);

        formLayout->setWidget(1, QFormLayout::SpanningRole, telephone);

        address = new QLineEdit(layoutWidget);
        address->setObjectName(QString::fromUtf8("address"));
        address->setStyleSheet(QString::fromUtf8("font: 12pt \"DejaVu Serif\";\n"
"color: #408da9;\n"
"border: 1px solid #408da9; "));
        address->setMaxLength(50);

        formLayout->setWidget(2, QFormLayout::SpanningRole, address);

        date = new QDateTimeEdit(layoutWidget);
        date->setObjectName(QString::fromUtf8("date"));
        date->setStyleSheet(QString::fromUtf8("font: 12pt \"DejaVu Serif\";\n"
"color: #408da9;\n"
"border: 1px solid #408da9; "));
        date->setAccelerated(false);
        date->setKeyboardTracking(true);
        date->setProperty("showGroupSeparator", QVariant(false));
        date->setDate(QDate(2020, 5, 1));
        date->setTime(QTime(2, 0, 0));
        date->setMaximumDateTime(QDateTime(QDate(9999, 12, 31), QTime(23, 59, 59)));
        date->setMinimumDateTime(QDateTime(QDate(2020, 4, 8), QTime(0, 0, 0)));
        date->setMinimumDate(QDate(2020, 4, 8));
        date->setCurrentSection(QDateTimeEdit::NoSection);
        date->setCalendarPopup(false);
        date->setTimeSpec(Qt::LocalTime);

        formLayout->setWidget(3, QFormLayout::SpanningRole, date);

        back = new QPushButton(Form);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(0, 0, 41, 31));
        back->setStyleSheet(QString::fromUtf8("background-color: #434f42; \n"
"background: transparent;\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/back.svg"), QSize(), QIcon::Normal, QIcon::Off);
        back->setIcon(icon1);
        back->setIconSize(QSize(30, 30));
        buy = new QTableView(Form);
        buy->setObjectName(QString::fromUtf8("buy"));
        buy->setGeometry(QRect(0, 80, 1001, 251));
        buy->setStyleSheet(QString::fromUtf8("QHeaderView::section:horizontal {\n"
"color: white; \n"
"border: none; \n"
"font: 12pt;\n"
"background-color: #9bcfe4;\n"
"}\n"
"\n"
"QTableView {\n"
"background-color: white;\n"
"font: 12pt \"DejaVu Serif\";\n"
"color: #408da9;\n"
" }"));
        buy->setAutoScroll(true);
        buy->setEditTriggers(QAbstractItemView::NoEditTriggers);
        total = new QLabel(Form);
        total->setObjectName(QString::fromUtf8("total"));
        total->setGeometry(QRect(10, 340, 321, 31));
        total->setStyleSheet(QString::fromUtf8("color: #408da9;\n"
"font: 14pt \"DejaVu Serif\";\n"
"text-align: left;"));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        title->setText(QApplication::translate("Form", "ChristmasTree", nullptr));
        exit->setText(QString());
        buy_now->setText(QApplication::translate("Form", "BUY NOW", nullptr));
        label_5->setText(QApplication::translate("Form", "\320\237\320\276\320\266\320\260\320\273\321\203\320\271\321\201\321\202\320\260, \320\267\320\260\320\277\320\276\320\273\320\275\320\270\321\202\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        name->setPlaceholderText(QApplication::translate("Form", "\320\230\320\274\321\217", nullptr));
        telephone->setInputMask(QString());
        telephone->setText(QString());
        telephone->setPlaceholderText(QApplication::translate("Form", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260", nullptr));
        address->setPlaceholderText(QApplication::translate("Form", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        date->setDisplayFormat(QApplication::translate("Form", "\320\264\320\265\320\275\321\214: dd   \320\274\320\265\321\201\321\217\321\206: MM    \320\262\321\200\320\265\320\274\321\217: HH:mm", nullptr));
        back->setText(QString());
        total->setText(QApplication::translate("Form", "\320\230\321\202\320\276\320\263:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
