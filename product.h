#ifndef PRODUCT_H
#define PRODUCT_H
#include "category.h"
//#include "QString"
#include <QString>

class Product:public Category
{
public:
    Product(const QString &name,int id,int price);

    QString getQuality() const;
    void setQuality(const QString &newQuality);

    int getPrice() const;
    void setPrice(int newPrice);

   // friend bool operator==(const Product& left, const Product& right);

private:
    QString quality;
    int price;
};

#endif // PRODUCT_H
