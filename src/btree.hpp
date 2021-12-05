#pragma once
#include <iostream>
#include "object.hpp"
#include "Integer.hpp"
#include "Date.hpp"
using namespace std;

int equal(object* o1, object* o2) {
    if (((Integer*)o1)->getValue() > ((Date*)o2)->getYear()) return 1;
    else if (((Integer*)o1)->getValue() < ((Date*)o2)->getYear()) return -1;
    else if (((Integer*)o2)->getValue() > ((Date*)o1)->getYear()) return -1;
    else if (((Integer*)o2)->getValue() < ((Date*)o1)->getYear()) return 1;
    else if (((Integer*)o2)->getValue() == ((Date*)o1)->getYear()) return 0;
    else if (((Integer*)o1)->equals((Integer*)o2) < 0) return -1;
    else if (((Integer*)o1)->equals((Integer*)o2) > 0) return 1;
    else if (((Integer*)o1)->equals((Integer*)o2) == 0) return 0;
    else if ((Date*)o1->equals((Date*)o2) < 0) return -1;
    else if ((Date*)o1->equals((Date*)o2) > 0) return 1;
    else if ((Date*)o1->equals((Date*)o2) == 0) return 0;
    else return 0;
}

class Node {
public:
    Node() : o(nullptr), left(nullptr), right(nullptr) {}
    Node(object* obj) : o(obj), left(nullptr), right(nullptr) {}
    ~Node();
    friend class Btree;
private:
    object *o;
    Node *left;
    Node *right;
};

class Btree {
public:
    Btree();
    // вставка
    void insert();
    // удаление
    object* del();
    // вывод структуры
    string show();
    // количество элементов
    int size();
    // проверка на пустоту
    bool empty();
    // поиск объекта
    void search(object*);
    // балансировка
    void balance();
    // запись в текстовый файл
    void writeTxt(ofstream&);
    // чтение из текстового файла
    void readTxt(ifstream&);
    // запись в бинарный файл
    void writeBin(ofstream&);
    // чтение из бинарного файла
    void readBin(ifstream&);
    ~Btree();
private:
    Node *root;
    int count;
};

Btree::Btree() {
    this->root = nullptr;
    this->count = 0;
}

void Btree::insert() {
    string type;
    cout << "Write object's typename: ";
    cin >> type;
    if (type == "Integer") {
        root->o = new Integer;
    } else if (type == "Date") {
        root->o = new Date;
    } else {
        cout << "Invalid typename. Try again.";
        return;
    }
}

object* Btree::del() {
    return nullptr;
}

string Btree::show() {
    return nullptr;
} 

int Btree::size() {
    return this->count;
}

bool Btree::empty() {
    return this->root == nullptr;
}

void search(object* o) {}

void balance() {}

void Btree::writeTxt(ofstream &fout) {
    
}

void Btree::readTxt(ifstream &fin) {
    
}

void Btree::writeBin(ofstream &fout) {
    
}

void Btree::readBin(ifstream &fin) {
    
}