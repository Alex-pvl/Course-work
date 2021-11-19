#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include "math.h"
#include "object.hpp"
using namespace std;

// для записи в строку
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
    Integer(int value);

    int getValue();
    void setValue(int value);

    // перевод строки в число
    object* loadFromString(char*);
    // перевод числа в строку
    char* uploadInString();
    // получение имени класса
    char* getName();
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

    Integer& operator=(const Integer&);
    Integer operator+(const Integer&);
    friend Integer operator-(const Integer&, const Integer&);

    Integer& operator++();
    Integer operator++(int);

    friend ostream& operator<<(ostream&, Integer&);
	friend istream& operator>>(istream&, Integer&);
	friend ofstream& operator<<(ofstream&, Integer&);
	friend ifstream& operator>>(ifstream&, Integer&);

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
    int r = 0;
    int n = strlen(str)-1;
    for (int i = 0; i < strlen(str); i++) {
        r += (str[i] - '0') * pow(10, n);
        n--;
    }
    object* res = new Integer(r);
    return res;
}

char* Integer::uploadInString() {
    int n = getSize(this->getValue());
    char* str = new char[n];
    sprintf(str, "%d", this->getValue());
    return str;
}

char* Integer::getName() {
    char *i_name = new char[7];
    strcpy(i_name, "Integer");
    return i_name;
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
    object* res = new Integer(0);
    int sum = ((Integer*) o1)->getValue() + ((Integer*) o2)->getValue();
    ((Integer*) res)->setValue(sum);
    return res;
}

object* Integer::makeCopy(object* o) {
    int newVal = ((Integer*) o)->getValue();
    return new Integer(newVal);;
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

Integer Integer::operator++(int) {
    Integer temp = *this;
    ++*this;
    return temp;
}

Integer operator-(const Integer& first, const Integer& second) {
    Integer res;
    res.value = first.value - second.value;
    return res;
}

ostream& operator<<(ostream& os, Integer& n) {
	os << n.value;
	return os;
}

istream& operator>>(istream& is, Integer& n) {
	is >> n.value;
	return is;
}

ofstream& operator<<(ofstream& os, Integer& n) {
	os << &n.value;
	return os;
}

ifstream& operator>>(ifstream& is, Integer& n) {
	is >> n.value;
	return is;
}

Integer::~Integer() {
    this->value = 0;
}