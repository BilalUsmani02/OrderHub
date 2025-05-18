#include "adminpage.h"
#include "ui_adminpage.h"
#include <QTableWidgetItem>
#include <QMessageBox>

adminPage::adminPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::adminPage)
{
    ui->setupUi(this);
    connect(ui->productList, &QTableWidget::itemChanged,
            this, &adminPage::onItemChanged);


    vector<Product>* prods = Store::getInstance()->allProducts();

    if (prods->empty()) {
        ui->productList->setColumnCount(1);
        ui->productList->insertRow(0);
        QTableWidgetItem* nameItem = new QTableWidgetItem("No Products");
        ui->productList->setItem(0, 0, nameItem);
    } else {
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




