//#include "firstscreen.h" //gives an error if this is not added
#include "wallet.h"
#include "ui_wallet.h"

//int Wallet::currentBalance=0;
Wallet::Wallet(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Wallet)
{
    ui->setupUi(this);
    setFixedSize(400,604);

    //to avoid showing values on the screen at first
    ui->moneySpinBox->setSpecialValueText("--");
    ui->securityCodeSpinBox->setSpecialValueText("--");

    ui->moneySpinBox->setRange(0, 10000);
    ui->securityCodeSpinBox->setRange(99, 999);
    ui->cardNoLineEdit->setMaxLength(16);
    //currentBalance=FirstScreen::user->getWallet()->getCurrentBalance();
    /*showCurrentBalance();*/

}

Wallet::~Wallet()
{
    delete ui;
}

void Wallet::showCurrentBalance(){
    ui->currentMoneyLabel->setText(QString("Value: %1$").arg(FirstScreen::user->getWallet()->getCurrentBalance()));
    ui->currentMoneyLabel->setStyleSheet("border-image: url(:/img/img0/lineEditBackground.png); border-radius: 15px; color: #21561e; font-size: 12pt; font-weight: bold;");
}

int Wallet::getCurrentBalance(){
    return currentBalance;
}

void Wallet::setCurrentBalance(int newBalance){
    currentBalance=newBalance;
}

void Wallet::on_mainMenuButton_clicked()
{
    this->hide();
    FirstScreen f;
    f.setModal(true);
    f.exec();
}


void Wallet::on_confirmButton_clicked()
{
    if(!cardNo.isEmpty()){
        if(ui->monthComboBox->currentText()!="--" && ui->yearComboBox->currentText()!="--" && ui->securityCodeSpinBox->text()!="--"){
            int enteredValue=ui->moneySpinBox->value();
            //FirstScreen::user->getWallet()->currentBalance=currentBalance;
            currentBalance=FirstScreen::user->getWallet()->getCurrentBalance()+enteredValue;
            FirstScreen::user->getWallet()->setCurrentBalance(currentBalance);
            qDebug()<<FirstScreen::user->getWallet()->getCurrentBalance();
            ui->currentMoneyLabel->setText(QString("Value: %1$").arg(currentBalance));
            ui->currentMoneyLabel->setStyleSheet("border-image: url(:/img/img0/lineEditBackground.png); border-radius: 15px; color: #21561e; font-size: 12pt; font-weight: bold;");
        }
    }
}

void Wallet::on_cardNoLineEdit_textEdited(const QString &arg1)
{
    cardNo="";
    ui->cardNoLineEdit->setMaxLength(16); //maximum digits to enter
    QString filteredText;
    for (const QChar& ch : arg1){
        if (ch.isDigit()){ //allows only digits to be entered
            filteredText += ch;
        }
    }
    if(filteredText.length()==16){
        ui->cardNoLineEdit->setMaxLength(19); //to insert a " " between every 4 digits after entering 16 digits
        for(int i=filteredText.length()-1;i>0;i--){
            if(i%4==0) filteredText.insert(i, ' ');
        }
        cardNo=filteredText;
    }
    ui->cardNoLineEdit->setText(filteredText);
}
