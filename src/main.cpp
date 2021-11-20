//#include <iostream>
#include "Date.hpp"
using namespace std;

int main() {
    // object *i = new Integer;
    // object *i1 = new Integer(2);
    // object *i2 = new Integer(3);
    // i->unionObj(i1, i2);
    // char *res = i2->uploadInString();
    // cout << res;
    char *res = new char[19];
    sprintf(res, "%s", "02/11/2222 12:21:23");
    object *d = new Date;
    d->loadFromString(res);
    char *t = d->uploadInString();
    cout << t;
    return 0;
}
