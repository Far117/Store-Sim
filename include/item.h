#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class item
{
    public:
        item(string,string,float,float);
        virtual ~item();

        std::string name;
        float price;
        std::string category;
        float buyPrice;

    protected:
    private:
};

#endif // ITEM_H
