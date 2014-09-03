#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>


#include "save.h"
#include "functions.h"

using namespace std;

void saveInventory(shop s){
    cout << "Saving Stock Data..." << endl;
    ofstream out("bin/inventory.dat");

    for(int x=0;x<s.inventory.size();x++){
        out << s.inventory[x].name << "\n";
    }

    out.close();

    out.open("bin/prices.dat");

    vector<string> done;
    bool write=true;

    for(int x=0;x<s.inventory.size();x++){
        write=true;

        for(int z=0;z<done.size();z++){
            if(s.inventory[x].name==done[z]){
                write=false;
            }
        }

        if(write){
            out << s.inventory[x].name << "\n";
            out << s.inventory[x].price << "\n";
        }
    }

    return;
}

void save(shop s){
    clear_screen();

    cout << "Saving Accounts..." << endl;
    ofstream out("bin/shop.sav");

    out << s.name << "\n";
    out << s.owner << "\n";
    out << s.money << "\n";
    out << s.storage << "\n";
    out << s.stock << "\n";
    out << s.score << "\n";
    out << s.cashRegisters << "\n";
    out << s.cashiers << "\n";
    out << s.janitors << "\n";
    out << s.guards << "\n";

    out.close();

    saveInventory(s);

    cout << "Done!" << endl;
    return;
}

shop load(){
    shop s;

    ifstream in("bin/store.sav");
    string temp;
    vector<string> lines;

    while (!in.eof()){
        getline(in,temp);
        lines.push_back(temp);
    }

    in.close();

    s.name=lines[0];
    s.owner=lines[1];
    s.money=atof(lines[2].c_str());
    s.storage=atoi(lines[3].c_str());
    s.stock=atoi(lines[4].c_str());
    s.score=atoi(lines[5].c_str());
    s.cashRegisters=atoi(lines[6].c_str());
    s.cashiers=atoi(lines[7].c_str());
    s.janitors=atoi(lines[8].c_str());
    s.guards=atoi(lines[9].c_str());

    s.inventory=loadInventory();

    //==============================

    in.open("bin/prices.dat");
    lines.clear();

    string temp2;
    //float temp3;
    while(!in.eof()){
        in >> temp;
        in >> temp2;

        //temp3=atof(temp2.c_str());
        s.adjust(temp,atof(temp2.c_str()));
    }

    return s;
}

vector<item> loadInventory(){
    vector<item> inv;
    vector<item> items=getItems();

    string temp;

    ifstream in("bin/inventory.dat");

    while(!in.eof()){
        in >> temp;

        for(int x=0;x<items.size();x++){
            if (items[x].name==temp){
                inv.push_back(items[x]);
                break;
            }
        }
    }

    return inv;
}
