#ifndef MARKET_H
#define MARKET_H
#include "QString"
#include "marketproduct.h"
#include "QList"
class Market
{
public:
    Market(QString,QList<MarketProduct>);
    QString getName() const;
    void setName(const QString &newName);

    QList<MarketProduct> getMarketProductList() const;
    void setMarketProductList(const QList<MarketProduct> &newMarketProductList);
    bool operator==(const Market& other) const;


private:
    QString name;
    QList<MarketProduct> marketProductList;
};

#endif // MARKET_H
