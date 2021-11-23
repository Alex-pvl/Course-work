#pragma once
#include <iostream>
using namespace std;

class object {
public:
    object() {}
    // перевод строки в число
    virtual object* loadFromString(char*) = 0;
    // перевод числа в строку
    virtual char* uploadInString() = 0;
    // получение имени класса
    virtual char* getName() = 0;
    // получение идентификатора класса
    virtual int getId() = 0;
    // сравнение двух объектов
    virtual int equals(object*) = 0;
    // сумма объектов
    virtual object* unionObj(object*, object*) = 0;
    // создание копии объекта
    virtual object* makeCopy(object*) = 0;
    // запись объекта в бинарный файл
    virtual void writeInBinary(ofstream&) {}
    // чтение объекта из бинарного файла
    virtual void readFromBinary(ifstream&) {}
    // запись объекта в текстовый файл
    virtual void writeInTxt(ofstream&) {}
    // чтение объекта из текстового файла
    virtual void readFromTxt(ifstream&) {}

    virtual ~object() {}

private:

};
