#include <iostream>
#include <time.h>
#include <cstdlib>

#include "functions.h"
#include "shop.h"
#include "date.h"
#include "item.h"
#include "customer.h"
#include "save.h"

using namespace std;

static shop store;
static date calender;

struct info {
    int patch=0;
    float version=0.2;
    string name="Public Alpha";
};

//=================

void loop();
void computer();
void order();
void hire();
void adjust();
void report();

//=================
void splash(){
    info inf;

    cout << "           Store Sim v. " << inf.name << " " << inf.version << " patch #" << inf.patch << endl;
    enter();
}

void story(){
    clear_screen();
    cout << "Work...";
    scroll();
    cout << "Lots of work...";
    scroll();
    cout << "After years of having a desk job, you finally save up enough capitol";
    scroll();
    cout << "Now you can open up your own business, and make others work!";
    scroll();
    cout << "...";
    scroll();
    cout << "1 year later...";
    scroll();
    cout << "Your business, " << store.name << ", is completed...";
    scroll();
    cout << "However, you only have $" << store.money << " left in your account!";
    scroll();
    cout << "And no stock whatsoever!!!";
    scroll();
    cout << "How will you start off this one?";
    scroll();
    scroll();
    scroll();
    enter();
    loop();
}

void newgame(){

    store.owner=inputS("What is your name?\n: ");
    store.name=inputS("What would you like to name your store?\n: ");

    story();
    loop();
}

void loop(){
    computer();
    clear_screen();
    float todaysMoney=0;
    int sold=0;
    int possibleSold=0;
    float possibleMoney=0;
    int rejected=0;

    cout << "Beginning " << calender.getDate() << "..." << endl;

    int customersToday=(rand() % (store.cashRegisters*50))+1;

    vector<customer> customers;

    for (int x=0;x<customersToday;x++){
        customer c;
        c.setup();
        customers.push_back(c);
    }

    for (int x=0;x<customers.size();x++){
        for(int z=0;z<customers[x].shoppingList.size();z++){
            possibleSold++;
            possibleMoney+=customers[x].shoppingList[z].price;
            if (store.has(customers[x].shoppingList[z].name)){
                if (customers[x].wantsToBuy(customers[x].shoppingList[z])){
                    if (store.sell(customers[x].shoppingList[z].name)){
                            todaysMoney+=customers[x].shoppingList[z].price;

                            customers[x].money-=customers[x].shoppingList[z].price;
                            cout << customers[x].name << " bought " << customers[x].shoppingList[z].name << endl;
                            customers[x].shoppingList.erase(customers[x].shoppingList.begin()+z);

                            sold++;
                    }
                } else {
                    rejected++;
                }
            }
        }
    }

    cout << "\n\n\nEnd of " << calender.getDate() << endl;
    enter();
    clear_screen();
    cout << "Today's Report:\n\n" << endl;
    cout << "Money Made: $" << todaysMoney << endl;
    cout << "Customers Entered: " << customersToday << endl;
    cout << "Items Sold: " << sold << endl;
    cout << "Items Rejected: " << rejected << endl;
    cout << "\nTotal Items Requested: " << possibleSold << endl;
    cout << "Possible Money: $" << possibleMoney << "\n" << endl;

    enter();

    calender.passDay();
    loop();
}

void computer(){
    clear_screen();
    string choice;
    cout << calender.getDate() << ", 6:00 AM\n" << endl;
    cout << "Welcome to S.H.O.P.S: Super Heavy OPeration System!" << endl;
    choice=inputS("\n|\n|\n|\nEnter a command: ");

    if (lower(choice)=="help" || lower(choice) == "?"){
        cout << "Valid Operations: \n|" << endl;
        cout << "| Order: Buy some new stock" << endl;
        //cout << "Hire: Find some new employees" << endl;
        //cout << "Fire: Get rid of some employees" << endl;
        cout << "| Set: Adjust the pricing of your stock" << endl;
        cout << "| Start: Begins the next day" << endl;
        cout << "| Report: View your records" << endl;
        cout << "| Save: Save your game\n" << endl;
        enter();
    } else if (lower(choice)=="order"){
        order();
    } else if (lower(choice)=="hire"){
        hire();
    } else if (lower(choice)=="set"){
        adjust();
    } else if (lower(choice)=="start"){
        return;
    } else if (lower(choice)=="report"){
        report();
    } else if (lower(choice)=="save"){
        save(store);
        enter();
    }

    computer();
}

void order(){
    clear_screen();
    int choice;
    int choice2;

    cout << "Which item do you want to order? Currently available is: \n| ";

    vector<item> items;
    items=getItems();

    for(int x=0; x<items.size();x++){
        cout << items[x].name << ": $" << items[x].buyPrice << " (ID: " << x << ")\n| ";
    }

    do {
        cout << "\n\nEnter the ID of the item you would like (you have $" << store.money;
        choice=inputI(")?\n: ");
    } while (choice>items.size() || choice <0);

    clear_screen();

    do {
        cout << "\n\nHow many (each is $" << items[choice].buyPrice;
        choice2=inputI(")?\n: ");
    } while (choice2*items[choice].buyPrice>store.money);

    //store.money-=items[choice].buyPrice*choice2;
    store.order(choice,choice2);

    clear_screen();
    cout << "Order Processed! You now have $" << store.money << "." << endl;
    enter();

    return;
}

void hire(){
    ;
}

void adjust(){
    clear_screen();
    vector<item> items=getItems();

    cout << "Which item would you like to adjust the price for?";

    for (int x=0;x<items.size();x++){
        cout << "\n| " << items[x].name << "(ID " << x << ":\n|    MSRP: $"
             << items[x].price << "\n|    Cost: $" << items[x].buyPrice;
    }

    int choice;
    do{
        choice=inputI("Enter the ID of the item you would like to adjust: ");
    } while (choice>items.size() || choice < 0);

    clear_screen();

    float choice2=inputF("Enter the new price of the item: $");

    cout << "Updating data..." << endl;
    store.adjust(choice,choice2);
    cout << "Done!" << endl;

    enter();
    return;
}

void report(){
    clear_screen();

    cout << "\t\t\t\t\t" << store.name << "(R):\n" << endl;
    cout << "| Current Balance: $" << store.money << endl;
    cout << "| Total Storage Space: " << store.stock << "/" << store.storage << endl;
    cout << "| StoreScore (R): " << store.score << "\n" << endl;

    enter();
    return;
}

void init(){
    srand(time(NULL));

    initItems();
}

int main(){
    clear_screen();
    splash();
    init();
    clear_screen();

    make("bin");
    clear_screen();
    if (!exists("bin/store.sav")){
        newgame();
    }else {
        cout << "Load your old game or start a new one?" << endl;
        if(lower(inputS(": "))=="new"){
            newgame();
        }else{
            store=load();
            loop();
        }
    }

    return 0;
}
