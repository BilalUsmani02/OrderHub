/********************************************************************************
** Form generated from reading UI file 'orderinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERINFO_H
#define UI_ORDERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrderInfo
{
public:
    QLineEdit *orderId;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *status;
    QLabel *label_4;
    QLineEdit *address;
    QTableWidget *cartList;
    QLabel *label_3;
    QLineEdit *payMethod;

    void setupUi(QWidget *OrderInfo)
    {
        if (OrderInfo->objectName().isEmpty())
            OrderInfo->setObjectName("OrderInfo");
        OrderInfo->resize(1033, 540);
        orderId = new QLineEdit(OrderInfo);
        orderId->setObjectName("orderId");
        orderId->setGeometry(QRect(180, 30, 113, 28));
        label = new QLabel(OrderInfo);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 30, 63, 21));
        label_2 = new QLabel(OrderInfo);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 70, 63, 21));
        status = new QLineEdit(OrderInfo);
        status->setObjectName("status");
        status->setGeometry(QRect(180, 70, 113, 28));
        label_4 = new QLabel(OrderInfo);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 110, 63, 21));
        address = new QLineEdit(OrderInfo);
        address->setObjectName("address");
        address->setGeometry(QRect(180, 110, 113, 28));
        cartList = new QTableWidget(OrderInfo);
        cartList->setObjectName("cartList");
        cartList->setGeometry(QRect(60, 210, 891, 301));
        label_3 = new QLabel(OrderInfo);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 150, 121, 20));
        payMethod = new QLineEdit(OrderInfo);
        payMethod->setObjectName("payMethod");
        payMethod->setGeometry(QRect(180, 150, 113, 28));

        retranslateUi(OrderInfo);

        QMetaObject::connectSlotsByName(OrderInfo);
    } // setupUi

    void retranslateUi(QWidget *OrderInfo)
    {
        OrderInfo->setWindowTitle(QCoreApplication::translate("OrderInfo", "Form", nullptr));
        label->setText(QCoreApplication::translate("OrderInfo", "Order ID:", nullptr));
        label_2->setText(QCoreApplication::translate("OrderInfo", "Status:", nullptr));
        status->setText(QString());
        label_4->setText(QCoreApplication::translate("OrderInfo", "Address", nullptr));
        label_3->setText(QCoreApplication::translate("OrderInfo", "Payment Method: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OrderInfo: public Ui_OrderInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERINFO_H
