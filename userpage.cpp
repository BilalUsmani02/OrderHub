#include "userpage.h"
#include "ui_userpage.h"
#include "payment.h"
#include "orderinfo.h"
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QString>
#include <QDebug>

userPage::userPage(User& user,QWidget *parent)
    : QWidget(parent), ui(new Ui::userPage),
    currentUser(user.getId(),user.getName()), order(currentUser.getId())
{
    qDebug() << "Initializing userPage for user ID:" << currentUser.getId();

    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    this->show();

    // inside userPage constructor after setupUi

    vector<Product>* prods = Store::getInstance()->allProducts();
    ui->productList->setColumnCount(4);
    QStringList headers;
    headers << "Name" << "Price" << "Quantity" << " ";
    ui->productList->setHorizontalHeaderLabels(headers);
    ui->productList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < static_cast<int>(prods->size()); ++i) {
        Product product = prods->at(i);
        ui->productList->insertRow(i);

        auto* nameItem = new QTableWidgetItem(QString::fromStdString(product.getName()));
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
        ui->productList->setItem(i, 0, nameItem);

        auto* priceItem = new QTableWidgetItem(QString::number(product.getPrice(), 'f', 2));
        priceItem->setFlags(priceItem->flags() & ~Qt::ItemIsEditable);
        ui->productList->setItem(i, 1, priceItem);

        // Create quantity widget
        auto* quantityWidget = new QWidget();
        auto* layout = new QHBoxLayout(quantityWidget);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setAlignment(Qt::AlignCenter);

        auto* minusBtn = new QPushButton("-");
        auto* qtyLabel = new QLabel("1");
        auto* plusBtn = new QPushButton("+");

        minusBtn->setFixedSize(30, 25);
        plusBtn->setFixedSize(30, 25);
        qtyLabel->setFixedWidth(25);
        qtyLabel->setAlignment(Qt::AlignCenter);

        layout->addWidget(minusBtn);
        layout->addWidget(qtyLabel);
        layout->addWidget(plusBtn);
        ui->productList->setCellWidget(i, 2, quantityWidget);

        // Create Add button
        auto* addButton = new QPushButton("Add");
        ui->productList->setCellWidget(i, 3, addButton);

        // Connect buttons using value captures (by copy)
        connect(plusBtn, &QPushButton::clicked, this, [qtyLabel]() {
            int qty = qtyLabel->text().toInt();
            qtyLabel->setText(QString::number(qty + 1));
        });

        connect(minusBtn, &QPushButton::clicked, this, [qtyLabel]() {
            int qty = qtyLabel->text().toInt();
            if (qty > 1)
                qtyLabel->setText(QString::number(qty - 1));
        });

        connect(addButton, &QPushButton::clicked, this, [this, product, qtyLabel]() {
            int quantity = qtyLabel->text().toInt();
            OrderItem item(product.getId(), product.getName(), product.getPrice(), quantity);
            order.addItemToCart(item);
            qtyLabel->setText("1");
        });
    }

}

void userPage::populateCartTable(const Order& ord)
{
    qDebug() << "Populating cart table";
    const auto& cart = ord.getCart();

    ui->cartList->clear();
    ui->cartList->setRowCount(0);
    ui->cartList->setColumnCount(5);
    ui->cartList->setHorizontalHeaderLabels({"Name", "Unit Price", "Qty", "Sub-total", "Remove"});
    ui->cartList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < static_cast<int>(cart.size()); ++i) {
        const OrderItem& it = cart[i];
        qDebug() << "Cart item:" << QString::fromStdString(it.getName()) << "Qty:" << it.getQuantity();

        ui->cartList->insertRow(i);
        QTableWidgetItem* nameItem = new QTableWidgetItem(QString::fromStdString(it.getName()));
        QTableWidgetItem* priceItem = new QTableWidgetItem(QString::number(it.getPrice(), 'f', 2));
        QTableWidgetItem* subtotalItem = new QTableWidgetItem(QString::number(it.totalPrice(), 'f', 2));

        QWidget* quantityWidget = new QWidget();
        QHBoxLayout* layout = new QHBoxLayout(quantityWidget);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setAlignment(Qt::AlignCenter);

        QPushButton* minusBtn = new QPushButton("-");
        QLabel* qtyLabel = new QLabel(QString::number(it.getQuantity()));
        QPushButton* plusBtn = new QPushButton("+");

        layout->addWidget(minusBtn);
        layout->addWidget(qtyLabel);
        layout->addWidget(plusBtn);
        ui->cartList->setCellWidget(i, 2, quantityWidget);

        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
        priceItem->setFlags(priceItem->flags() & ~Qt::ItemIsEditable);
        subtotalItem->setFlags(subtotalItem->flags() & ~Qt::ItemIsEditable);

        ui->cartList->setItem(i, 0, nameItem);
        ui->cartList->setItem(i, 1, priceItem);
        ui->cartList->setItem(i, 3, subtotalItem);

        connect(plusBtn, &QPushButton::clicked, this, [=]() {
            int productId = it.Product::getId();
            qDebug() << "Increasing quantity for product ID:" << productId;
            order.increaseQuantity(productId);
            populateCartTable(order);
        });

        connect(minusBtn, &QPushButton::clicked, this, [=]() {
            int productId = it.Product::getId();
            qDebug() << "Decreasing quantity for product ID:" << productId;
            order.decreaseQuantity(productId);
            populateCartTable(order);
        });

        QPushButton* rmvBtn = new QPushButton("Remove Item");
        ui->cartList->setCellWidget(i, 4, rmvBtn);

        connect(rmvBtn, &QPushButton::clicked, this, [=]() {
            int productId = it.Product::getId();
            qDebug() << "Removing product ID:" << productId << "from cart";
            order.removeItem(productId);
            populateCartTable(order);
        });
    }

    QString oTotal = QString::number(order.calculateTotalPrice(), 'f', 2);
    qDebug() << "Total Order Price:" << oTotal;
    ui->orderTotal->setText(oTotal);
}

