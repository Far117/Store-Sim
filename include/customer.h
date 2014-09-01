#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>

#include "item.h"

class customer
{
    public:
        customer();
        virtual ~customer();

        void clean();
        void setname();
        void setList();
        void setup();


        float money;
        std::string name;
        int happiness;

        std::vector<item> shoppingList;

    protected:
    private:
};

#endif // CUSTOMER_H
