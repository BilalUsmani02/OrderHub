#include "login.h"
#include "ui_login.h"
#include <iostream>
#include "store.h"
#include "adminPage.h"
#include "userPage.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

using namespace std;

void xorEncryptDecrypt(QString& str) {
    char key = 'K';
    QByteArray data = str.toLocal8Bit();
    for (int i = 0; i < data.size(); ++i) {
        data[i] = data[i] ^ key;
    }
    str = QString::fromLocal8Bit(data);
}

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{

    ui->setupUi(this);
    qDebug() << "Login UI setup complete";
    hideAll();
}

login::~login()
{
    delete ui;
}


void login::on_loginbutton_clicked()
{
    QString u = ui->iusername->text();
    QString p = ui->ipassword->text();
    ui->errormsg->setText(" ");

    // 🔒 Special case: Check hardcoded admin credentials
    if (u == "admin" && p == "admin123") {
        adminPage *adminWindow = new adminPage();
        connect(adminWindow, &adminPage::destroyed, this, &login::show);
        adminWindow->show();
        this->hide();
        return;
    }

    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->errormsg->setText("Could not open users.txt");
        ui->errormsg->setStyleSheet("QLabel { color : red; }");
        return;
    }

    QTextStream in(&file);
    bool loginSuccess = false;
    int matchedId = -1;
    QString matchedUsername;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(" ");
        if (parts.size() == 3) {
            int fileId = parts[0].toInt();
            QString fileUsername = parts[1];
            QString filePassword = parts[2];

            xorEncryptDecrypt(filePassword);  // Decrypt

            if (fileUsername == u && filePassword == p) {
                loginSuccess = true;
                matchedId = fileId;
                matchedUsername = fileUsername;
                break;
            }
        }
    }

    file.close();

    if (loginSuccess) {
        User currentUser(matchedId, matchedUsername.toStdString());
        userPage *userPageWindow = new userPage(currentUser);
        connect(userPageWindow, &userPage::destroyed, this, &login::show);
        userPageWindow->show();
        this->hide();
    } else {
        ui->errormsg->setText("Invalid username or password");
        ui->errormsg->setStyleSheet("QLabel { color : red; }");
    }
}




void login::on_registerBtn_clicked()
{
    QString newUsername = ui->rusername->text();
    QString newPassword = ui->rpassword->text();

    if (newUsername.isEmpty() || newPassword.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Username and password cannot be empty.");
        return;
    }

    // Determine the next available user ID
    int lastId = 0;
    QFile readFile("users.txt");
    if (readFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&readFile);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(" ");
            if (parts.size() >= 1) {
                bool ok;
                int id = parts[0].toInt(&ok);
                if (ok && id > lastId) {
                    lastId = id;
                }
            }
        }
        readFile.close();
    }

    // Set the static nextUid to lastId + 1
    User::nextUid = lastId + 1;

    // Create a new User
    User newUser(newUsername.toStdString());
    int userId = newUser.getId();

    // Encrypt the password
    xorEncryptDecrypt(newPassword);

    // Append new user to the file
    QFile file("users.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open users.txt");
        return;
    }

    QTextStream out(&file);
    out << userId << " " << newUsername << " " << newPassword << "\n";
    file.close();

    QMessageBox::information(this, "Registration", "Account created successfully.");
    ui->rusername->clear();
    ui->rpassword->clear();
}


void login::hideAll() {
    // Hide all login and register widgets
    ui->iusername->hide();
    ui->ipassword->hide();
    ui->loginbutton->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_4->hide();

    ui->rusername->hide();
    ui->rpassword->hide();
    ui->registerBtn->hide();
    ui->label_3->hide();
    ui->label_6->hide();
    ui->label_5->hide();
}


void login::on_LP_clicked() {
    hideAll();

    // Show login widgets
    ui->iusername->show();
    ui->ipassword->show();
    ui->loginbutton->show();
    ui->label->show();
    ui->label_2->show();
    ui->label_4->show();
}


void login::on_RP_clicked() {
    hideAll();

    // Show register widgets
    ui->rusername->show();
    ui->rpassword->show();
    ui->registerBtn->show();
    ui->label_3->show();
    ui->label_6->show();
    ui->label_5->show();
}
