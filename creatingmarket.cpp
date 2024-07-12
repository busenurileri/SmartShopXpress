#include "creatingmarket.h"
#include <QDebug>

Category CreatingMarket::fruitCategory("Fruits", 1); //when the category ID matches the product IDs, they can be associated.
Category CreatingMarket::vegetableCategory("Vegetables", 2); //when the category ID matches the product IDs, they can be associated.



CreatingMarket::CreatingMarket() {
//it is your responsibility to add the markets you create to existingMarkets. otherwise your market will not be shown in the app
    qDebug() << "start constructor";
    createMarketA();
    createMarketB();
    createMarketC();
    createMarketD();
    qDebug() << "finish constructor";


}

QList<Market> CreatingMarket::existingMarkets;

void CreatingMarket::createMarketA(){
 qDebug() << "start create market A";
    // Create products
    Product apple("Apple", fruitCategory.getId(), 5);
    Product pear("Pear", fruitCategory.getId(), 4);
    Product banana("Banana", fruitCategory.getId(), 6);
    Product orange("Orange", fruitCategory.getId(), 3);
    Product strawberry("Strawberry", fruitCategory.getId(), 8);
    Product grape("Grape", fruitCategory.getId(), 10);
    Product pineapple("Pineapple", fruitCategory.getId(), 12);
    // Create market products
    MarketProduct appleProduct(apple, 100);
    MarketProduct pearProduct(pear, 50);
    MarketProduct bananaProduct(banana, 75);
    MarketProduct orangeProduct(orange, 30);
    MarketProduct strawberryProduct(strawberry, 20);
    MarketProduct grapeProduct(grape, 40);
    MarketProduct pineappleProduct(pineapple, 15);
    qDebug() << "start fruit product list";
    // Create a market object
    QList<MarketProduct> fruitProductList;
    fruitProductList << appleProduct << pearProduct << bananaProduct << orangeProduct << strawberryProduct << grapeProduct << pineappleProduct;
    Product carrot("Carrot", vegetableCategory.getId(), 3);
    Product tomato("Tomato", vegetableCategory.getId(), 6);
    Product cucumber("Cucumber", vegetableCategory.getId(), 3);
    Product potato("Potato", vegetableCategory.getId(), 4);
    Product onion("Onion", vegetableCategory.getId(), 2);
    Product pepper("Pepper", vegetableCategory.getId(), 4);
    Product lettuce("Lettuce", vegetableCategory.getId(), 5);

    // Create market products for vegetables
    MarketProduct carrotProduct(carrot, 80);
    MarketProduct tomatoProduct(tomato, 60);
    MarketProduct cucumberProduct(cucumber, 70);
    MarketProduct potatoProduct(potato, 100);
    MarketProduct onionProduct(onion, 90);
    MarketProduct pepperProduct(pepper, 50);
    MarketProduct lettuceProduct(lettuce, 40);

    // Create a market object for vegetables
    QList<MarketProduct> vegetableProductList;
    vegetableProductList << carrotProduct << tomatoProduct << cucumberProduct << potatoProduct << onionProduct << pepperProduct << lettuceProduct;
    qDebug() << "start product list";
    QList<MarketProduct> productList = fruitProductList + vegetableProductList;
    Market marketA("MarketA", productList);

    /*    BuySomethingScreen ekranı her oluşturulduğunda CreatingMarket creatingMarketObject; objesi tekrar oluşuyor ve
     *    existingMarkets vektorune tekrar bu marketleri ekliyor. aynı marketlerin eklenmesini onlemek icin asagisaki kontrol eklendi.
     * */
    if (!existingMarkets.contains(marketA)) {
        existingMarkets << marketA;
        qDebug() << "finish creating market a";
    }


}

void CreatingMarket::createMarketB(){
    Product apple("Apple", fruitCategory.getId(), 7);
    Product pear("Pear", fruitCategory.getId(), 6);
    Product banana("Banana", fruitCategory.getId(), 10);
    Product orange("Orange", fruitCategory.getId(), 4);
    Product strawberry("Strawberry", fruitCategory.getId(), 5);

    MarketProduct appleProduct(apple, 50);
    MarketProduct pearProduct(pear, 25);
    MarketProduct bananaProduct(banana, 50);
    MarketProduct orangeProduct(orange, 50);
    MarketProduct strawberryProduct(strawberry, 50);

    QList<MarketProduct> fruitProductList;
    fruitProductList << appleProduct << pearProduct << bananaProduct << orangeProduct << strawberryProduct;

    Product tomato("Tomato", vegetableCategory.getId(), 6);
    Product cucumber("Cucumber", vegetableCategory.getId(), 3);
    Product potato("Potato", vegetableCategory.getId(), 4);
    Product pepper("Pepper", vegetableCategory.getId(), 4);

    MarketProduct tomatoProduct(tomato, 60);
    MarketProduct cucumberProduct(cucumber, 70);
    MarketProduct potatoProduct(potato, 100);
    MarketProduct pepperProduct(pepper, 50);

    QList<MarketProduct> vegetableProductList;
    vegetableProductList << tomatoProduct << cucumberProduct << potatoProduct << pepperProduct;

    QList<MarketProduct> productList = fruitProductList + vegetableProductList;
    Market marketB("MarketB", productList);
    if (!existingMarkets.contains(marketB)) {
        existingMarkets << marketB;
    }

}

