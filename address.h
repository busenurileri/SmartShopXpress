#ifndef ADDRESS_H
#define ADDRESS_H
#include <QString>


class Address
{
public:
    Address(QString,QString,QString,QString,int);
    Address();
    QString getName() const;
    void setName(const QString &newName);

    QString getCity() const;
    void setCity(const QString &newCity);

    QString getStreet() const;
    void setStreet(const QString &newStreet);

    QString getBuilding() const;
    void setBuilding(const QString &newBuilding);

    int getDoorNum() const;
    void setDoorNum(int newDoorNum);
    QString getAddressInfo();

private:
    QString name;//ev okul gibi başlık için
    QString city;
    QString street;
    QString building;
    int doorNum;




};

#endif // ADDRESS_H
