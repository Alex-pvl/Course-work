#pragma once
#include <iostream>
#include <string>
using namespace std;

class object {
public:
    virtual void loadFromString()=0;
    virtual string uploadInString()=0;
    virtual void writeInBinary()=0;
    virtual void readFromBinary()=0;
    virtual int getId()=0;
    virtual char* getName()=0;
    virtual bool isEqual()=0;
    virtual void unionObj()=0;
    virtual void makeCopy()=0;

private:

};