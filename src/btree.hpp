#pragma once
#include <iostream>
#include "object.hpp"
using namespace std;

class BTree {
public:

private:
    BTree *left;
    BTree *right;
    int count;
    object *o;
};