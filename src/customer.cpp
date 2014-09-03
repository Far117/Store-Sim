#include <vector>
#include <cmath>
#include <cstdlib>

#include "customer.h"
#include "item.h"

using namespace std;

customer::customer()
{
    //ctor
}

customer::~customer()
{
    //dtor
}

void customer::clean(){
    money = floor(money*100+0.5)/100;
}

void customer::setList(){
    vector<item> items=getItems();
    int limit;

    if (rand() % 2 == 0){
        limit=10;
    }else if (rand() %2 == 0){
        limit=25;
    }else if (rand() % 2 == 0){
        limit=50;
    }else{
        limit=100;
    }

    for(int x=0;x<(rand() % limit)+1;x++){
        shoppingList.push_back(items[rand() %items.size()]);
    }

    return;
}

void customer::setup(){
    name="Joe Flo";
    setList();

    for(int x=0;x<shoppingList.size();x++){
        money+=shoppingList[x].price;
    }

    money+=money*(float)(rand() % 10 + 1) / 100;

    clean();
}

bool customer::wantsToBuy(item thing){
    float overPay=(thing.price-thing.buyPrice);
    overPay/=thing.price;
    overPay*=100;

    int tolerance=rand()%90+11;
    if((float)overPay>tolerance){
        return false;
    }else{
        cout << name << " thought " << thing.name << " was too expensive." << endl;
        return true;
    }
}
