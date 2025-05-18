#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <vector>
#include <fstream>
#include<QString>

using namespace std;

class Product{
    int id;
    string name;
    float price;
public:
    Product(int i=0,string n="", float p=0);
    void setName(string n);
    void setPrice(float p);
    int getId()const;
    string getName()const;
    float getPrice()const;
    virtual void display()const;
};

class OrderItem: public Product{
    int quantity;
public:
    OrderItem(int i=0,string n="",float p=0, int q=0);
    int getQuantity()const;
    float totalPrice()const;
    void display() const;
};

class PaymentMethod{
protected:
    string paymentType;
    float amountPaid;

public:
    string getPaymentType()const;
    float getAmountPaid()const;
    virtual void pay(float amount) = 0;
};

class CardPayment : public PaymentMethod {
    string cardNumber;
    string expiry;
    int cvv;

public:
    CardPayment();

    void pay(float amount);

};

class CashPayment : public PaymentMethod {
public:
    CashPayment();

    void pay(float amount);
};

class EasyPaisaPayment : public PaymentMethod {
    int accountNumber;
public:
    EasyPaisaPayment();

    void pay(float amount);
};

class JazzCashPayment : public PaymentMethod {
    int accountNumber;
public:
    JazzCashPayment();

    void pay(float amount);
};

class Order{
    static int nextId;
    int orderId, userId;
    string status;
    vector<OrderItem> cart;
    PaymentMethod* paymentMethod;

public:
    Order(int uid);

    ~Order();
    const vector<OrderItem>& getCart() const ;
    int getId() const;
    int getUserId() const;
    string getStatus() const ;
    string getPaymentMethod() const;

    void setStatus(string stat);
    void setPaymentMethod(PaymentMethod* pm);

    void addItem(OrderItem item);
    float calculateTotalPrice() const;
    void display() const;
};


class Store{
private:
    vector<Product> products;
    vector<Order> orders;
    Store();
    void loadProducts();
    void loadOrders();

public:
    static Store* getInstance();

    Store(Store const&) = delete;
    Store(Store&&) = delete;
    Store& operator=(Store const&) = delete;
    Store& operator=(Store&&) = delete;

    ~Store();
    vector<Product>* allProducts();
    vector<Order>* allOrders();
    void saveProducts();

    void saveOrders();
    void addProduct(const Product& p);
    void addOrder(Order o);

    void editProduct(int id, const string& newName, float newPrice);

    Product* getProductById(int id);
    void displayProducts();
    void displayOrders();
    void displayUserOrders(int userId) const ;
    void updateOrderStatus(int orderId, const string& status);
    void trackOrder(int orderId);


};
class Admin{
public:
    void viewProducts(Store& store);
    void addProduct(Store& store);
    void editProduct(Store& store);
    void updateOrderStatus(Store& store);
};

class User{
    static int id;
    string name;
public:
    User(int i=0, string n="");
    int getId() const;
    string getName() const;
    void viewProducts(Store& store);
    void placeOrder(Store& store);
    void trackOrder(Store& store);
    void viewMyOrders(Store& store);
};

int authenticator(QString username,QString password);

#endif
