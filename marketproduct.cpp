#include "marketproduct.h"



MarketProduct::MarketProduct(const class Product &product, int stock) : product(product), stock(stock)
{
    id=count++;
}

int MarketProduct::count=10;


Product MarketProduct::getProduct() const
{
    return product;
}

void MarketProduct::setProduct(const Product &newProduct)
{
    product = newProduct;
}

int MarketProduct::getStock() const
{
    return stock;
}

void MarketProduct::setStock(int newStock)
{
    stock = newStock;
}


QString MarketProduct::getName() const{
    return product.getName();
}

int MarketProduct::getId() const
{
    return id;
}

bool MarketProduct::operator==(const MarketProduct& other) const {
    return id == other.id;
}

