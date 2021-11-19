#include <iostream>
#include "Integer.hpp"
using namespace std;

int main() {
    // ++, +, 

    object *i = new Integer(234);
    object *j = new Integer(234);
    i = (Integer *) i++;
    // char *res = "232";
    // i->loadFromString(res);
    // char *t = i->uploadInString();
    //ifstream f("qwerty.txt");
    //i->writeInTxt(f);
    //i->readFromTxt(f);
    char *res = i->uploadInString();
    cout << res;
    return 0;
}
