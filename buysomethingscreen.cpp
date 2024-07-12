#include "buysomethingscreen.h"
#include "ui_buysomethingscreen.h"

//QList<Market> BuySomethingScreen::marketList = QList<Market>();
//QList<Product> BuySomethingScreen::productList = QList<Product>();

BuySomethingScreen::BuySomethingScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuySomethingScreen)
{
    setFixedSize(400,604);
    ui->setupUi(this);
    selectedItem="";
    // selectedItemForFavorite="";

    cheapestOneId=0;//secilmediginde random deger donduruyor. urun ustteki widgettan secilince hata cıkarmaması icin
    connect(ui->listWidget, &QListWidget::itemClicked, this, &BuySomethingScreen::onItemClicked);





}



BuySomethingScreen::~BuySomethingScreen()
{
    delete ui;
}




void BuySomethingScreen::setFruitsProduct()
{

    QFont font;
    font.setPointSize(14); // Set the font size (adjust as needed)

    // Set the font for the QListWidget
    ui->listWidget->setFont(font);

    QSize iconSize(48, 48);

    // Set the icon size for the QListWidget
    ui->listWidget->setIconSize(iconSize);


    int marketCount=CreatingMarket::existingMarkets.size();
    //  int productsSize=CreatingMarket::existingMarkets[0].getMarketProductList().size();
    qDebug() << "market count "<<marketCount;
    qDebug() << "product  count "<<CreatingMarket::existingMarkets[0].getMarketProductList().size();
    for (int i = 0; i < marketCount; i++) {
        qDebug() << "first loop";
        for (int j = 0; j < CreatingMarket::existingMarkets[i].getMarketProductList().size(); j++) {
            qDebug() << "second loop";
            const Product& product = CreatingMarket::existingMarkets[i].getMarketProductList()[j].getProduct();
            qDebug() << "product id" <<product.getId();
            qDebug() << "product name" <<product.getName();
            if (product.getId() == 1) {
                // Add item to QListWidget
                QString itemName = product.getName();

                auto it = std::find(productNameControl.begin(), productNameControl.end(), itemName);

                if (it == productNameControl.end()) { //aynı isimli product bulamazsa eklemesi için
                    int price=product.getPrice();// Assuming getName() returns a QString

                    QString itemText = itemName ;//+ "    " + QString::number(price) + " ($)";
                    ui->listWidget->addItem(itemText);


                    QIcon icon(":/img/img0/productImages/"+itemName+".png");

                    ui->listWidget->item(ui->listWidget->count() - 1)->setIcon(icon);


                    // Set foreground color for the added item to black
                    ui->listWidget->item(ui->listWidget->count() - 1)->setForeground(Qt::red);

                    productNameControl.push_back(itemName);
                }

            }
        }
    }



}

void BuySomethingScreen::setVegetablesProduct()
{

    QFont font;
    font.setPointSize(14); // Set the font size (adjust as needed)

    // Set the font for the QListWidget
    ui->listWidget->setFont(font);

    QSize iconSize(48, 48);

    // Set the icon size for the QListWidget
    ui->listWidget->setIconSize(iconSize);


    int marketCount=CreatingMarket::existingMarkets.size();
    //  int productsSize=CreatingMarket::existingMarkets[0].getMarketProductList().size();
    qDebug() << "market count "<<marketCount;
    qDebug() << "product  count "<<CreatingMarket::existingMarkets[0].getMarketProductList().size();
    for (int i = 0; i < marketCount; i++) {
        qDebug() << "first loop";
        for (int j = 0; j < CreatingMarket::existingMarkets[i].getMarketProductList().size(); j++) {
            qDebug() << "second loop";
            const Product& product = CreatingMarket::existingMarkets[i].getMarketProductList()[j].getProduct();
            qDebug() << "product id" <<product.getId();
            qDebug() << "product name" <<product.getName();
            if (product.getId() == 2) {
                // Add item to QListWidget
                QString itemName = product.getName();

                auto it = std::find(productNameControl.begin(), productNameControl.end(), itemName);

                if (it == productNameControl.end()) {
                    int price=product.getPrice();// Assuming getName() returns a QString

                    QString itemText = itemName;// + "   " + QString::number(price) + " ($)";
                    ui->listWidget->addItem(itemText);


                    QIcon icon(":/img/img0/productImages/"+itemName+".png");

                    ui->listWidget->item(ui->listWidget->count() - 1)->setIcon(icon);


                    // Set foreground color for the added item to black
                    ui->listWidget->item(ui->listWidget->count() - 1)->setForeground(Qt::red);

                    productNameControl.push_back(itemName);
                }

            }
        }
    }



}