userPage::~userPage()
{
    delete ui;
    qDebug() << "Destroying userPage UI";
}

void userPage::on_tabWidget_tabBarClicked(int index)
{
    qDebug() << "Tab switched to index:" << index;
    ui->address->hide();
    ui->label_2->hide();
    ui->orderTotal->hide();
    ui->label->hide();
    ui->placeOrder->hide();

    ui->cartList->clear();
    ui->cartList->setRowCount(0);
    ui->cartList->setColumnCount(0);


    if (index == 2 && !order.getCart().empty()) {
        qDebug() << "Switching to Cart tab with non-empty cart";
        populateCartTable(order);
        ui->address->show();
        ui->label_2->show();
        ui->orderTotal->show();
        ui->label->show();
        ui->placeOrder->show();
    }

    if (index == 1) {
        qDebug() << "Switching to Order History tab";
        vector<Order>* orders = Store::getInstance()->allOrders();
        ui->orderList->setRowCount(0);
        ui->orderList->setColumnCount(4); // Now 4 columns
        ui->orderList->setHorizontalHeaderLabels(QStringList() << "Order ID" << "Status" << "Total Price" << " ");



        if (orders->empty()) {
            ui->orderList->setRowCount(1);
            ui->orderList->setItem(0, 0, new QTableWidgetItem("No orders"));
            ui->orderList->setSpan(0, 0, 1, 4); // Spanning 3 columns
        }

        bool ord = false;
        int row = 0;
        for (const auto& order : *orders) {
            if (order.getUserId() == currentUser.getId()) {
                ord = true;
                ui->orderList->insertRow(row);
                ui->orderList->setItem(row, 0, new QTableWidgetItem(QString::number(order.getId())));
                ui->orderList->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(order.getStatus())));

                float totalPrice = order.calculateTotalPrice();
                QString priceStr = QString("Rs. %1").arg(totalPrice, 0, 'f', 2);
                ui->orderList->setItem(row, 2, new QTableWidgetItem(priceStr));

                // Add View Button
                QPushButton* viewButton = new QPushButton("View");
                ui->orderList->setCellWidget(row, 3, viewButton);

                // Connect view button with a lambda capturing the order object
                Order* orderCopy =new Order(order);
                connect(viewButton, &QPushButton::clicked, this, [orderCopy]() {
                    OrderInfo* infoWindow = new OrderInfo(*orderCopy); // Assuming OrderInfo takes an Order
                    infoWindow->setAttribute(Qt::WA_DeleteOnClose);
                    infoWindow->show();
                });

                ++row;
            }
        }


        if (!ord) {
            ui->orderList->setRowCount(1);
            ui->orderList->setItem(0, 0, new QTableWidgetItem("No orders"));
            ui->orderList->setSpan(0, 0, 1, 3); // Spanning all 3 columns
        }

        ui->orderList->resizeColumnsToContents();
        ui->orderList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }

}

void userPage::on_placeOrder_clicked()
{
    QString addr=ui->address->text();
    if (addr.isEmpty()){
        QMessageBox::warning(this, "Input Error", "Please enter address");
        return;
    }else{
        order.setAddress(addr.toStdString());
        qDebug() << "Place Order clicked";
        Payment* paymentWindow = new Payment(order);
        connect(paymentWindow, &Payment::destroyed, this, &userPage::show);
        connect(paymentWindow, &Payment::deleteOrder, this, &userPage::onPaymentFinished);
        paymentWindow->show();
        this->hide();
    }
}

void userPage::onPaymentFinished()
{
    order.clearOrder();
    ui->tabWidget->setCurrentIndex(0);
    qDebug() << "Payment finished. Clearing order.";

}



void userPage::on_logout_clicked()
{
    emit logoutSignal();
    qDebug()<<"loged out";
    this->close();
    qDebug() << "User logged out. Closing userPage.";

}
