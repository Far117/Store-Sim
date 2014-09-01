#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <vector>

#include "item.h"


class shop {
    public:
        shop();
        virtual ~shop();

        void order(int,int);
        void adjust(int,float);
        bool sell(std::string);

        float money=1000;
        int storage=100;
        int stock=0;
        int cashRegisters=1;
        int cashiers=0;
        int janitors=0;
        int guards=0;


        std::string name;
        std::string owner;

        std::vector<item> inventory;
    protected:
    private:
};

#endif // SHOP_H
