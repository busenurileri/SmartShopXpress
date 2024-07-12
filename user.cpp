#include "user.h"
#include "ui_user.h"



QMap<int, int> User::getIdAmountMap() const
{
    return idAmountMap;
}
void User::clearIdAmountMap(){ //sepeti bosaltmak icin
    idAmountMap.clear();
}

User::User(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::User)
{
    ui->setupUi(this);
    setFixedSize(400,604);
    //currentBalance=0;
    wallet=new Wallet();
    wallet->setCurrentBalance(0);
   /* wallet->setCurrentBalance(0);*/
   // getWallet()->setCurrentBalance(0);
    //qDebug()<<getWallet()->getCurrentBalance();

}

User::~User()
{
   // delete wallet;
    delete ui;
}
/*
void User::setCurrentMoneyforUser(int m){
    currentBalance=m;
}
int User::getCurrentMoneyForUser(){
    return currentBalance;
}*/
void User::showInfo(User* u){
    ui->usernameLabel->setText(u->getName()+" "+u->getSurname());
    ui->emailLabel->setText(u->getEmail());
    ui->phoneLabel->setText(u->getPhoneNumber());
    ui->genderLabel->setText(u->getGender()==Female?"Female":"Male");

    ui->usernameLabel->setStyleSheet("color: #20571e; font-size: 11px; font-weight: bold;");
    ui->emailLabel->setStyleSheet("color: #20571e; font-size: 11px;font-weight: bold;");
    ui->phoneLabel->setStyleSheet("color: #20571e; font-size: 11px;font-weight: bold;");
    ui->genderLabel->setStyleSheet("color: #20571e; font-size: 11px;font-weight: bold;");

}

int User::getId() {
    return id;
}

void User::setId(int id) {
    this->id = id;
}

int User::getAge() {
    return age;
}

void User::setAge(int age) {
    this->age = age;
}

QString User::getName() {
    return name;
}

void User::setName(QString name) {
    this->name = name;
}

QString User::getSurname() {
    return surname;
}

void User::setSurname(QString surname) {
    this->surname = surname;
}

QString User::getEmail() {
    return email;
}

void User::setEmail(QString email) {
    this->email = email;
}

QString User::getPhoneNumber(){
    return phoneNumber;
}
void User::setPhoneNumber(QString phoneNumber){
    this->phoneNumber=phoneNumber;
}
QString User::getPassword(){
    return password;
}
void User::setPassword(QString passw){
    this->password=passw;
}

Gender User::getGender(){
    return gender;
}

void User::setGender(Gender gender) {
    this->gender = gender;
}

void User::addAddress(Address address){
    if(this->addressVector.size()<4){
        addressVector.push_back(address);
    }
}

Address User::getAddressByName(QString name){
    for(int i=0;i<addressVector.size();i++){
        if(addressVector[i].getName()==name){
            return addressVector[i];
        }

    }
    return Address();//eğer bulamazsa default constructor döndürüyor
}

void User::deleteAddressByName(QString name) {
    for (int i = 0; i < addressVector.size(); i++) {
        if (addressVector[i].getName() == name) {
            // If the name matches, erase the address from the vector
            addressVector.erase(addressVector.begin() + i);
            return; // Return after deletion to avoid continuing the loop unnecessarily
        }
    }
}

void User::on_logOutButton_clicked()
{
    this->hide();
    FirstScreen::user=nullptr;
    FirstScreen f;
    f.setModal(true);
    f.exec();
}

Wallet* User::getWallet() const
{
    return wallet;
}
/*void User::createWallet(){
    wallet=new Wallet();
}
*/
void User::on_mainMenuButton_clicked()
{
    this->hide();
    FirstScreen f;
    f.setModal(true);
    f.exec();
}

bool User:: favoriteOrNot(MarketProduct product) {
    // Use std::find to check if item exists in favorites vector
    qDebug()<<"favori or not ksımıa girdi";
    return std::find(favorites.begin(), favorites.end(), product) != favorites.end();
}

void User::addFavorite(MarketProduct product) {
    if (!favoriteOrNot(product)) {  // check if the item is not already a favorite
        favorites.push_back(product);
        qDebug()<<"favorilere pushladı";
    }
}
void User::deleteFavorite(MarketProduct product){
    if (favoriteOrNot(product)){
        auto it = std::find(favorites.begin(), favorites.end(), product);
        if (it != favorites.end()) {
            favorites.erase(it);
        }
    }
}

const std::vector<MarketProduct>& User:: getFavorites() const {
    return favorites;
}

void User::addIdAmount(int id, int amount)
{

    if (idAmountMap.contains(id)) {
        // Key exists, add the amount to the existing amount
        idAmountMap[id] += amount;
    } else {
        // Key doesn't exist, add a new key-value pair
        idAmountMap.insert(id, amount);
    }



}

void User::deleteIdAmount(int id, int amount)
{

}

void User::updateIdAmount(int id, int amount)
{
    if (idAmountMap.contains(id)) {
        // Key exists, add the amount to the existing amount
        idAmountMap[id] = amount;
    }
}







