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
    else if (o1->getId() == 1 && o2->getId() == 1) {
        return (((Integer*)o1)->equals((Integer*)o1, (Integer*)o2));
    }
    else if (o1->getId() == 2 && o2->getId() == 2) {
        return (((Date*)o1)->equals((Date*)o1, (Date*)o2));
    }
    return 0;
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
    int size() {
        if (root != nullptr) return root->count + 1;
        return 0;
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
    int search2(int k) {
        object *res = searchNode(root, k);
        if (res != nullptr) return c;
        return -1;
    }
    // поиск элемента в дереве
    void search(int k) {
        object *res = searchNode(root, k);
        if (res != nullptr) cout << "Object was found - " << res->getValueObj() << "(" << res->uploadInString() << ")\n";
        else cout << "Cannot find this data.\n"; 
        c = 0;
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
    // вывод узла
    void showNode(Node *t, int level) {
        if (t == nullptr) {
            return;
        } 
        showNode(t->right, level+1);
        for (int i = 0; i < level; i++) cout << "\t";
        cout << t->o->getValueObj() << "(" << t->o->uploadInString() << ")" << endl;
        showNode(t->left, level+1);
    }
    // Node* minValueObj(Node* n) {
    //     Node *cur = n;
    //     while (cur && cur->left != nullptr) {
    //         cur = cur->left;
    //     }
    //     return cur;
    // }
    // // удаление объекта
    // bool deleteObj(int k) {
    //     bool del;
    //     root = deleteNodes(root, k, del);
    //     return del;
    // }
    // Node* Del(Node* t, Node* t0) {
    //     if (t->left != nullptr) {
    //         t->left = Del(t->left, t0);
    //         return t;
    //     }
    //     t0->key = t->key;
    //     t0->o = t->o;
    //     Node* x = t->right;
    //     delete t;
    //     return x;
    // }
    // // удаление узла
    // Node* deleteNodes(Node *r, int k, bool &deleted) {
    //     bool del;
    //     if (r == nullptr) {
    //         deleted = false;
    //         return r;
    //     }
    //     if (k < r->key) {
    //         r->left = deleteNodes(r->left, k, del);
    //         //r->count--;
    //         deleted = del;
    //     }
    //     if (k > r->key) {
    //         r->right = deleteNodes(r->right, k, del);
    //         //r->count--;
    //         deleted = del;
    //     }
    //     deleted = true;
    //     if (r->left == nullptr && r->right == nullptr) {
    //         delete r;
    //         return nullptr;
    //     }
    //     if (r->left == nullptr) {
    //         Node* x = r->right;
    //         delete r;
    //         return x;
    //     }
    //     if (r->right == nullptr) {
    //         Node* x = r->left;
    //         delete r;
    //         return x;
    //     }
    //     r->right = Del(r->right, r);
    //     if (del) r->count--;
    //     return r;
    // }

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
            //r->count--;
            deleted = del;
        }
        else if (equal(elem->o, r->o) > 0) {
            r->right = deleteNodes(r->right, elem, del);
            //r->count--;
            deleted = del;
        }
        else {
            deleted = true;
            if (r->left == nullptr && r->right == nullptr) {
                return nullptr;
            }
            else if (r->left == nullptr) {
                Node *x = r->right;
                //r->count--;
                delete r;
                return x;
            }
            else if (r->right == nullptr) {
                Node *x = r->left;
                //r->count--;
                delete r;
                return x;
            }
            Node *tmp = minValueObj(r->right);
            r->o = tmp->o;
            //r->count--;
            r->right = deleteNodes(r->right, tmp, del);
        }
        if (del) r->count--;
        return r;
    }

    // void del(int k) {
    //     root = deleteNode(root, k);
    // }
    // Node* findMax(Node* r) {
    //     if (r == nullptr) return nullptr;
    //     while (r->right != nullptr) {
    //         r = r->right;
    //     }
    //     return r;
    // }
    // Node* deleteNode(Node* r, int k) {
    //     if (r == nullptr) return r;
    //     if (r->key > k) {
    //         r->left = deleteNode(r->left, k);
    //         return r;
    //     }
    //     else if (r->key < k) {
    //         r->right = deleteNode(r->right, k);
    //         return r;
    //     }
    //     if (r->left == nullptr) {
    //         Node* tmp = r->right;
    //         delete r;
    //         return tmp;
    //     }
    //     else if (r->right == nullptr) {
    //         Node* tmp = r->left;
    //         delete r;
    //         return tmp;
    //     }
    //     else {
    //         Node* succParent = r;
    //         Node* succ = r->right;
    //         while (succ->left != nullptr) {
    //             succParent = succ;
    //             succ = succ->left;
    //         }
    //         if (succParent != r) succParent->left = succ->right;
    //         else succParent->right = succ->right;
    //         r->key = succ->key;
    //         r->o = succ->o;
    //         delete succ;
    //         return r;
    //     }
    // }
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
        if (t == nullptr) return;
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
    }
private:
    Node *root;
    int c;
};
