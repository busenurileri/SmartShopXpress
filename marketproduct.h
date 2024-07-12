#ifndef MARKETPRODUCT_H
#define MARKETPRODUCT_H
#include "product.h"

class MarketProduct
{
public:
    MarketProduct(const Product &product,int);
    Product getProduct() const;
    void setProduct(const Product &newProduct);

    int getStock() const;
    void setStock(int newStock);

    QString getName() const;



    int getId() const;
    bool operator==(const MarketProduct& other) const;


private:
    Product product;
    int stock;
    static int count;
    int id;
};

#endif // MARKETPRODUCT_H
