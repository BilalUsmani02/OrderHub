#ifndef USERPAGE_H
#define USERPAGE_H
#include "store.h"
#include <QWidget>

namespace Ui {
class userPage;
}

class userPage : public QWidget
{
    Q_OBJECT

public:
    explicit userPage(User& user,QWidget *parent = nullptr);
    ~userPage();

signals:
    void cartUpdated(const Order&);


private slots:
    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::userPage *ui;
    User user{"Bilal"};
    Order* order=nullptr;
    void populateCartTable(const Order& ord);
};
#endif // USERPAGE_H
