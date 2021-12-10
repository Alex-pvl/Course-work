#include <iostream>
#include "Date.hpp"
#include "Integer.hpp"
#include "btree.hpp"
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
    // object *d1 = new Date(2,2,3,4,6,7);
    // object *d2 = new Date(7,11,1,5,7,4);
    // object *d = new Date;
    
    // object *i = new Date;
    // cin >> *(Date*)i;

    // cout << i;
    // char *res = d->uploadInString();
    // cout << res << endl;
    // object *d2 = new Date;
    // d2->makeCopy(d);
    // char *rr = d2->uploadInString();
    // cout << rr;
    // ((Date*)d1)->incSecond();
    // char *res = d1->uploadInString();
    // cout << res; 

    // cout << "Available commands:" << 
    // "\n-create Binary Tree" << "\n\t-insert new object" << "\n\t\t-new Integer\n\t\t-new Date" << 
    //                              "\n\t-delete by number" <<
    //                              "\n\t-show" << 
    //                              "\n\t-get size" <<
    //                              "\n\t-is empty?" <<
    //                              "\n\t-write to txt file" <<
    //                              "\n\t-write to binary file" <<
    //                              "\n\t-read from txt file" <<
    //                              "\n\t-read from binary file" <<
    // "\n-delete Binary Tree" << 
    // "\n-quite\n";

    // string mode;
    // cin >> mode;

    // if (mode == "help")
    
    Btree bt;
    object* o1 = new Integer(5);
    object *o2 = new Date(1,2,3,4,5,6);
    object *o3 = new Integer(7);
    object *o4 = new Date(1,2,1,5,6,7);
    bt.add(o1);
    bt.add(o2);
    bt.add(o3);
    bt.add(o4);
    
    bt.show();
    //cout << o1->getValueObj() << endl << o2->getValueObj() << endl << o3->getValueObj() << endl << o4->getValueObj();
    
    // object* o2 = new Integer(13);
    // object* o3 = new Integer(9);
    // object* o4 = new Integer(11);
    // object* o5 = new Integer(17);

    // bt->insert(bt, (Integer*)o1);
    // bt->insert(bt, (Integer*)o2);
    // bt->insert(bt, (Integer*)o3);
    // bt->insert(bt, (Integer*)o4);
    

    
    return 0;
}
