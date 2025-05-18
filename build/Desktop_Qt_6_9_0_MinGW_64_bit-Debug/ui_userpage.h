/********************************************************************************
** Form generated from reading UI file 'userpage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERPAGE_H
#define UI_USERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userPage
{
public:
    QTabWidget *tabWidget;
    QWidget *Products;
    QTableWidget *productList;
    QWidget *Orders;

    void setupUi(QWidget *userPage)
    {
        if (userPage->objectName().isEmpty())
            userPage->setObjectName("userPage");
        userPage->resize(1163, 598);
        tabWidget = new QTabWidget(userPage);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 60, 1141, 521));
        Products = new QWidget();
        Products->setObjectName("Products");
        productList = new QTableWidget(Products);
        productList->setObjectName("productList");
        productList->setGeometry(QRect(10, 10, 1121, 461));
        tabWidget->addTab(Products, QString());
        Orders = new QWidget();
        Orders->setObjectName("Orders");
        tabWidget->addTab(Orders, QString());

        retranslateUi(userPage);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(userPage);
    } // setupUi

    void retranslateUi(QWidget *userPage)
    {
        userPage->setWindowTitle(QCoreApplication::translate("userPage", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Products), QCoreApplication::translate("userPage", "Products", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Orders), QCoreApplication::translate("userPage", "Orders", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userPage: public Ui_userPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPAGE_H
