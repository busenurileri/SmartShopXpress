#include "market.h"



Market::Market(QString name, QList<MarketProduct> productList)
{
    this->name=name;
    this->marketProductList=productList;
}

QString Market::getName() const
{
    return name;
}

void Market::setName(const QString &newName)
{
    name = newName;
}

QList<MarketProduct> Market::getMarketProductList() const
{
    return marketProductList;
}

void Market::setMarketProductList(const QList<MarketProduct> &newMarketProductList)
{
    marketProductList = newMarketProductList;
}

bool Market:: operator==(const Market& other) const {
    // Compare the attributes of the Market objects
    // Return true if they are equal, false otherwise
    return (this->getName() == other.getName()); // Assuming getName() returns the name of the Market
}
