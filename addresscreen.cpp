#include "addresscreen.h"
#include "ui_addresscreen.h"
#include <QDebug>

Addresscreen::Addresscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Addresscreen)
{
    ui->setupUi(this);
    setFixedSize(400,604);

}

Addresscreen::~Addresscreen()
{
    delete ui;
}

void Addresscreen::on_mainMenuButton_clicked()
{
    this->hide();
    FirstScreen f;
    f.setModal(true);
    f.exec();

}

//adres ekranında tutulan adresin ismini atıyor
void Addresscreen::on_enterAddressNameLineEdit_editingFinished()
{
    address.setName(ui->enterAddressNameLineEdit->text());

    qDebug() << address.getName();

}


void Addresscreen::on_enterAddressCityLineEdit_editingFinished()
{
    address.setCity(ui->enterAddressCityLineEdit->text());

}


void Addresscreen::on_enterAddressStreetLineEdit_editingFinished()
{
    address.setStreet(ui->enterAddressStreetLineEdit->text());
}


void Addresscreen::on_enterAddressBuildingLineEdit_editingFinished()
{
     address.setBuilding(ui->enterAddressBuildingLineEdit->text());
}


void Addresscreen::on_enterAddressDoorNumLineEdit_editingFinished()
{
     address.setDoorNum(ui->enterAddressDoorNumLineEdit->text().toInt());
}


void Addresscreen::on_addAddressPushButton_clicked()
{
     //bilgilerin hepsi yazılmış mı kontrol ediyoruz
     bool allInfoIsWritten=true;
     if(ui->enterAddressNameLineEdit->text()=="Address name"){
         allInfoIsWritten=false;
     }
     if(ui->enterAddressCityLineEdit->text()=="City"){
         allInfoIsWritten=false;
     }
     if(ui->enterAddressStreetLineEdit->text()=="Street"){
         allInfoIsWritten=false;
     }
     if(ui->enterAddressBuildingLineEdit->text()=="Building name"){
         allInfoIsWritten=false;
     }
     if(ui->enterAddressDoorNumLineEdit->text()== "Door num"){
         allInfoIsWritten=false;
     }

     if(allInfoIsWritten){
         //line editleri tekrar güncelliyoruz


         ui->enterAddressNameLineEdit->clear();
         ui->enterAddressCityLineEdit->clear();
         ui->enterAddressStreetLineEdit->clear();
         ui->enterAddressBuildingLineEdit->clear();
         ui->enterAddressDoorNumLineEdit->clear();

         ui->enterAddressNameLineEdit->insert(QString("Address name"));
         ui->enterAddressCityLineEdit->insert(QString(QString("City")));
         ui->enterAddressStreetLineEdit->insert(QString("Street"));
         ui->enterAddressBuildingLineEdit->insert(QString("Building"));
         ui->enterAddressDoorNumLineEdit->insert(QString("Door num"));



         //kullanıcının address vektörüne bu adresi ekleyip, adress ekranında formalite tutulan adresi default const ile tekrar oluşturuyoruz
        // FirstScreen::user.addAddress(this->address);
         FirstScreen::user->addAddress(this->address);
         ui->addressCheckBox1->setText(address.getAddressInfo());
         this->address=Address();
     }
}

