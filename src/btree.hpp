#pragma once
#include <iostream>
#include "object.hpp"
using namespace std;

class Btree {
public:
    Btree();
    // вставка
    void insert(object*);
    // удаление
    object* del(object*);
    // вывод структуры
    char* show();
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
    class Node {
    public:
        Node();
        Node(object*);
        ~Node();
        friend class BTree;
    private:
        object *o;
        Node *left;
        Node *right;
    };
    
    Node *root;
    int count;
};

Btree::Btree() {
    this->root = nullptr;
    this->count = 0;
}

void Btree::insert(object* o) {}

object* Btree::del(object *o) {
    return nullptr;
}

char* Btree::show() {
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