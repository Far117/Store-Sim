#include "item.h"
#include <vector>

static vector<item> items;

item::item(string n, string c, float p)
{
    name=n;
    category=c;
    price=p;
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

}
