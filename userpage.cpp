#include "userpage.h"
#include "ui_userpage.h"
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QLabel>

userPage::userPage(QWidget *parent): QWidget(parent), ui(new Ui::userPage){

    User user;
    Order order(user.getId());

    ui->setupUi(this);
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
                if ()

            });
        }
    }
}

userPage::~userPage()
{
    delete ui;
}


