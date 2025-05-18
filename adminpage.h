#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QWidget>

namespace Ui {
class adminPage;
}

class adminPage : public QWidget
{
    Q_OBJECT

public:
    explicit adminPage(QWidget *parent = nullptr);
    ~adminPage();

private:
    Ui::adminPage *ui;
};

#endif // ADMINPAGE_H
