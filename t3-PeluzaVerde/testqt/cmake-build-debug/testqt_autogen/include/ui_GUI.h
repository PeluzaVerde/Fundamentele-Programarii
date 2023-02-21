/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI
{
public:
    QListWidget *ShoplistWidget;
    QLineEdit *lineEdit;
    QLineEdit *show_lineEdit;
    QPushButton *show_pushButton;
    QListWidget *cat_listWidget;

    void setupUi(QWidget *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName(QString::fromUtf8("GUI"));
        GUI->resize(781, 488);
        ShoplistWidget = new QListWidget(GUI);
        ShoplistWidget->setObjectName(QString::fromUtf8("ShoplistWidget"));
        ShoplistWidget->setGeometry(QRect(30, 30, 301, 251));
        lineEdit = new QLineEdit(GUI);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 360, 113, 28));
        show_lineEdit = new QLineEdit(GUI);
        show_lineEdit->setObjectName(QString::fromUtf8("show_lineEdit"));
        show_lineEdit->setGeometry(QRect(560, 340, 113, 28));
        show_pushButton = new QPushButton(GUI);
        show_pushButton->setObjectName(QString::fromUtf8("show_pushButton"));
        show_pushButton->setGeometry(QRect(580, 400, 83, 29));
        cat_listWidget = new QListWidget(GUI);
        cat_listWidget->setObjectName(QString::fromUtf8("cat_listWidget"));
        cat_listWidget->setGeometry(QRect(500, 60, 256, 192));

        retranslateUi(GUI);

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QWidget *GUI)
    {
        GUI->setWindowTitle(QCoreApplication::translate("GUI", "GUI", nullptr));
        show_pushButton->setText(QCoreApplication::translate("GUI", "Show Items", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
