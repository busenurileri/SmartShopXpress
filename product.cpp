#include "product.h"

Product::Product(const QString &name, int id,int price) : Category(name, id) {
    this->price=price;
}


QString Product::getQuality() const
{
    return quality;
}

void Product::setQuality(const QString &newQuality)
{
    quality = newQuality;
}

int Product::getPrice() const
{
    return price;
}

void Product::setPrice(int newPrice)
{
    price = newPrice;
}
/*
bool operator==(const Product& left, const Product& right) {
    return left.getName() == right.getName() && left.getId() == right.getId();
}
*/
