#include "login.h"
#include "ui_login.h"
#include <iostream>
#include "store.h"
#include "adminPage.h"
#include "userPage.h"


using namespace std;

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_loginbutton_clicked()
{
    QString u=ui->iusername->text();
    QString p=ui->ipassword->text();

    ui->errormsg->setText(" ");

    if(authenticator(u,p)==1){
        userPage *userPageWindow = new userPage();  // parent is login
        connect(userPageWindow, &userPage::destroyed, this, &login::show);  // show login when userPage is closed
        userPageWindow->show();
        this->hide();


    }else if (authenticator(u,p)==2){
        adminPage *adminPageWindow = new adminPage();  // parent is login
        connect(adminPageWindow, &adminPage::destroyed, this, &login::show);  // show login when adminPage is closed
        adminPageWindow->show();
        this->hide();

    }else{
        ui->errormsg->setText("Invalid username or password");
        ui->errormsg->setStyleSheet("QLabel { color : red; }");
    }
}

