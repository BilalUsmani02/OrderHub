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
#include <QtWidgets/QCheckBox>
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
    QLabel *label_4;
    QLabel *label;
    QLineEdit *iusername;
    QLabel *label_2;
    QLineEdit *ipassword;
    QPushButton *loginbutton;
    QLabel *errormsg;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *rusername;
    QLabel *label_6;
    QLineEdit *rpassword;
    QPushButton *registerBtn;
    QPushButton *LP;
    QPushButton *RP;
    QLabel *label_7;
    QCheckBox *loginShowPassword;
    QCheckBox *registerShowPassword;
    QLabel *errormsg2;
    QPushButton *pushButton;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(1127, 538);
        centralwidget = new QWidget(login);
        centralwidget->setObjectName("centralwidget");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(400, 160, 121, 41));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(280, 220, 100, 21));
        iusername = new QLineEdit(centralwidget);
        iusername->setObjectName("iusername");
        iusername->setGeometry(QRect(400, 220, 200, 28));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(280, 270, 100, 21));
        ipassword = new QLineEdit(centralwidget);
        ipassword->setObjectName("ipassword");
        ipassword->setGeometry(QRect(400, 270, 200, 28));
        ipassword->setEchoMode(QLineEdit::EchoMode::Password);
        loginbutton = new QPushButton(centralwidget);
        loginbutton->setObjectName("loginbutton");
        loginbutton->setGeometry(QRect(400, 370, 100, 30));
        errormsg = new QLabel(centralwidget);
        errormsg->setObjectName("errormsg");
        errormsg->setGeometry(QRect(280, 180, 400, 30));
        errormsg->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(400, 170, 121, 31));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(280, 220, 100, 20));
        rusername = new QLineEdit(centralwidget);
        rusername->setObjectName("rusername");
        rusername->setGeometry(QRect(400, 220, 200, 28));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(280, 270, 100, 20));
        rpassword = new QLineEdit(centralwidget);
        rpassword->setObjectName("rpassword");
        rpassword->setGeometry(QRect(400, 270, 200, 28));
        rpassword->setEchoMode(QLineEdit::EchoMode::Password);
        registerBtn = new QPushButton(centralwidget);
        registerBtn->setObjectName("registerBtn");
        registerBtn->setGeometry(QRect(400, 370, 100, 30));
        LP = new QPushButton(centralwidget);
        LP->setObjectName("LP");
        LP->setGeometry(QRect(30, 20, 100, 30));
        RP = new QPushButton(centralwidget);
        RP->setObjectName("RP");
        RP->setGeometry(QRect(30, 60, 100, 30));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(400, 20, 281, 121));
        label_7->setPixmap(QPixmap(QString::fromUtf8("order-hub-high-resolution-logo.png")));
        label_7->setScaledContents(true);
        loginShowPassword = new QCheckBox(centralwidget);
        loginShowPassword->setObjectName("loginShowPassword");
        loginShowPassword->setGeometry(QRect(620, 270, 93, 26));
        registerShowPassword = new QCheckBox(centralwidget);
        registerShowPassword->setObjectName("registerShowPassword");
        registerShowPassword->setGeometry(QRect(620, 270, 93, 26));
        errormsg2 = new QLabel(centralwidget);
        errormsg2->setObjectName("errormsg2");
        errormsg2->setGeometry(QRect(400, 300, 351, 61));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(970, 30, 83, 29));
        login->setCentralWidget(centralwidget);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Login", nullptr));
        label_4->setText(QCoreApplication::translate("login", "LOGIN", nullptr));
        label->setText(QCoreApplication::translate("login", "User Name", nullptr));
        label_2->setText(QCoreApplication::translate("login", "Password", nullptr));
        loginbutton->setText(QCoreApplication::translate("login", "Login", nullptr));
        errormsg->setText(QString());
        label_5->setText(QCoreApplication::translate("login", "REGISTER", nullptr));
        label_3->setText(QCoreApplication::translate("login", "User Name", nullptr));
        label_6->setText(QCoreApplication::translate("login", "Password", nullptr));
        registerBtn->setText(QCoreApplication::translate("login", "Register", nullptr));
        LP->setText(QCoreApplication::translate("login", "Login Page", nullptr));
        RP->setText(QCoreApplication::translate("login", "Register Page", nullptr));
        label_7->setText(QString());
        loginShowPassword->setText(QCoreApplication::translate("login", "Show", nullptr));
        registerShowPassword->setText(QCoreApplication::translate("login", "Show", nullptr));
        errormsg2->setText(QString());
        pushButton->setText(QCoreApplication::translate("login", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
