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
    explicit userPage(QWidget *parent = nullptr);
    ~userPage();

private:
    Ui::userPage *ui;
};

#endif // USERPAGE_H
