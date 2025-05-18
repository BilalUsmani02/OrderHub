#include "userpage.h"
#include "ui_userpage.h"
#include "payment.h"
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QString>

userPage::userPage(User& user,QWidget *parent): QWidget(parent), ui(new Ui::userPage),currentUser(user.getId(),user.getName()){

    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);

    this->show();

    vector<Product>* prods = Store::getInstance()->allProducts();
    if (prods->empty()) {
        ui->productList->setColumnCount(1);
        ui->productList->insertRow(0);
        QTableWidgetItem* nameItem = new QTableWidgetItem("No Products");
        ui->productList->setItem(0, 0, nameItem);
    } else {
        ui->productList->setColumnCount(4);
        QStringList headers;
        headers << "Name" << "Price" << "Quantity" << " ";
        ui->productList->setHorizontalHeaderLabels(headers);
        ui->productList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


        for(int i=0;i<static_cast<int>(prods->size());i++){
            const Product& product=prods->at(i);
            ui->productList->insertRow(i);

            QTableWidgetItem* nameItem = new QTableWidgetItem(QString::fromStdString(product.getName()));
            nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
            ui->productList->setItem(i, 0, nameItem);

            QTableWidgetItem* priceItem = new QTableWidgetItem(QString::number(product.getPrice(), 'f', 2));
            priceItem->setFlags(priceItem->flags() & ~Qt::ItemIsEditable);
            ui->productList->setItem(i, 1, priceItem);

            QWidget* quantityWidget = new QWidget();
            QHBoxLayout* layout = new QHBoxLayout(quantityWidget);
            layout->setContentsMargins(0, 0, 0, 0);
            layout->setAlignment(Qt::AlignCenter);

            QPushButton* minusBtn = new QPushButton("-");
            QLabel* qtyLabel = new QLabel("1");
            QPushButton* plusBtn = new QPushButton("+");

            minusBtn->setFixedSize(30, 25);
            plusBtn->setFixedSize(30, 25);
            qtyLabel->setFixedWidth(25);
            qtyLabel->setAlignment(Qt::AlignCenter);

            layout->addWidget(minusBtn);
            layout->addWidget(qtyLabel);
            layout->addWidget(plusBtn);

            ui->productList->setCellWidget(i, 2, quantityWidget);

            // Column 3: Add to Cart Button
            QPushButton* addButton = new QPushButton("Add");
            ui->productList->setCellWidget(i, 3, addButton);

            // Track quantity per row using lambda capture
            connect(plusBtn, &QPushButton::clicked, this, [=]() {
                int qty = qtyLabel->text().toInt();
                qtyLabel->setText(QString::number(qty + 1));
            });

            connect(minusBtn, &QPushButton::clicked, this, [=]() {
                int qty = qtyLabel->text().toInt();
                if (qty > 1) qtyLabel->setText(QString::number(qty - 1));
            });

            connect(addButton, &QPushButton::clicked, this, [=]() {
                int quantity = qtyLabel->text().toInt();
                if (!order){
                    order=new Order(user.getId());
                }

                OrderItem item(product.getId(),product.getName(),product.getPrice(),quantity);
                order->addItem(item);

            });

            // Optional: Auto-resize columns
        }
    }
}

void userPage::populateCartTable(const Order& ord)
{
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


    QString oTotal = QString::number(order->calculateTotalPrice(), 'f', 2); // 2-decimal formatting
    ui->orderTotal->setText(oTotal);

}


userPage::~userPage()
{
    if (order) {
        delete order;
        order = nullptr;
    }
    delete ui;
}



void userPage::on_tabWidget_tabBarClicked(int index)
{
    ui->orderTotal->hide();
    ui->label->hide();
    ui->placeOrder->hide();

    const int productTabIndex =0;
    const int cartTabIndex = 2;

    if (index == cartTabIndex &&  order) {
        populateCartTable(*order);
        ui->orderTotal->show();
        ui->label->show();
        ui->placeOrder->show();
    }else{
        ui->orderTotal->hide();
        ui->label->hide();
        ui->placeOrder->hide();
    }

    if(index==1){
        vector<Order>* orders = Store::getInstance()->allOrders();

        // Clear existing rows
        ui->orderList->setRowCount(0);

        // Set column headers (optional if already done in Designer)
        ui->orderList->setColumnCount(2);
        ui->orderList->setHorizontalHeaderLabels(QStringList() << "Order ID" << "Status");

        // Check if orders list is empty
        if (orders->empty()) {
            ui->orderList->setRowCount(1);
            ui->orderList->setItem(0, 0, new QTableWidgetItem("No orders"));
            ui->orderList->setSpan(0, 0, 1, 3); // Span across all 3 columns
        }
        bool ord=false;
        int row = 0;
        for (const auto& order : *orders) {
            if(order.getUserId()==currentUser.getId()){
                ord=true;
                ui->orderList->insertRow(row);
                ui->orderList->setItem(row, 0, new QTableWidgetItem(QString::number(order.getId())));
                ui->orderList->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(order.getStatus())));
                ++row;
            }
        }
        if(ord==false){
            ui->orderList->setRowCount(1);
            ui->orderList->setItem(0, 0, new QTableWidgetItem("No orders"));
            ui->orderList->setSpan(0, 0, 1, 3); // Span across all 3 columns
        }

        ui->orderList->resizeColumnsToContents();
        ui->orderList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }

}

void userPage::onPaymentWindowDestroyed(){
    if (order) {
        delete order;
        order = nullptr;
    }
    this->show();
}


void userPage::on_placeOrder_clicked()
{
    Payment *paymentWindow = new Payment(*order);
    paymentWindow->show();
    connect(paymentWindow, &Payment::destroyed, this, &userPage::onPaymentWindowDestroyed);
    qDebug("destoy");
    connect(paymentWindow, &Payment::destroyed, this, &userPage::show);
    // Re-show this page

    this->hide();
}



void userPage::on_logout_clicked()
{
    delete this;
}
