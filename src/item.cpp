#include "item.h"
#include <vector>

using namespace std;

static vector<item> items;

item::item(string n, string c, float p, float b)
{
    name=n;
    category=c;
    price=p;
    buyPrice=b;
}

item::~item()
{
    //dtor
}

item createItem(string name, string category, float price, float buyprice){
    return item(name,category,price,buyprice);
}

void initItems(){
    item genVideo("Generic Videogame","Video Games", 20,15);
    item genFurniture("Generic Furniture","Furniture", 100, 75);
    item genElectronics("Generic Electronic","Electronics",500,450);
    item genFood("Generic Food","Food",5,4);
    item genBooks("Generic Book","Books",10,7);

    items.push_back(genVideo);
    items.push_back(genFurniture);
    items.push_back(genElectronics);
    items.push_back(genFood);
    items.push_back(genBooks);
}

item addItem(string name){
    ;
}

vector<item> getItems(){
    return items;
}

void adjustItem(int id, float price){
    items[id].price=price;
    return;
}
