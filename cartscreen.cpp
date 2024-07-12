#include "cartscreen.h"
#include "ui_cartscreen.h"

CartScreen::CartScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CartScreen)
{
    ui->setupUi(this);
    setFixedSize(400,604);
    showProducts();
    updateCostLabel();
   // currentAmount=1;
    currentProductId=0;

}

CartScreen::~CartScreen()
{
    delete ui;
}

void CartScreen::on_mainMenuButton_clicked()
{
    this->hide();
    FirstScreen f;
    f.setModal(true);
    f.exec();

}

void CartScreen::showProducts() {
    ui->listWidget->clear();

    // Get the product ID - amount map from the user
    const QMap<int, int>& idAmountMap = FirstScreen::user->getIdAmountMap();

    // Iterate over the keys (product IDs) of the map
    for (auto it = idAmountMap.constBegin(); it != idAmountMap.constEnd(); ++it) {
        // Get the product ID and amount
        int productId = it.key();
        int amount = it.value();

        if(amount!=0){
            // Get the corresponding MarketProduct
            const MarketProduct& product = CreatingMarket::getMarketProductById(productId);

            // Construct the item text
            QString itemName = product.getName();
            int price = product.getProduct().getPrice();
            QString itemText = itemName + "         " + QString::number(price) + " ($)    Id=" + QString::number(productId);

            // Add item to list widget
            ui->listWidget->addItem(itemText);

            // Set icon for the added item
            QIcon icon(":/img/img0/productImages/" + itemName + ".png");
            ui->listWidget->item(ui->listWidget->count() - 1)->setIcon(icon);

            // Set foreground color for the added item
            ui->listWidget->item(ui->listWidget->count() - 1)->setForeground(QColor("#21561e"));
        }

    }
}


void CartScreen::updateCostLabel() {
    int cost = 0;
   const QMap<int, int> &idAmountMap = FirstScreen::user->getIdAmountMap();

    // Iterate through each id in the idAmountMap
    for (auto it = idAmountMap.constBegin(); it != idAmountMap.constEnd(); ++it) {
        int id = it.key();
        int amount = it.value();

        // Calculate the cost for each id and add to the total cost
        cost += (CreatingMarket::getCostById(id) * amount);
    }

    // Update the total cost label on the UI
    ui->totalCostLabel2->setText(" " + QString::number(cost) + " $");
}


//herhangi bir ürüne tıklanınca onun adedini labela yazdırıyor ve current product id yi güncelliyor
void CartScreen::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString idString;
    int id;

    int equalsIndex = item->text().indexOf('=');
    //idString = item->text().mid(equalsIndex + 1, 2);
    idString = item->text().mid(equalsIndex + 1); //= den sonra 22 basamaktan fazla sayı gelirse diye. (= den stringin sonuna kadar olan kısmı alır)
    id = idString.toInt();

    int amount=FirstScreen::user->getIdAmountMap()[id];
    currentProductId=id;
    ui->amountLabel->setText(QString::number(amount));

}


void CartScreen::on_comboBox_currentIndexChanged(int index)
{
    if(index==0){//recursion a girmesin diye koydum
        return;
    }
   qDebug() << "INdex is " <<index;
   //indexin bir fazlası amount
   int currentAmount = index+1;

   FirstScreen::user->updateIdAmount(currentProductId,currentAmount);
   ui->amountLabel->setText(QString::number(currentAmount));
   updateCostLabel();

   ui->comboBox->setCurrentIndex(0);

}


void CartScreen::on_deleteProductButton_clicked()
{
   int currentAmount = ui->amountLabel->text().toInt();

   if(currentProductId!=0){
        FirstScreen::user->updateIdAmount(currentProductId,currentAmount-1);
        ui->amountLabel->setText(QString::number(currentAmount-1));
        if(ui->amountLabel->text()=='0'){//adet 0 a düşünce eksili bir değere düsmesini engellemek icin
            currentProductId=0;
        }
        updateCostLabel();
        showProducts();
   }
}



void CartScreen::on_buyPushButton_clicked()
{
    QString labelText = ui->totalCostLabel2->text().trimmed();
    int spaceIndex = labelText.indexOf(' ');
    QString totalCostText = labelText.left(spaceIndex);
    int totalCost = totalCostText.toInt();

    if(FirstScreen::user->getWallet()->getCurrentBalance()>=totalCost){
        qDebug()<<FirstScreen::user->getWallet()->getCurrentBalance()-totalCost;
        FirstScreen::user->getWallet()->setCurrentBalance(FirstScreen::user->getWallet()->getCurrentBalance()-totalCost);
        qDebug()<<FirstScreen::user->getWallet()->getCurrentBalance();
        QMessageBox msgBox;
        msgBox.setWindowTitle(tr("Information"));
        msgBox.setText(tr("Your order has been received. It will be delivered as soon as possible.!"));
        msgBox.setStyleSheet("QMessageBox { background-color: #e0e0e0; }"); // Arkaplan rengini gri olarak ayarlar
        msgBox.exec();
        FirstScreen::user->clearIdAmountMap();
        updateCostLabel();
        showProducts();
    }
    else{
        QMessageBox msgBox;
        msgBox.setWindowTitle(tr("Warning!"));
        msgBox.setText(tr("Not enough money in the wallet!"));
        msgBox.setStyleSheet("QMessageBox { background-color: #e0e0e0; }"); // Arkaplan rengini gri olarak ayarlar
        msgBox.exec();
    }
}

