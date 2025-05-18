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
    QLineEdit *rusername;
    QLineEdit *rpassword;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *registerBtn;
    QPushButton *LP;
    QPushButton *RP;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(1044, 600);
        centralwidget = new QWidget(login);
        centralwidget->setObjectName("centralwidget");
        iusername = new QLineEdit(centralwidget);
        iusername->setObjectName("iusername");
        iusername->setGeometry(QRect(718, 211, 113, 28));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(578, 211, 81, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(578, 271, 81, 21));
        ipassword = new QLineEdit(centralwidget);
        ipassword->setObjectName("ipassword");
        ipassword->setGeometry(QRect(718, 271, 113, 28));
        loginbutton = new QPushButton(centralwidget);
        loginbutton->setObjectName("loginbutton");
        loginbutton->setGeometry(QRect(730, 350, 83, 29));
        errormsg = new QLabel(centralwidget);
        errormsg->setObjectName("errormsg");
        errormsg->setGeometry(QRect(558, 161, 311, 31));
        rusername = new QLineEdit(centralwidget);
        rusername->setObjectName("rusername");
        rusername->setGeometry(QRect(720, 210, 113, 28));
        rpassword = new QLineEdit(centralwidget);
        rpassword->setObjectName("rpassword");
        rpassword->setGeometry(QRect(720, 270, 113, 28));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(580, 210, 71, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(740, 140, 111, 41));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(740, 150, 81, 31));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(580, 270, 63, 20));
        registerBtn = new QPushButton(centralwidget);
        registerBtn->setObjectName("registerBtn");
        registerBtn->setGeometry(QRect(730, 350, 83, 29));
        LP = new QPushButton(centralwidget);
        LP->setObjectName("LP");
        LP->setGeometry(QRect(130, 150, 83, 29));
        RP = new QPushButton(centralwidget);
        RP->setObjectName("RP");
        RP->setGeometry(QRect(130, 270, 121, 29));
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
        label_3->setText(QCoreApplication::translate("login", "UserName", nullptr));
        label_4->setText(QCoreApplication::translate("login", "LOGIN", nullptr));
        label_5->setText(QCoreApplication::translate("login", "REGISTER", nullptr));
        label_6->setText(QCoreApplication::translate("login", "Password", nullptr));
        registerBtn->setText(QCoreApplication::translate("login", "Register", nullptr));
        LP->setText(QCoreApplication::translate("login", "Login Page", nullptr));
        RP->setText(QCoreApplication::translate("login", "Register Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
