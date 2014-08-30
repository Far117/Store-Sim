#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>

class customer
{
    public:
        customer();
        virtual ~customer();

        void clean();
        void setname();


        float money;
        std::string name;
        int happiness;

    protected:
    private:
};

#endif // CUSTOMER_H
