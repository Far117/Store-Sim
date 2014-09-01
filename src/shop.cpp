#include "shop.h"
#include "item.h"

using namespace std;

shop::shop()
{
    //ctor
}

shop::~shop()
{
    //dtor
}

void shop::order(int id, int amount){
    vector<item> all=getItems();
    for (int x=0; x<amount; x++){
        if (stock<storage){
            item clone=all[id];
            inventory.push_back(clone);
            stock++;
            money-=clone.buyPrice;
        } else {
            cout << "You didn't have enough space for the delivery person! An item was returned..." << endl;
        }
    }
}

void shop::adjust(int id, float newPrice){
    vector<item> items=getItems();
    string name=items[id].name;

    adjustItem(id,newPrice);

    for(int x=0;x<inventory.size();x++){
        if (inventory[x].name==name){
            inventory[x].price=newPrice;
        }
    }

    return;
}

bool shop::sell(string name){
    for (int x=0;x<inventory.size();x++){
        if (name==inventory[x].name){
            cout << "Sold " << name << "!" << endl;
            money+=inventory[x].price;
            inventory.erase(inventory.begin()+x);
            stock--;
            return true;
        }
    }

    return false;
}
