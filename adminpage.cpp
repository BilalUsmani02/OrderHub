#include "adminpage.h"
#include "ui_adminpage.h"
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QComboBox>

adminPage::adminPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::adminPage)
{
    ui->setupUi(this);
    connect(ui->productList, &QTableWidget::itemChanged,
            this, &adminPage::onItemChanged);

    populateProdList();
    populateOrdList();

}
adminPage::~adminPage()
{
    delete ui;
}


void adminPage::onItemChanged(QTableWidgetItem *item) {
    int row = item->row();
    int col = item->column();
    vector<Product>* prods = Store::getInstance()->allProducts();

    if (row < 0 || row >= static_cast<int>(prods->size()))
        return;

    if (col == 0) { // Name edited
        std::string newName = item->text().toStdString();
        (*prods)[row].setName(newName);
    } else if (col == 1) { // Price edited
        bool ok;
        float newPrice = item->text().toFloat(&ok);
        if (ok) {
            (*prods)[row].setPrice(newPrice);
        } else {
            QMessageBox::warning(this, "Invalid Input", "Please enter a valid price.");
            ui->productList->blockSignals(true);
            item->setText(QString::number((*prods)[row].getPrice(), 'f', 2));
            ui->productList->blockSignals(false);
        }
    }
}



void adminPage::populateProdList(){
    vector<Product>* prods = Store::getInstance()->allProducts();

    if (prods->empty()) {
        ui->productList->setColumnCount(1);
        ui->productList->insertRow(0);
        QTableWidgetItem* nameItem = new QTableWidgetItem("No Products");
        ui->productList->setItem(0, 0, nameItem);
    } else {
        ui->productList->clear();
        ui->productList->setRowCount(0);
        ui->productList->setColumnCount(2);
        QStringList headers;
        headers << "Name" << "Price" ;
        ui->productList->setHorizontalHeaderLabels(headers);
        ui->productList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


        for (int i = 0; i < static_cast<int>(prods->size()); i++) {
            const Product& product = prods->at(i);
            ui->productList->insertRow(i);

            QTableWidgetItem* nameItem = new QTableWidgetItem(QString::fromStdString(product.getName()));
            nameItem->setFlags(nameItem->flags() | Qt::ItemIsEditable); // Editable
            ui->productList->setItem(i, 0, nameItem);

            QTableWidgetItem* priceItem = new QTableWidgetItem(QString::number(product.getPrice(), 'f', 2));
            priceItem->setFlags(priceItem->flags() | Qt::ItemIsEditable); // Editable
            ui->productList->setItem(i, 1, priceItem);

        }
    }
}

void adminPage::populateOrdList(){

    vector<Order>* orders = Store::getInstance()->allOrders();
    if (orders->empty()) {
        ui->orderList->setColumnCount(1);
        ui->orderList->insertRow(0);
        QTableWidgetItem* nameItem = new QTableWidgetItem("No Orders");
        ui->orderList->setItem(0, 0, nameItem);
    }else{
        // Clear existing rows
        ui->orderList->setRowCount(0);

        // Set column headers (optional if already done in Designer)
        ui->orderList->setColumnCount(3);
        ui->orderList->setHorizontalHeaderLabels(QStringList() << "Order ID" << "User ID" << "Status");

        // Check if orders list is empty
        if (orders->empty()) {
            ui->orderList->setRowCount(1);
            ui->orderList->setItem(0, 0, new QTableWidgetItem("No orders"));
            ui->orderList->setSpan(0, 0, 1, 3); // Span across all 3 columns
        }

        int row = 0;
        for (const auto& order : *orders) {
            ui->orderList->insertRow(row);
            QTableWidgetItem* idItem = new QTableWidgetItem(QString::number(order.getId()));
            idItem->setFlags(idItem->flags() & ~Qt::ItemIsEditable);
            ui->orderList->setItem(row, 0, idItem);

            QTableWidgetItem* userItem = new QTableWidgetItem(QString::number(order.getUserId()));
            userItem->setFlags(userItem->flags() & ~Qt::ItemIsEditable);
            ui->orderList->setItem(row, 1, userItem);

            QComboBox* statusCombo = new QComboBox();
            statusCombo->addItems({"Pending", "Accepted", "In Transit", "Shipped"});

            // Set current value
            int index = statusCombo->findText(QString::fromStdString(order.getStatus()));
            statusCombo->setCurrentIndex(index == -1 ? 0 : index);  // default to "Pending" if not found

            // Set the combo box in the cell
            ui->orderList->setCellWidget(row, 2, statusCombo);

            // Capture the row index in the lambda
            connect(statusCombo, &QComboBox::currentTextChanged, this, [=](const QString &newStatus) {
                vector<Order>* orders = Store::getInstance()->allOrders();
                if (row >= 0 && row < static_cast<int>(orders->size())) {
                    (*orders)[row].setStatus(newStatus.toStdString());
                }
            });

            ++row;
        }

        ui->orderList->resizeColumnsToContents();  // Optional: Auto-resize columns
        ui->orderList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    }
}

void adminPage::on_logout_clicked()
{
    delete this;
}



void adminPage::on_pushButton_clicked()
{
    vector<Product>* prods = Store::getInstance()->allProducts();
    QString name = ui->pName->text().trimmed();
    QString priceStr = ui->pPrice->text().trimmed();

    if (name.isEmpty() || priceStr.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill both product name and price.");
        return;
    }

    bool ok;
    float price = priceStr.toFloat(&ok);
    if (!ok || price < 0) {
        QMessageBox::warning(this, "Invalid Price", "Please enter a valid, non-negative price.");
        return;
    }

    Product newProduct(name.toStdString(), price);
    prods->push_back(newProduct);
    populateProdList();

    ui->pName->setText("");
    ui->pPrice->setText("");
    QMessageBox::information(this, "Product Added", "Product Added Successfully");
}

