#pragma once
#include <iostream>
#include <string>
using namespace std;

class object {
public:
    object() {}
    // перевод строки в объект
    virtual object* loadFromString(char*) = 0;
    // перевод объекта в строку
    virtual string uploadInString() = 0;
    // получение имени класса
    virtual string getName() = 0;
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
    // ввод объекта с клавиатуры 
    virtual void getObject() = 0;
    ~object() {}
};
