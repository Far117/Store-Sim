#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <vector>

class item
{
    public:
        item(std::string,std::string,float,float);
        virtual ~item();

        std::string name;
        float price;
        std::string category;
        float buyPrice;

    protected:
    private:
};

void adjustItem(int, float);
std::vector<item> getItems();
void initItems();
void addItem();

#endif // ITEM_H
