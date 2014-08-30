#include <iostream>

#include "functions.h"
#include "shop.h"
#include "date.h"

using namespace std;

static shop store;

struct info {
    int patch=0;
    float version=0.0;
    string name="Alpha";
};

//=================

void loop();
void computer();
void order();
void hire();

//=================
void splash(){
    info inf;

    cout << "           Store Sim v. " << inf.name << " " << inf.version << " patch #" << inf.patch << endl;
    enter();
}

void story(){
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
    cout << "However, you only have $" << store.money << "left in your account!";
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

    loop();
}

void loop(){
    clear_screen();

}

void computer(){
    clear_screen();
    string choice;
    cout << "Welcome to S.H.O.P.S: Super Heavy OPeration System!" << endl;
    choice=inputS("\n|\n|\n|\nEnter a command: ");

    if (lower(choice)=="help" || lower(choice) == "?"){
        cout << "Valid Operations: " << endl;
        cout << "Order: Buy some new stock" << endl;
        cout << "Hire: Find some new employees" << endl;
        cout << "Fire: Get rid of some employees" << endl;
        cout << "Set: Adjust the pricing of your stock" << endl;
        cout << "Start: Begins the next day" << endl;
        enter();
    } else if (lower(choice)=="order"){
        order();
    } else if (lower(choice)=="hire"){
        hire();
    }

    computer();
}

void order(){
    ;
}

void hire(){
    ;
}

int main(){
    clear_screen();
    splash();
    clear_screen();

    make("bin");
    if (!exists("bin/store.sav")){
        newgame();
    }

    return 0;
}
