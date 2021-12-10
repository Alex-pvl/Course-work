#pragma once
#include <iostream>
#include "object.hpp"
#include "Integer.hpp"
#include "Date.hpp"
using namespace std;

int equal(object* o1, object* o2) {
    // if (sizeof(o1) == sizeof(Integer) && sizeof(o2) == sizeof(Date)) {
    //     if (((Integer*)o1)->getValue() > ((Date*)o2)->getYear()) return 1;
    //     else if (((Integer*)o1)->getValue() < ((Date*)o2)->getYear()) return -1;
    //     else return 0;
    // }
    // else if (sizeof(o1) == sizeof(Date) && sizeof(o2) == sizeof(Integer)) {
    //     if (((Integer*)o2)->getValue() < ((Date*)o1)->getYear()) return 1;
    //     else if (((Integer*)o2)->getValue() > ((Date*)o1)->getYear()) return -1;
    //     else return 0;
    // }
    // return o1->equals(o2);
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
        }
        Node(object* obj) {
            o = obj;
            left = nullptr;
            right = nullptr;
        }
        friend class Btree;
    private:
        object *o;
        Node *left;
        Node *right;
    };

class Btree {
public:
    Btree() {
        count = 0;
        root = nullptr;
    }
    // удаление узла
    void deleteNotes(Node *n) {
        if (!n) return;
        delete n;
        delete n->left;
        delete n->right;
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
    object* getData(Node *n) {
        return n->o;
    }
    // добавление
    void add(object *obj) {
        Node *n = new Node(obj);
      
        if (!n) {
            return;
        }
        root = insertNode(root, n);
    }
    // вставка узла
    Node* insertNode(Node *node, Node *elem) {
        if (node == nullptr) return elem;
    
        if (equal(node->o, elem->o) < 0) 
            node->left = insertNode(node->left, elem);
        else node->right = insertNode(node->right, elem);

        return node;
    }
    // поиск элемента в дереве
    Node *search(object *obj) {
        return searchNode(root, obj);
    }
    // поиск узла
    Node *searchNode(Node *node, object *obj) {
        if (equal(node->o, obj) == 0) return node;
        else {
            if (equal(node->o, obj) < 0) {
                searchNode(node->left, obj);
            }
            else {
                searchNode(node->right, obj);
            }
        }
    }
    // вывод структуры
    void show() {
        showNode(root);
    }
    void showNode(Node *n) {
        if (n != nullptr) {
            cout << n->o->uploadInString() << "\n";
            showNode(n->left);
            showNode(n->right);
        }
    }
    // удаление узла
    void deleteNodes(Node *n) {
        if (!n) return;
        delete n->o;
        delete n->left;
        delete n->right;
    }
    ~Btree() {
        deleteNodes(root);
    }
private:
    int count;
    Node *root;
};
