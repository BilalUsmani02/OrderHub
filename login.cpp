#include "login.h"
#include "ui_login.h"
#include <iostream>
#include "store.h"
#include "adminPage.h"
#include "userPage.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QCheckBox>
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
    connect(ui->loginShowPassword, &QCheckBox::stateChanged, this, &login::toggleLoginPasswordVisibility);
    connect(ui->registerShowPassword, &QCheckBox::stateChanged, this, &login::toggleRegisterPasswordVisibility);

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

    // Check for existing username and determine the last user ID
    int lastId = 0;
    bool usernameExists = false;

    QFile readFile("users.txt");
    if (readFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&readFile);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(" ");
            if (parts.size() >= 2) {
                bool ok;
                int id = parts[0].toInt(&ok);
                QString existingUsername = parts[1];
                if (ok && id > lastId) {
                    lastId = id;
                }
                if (existingUsername == newUsername) {
                    usernameExists = true;
                    break;
                }
            }
        }
        readFile.close();
    }

    if (usernameExists) {
        QMessageBox::warning(this, "Registration Error", "Username already exists. Please choose a different username.");
        return;
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

void login::toggleLoginPasswordVisibility(int state) {
    if (state == Qt::Checked) {
        ui->ipassword->setEchoMode(QLineEdit::Normal);
    } else {
        ui->ipassword->setEchoMode(QLineEdit::Password);
    }
}

void login::toggleRegisterPasswordVisibility(int state) {
    if (state == Qt::Checked) {
        ui->rpassword->setEchoMode(QLineEdit::Normal);
    } else {
        ui->rpassword->setEchoMode(QLineEdit::Password);
    }
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
    ui->loginShowPassword->hide();
    ui->registerShowPassword->hide();

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
    ui->loginShowPassword->show(); // 👈 Show checkbox
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
    ui->registerShowPassword->show(); // 👈 Show checkbox
}

