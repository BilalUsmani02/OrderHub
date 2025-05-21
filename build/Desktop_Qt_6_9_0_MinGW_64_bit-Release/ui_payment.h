/********************************************************************************
** Form generated from reading UI file 'payment.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYMENT_H
#define UI_PAYMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Payment
{
public:
    QLabel *PaymentType;
    QComboBox *paymentType;
    QPushButton *placeOrder;
    QTableWidget *cartList;
    QLineEdit *orderTotal;
    QLabel *label;
    QLineEdit *cardnum;
    QLineEdit *cvv;
    QLineEdit *exp;
    QLabel *lcardnum;
    QLabel *lexp;
    QLabel *lcvv;
    QLineEdit *laccnum;
    QLabel *accnum;

    void setupUi(QWidget *Payment)
    {
        if (Payment->objectName().isEmpty())
            Payment->setObjectName("Payment");
        Payment->resize(1087, 587);
        PaymentType = new QLabel(Payment);
        PaymentType->setObjectName("PaymentType");
        PaymentType->setGeometry(QRect(610, 60, 151, 31));
        paymentType = new QComboBox(Payment);
        paymentType->addItem(QString());
        paymentType->addItem(QString());
        paymentType->addItem(QString());
        paymentType->addItem(QString());
        paymentType->setObjectName("paymentType");
        paymentType->setGeometry(QRect(790, 60, 181, 28));
        placeOrder = new QPushButton(Payment);
        placeOrder->setObjectName("placeOrder");
        placeOrder->setGeometry(QRect(850, 510, 101, 31));
        cartList = new QTableWidget(Payment);
        cartList->setObjectName("cartList");
        cartList->setGeometry(QRect(30, 60, 541, 451));
        orderTotal = new QLineEdit(Payment);
        orderTotal->setObjectName("orderTotal");
        orderTotal->setGeometry(QRect(450, 540, 113, 28));
        orderTotal->setReadOnly(true);
        label = new QLabel(Payment);
        label->setObjectName("label");
        label->setGeometry(QRect(380, 540, 63, 20));
        cardnum = new QLineEdit(Payment);
        cardnum->setObjectName("cardnum");
        cardnum->setGeometry(QRect(810, 170, 113, 28));
        cvv = new QLineEdit(Payment);
        cvv->setObjectName("cvv");
        cvv->setGeometry(QRect(810, 230, 113, 28));
        exp = new QLineEdit(Payment);
        exp->setObjectName("exp");
        exp->setGeometry(QRect(810, 310, 113, 28));
        lcardnum = new QLabel(Payment);
        lcardnum->setObjectName("lcardnum");
        lcardnum->setGeometry(QRect(660, 170, 131, 20));
        lexp = new QLabel(Payment);
        lexp->setObjectName("lexp");
        lexp->setGeometry(QRect(660, 310, 141, 20));
        lcvv = new QLabel(Payment);
        lcvv->setObjectName("lcvv");
        lcvv->setGeometry(QRect(660, 240, 141, 20));
        laccnum = new QLineEdit(Payment);
        laccnum->setObjectName("laccnum");
        laccnum->setGeometry(QRect(810, 190, 113, 28));
        accnum = new QLabel(Payment);
        accnum->setObjectName("accnum");
        accnum->setGeometry(QRect(660, 200, 131, 20));

        retranslateUi(Payment);

        QMetaObject::connectSlotsByName(Payment);
    } // setupUi

    void retranslateUi(QWidget *Payment)
    {
        Payment->setWindowTitle(QCoreApplication::translate("Payment", "Form", nullptr));
        PaymentType->setText(QCoreApplication::translate("Payment", "Select  Payment Type:", nullptr));
        paymentType->setItemText(0, QCoreApplication::translate("Payment", "Cash", nullptr));
        paymentType->setItemText(1, QCoreApplication::translate("Payment", "Card", nullptr));
        paymentType->setItemText(2, QCoreApplication::translate("Payment", "EasyPaisa", nullptr));
        paymentType->setItemText(3, QCoreApplication::translate("Payment", "JazzCash", nullptr));

        placeOrder->setText(QCoreApplication::translate("Payment", "Place Order", nullptr));
        orderTotal->setText(QCoreApplication::translate("Payment", "0", nullptr));
        label->setText(QCoreApplication::translate("Payment", "Total   =", nullptr));
        lcardnum->setText(QCoreApplication::translate("Payment", "Card Number", nullptr));
        lexp->setText(QCoreApplication::translate("Payment", "Expiry Date(MM/YY)", nullptr));
        lcvv->setText(QCoreApplication::translate("Payment", "CVV", nullptr));
        accnum->setText(QCoreApplication::translate("Payment", "Account Number", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Payment: public Ui_Payment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYMENT_H
