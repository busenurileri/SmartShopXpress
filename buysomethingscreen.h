#ifndef BUYSOMETHINGSCREEN_H
#define BUYSOMETHINGSCREEN_H

#include <QDialog>
//#include "market.h"
#include "creatingmarket.h"
//#include "cartscreen.h"
#include "QList"
#include "product.h"
#include "firstscreen.h"

#include <QListWidgetItem>
#include <algorithm>

namespace Ui {
class BuySomethingScreen;
}

class BuySomethingScreen : public QDialog
{
    Q_OBJECT

public:
    explicit BuySomethingScreen(QWidget *parent = nullptr);
    ~BuySomethingScreen();

    //bunlar ekrana ürünleri getiren methodlar
    void setFruitsProduct();
    void setVegetablesProduct();

private slots:
    void on_mainMenuButton_2_clicked();

    void on_cheapProductListWidget_itemPressed(QListWidgetItem *item);

    void on_addSomethingPushButton_clicked();

    void on_favoriteButton_clicked();

 //   void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    CreatingMarket creatingMarketObject;
    Ui::BuySomethingScreen *ui;
    QString selectedItem;//biri ürüne tıklayınca en ucuz kısmına diğer marketlerdeki gelsin diye ismini tutup bununla arama yapmak için

    int cheapestOneId;// en ucuz kısmından seçilince id sini tutuyorum bunu alırsa ya da favori vs de kullanmak için

    std::vector<QString> productNameControl; //aynı isimdeki ürünlerin vir kere yazdırılması için kontrol vektörü
   // QString selectedItemForFavorite;

public slots:
    void onItemClicked(QListWidgetItem *item);

};

#endif // BUYSOMETHINGSCREEN_H
