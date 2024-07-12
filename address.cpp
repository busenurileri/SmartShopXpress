#include "address.h"

Address::Address(QString name,QString city,QString street,QString building,int doorNum){

    this->name=name;
    this->city=city;
    this->street=street;
    this->building=building;
    this->doorNum=doorNum;

}
Address::Address(){}

QString Address::getName() const
{
    return name;
}

void Address::setName(const QString &newName)
{
    name = newName;
}

QString Address::getCity() const
{
    return city;
}

void Address::setCity(const QString &newCity)
{
    city = newCity;
}

QString Address::getStreet() const
{
    return street;
}

void Address::setStreet(const QString &newStreet)
{
    street = newStreet;
}

QString Address::getBuilding() const
{
    return building;
}

void Address::setBuilding(const QString &newBuilding)
{
    building = newBuilding;
}

int Address::getDoorNum() const
{
    return doorNum;
}

void Address::setDoorNum(int newDoorNum)
{
    doorNum = newDoorNum;
}

QString Address::getAddressInfo(){

    QString strValue = QString::number(getDoorNum());

    QString str= getName()+" "+getCity()+" "+ getStreet()+" "+getBuilding()+" "+strValue;
    return str;
}
