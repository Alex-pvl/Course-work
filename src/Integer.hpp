#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include "math.h"
#include "object.hpp"
using namespace std;

class Integer : public object {
public:
    Integer();
    Integer(int);

    int getValue();
    void setValue(int);

    // перевод строки в число
    object* loadFromString(char*);
    // перевод числа в строку
    string uploadInString();
    // получение имени класса
    string getName();
    // получение идентификатора класса
    int getId();
    // сравнение двух объектов
    int equals(object*, object*);
    // сумма объектов
    object* unionObj(object*, object*);
    // создание копии объекта
    object* makeCopy(object*);
    // запись объекта в бинарный файл
    void writeInBinary(ofstream&);
    // чтение объекта из бинарного файла
    void readFromBinary(ifstream&);
    // ввод числа с клавиатуры
    void getObject();
    // получение ключа для дерева
    int getValueObj();

    Integer& operator=(const Integer&);
    Integer operator+(const Integer&);
    friend Integer operator-(const Integer&, const Integer&);

    friend ostream& operator<<(ostream&, Integer&);
    friend istream& operator>>(istream&, Integer&);

    ~Integer();
private:
    int value;
};

Integer::Integer() {
    this->value = 0;
}

Integer::Integer(int value) {
    this->value = value;
}

int Integer::getValue() {
    return this->value;
}

// получение ключа объекта
int Integer::getValueObj() {
    return this->value;
}

void Integer::setValue(int value) {
    this->value = value;
}

// чтение числа из строки
object* Integer::loadFromString(char *str) {
    this->value = atoi(str);
    return this;
}

// загрузка числа в строку
string Integer::uploadInString() {
    return to_string(this->value);
}

// имя класса
string Integer::getName() {
    return "Integer";
}

// уникальный идентификатор
int Integer::getId() {
    return 1;
}

// сравнение двух целочисленных объектов 
int Integer::equals(object* o1, object* o2) {
    int i1 = ((Integer*)o1)->value, i2 = ((Integer*)o2)->value;
    if (i1 > i2) return 1;
    else if (i1 < i2) return -1;
    else return 0;
}

// сложение двух целых чисел
object* Integer::unionObj(object* o1, object* o2) {
	this->value += ((Integer*)o1)->value;
	this->value += ((Integer*)o2)->value;
	return this;
}

// создание копии числа
object* Integer::makeCopy(object* o) {
    this->setValue(((Integer*) o)->getValue());
    return ((Integer*)this);
}

// запись в бинарный файл
void Integer::writeInBinary(ofstream& fout) {
    fout.write((char*)&value, sizeof(int));
}
    
// чтение из бинарного файла
void Integer::readFromBinary(ifstream& fin) {
    fin.read((char*)&value, sizeof(int));
}

// консольный ввод
void Integer::getObject() {
    cin >> this->value;
}

// оператор присваивания
Integer& Integer::operator=(const Integer& n) {
    this->value = n.value;
    return *this;
}

// оператор сложения
Integer Integer::operator+(const Integer& n) {
    Integer res;
    res.value = this->value + n.value;
    return res;
}

// оператор вычитания
Integer operator-(const Integer& first, const Integer& second) {
    Integer res;
    res.value = first.value - second.value;
    return res;
}

// оператор консольного вывода
ostream& operator<<(ostream& os, Integer& i) {
    os << ((Integer*)&i)->uploadInString();
    return os;
}

// оператор консольного ввода
istream& operator>>(istream& is, Integer& i) {
    is >> i.value;
    return is;
}

Integer::~Integer() {
    delete this;
}