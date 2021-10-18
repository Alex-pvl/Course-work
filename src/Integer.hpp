#pragma once
#include <iostream>
#include <string>
#include "object.hpp"

class Integer : public object {
public:
    Integer(int value=0) {
        this->setValue(value);
    }

    int getValue() {
        return this->value;
    }

    void setValue(int value) {
        this->value = value;
    }

    // перевод строки в число
    void loadFromString(const char *str) override {
        
    }

    // перевод числа в строку
    char* uploadInString() override {
        
    }

    char* getName() override {
        char *i_name = new char[7];
        strcpy(i_name, "Integer");
        return i_name;
    }

    ~Integer() {
        free(this);
    }

private:
    int value;
};

int getSize(int n) {
    int size = 0, val = n;
    while (val > 0) {
        size++;
        val /= 10;
    }
    return size;
}