#include "payment.h"
#include "ui_payment.h"
#include <QWidget>
#include <QMessageBox>

Payment::Payment(Order& order,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Payment),ord(order),store(Store::getInstance())
{
    connect(this, &Payment::paymentCompleted, this, &Payment::onPaymentCompleted);

    Store* store = Store::getInstance();

    ui->setupUi(this);
    hideAllPaymentFields();
    const auto& cart = ord.getCart();
    ui->cartList->clear();
    ui->cartList->setRowCount(0);
    ui->cartList->setColumnCount(4);
    ui->cartList->setHorizontalHeaderLabels(
        {"Name","Unit Price","Qty","Sub-total"});
    ui->cartList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < static_cast<int>(cart.size()); ++i) {
        const OrderItem& it = cart[i];
        ui->cartList->insertRow(i);

        QTableWidgetItem* nameItem = new QTableWidgetItem(QString::fromStdString(it.getName()));
        QTableWidgetItem* priceItem = new QTableWidgetItem(QString::number(it.getPrice(), 'f', 2));
        QTableWidgetItem* qtyItem = new QTableWidgetItem(QString::number(it.getQuantity()));
        QTableWidgetItem* subtotalItem = new QTableWidgetItem(QString::number(it.totalPrice(), 'f', 2));

        // Make them all non-editable
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
        priceItem->setFlags(priceItem->flags() & ~Qt::ItemIsEditable);
        qtyItem->setFlags(qtyItem->flags() & ~Qt::ItemIsEditable);
        subtotalItem->setFlags(subtotalItem->flags() & ~Qt::ItemIsEditable);

        ui->cartList->setItem(i, 0, nameItem);
        ui->cartList->setItem(i, 1, priceItem);
        ui->cartList->setItem(i, 2, qtyItem);
        ui->cartList->setItem(i, 3, subtotalItem);
    }


    QString oTotal = QString::number(ord.calculateTotalPrice(), 'f', 2); // 2-decimal formatting
    ui->orderTotal->setText(oTotal);

}

void Payment::hideAllPaymentFields()
{
    // Card fields
    ui->lcardnum->setVisible(false);
    ui->lexp->setVisible(false);
    ui->lcvv->setVisible(false);
    ui->cardnum->setVisible(false);
    ui->exp->setVisible(false);
    ui->cvv->setVisible(false);

    // EasyPaisa and JazzCash
    ui->accnum->setVisible(false);
    ui->laccnum->setVisible(false);
}

Payment::~Payment()
{
    delete ui;
}

void Payment::on_paymentType_currentIndexChanged(int index)
{
    hideAllPaymentFields();
    const int cash=0;
    const int card=1;
    const int eP=2;
    const int jC=3;

    if(index==card){
        ui->lcardnum->setVisible(true);
        ui->lexp->setVisible(true);
        ui->lcvv->setVisible(true);
        ui->cardnum->setVisible(true);
        ui->exp->setVisible(true);
        ui->cvv->setVisible(true);
    }else if (index==eP){
        ui->accnum->setVisible(true);
        ui->laccnum->setVisible(true);
    }else if (index==jC){
        ui->accnum->setVisible(true);
        ui->laccnum->setVisible(true);
    }
}


void Payment::on_placeOrder_clicked()
{

    int idx = ui->paymentType->currentIndex();
    PaymentMethod* payment = nullptr;
    QString err;
    bool ok=true;
    if(idx==0){
        payment=new CashPayment();
    }else if(idx==1){
        QString cardNo=ui->cardnum->text();
        QString exp=ui->exp->text();
        QString cvv=ui->cvv->text();
        if (cardNo.isEmpty() || exp.isEmpty() || cvv.isEmpty()) {
            ok  = false;
            err = "Please fill in card number, expiry and CVV.";
        } else {
            payment=new CardPayment(cardNo.toStdString(), exp.toStdString(), cvv.toStdString(),ord.calculateTotalPrice());
        }
    }else if (idx==2){

        QString acc=ui->accnum->text();
        payment=new EasyPaisaPayment(acc.toStdString());
    }else if (idx==3){
        QString acc=ui->accnum->text();
        payment=new JazzCashPayment(acc.toStdString());
    }

    if (!ok) {
        QMessageBox::warning(this, "Invalid data", err);
        return;
    }
    ord.setPaymentMethod(payment);
    store->addOrder(ord);
    QMessageBox::information(this, "Success", "Payment recorded, order placed.");

    emit deleteOrder();
    emit paymentCompleted();
}

void Payment::onPaymentCompleted() {
    delete this;
}
