#pragma once
#include <iostream>
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
    bool add(object *obj) {
        Node *n = new Node(obj);
        bool ins;
        if (!n) {
            return false;
        }
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
        inserted = ins;
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
        showNode(root, 0);
    }
    void showNode(Node *t, int level) {
        if (t == nullptr) {
            return;
        }
        showNode(t->right, level + 1);
        for (int i = 0; i < 3*level; i++) cout << " ";
        cout << t->o->getId() << endl;
        showNode(t->left, level+1);
    }
    bool deleteObj(object* obj) {
        Node *n = new Node(obj);
        bool del;
        if (!n) {
            return false;
        }
        root = deleteNodes(root, n, del);
        return del;
    }
    Node* Del(Node *t, Node *t0) {
        if (t->left != nullptr) {
            t->left = Del(t->left, t0);
            return t;
        }
        t0->o = t->o;
        Node *x = t->right;
        delete t;
        return x;
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
            deleted = del;
            return r;
        }
        else if (equal(elem->o, r->o) > 0) {
            r->right = deleteNodes(r->right, elem, del);
            deleted = del;
            return r;
        }
        deleted = true;
        if (r->left == nullptr && r->right == nullptr) {
            delete r;
            return nullptr;
        }
        if (r->left == nullptr) {
            Node *x = r->right;
            delete r;
            return x;
        }
        if (r->right == nullptr) {
            Node *x = r->left;
            delete r;
            return x;
        }
        r->right = Del(r->right, r);
    }
    ~Btree() {
        
    }
private:
    int count;
    Node *root;
};
