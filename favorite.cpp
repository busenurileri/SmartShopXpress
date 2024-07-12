#include "favorite.h"
#include "ui_favorite.h"

Favorite::Favorite(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Favorite)
{
    ui->setupUi(this);
    setFixedSize(400,604);
    selectedItemForFavorite="";

}

Favorite::~Favorite()
{
    delete ui;
}

void Favorite::on_mainMenuButton_clicked()
{
    this->hide();
    FirstScreen f;
    f.setModal(true);
    f.exec();
}

void Favorite::showFavorites(){
    ui->favListWidget->clear();
    for(int i=0;i<FirstScreen::user->getFavorites().size();i++){
        QFont font;
        font.setPointSize(13); // Set the font size (adjust as needed)
        ui->favListWidget->setFont(font);
        QSize iconSize(48, 48);
        ui->favListWidget->setIconSize(iconSize);

        qDebug()<<"favoriler gösteriliyor";
        QString itemName =FirstScreen::user->getFavorites()[i].getName() + "         " + QString::number(FirstScreen::user->getFavorites()[i].getProduct().getPrice()) + " ($)    Id="+QString::number(FirstScreen::user->getFavorites()[i].getId());
        ui->favListWidget->addItem(itemName);


        int index = itemName.indexOf(' ');
        QString productName = itemName.left(index);

        QIcon icon(":/img/img0/productImages/"+productName+".png");
        ui->favListWidget->item(ui->favListWidget->count() - 1)->setIcon(icon);
        ui->favListWidget->item(ui->favListWidget->count() - 1)->setForeground(QColor("#21561e"));

    }
}

void Favorite::on_deleteFavButton_clicked()
{
    if(selectedItemForFavorite!=""){
        QString idString;
        int id;
        int equalsIndex = selectedItemForFavorite.indexOf('=');
        idString = selectedItemForFavorite.mid(equalsIndex + 1);
        id = idString.toInt();
        const MarketProduct &product = CreatingMarket::getMarketProductById(id);
        FirstScreen::user->deleteFavorite(product);
        selectedItemForFavorite="";
        showFavorites();
    }
}


void Favorite::on_favListWidget_itemClicked(QListWidgetItem *item)
{
    if (item) {
        selectedItemForFavorite= item->text();
    }
}


void Favorite::on_addCartButton_clicked()
{

    if(selectedItemForFavorite!=""){
        QString idString;
        int id;
        int equalsIndex = selectedItemForFavorite.indexOf('=');
        idString = selectedItemForFavorite.mid(equalsIndex + 1);
        id = idString.toInt();
        int amount=ui->comboBox->currentText().toInt();

        const MarketProduct &product = CreatingMarket::getMarketProductById(id);
        if(product.getStock()>=amount){
            qDebug() << "you can buy";
            FirstScreen::user->addIdAmount(id,amount);
        }
        else{
            qDebug() << "stock is unsufficient";
        }
    }

}

