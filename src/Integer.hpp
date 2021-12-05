#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include "math.h"
#include "object.hpp"
using namespace std;

// длина числа
int getSize(int n) {
    int size = 0, val = n;
    while (val > 0) {
        size++;
        val /= 10;
    }
    return size;
}

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
    int equals(object*);
    // сумма объектов
    object* unionObj(object*, object*);
    // создание копии объекта
    object* makeCopy(object*);
    // запись объекта в бинарный файл
    void writeInBinary(ofstream&);
    // чтение объекта из бинарного файла
    void readFromBinary(ifstream&);
    // запись объекта в текстовый файл
    void writeInTxt(ofstream&);
    // чтение объекта из текстового файла
    void readFromTxt(ifstream&);
    // ввод числа с клавиатуры
    void getObject();

    Integer& operator=(const Integer&);
    Integer operator+(const Integer&);
    friend Integer operator-(const Integer&, const Integer&);

    Integer& operator++();
    Integer& operator--();

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

void Integer::setValue(int value) {
    this->value = value;
}

object* Integer::loadFromString(char *str) {
    this->value = atoi(str);
    return this;
}

string Integer::uploadInString() {
    return to_string(this->value);
}

string Integer::getName() {
    return "Integer";
}

int Integer::getId() {
    return 1;
}

int Integer::equals(object* o) {
    if (this->value > ((Integer*) o)->value) return 1;
    else if (this->value < ((Integer*) o)->value) return -1;
    else return 0;
}

object* Integer::unionObj(object* o1, object* o2) {
	this->value += ((Integer*)o1)->value;
	this->value += ((Integer*)o2)->value;
	return this;
}

object* Integer::makeCopy(object* o) {
    this->value = ((Integer*) o)->value;
    return this;
}

void Integer::writeInBinary(ofstream& fout) {
    int id = getId();
    fout.write((char*)&id, sizeof(int));
    fout.write((char*)&value, sizeof(int));
}
    
void Integer::readFromBinary(ifstream& fin) {
    int id;
    fin.read((char*)&id, sizeof(int));
    fin.read((char*)&value, sizeof(int));
}

void Integer::writeInTxt(ofstream& fout) {
    int id = getId();
    fout << id << " ";
    fout << this->getValue();
}

void Integer::readFromTxt(ifstream& fin) {
    int id, n;
    fin >> id >> n;
    this->setValue(n);
}

void Integer::getObject() {
    cin >> this->value;
}

Integer& Integer::operator=(const Integer& n) {
    this->value = n.value;
    return *this;
}

Integer Integer::operator+(const Integer& n) {
    Integer res;
    res.value = this->value + n.value;
    return res;
}

Integer& Integer::operator++() {
    this->value = this->value + 1;
    return *this;
}

Integer& Integer::operator--() {
    this->value = this->value - 1;
    return *this;
}

Integer operator-(const Integer& first, const Integer& second) {
    Integer res;
    res.value = first.value - second.value;
    return res;
}

ostream& operator<<(ostream& os, Integer& i) {
    os << i.value;
    return os;
}

istream& operator>>(istream& is, Integer& i) {
    is >> i.value;
    return is;
}

Integer::~Integer() {
    this->value = 0;
}