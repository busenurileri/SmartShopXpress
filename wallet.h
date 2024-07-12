#ifndef WALLET_H
#define WALLET_H

#include <QDialog>
#include <QString>
#include "firstscreen.h"

namespace Ui {
class Wallet;
}

class Wallet : public QDialog
{
    Q_OBJECT
private:
    QString cardNo;
    int currentBalance;
public:
    explicit Wallet(QWidget *parent = nullptr);
    ~Wallet();
    void showCurrentBalance();
    int getCurrentBalance();
    void setCurrentBalance(int);

private slots:
    void on_mainMenuButton_clicked();

    void on_confirmButton_clicked();

    void on_cardNoLineEdit_textEdited(const QString &arg1);

private:
    Ui::Wallet *ui;
};

#endif // WALLET_H
