/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QLineEdit *iusername;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *ipassword;
    QPushButton *loginbutton;
    QLabel *errormsg;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(800, 600);
        centralwidget = new QWidget(login);
        centralwidget->setObjectName("centralwidget");
        iusername = new QLineEdit(centralwidget);
        iusername->setObjectName("iusername");
        iusername->setGeometry(QRect(370, 210, 113, 28));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 210, 81, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(230, 270, 81, 21));
        ipassword = new QLineEdit(centralwidget);
        ipassword->setObjectName("ipassword");
        ipassword->setGeometry(QRect(370, 270, 113, 28));
        loginbutton = new QPushButton(centralwidget);
        loginbutton->setObjectName("loginbutton");
        loginbutton->setGeometry(QRect(310, 350, 83, 29));
        errormsg = new QLabel(centralwidget);
        errormsg->setObjectName("errormsg");
        errormsg->setGeometry(QRect(210, 160, 311, 31));
        login->setCentralWidget(centralwidget);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "login", nullptr));
        label->setText(QCoreApplication::translate("login", "User Name", nullptr));
        label_2->setText(QCoreApplication::translate("login", "Password", nullptr));
        loginbutton->setText(QCoreApplication::translate("login", "login", nullptr));
        errormsg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