void CreatingMarket::createMarketC(){
    Product banana("Banana", fruitCategory.getId(), 8);
    Product orange("Orange", fruitCategory.getId(), 5);
    Product strawberry("Strawberry", fruitCategory.getId(), 10);
    Product kiwi("Kiwi", fruitCategory.getId(), 12);
    Product watermelon("Watermelon", fruitCategory.getId(), 15);

    MarketProduct bananaProduct(banana, 30);
    MarketProduct orangeProduct(orange, 40);
    MarketProduct strawberryProduct(strawberry, 50);
    MarketProduct kiwiProduct(kiwi, 4);
    MarketProduct watermelonProduct(watermelon, 25);

    QList<MarketProduct> fruitProductList;
    fruitProductList <<bananaProduct << orangeProduct << strawberryProduct<<kiwiProduct<<watermelonProduct;

    Product tomato("Tomato", vegetableCategory.getId(), 5);
    Product cucumber("Cucumber", vegetableCategory.getId(), 4);
    Product potato("Potato", vegetableCategory.getId(), 3);
    Product pepper("Pepper", vegetableCategory.getId(), 2);
    Product radish("Radish", vegetableCategory.getId(), 3);
    Product eggplant("Eggplant", vegetableCategory.getId(), 8);

    MarketProduct tomatoProduct(tomato, 60);
    MarketProduct cucumberProduct(cucumber, 70);
    MarketProduct potatoProduct(potato, 100);
    MarketProduct pepperProduct(pepper, 50);
    MarketProduct radishProduct(radish, 70);
    MarketProduct eggplantProduct(eggplant, 45);

    QList<MarketProduct> vegetableProductList;
    vegetableProductList << tomatoProduct << cucumberProduct << potatoProduct << pepperProduct<<radishProduct<<eggplantProduct;

    QList<MarketProduct> productList = fruitProductList + vegetableProductList;
    Market marketC("MarketC", productList);
    if (!existingMarkets.contains(marketC)) {
        existingMarkets << marketC;
    }

}

void CreatingMarket::createMarketD(){
    Product banana("Banana", fruitCategory.getId(), 10);
    Product orange("Orange", fruitCategory.getId(), 4);
    Product strawberry("Strawberry", fruitCategory.getId(), 5);
    Product watermelon("Watermelon", fruitCategory.getId(), 15);
    Product cherry("Cherry", fruitCategory.getId(), 9);
    Product blackberry("Blackberry", fruitCategory.getId(), 10);

    MarketProduct bananaProduct(banana, 50);
    MarketProduct orangeProduct(orange, 50);
    MarketProduct strawberryProduct(strawberry, 50);
    MarketProduct watermelonProduct(watermelon, 25);
    MarketProduct cherryProduct(cherry, 25);
    MarketProduct blackberryProduct(blackberry, 30);

    QList<MarketProduct> fruitProductList;
    fruitProductList <<bananaProduct << orangeProduct << strawberryProduct<<watermelonProduct<<cherryProduct<<blackberryProduct;

    Product tomato("Tomato", vegetableCategory.getId(), 6);
    Product cucumber("Cucumber", vegetableCategory.getId(), 3);
    Product potato("Potato", vegetableCategory.getId(), 4);
    Product pepper("Pepper", vegetableCategory.getId(), 4);
    Product radish("Radish", vegetableCategory.getId(), 2);
    Product eggplant("Eggplant", vegetableCategory.getId(), 6);

    MarketProduct tomatoProduct(tomato, 60);
    MarketProduct cucumberProduct(cucumber, 70);
    MarketProduct potatoProduct(potato, 100);
    MarketProduct pepperProduct(pepper, 50);
    MarketProduct radishProduct(radish, 7);

    QList<MarketProduct> vegetableProductList;
    vegetableProductList << tomatoProduct << cucumberProduct << potatoProduct << pepperProduct<<radishProduct;

    QList<MarketProduct> productList = fruitProductList + vegetableProductList;
    Market marketD("MarketD", productList);
    if (!existingMarkets.contains(marketD)) {
        existingMarkets << marketD;
    }

}


MarketProduct CreatingMarket::getMarketProductById(int id)
{
    int marketCount=CreatingMarket::existingMarkets.size();
    for (int i = 0; i < marketCount; i++) {

        for (int j = 0; j < CreatingMarket::existingMarkets[i].getMarketProductList().size(); j++) {
            MarketProduct& product = CreatingMarket::existingMarkets[i].getMarketProductList()[j];

            if (product.getId()==id) {
                return product;
            }
        }
    }
}

int CreatingMarket::getCostById(int id)
{
    return getMarketProductById(id).getProduct().getPrice();
}
