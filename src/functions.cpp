#include <iostream>
#include <time.h>
#include <cstdlib>

#include "functions.h"

using namespace std;

void enter(){
    cout << "Press enter to continue...";
    cin.ignore();
}

string inputS(string x){

    string temp;

    cout << x;
    getline(cin,temp);
    //cout << endl;

    return temp;
}

int inputI(string x){
    int temp;

    cout << x;
    cin >> temp;
    cout << endl;

    cin.clear();
    cin.ignore();
    //getline(cin, temp);
    return temp;
}

float inputF(string x){
    float temp;

    cout << x;
    cin >> temp;
    cout << endl;

    cin.ignore();

    return temp;
}

string lower(string s){ //converts string to lowercase
    for(int j=0;j<s.length();++j){
        s[j]=tolower(s[j]);
    }
    return s;
}

void pause(unsigned int ms){

    //std::this_thread::sleep_for(std::chrono::milliseconds(ms));

    clock_t goal = ms + clock();
    while (goal > clock());

}

void scroll(){
    for(int x=0;x<=3;x++){
        cout << endl;
        pause(1000);
    }
}

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    const bool isWindows=true;
#else
    const bool isWindows=false;
#endif // defined


void clear_screen() {
    if(isWindows){
        system("cls");
    }else{
        system("clear");
    }
    return;
}

void make(string name){
#if isWindows
    _mkdir(name.c_str());
#else
    string path="mkdir "+name;
    system(path.c_str());
#endif
}

bool exists(string name){
    ifstream check(name);
    return check.good();
}
