#pragma once
#include <iostream>
#include <fstream>
#include "object.hpp"
#include "Integer.hpp"
#include "Date.hpp"
using namespace std;

int equal(object* o1, object* o2) {
    if (o1->getValueObj() < o2->getValueObj()) return -1;
    else if (o1->getValueObj() > o2->getValueObj()) return 1;
    else return 0;
}

class Btree;

class Node {
    public:
        Node() {
            o = nullptr;
            left = nullptr;
            right = nullptr;
            count = 0;
        }
        Node(object* obj) {
            o = obj;
            left = nullptr;
            right = nullptr;
            count = 0;
        }
        ~Node() {
            delete o;
            if (left) delete left;
            if (right) delete right;
        }
        friend class Btree;
    private:
        object *o;
        Node *left;
        Node *right;
        int count;
    };

class Btree {
public:
    Btree() {
        root = nullptr;
    }
    // геттер корня узла
    Node* getRoot() {
        return root;
    }
    // геттер левого лепестка
    Node* getLeft(Node* n) {
        return n->left;
    }
    // геттер правого лепестка
    Node* getRight(Node* n) {  
        return n->right;
    }
    // добавление
    bool add(object *obj) {
        Node *n = new Node(obj);
        bool ins;
        if (!n) {
            return false;
        }
        if (((Date*)obj)->getDay() == 1 && ((Date*)obj)->getMonth() == 1 && ((Date*)obj)->getYear() == 1 && 
        ((Date*)obj)->getHour() == 0 && ((Date*)obj)->getMinute() == 0 && ((Date*)obj)->getSecond() == 0) return false;
        root = insertNode(root, n, ins);
        return ins;
    }
    // вставка узла
    Node* insertNode(Node *node, Node *elem, bool &inserted) {
        bool ins;
        if (node == nullptr) {
            inserted = true;
            return elem;
        }
        if (equal(elem->o, node->o) < 0) {
            node->left = insertNode(node->left, elem, ins);
        }
        else if (equal(elem->o, node->o) > 0) {
            node->right = insertNode(node->right, elem, ins);
        }
        else {
            inserted = false;
            return node;
        }
        if (ins) node->count++;
        inserted = ins;
        return node;
    }
    // поиск элемента в дереве
    bool search(object *obj) {
        bool find;
        if (searchNode(root, obj) != nullptr) find = true;
        else find = false;
        return find;
    }
    // поиск узла
    Node *searchNode(Node *node, object *obj) {
        if (node == nullptr) return nullptr;
        if (equal(node->o, obj) == 0) return node;
        else if (equal(node->o, obj) < 0) searchNode(node->left, obj);
        else searchNode(node->right, obj);
        return node;
    }
    // вывод структуры
    void show() {
        showNode(root, 0);
    }
    // вывод узла
    void showNode(Node *t, int level) {
        if (t == nullptr) {
            return;
        }
        showNode(t->right, level+1);
        for (int i = 0; i < 3*level; i++) cout << " ";
        cout << t->o->getValueObj() << "(" << t->o->uploadInString() << ")" << endl;
        showNode(t->left, level+1);
    }
    Node* minValueObj(Node* n) {
        Node *cur = n;
        while (cur && cur->left != nullptr) {
            cur = cur->left;
        }
        return cur;
    }
    // удаление объекта
    bool deleteObj(object* obj) {
        Node *n = new Node(obj);
        bool del;
        if (!n) {
            return false;
        }
        root = deleteNodes(root, n, del);
        return del;
    }
    // удаление узла
    Node* deleteNodes(Node *r, Node *elem, bool &deleted) {
        bool del;
        if (r == nullptr) {
            deleted = false;
            return r;
        }
        if (equal(elem->o, r->o) < 0) {
            r->left = deleteNodes(r->left, elem, del);
            r->count--;
            deleted = del;
        }
        else if (equal(elem->o, r->o) > 0) {
            r->right = deleteNodes(r->right, elem, del);
            r->count--;
            deleted = del;
        }
        else {
            deleted = true;
            if (r->left == nullptr && r->right == nullptr) {
                return nullptr;
            }
            else if (r->left == nullptr) {
                Node *x = r->right;
                r->count--;
                free(r);
                return x;
            }
            else if (r->right == nullptr) {
                Node *x = r->left;
                r->count--;
                free(r);
                return x;
            }
            Node *tmp = minValueObj(r->right);
            r->o = tmp->o;
            r->count--;
            r->right = deleteNodes(r->right, tmp, del);
        }
        return r;
    }
    // запись структуры в бинарный файл для пользователя
    void wrBin() {
        ofstream fout("BinaryTree.dat", ofstream::binary);
        if (!fout.is_open()) cout << "Cannot open file.";
        else {
            cout << "Binary Tree was written in the binary file.\n";
            writeInBinary(fout, root, 0);
        }
    }
    // запись структуры в бинарный файл
    void writeInBinary(ofstream &fout, Node *t, int level) {
        if (t == nullptr) return;
        fout.write((char*)&t, sizeof(Node));
        t->o->writeInBinary(fout);
        writeInBinary(fout, t->left, level+1);
        writeInBinary(fout, t->right, level+1);
    }
    // чтение структуры из бинарного файла для пользоователя
    void rBin() {

    }
    // чтение структуры из бинарного файла 
    void readFromBinary(ifstream& fin) {
        
    }
    // деструктор
    ~Btree() {
        delete root;
    }
private:
    Node *root;
};
