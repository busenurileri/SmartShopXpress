#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QDialog>
#include "firstscreen.h"

namespace Ui {
class LoginScreen;
}

class LoginScreen : public QDialog
{
    Q_OBJECT

public:
    explicit LoginScreen(QWidget *parent = nullptr);
    ~LoginScreen();

private slots:
    void on_mainMenuButton_clicked();

    void on_redirectSignupPushButton_clicked();

    void on_loginButton_clicked();

private:
    Ui::LoginScreen *ui;
};

#endif // LOGINSCREEN_H
