#ifndef SHOP_H
#define SHOP_H

#include <iostream>


class shop {
    public:
        shop();
        virtual ~shop();

        float money=1000;
        int storage=100;
        int stock=0;


        std::string name;
        std::string owner;
    protected:
    private:
};

#endif // SHOP_H
