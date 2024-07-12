#ifndef CARTSCREEN_H
#define CARTSCREEN_H

#include <QDialog>
#include "firstscreen.h"
#include <QListWidgetItem>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class CartScreen;
}

class CartScreen : public QDialog
{
    Q_OBJECT

public:
    explicit CartScreen(QWidget *parent = nullptr);
    ~CartScreen();

private slots:
    void on_mainMenuButton_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_comboBox_currentIndexChanged(int index);

    void on_deleteProductButton_clicked();


    void on_buyPushButton_clicked();

private:
    Ui::CartScreen *ui;
    void showProducts();
    void updateCostLabel();
   // int currentAmount;
    int currentProductId; //tıklanılan ürünün id sini tutuyor
};

#endif // CARTSCREEN_H
