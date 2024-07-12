#ifndef USER_H
#define USER_H

#include <QDialog>
#include <QString>
#include "Gender.h"
#include "address.h"
#include "wallet.h"
#include "firstscreen.h"
#include "favorite.h"
#include "marketproduct.h"
#include <QDebug>

class Wallet;// Forward declaration
class Favorite; // Forward declaration

namespace Ui {
class User;
}

class User : public QDialog
{
    Q_OBJECT

private:
    int id;
    int age;
    QString name;
    QString surname;
    QString email;
    QString phoneNumber;
    QString password;
    Gender gender;
    //int currentBalance;
    std::vector<Address> addressVector;
    Wallet *wallet;
    //std::vector<Favorite> favorites;
    //std::vector<QString> favorites;
    std::vector<MarketProduct> favorites;

    QMap<int,int> idAmountMap;// ilki id,ikincisi amount

public:
    explicit User(QWidget *parent = nullptr);

    ~User();

    int getId();
    void setId(int);
    int getAge();
    void setAge(int);
    QString getName();
    void setName(QString);
    QString getSurname() ;
    void setSurname(QString);
    QString getEmail() ;
    void setEmail(QString);
    QString getPhoneNumber();
    void setPhoneNumber(QString);
    QString getPassword();
    void setPassword(QString);
   /* void setCurrentMoneyforUser(int);
    int getCurrentMoneyForUser();*/

    Gender getGender();
    void setGender(Gender);

    void addAddress(Address);
    Address getAddressByName(QString);
    void deleteAddressByName(QString);

    Wallet* getWallet() const;
    //void createWallet();
    //Wallet updateWallet(int);
    void showInfo(User*);

    bool favoriteOrNot(MarketProduct);
    void addFavorite(MarketProduct);
    void deleteFavorite(MarketProduct);
    const std::vector<MarketProduct>& getFavorites() const;

    void addIdAmount(int,int);
    void deleteIdAmount(int,int);

    void updateIdAmount(int,int);


    QMap<int, int> getIdAmountMap() const;
    void clearIdAmountMap();//sepeti bosaltmak icin


private slots:
    void on_logOutButton_clicked();

  //  void on_mainMenuButton_clicked();

    void on_mainMenuButton_clicked();

private:
    Ui::User *ui;
};

#endif // USER_H
