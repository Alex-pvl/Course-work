#pragma once
#include <iostream>
#include <fstream>
#include "object.hpp"
#include "Integer.hpp"
#include "Date.hpp"
using namespace std;

int equal(object* o1, object* o2) {
    if ((o1->getId() == 1 && o2->getId() == 2) || (o1->getId() == 2 && o2->getId() == 1)) {
        if (o1->getValueObj() < o2->getValueObj()) return -1;
        else if (o1->getValueObj() > o2->getValueObj()) return 1;
        else return 0;
    }
    else return o1->equals(o1,o2);
}

class Btree;

class Node {
    public:
        Node() {
            o = nullptr;
            key = 0;
            left = nullptr;
            right = nullptr;
            count = 0;
        }
        Node(object* obj) {
            o = obj;
            key = obj->getValueObj();
            left = nullptr;
            right = nullptr;
            count = 0;
        }
        friend class Btree;
    private:
        int key;
        object *o;
        Node *left;
        Node *right;
        int count;
    };

class Btree {
public:
    Btree() {
        root = nullptr;
        c = 0;
    }
    // кол-во узлов в дереве
    int size() {
        if (root != nullptr) return root->count + 1;
        return 0;
    }
    // добавление
    bool add(object *obj) {
        Node *n = new Node(obj);
        bool ins; //флаг об успешной/неуспешной вставке
        if (!n) {
            return false;
        }
        // проверка на невалидность даты
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
    // кол-во пройденных узлов до найденного
    int search2(int k) {
        object* res = searchNode(root, k);
        if (res != nullptr) {
            int cc = c;
            c = 0;
            return cc;
        } 
        return -1; // в случае отсутствия элемента в дереве
    }
    // поиск элемента в дереве
    object* search(int k) {
        object *res = searchNode(root, k);
        if (res != nullptr) return res;
        else return nullptr;
    }
    // поиск узла
    object *searchNode(Node *node, int k) {
        if (node == nullptr) return nullptr;
        if (k == node->key) return node->o;
        if (k < node->key) {
            c++;
            return searchNode(node->left, k);
        } else {
            c++;
            return searchNode(node->right, k);
        }
    }
    // вывод структуры
    void show() {
        showNode(root, 0);
    }
    // распечатка rihgt -> root -> left
    void showNode(Node *t, int level) {
        if (t == nullptr) {
            return;
        } 
        showNode(t->right, level+1);
        for (int i = 0; i < level; i++) cout << "\t";
        cout  << t->o->getValueObj() << "(" << t->o->uploadInString() << ")[" << t->count << "]" << endl;
        showNode(t->left, level+1);
    }
    // удаление элемента для пользователя
    void del(object* obj) {
        root = deleteNode(root, obj);
    }
    // поиск минимального для замены
    Node* FindMin(Node* r) {
        while (r->left != nullptr) r = r->left;
        return r;
    }
    // рекурсивное удаление узла
    Node* deleteNode(Node* r, object* obj) {
        if (r == nullptr) return r;
        else if (equal(obj, r->o) < 0) {
            r->count--;
            r->left = deleteNode(r->left, obj);
        } 
        else if (equal(obj, r->o) > 0) {
            r->count--;
            r->right = deleteNode(r->right, obj); 
        } 
        // нашли, что удалять
        else {
            // лепесток
            if (r->left == nullptr && r->right == nullptr) {
                delete r;
                r = nullptr;
            }
            // один сын
            else if(r->left == nullptr) {
                r->count--;
                Node* tmp = r;
                r = r->right;
                delete tmp;
            }
            else if(r->right == nullptr) {
                r->count--;
                Node* tmp = r;
                r = r->left;
                delete tmp;
            }
            // оба сына
            else {
                Node* tmp = FindMin(r->right);
                r->count--;
                r->o = tmp->o;
                r->key = tmp->key;
                r->right = deleteNode(r->right, tmp->o);
            }
        }
        return r;
    } 
    // запись структуры в бинарный файл для пользователя
    void wrBin() {
        ofstream fout("BinaryTree.dat", ios::binary);
        if (!fout.is_open()) cout << "Cannot open file.";
        else {
            cout << "Binary Tree was written in the binary file.\n";
            writeInBinary(fout, root);
        }
    }
    // запись структуры в бинарный файл
    void writeInBinary(ofstream &fout, Node *t) {
        if (t == nullptr) {
            return;
        }
        // получаем ID объекта
        int key = t->o->getId();
        fout.write((char*)&key, sizeof(int));
        t->o->writeInBinary(fout);
        writeInBinary(fout, t->left);
        writeInBinary(fout, t->right);
    }
    // чтение структуры из бинарного файла для пользоователя
    void rBin() {
        ifstream fin("BinaryTree.dat", ios::binary);
        if (!fin.is_open()) cout <<  "Cannot open file.";
        else {
            cout << "Binary Tree was read from the binary file.\n";
            readFromB(fin);
        }
    }
    // чтение структуры из бинарного файла 
    void readFromB(ifstream& fin) {
        // считываем, пока не конец файла
        while (true) {
            int key;
            object *obj;
            fin.read((char*)&key, sizeof(int));
            if (key == 1) {
                obj = new Integer;
            } else if (key == 2) {
                obj = new Date;
            }
            obj->readFromBinary(fin);
            add(obj);
            if (fin.peek() == EOF) break;
        }
    }
    // деструктор
    ~Btree() {
        delete root;
        c = 0;
    }
private:
    Node *root;
    int c;
};
