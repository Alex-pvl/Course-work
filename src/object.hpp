#pragma once
#include <iostream>
#include <string>
using namespace std;

class object {
public:
    virtual void loadFromString(const char*)=0;               
    virtual char* uploadInString()=0;
    virtual ofstream writeInBinary(ofstream, object)=0;
    virtual ifstream readFromBinary(ifstream, object)=0;
    virtual int getId()=0;
    virtual char* getName()=0;
    virtual bool isEqual(object)=0;
    virtual void unionObj()=0;
    virtual void makeCopy()=0;

private:

};