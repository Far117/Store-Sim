#ifndef DATE_H
#define DATE_H

#include <iostream>

class date
{
public:

    date();

    void passDay();
    void passWeek();
    void passMonth();
    void passYear();

    void check();
    std::string getDate();

    int day;
    int month;
    int year;
};
#endif // DATE_H
