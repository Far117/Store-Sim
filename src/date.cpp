#include <iostream>
#include <sstream>

#include "date.h"

using namespace std;

date::date(){
    day=1;
    month=1;
    year=2010;
}

void date::check(){
    if (day>31){
        day=1;
        month++;
    } else if(month==9 && day>30){
        month++;
        day=1;
    } else if (month==4 && day>30){
        month++;
        day=1;
    } else if (month==6 && day>30){
        month++;
        day=1;
    } else if (month==11 && day>30){
        month++;
        day=1;
    } else if (month==2 && day>28 && (year%4!=0)){
        month++;
        day=1;
    } else if (month ==2 && day>29){
        month++;
        day=1;
    }

    if (month>12){
        year++;
        month=1;
    }
}

void date::passDay(){
    day++;
    check();
}

void date::passWeek(){
    for(int x=0;x<7;x++){
        passDay();
    }
}

void date::passMonth(){
    for(int x=0;x<4;x++){
        passWeek();
    }
}

void date::passYear(){
    for(int x=0;x<12;x++){
        passMonth();
    }
}

string date::getDate(){
    stringstream temp;
    temp << month << "/" << day << "/" << year;

    return temp.str();
}
