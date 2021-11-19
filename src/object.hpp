#pragma once
#include <iostream>
using namespace std;

class object {
public:
    object() {}
    
    virtual object* loadFromString(char*) = 0;               
    virtual char* uploadInString() = 0;
    virtual void writeInBinary(ofstream&) {}
    virtual void readFromBinary(ifstream&) {}
    virtual void writeInTxt(ofstream&) {}
    virtual void readFromTxt(ifstream&) {}
    virtual int getId() = 0;
    virtual char* getName() = 0;
    virtual int equals(object*) = 0;
    virtual object* unionObj(object*, object*) = 0;
    virtual object* makeCopy(object*) = 0;

    virtual ~object() {}

private:

};
