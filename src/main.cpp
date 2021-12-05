#include <iostream>
#include "Date.hpp"
#include "Integer.hpp"
#include <cstring>
using namespace std;


int main() {
    // object *i = new Integer;
    // object *i1 = new Integer(2);
    // object *i2 = new Integer(3);
    // i->unionObj(i1, i2);
    // char *res = i2->uploadInString();
    // cout << res;
    // char *res = new char[19];
    // sprintf(res, "%s", "02/11/2222 12:21:23");
    // object *d = new Date;
    // d->loadFromString(res);
    // char *t = d->uploadInString();
    // cout << t;
    object *d1 = new Date(2,2,3,4,6,7);
    object *d2 = new Date(7,11,1,5,7,4);
    object *d = new Date;
    
    object *i = new Date;
    cin >> *(Date*)i;

    cout << i;
    // char *res = d->uploadInString();
    // cout << res << endl;
    // object *d2 = new Date;
    // d2->makeCopy(d);
    // char *rr = d2->uploadInString();
    // cout << rr;
    // ((Date*)d1)->incSecond();
    // char *res = d1->uploadInString();
    // cout << res;
    
    return 0;
}
