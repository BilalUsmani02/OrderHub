#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QWidget>
#include<QTableWidgetItem>
#include "store.h"
#include <vector>

namespace Ui {
class adminPage;
}

class adminPage : public QWidget
{
    Q_OBJECT

public:
    explicit adminPage(QWidget *parent = nullptr);
    void onItemChanged(QTableWidgetItem *item);

    ~adminPage();

private slots:


    void on_logout_clicked();

private:
    Ui::adminPage *ui;
};

#endif // ADMINPAGE_H
