/********************************************************************************
** Form generated from reading UI file 'adminpage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPAGE_H
#define UI_ADMINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminPage
{
public:
    QTabWidget *tabWidget;
    QWidget *Products;
    QTableWidget *productList;
    QWidget *Orders;
    QTableWidget *orderList;
    QPushButton *logout;
    QPushButton *pushButton;
    QLineEdit *pName;
    QLineEdit *pPrice;

    void setupUi(QWidget *adminPage)
    {
        if (adminPage->objectName().isEmpty())
            adminPage->setObjectName("adminPage");
        adminPage->resize(1178, 589);
        tabWidget = new QTabWidget(adminPage);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 50, 981, 521));
        Products = new QWidget();
        Products->setObjectName("Products");
        productList = new QTableWidget(Products);
        productList->setObjectName("productList");
        productList->setGeometry(QRect(10, 10, 961, 461));
        tabWidget->addTab(Products, QString());
        Orders = new QWidget();
        Orders->setObjectName("Orders");
        orderList = new QTableWidget(Orders);
        orderList->setObjectName("orderList");
        orderList->setGeometry(QRect(10, 10, 1111, 461));
        tabWidget->addTab(Orders, QString());
        logout = new QPushButton(adminPage);
        logout->setObjectName("logout");
        logout->setGeometry(QRect(1060, 20, 83, 29));
        pushButton = new QPushButton(adminPage);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1042, 430, 91, 29));
        pName = new QLineEdit(adminPage);
        pName->setObjectName("pName");
        pName->setGeometry(QRect(1030, 330, 113, 28));
        pPrice = new QLineEdit(adminPage);
        pPrice->setObjectName("pPrice");
        pPrice->setGeometry(QRect(1030, 370, 113, 28));

        retranslateUi(adminPage);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(adminPage);
    } // setupUi

    void retranslateUi(QWidget *adminPage)
    {
        adminPage->setWindowTitle(QCoreApplication::translate("adminPage", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Products), QCoreApplication::translate("adminPage", "Products", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Orders), QCoreApplication::translate("adminPage", "Orders", nullptr));
        logout->setText(QCoreApplication::translate("adminPage", "Logout", nullptr));
        pushButton->setText(QCoreApplication::translate("adminPage", "Add Product", nullptr));
        pName->setText(QString());
        pName->setPlaceholderText(QCoreApplication::translate("adminPage", "Name", nullptr));
        pPrice->setText(QString());
        pPrice->setPlaceholderText(QCoreApplication::translate("adminPage", "Price", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminPage: public Ui_adminPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPAGE_H
