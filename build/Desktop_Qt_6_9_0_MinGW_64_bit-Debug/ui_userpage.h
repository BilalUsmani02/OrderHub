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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
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
    QWidget *Cart;
    QTableWidget *cartList;
    QLabel *label;
    QLineEdit *orderTotal;
    QPushButton *placeOrder;

    void setupUi(QWidget *userPage)
    {
        if (userPage->objectName().isEmpty())
            userPage->setObjectName("userPage");
        userPage->resize(1163, 598);
        tabWidget = new QTabWidget(userPage);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 60, 1141, 521));
        tabWidget->setTabPosition(QTabWidget::TabPosition::North);
        tabWidget->setTabShape(QTabWidget::TabShape::Rounded);
        Products = new QWidget();
        Products->setObjectName("Products");
        productList = new QTableWidget(Products);
        productList->setObjectName("productList");
        productList->setGeometry(QRect(10, 10, 1121, 461));
        tabWidget->addTab(Products, QString());
        Orders = new QWidget();
        Orders->setObjectName("Orders");
        tabWidget->addTab(Orders, QString());
        Cart = new QWidget();
        Cart->setObjectName("Cart");
        cartList = new QTableWidget(Cart);
        cartList->setObjectName("cartList");
        cartList->setGeometry(QRect(20, 20, 1101, 411));
        label = new QLabel(Cart);
        label->setObjectName("label");
        label->setGeometry(QRect(660, 450, 63, 20));
        orderTotal = new QLineEdit(Cart);
        orderTotal->setObjectName("orderTotal");
        orderTotal->setGeometry(QRect(730, 450, 113, 28));
        orderTotal->setReadOnly(true);
        placeOrder = new QPushButton(Cart);
        placeOrder->setObjectName("placeOrder");
        placeOrder->setGeometry(QRect(1020, 440, 91, 29));
        tabWidget->addTab(Cart, QString());

        retranslateUi(userPage);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(userPage);
    } // setupUi

    void retranslateUi(QWidget *userPage)
    {
        userPage->setWindowTitle(QCoreApplication::translate("userPage", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Products), QCoreApplication::translate("userPage", "Products", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Orders), QCoreApplication::translate("userPage", "Orders", nullptr));
        label->setText(QCoreApplication::translate("userPage", "Total   =", nullptr));
        orderTotal->setText(QCoreApplication::translate("userPage", "0", nullptr));
        placeOrder->setText(QCoreApplication::translate("userPage", "Place Order", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Cart), QCoreApplication::translate("userPage", "Cart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userPage: public Ui_userPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPAGE_H
