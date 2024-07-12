#ifndef CREATINGMARKET_H
#define CREATINGMARKET_H

#include "market.h"
#include <QList>

class CreatingMarket
{
private:


public:

    CreatingMarket();

    static QList<Market> existingMarkets;
    //QList<Market> existingMarkets;
    static Category fruitCategory;
    static Category vegetableCategory;



    void createMarketA();
    void createMarketB();
    void createMarketC();
    void createMarketD();
    static MarketProduct getMarketProductById(int);
    static int getCostById(int);


};

#endif // CREATINGMARKET_H
