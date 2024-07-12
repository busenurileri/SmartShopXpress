#ifndef FIRSTSCREEN_H
#define FIRSTSCREEN_H
#include <QApplication>
#include <QDialog>

#include <QStackedWidget>
#include <QLabel>
#include <QTimer>
#include <QPixmap>
#include "user.h"
//#include "user2.h"
#include "cartscreen.h"
#include "favorite.h"
#include "addresscreen.h"
#include "loginscreen.h"
#include "signupscreen.h"
#include "wallet.h"

#include "buysomethingscreen.h"
#include <QDebug>
#include <QMessageBox>

//user classı firstscreen içeriyor aynı zamanda firstscreende user classı içeriyor. ondan dolayı forward declaration yapılmazsa hata veriyor
class User;  // Forward declaration ("User" does not name a type hatası)

namespace Ui {
class FirstScreen;
}

class FirstScreen : public QDialog
{
    Q_OBJECT
private:

public:
    explicit FirstScreen(QWidget *parent = nullptr);
    ~FirstScreen();
    void changeImage();
    static User* user;  // Use a pointer for dynamic allocation
    static std::vector<User*> usersVector;
    // std::vector<User> usersVector;
    //static User2 user;
   // Wallet w;

private slots:
    void on_cartButton_clicked();

    void on_addressButton_clicked();

    void on_budgetButton_clicked();

    void on_favoriteButton_clicked();

    void on_accountButton_clicked();

    void on_category1PushButton_clicked();

    void on_category2PushButton_clicked();

private:
    Ui::FirstScreen *ui;
};

#endif // FIRSTSCREEN_H
