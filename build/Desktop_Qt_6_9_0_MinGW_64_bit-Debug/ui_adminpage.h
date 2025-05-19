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
    QLineEdit *pPrice;
    QPushButton *pushButton;
    QLineEdit *pName;
    QWidget *Orders;
    QTableWidget *orderList;
    QPushButton *logout;

    void setupUi(QWidget *adminPage)
    {
        if (adminPage->objectName().isEmpty())
            adminPage->setObjectName("adminPage");
        adminPage->resize(1178, 589);
        tabWidget = new QTabWidget(adminPage);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 60, 1131, 521));
        Products = new QWidget();
        Products->setObjectName("Products");
        productList = new QTableWidget(Products);
        productList->setObjectName("productList");
        productList->setGeometry(QRect(10, 10, 961, 461));
        pPrice = new QLineEdit(Products);
        pPrice->setObjectName("pPrice");
        pPrice->setGeometry(QRect(1000, 260, 113, 28));
        pushButton = new QPushButton(Products);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1012, 320, 91, 29));
        pName = new QLineEdit(Products);
        pName->setObjectName("pName");
        pName->setGeometry(QRect(1000, 220, 113, 28));
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

        retranslateUi(adminPage);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(adminPage);
    } // setupUi

    void retranslateUi(QWidget *adminPage)
    {
        adminPage->setWindowTitle(QCoreApplication::translate("adminPage", "Form", nullptr));
        pPrice->setText(QString());
        pPrice->setPlaceholderText(QCoreApplication::translate("adminPage", "Price", nullptr));
        pushButton->setText(QCoreApplication::translate("adminPage", "Add Product", nullptr));
        pName->setText(QString());
        pName->setPlaceholderText(QCoreApplication::translate("adminPage", "Name", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Products), QCoreApplication::translate("adminPage", "Products", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Orders), QCoreApplication::translate("adminPage", "Orders", nullptr));
        logout->setText(QCoreApplication::translate("adminPage", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminPage: public Ui_adminPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPAGE_H