void BuySomethingScreen::on_mainMenuButton_2_clicked()
{
    this->hide();
    FirstScreen f;
    f.setModal(true);
    f.exec();

}


void BuySomethingScreen::onItemClicked(QListWidgetItem *item) {


    ui->cheapProductListWidget->clear();

    QString text=item->text();
    int spaceIndex = text.indexOf(' ');
    selectedItem = text.left(spaceIndex);


    QFont font;
    font.setPointSize(10); // Set the font size (adjust as needed)

    // Set the font for the QListWidget
    ui->cheapProductListWidget->setFont(font);

    QSize iconSize(48, 48);

    // Set the icon size for the QListWidget
    ui->cheapProductListWidget->setIconSize(iconSize);


    int marketCount=CreatingMarket::existingMarkets.size();
    //  int productsSize=CreatingMarket::existingMarkets[0].getMarketProductList().size();
    qDebug() << "market count  "<<marketCount;
    qDebug() << "product  count "<<CreatingMarket::existingMarkets[0].getMarketProductList().size();
    for (int i = 0; i < marketCount; i++) {
        qDebug() << "first loop";
        for (int j = 0; j < CreatingMarket::existingMarkets[i].getMarketProductList().size(); j++) {
            qDebug() << "second loop";
            const Product& product = CreatingMarket::existingMarkets[i].getMarketProductList()[j].getProduct();
            qDebug() << "product id" <<product.getId();
            qDebug() << "product name" <<product.getName();
            if (product.getName()==selectedItem) {
                // Add item to QListWidget
                QString itemName = product.getName();
                int price=product.getPrice();// Assuming getName() returns a QString

                QString itemText = itemName + "         " + QString::number(price) + " ($)    Id="+QString::number(CreatingMarket::existingMarkets[i].getMarketProductList()[j].getId());
                ui->cheapProductListWidget->addItem(itemText);


                QIcon icon(":/img/img0/tomato.png");

                ui->cheapProductListWidget->item(ui->cheapProductListWidget->count() - 1)->setIcon(icon);


                // Set foreground color for the added item to black
                ui->cheapProductListWidget->item(ui->cheapProductListWidget->count() - 1)->setForeground(Qt::red);
            }
        }
    }






}

void BuySomethingScreen::on_cheapProductListWidget_itemPressed(QListWidgetItem *item)
{
    QString idString;
    int id;

    int equalsIndex = item->text().indexOf('=');
    //idString = item->text().mid(equalsIndex + 1, 2);
    idString = item->text().mid(equalsIndex + 1); //= den sonra 22 basamaktan fazla sayı gelirse diye. (= den stringin sonuna kadar olan kısmı alır)
    id = idString.toInt();

    cheapestOneId=id;


}


void BuySomethingScreen::on_addSomethingPushButton_clicked()
{

    if(selectedItem!="" && FirstScreen::user!=nullptr && cheapestOneId!=0){ //sepete eklenecek ürünü ekletiyor sonrasında tekrar secilerek islem yapması icin terkrar 0 lıyor
        qDebug() << "cheapest id issss" << cheapestOneId;
        int amount=ui->comboBox->currentText().toInt();

        //bu id ye bakarak ürünün yerini tutan bir product tutuyor.Stok kontrolü için
        //ürünü satın alırken bu değil pointer tutmak belki işimize yarayabilir(getMarketProductById product döndürdüğü için)
        const MarketProduct &product = CreatingMarket::getMarketProductById(cheapestOneId);

        if(product.getStock()>=amount){
            qDebug() << "you can buy";
            FirstScreen::user->addIdAmount(cheapestOneId,amount);
        }
        else{
            qDebug() << "stock is unsufficient";
        }
    }


}


void BuySomethingScreen::on_favoriteButton_clicked()
{
    if(selectedItem!="" && FirstScreen::user!=nullptr && cheapestOneId!=0){ //hesaba giris yapilmis olmasi beklenir
        const MarketProduct &product = CreatingMarket::getMarketProductById(cheapestOneId);
        //QString itemText = product.getName() + "         " + QString::number(product.getProduct().getPrice()) + " ($)    Id="+QString::number(product.getId());
        //FirstScreen::user->addFavorite(itemText);
        FirstScreen::user->addFavorite(product);
        qDebug()<<"fav butona gird";
    }
}

/*
void BuySomethingScreen::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if (item) {
        selectedItemForFavorite= item->text();
    }
}*/
