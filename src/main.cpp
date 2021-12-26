#include <iostream>
#include "Date.hpp"
#include "Integer.hpp"
#include "btree.hpp"
using namespace std;

int main() {
    string commands = "Binary Tree was created.\nAvailable commands:\n[1]-insert new object\n   [11]-new Integer\n   [12]-new Date\n[2]-delete object\n   [21]-delete Integer\n   [22]-delete Date\n[3]-search\n[4]-show\n[5]-write to binary file\n[6]-read from binary file\n[7]-exit\n[8]-size of binary tree\n[0]-help\n\nWrite command's id: ";
    cout << commands;
    Btree *bt = new Btree;
    int mode, insMode, delMode;
    int objMode;
    cin >> mode;
    while (true) {
        // вставка объекта
        if (mode == 1) {
            cout << "Write the inserting datatype\n([11] - Integer, [12] - Date): ";
            cin >> insMode;
            if (insMode == 11) {
                cout << "Write int value: ";
                object *i = new Integer; 
                cin >> *(Integer*)i;
                if (bt->add(i)) cout << "Integer object was inserted.\n";
                else cout << "Error.\n";
            }
            else if (insMode == 12) {
                cout << "Write date in valid format [dd/MM/yyyy hh:mm:ss]: ";
                object *d = new Date;
                cin >> *(Date*)d;
                if (bt->add(d)) cout << "Date object was inserted.\n";
                else cout << "Error.\n";
            }
            else {
                cout << "Invalid datatype, try again.\n";
            }
            cout << "Write command's id: ";
        }
        // удаление объекта
        if (mode == 2) {
            int s0 = bt->size();
            object* dell;
            cout << "Write deleting mode([21]-delete Integer,[22]-delete Date): ";
            cin >> delMode;
            if (delMode == 21) {
                cout << "Write int value: ";
                dell = new Integer;
            }
            else if (delMode == 22) {
                cout << "Write date in valid format [dd/MM/yyyy hh:mm:ss]: ";
                dell = new Date;
            }
            dell->getObject();
            bt->del(dell);
            int s1 = bt->size();
            if (s1 < s0) cout << "Object was deleted.\n";
            else cout << "Error\n";
            cout << "Write command's id: ";
        }
        // поиск объекта
        if (mode == 3) {
            cout << "Write the searching data: ";
            int k;
            cin >> k;
            object* res = bt->search(k);
            if (res != nullptr) {
                cout << "Object was found.\n";
                int id = res->getId();
                cout << "Available commands\n\t[31]-get class Name\n\t[32]-upload in string\n\t[33]-make copy\n\t[34]-union\n\t[35]-compare\n\t[36]-delete from binary tree\n\t[-1]-return to binary tree\n";
                cout << "Write obj mode: ";
                cin >> objMode;
                while (true) {
                    if (objMode == -1) {
                        break;
                    }
                    if (objMode == 31) {
                        cout << "Class name - ";
                        if (id == 1) cout << ((Integer*)res)->getName() << endl;
                        else if (id == 2) cout << ((Date*)res)->getName() << endl;
                        cout << "Write obj mode: ";
                        cin >> objMode;
                    }
                    if (objMode == 32) {
                        string str = res->uploadInString();
                        cout << "String - " << str << endl;
                        cout << "Write obj mode: ";
                        cin >> objMode;
                    }
                    if (objMode == 33) {
                        cout << "Making a copy - ";
                        object* res2;
                        if (id == 1) {
                            res2 = new Integer;
                        } 
                        else if (id == 2) {
                            res2 = new Date;
                        }
                        res2->makeCopy(res);
                        cout << res2->uploadInString() << endl;
                        cout << "Write obj mode: ";
                        cin >> objMode;
                    }
                    if (objMode == 34) {
                        cout << "Write the same class object: ";
                        object* sum;
                        if (id == 1) {
                            sum = new Integer;
                            cin >> *(Integer*)sum;
                            cout << "Union is - ";
                            object* re = new Integer;
                            re->unionObj(sum, res);
                            cout << re->uploadInString() << endl;
                        } 
                        else if (id == 2) {
                            sum = new Date;
                            cin >> *(Date*)sum;
                            cout << "Union is - ";
                            object* re = new Date;
                            re->unionObj(sum, res);
                            cout << re->uploadInString() << endl;
                        }
                        cout << "Write obj mode: ";
                        cin >> objMode;
                    }
                    if (objMode == 35) {
                        cout << "Write the same class object: ";
                        object* r;
                        if (id == 1) {
                            r = new Integer;
                            cin >> *(Integer*)r;
                        } 
                        else if (id == 2) {
                            r = new Date;
                            cin >> *(Date*)r;
                        }
                        int cmp = res->equals(res, r);
                        if (cmp > 0) cout << res->uploadInString() << " > " << r->uploadInString() << endl;
                        else if (cmp < 0) cout << res->uploadInString() << " < " << r->uploadInString() << endl;
                        else cout << res->uploadInString() << " == " << r->uploadInString() << endl;
                        cout << "Write obj mode: ";
                        cin >> objMode;
                    }
                    if (objMode == 36) {
                        int s0 = bt->size();
                        cout << "deleting...\n";
                        bt->del(res);
                        int s1 = bt->size();
                        if (s1 < s0) cout << "Object was deleted.\n";
                        else cout << "Error\n";
                        cout << "Write obj mode: ";
                        cin >> objMode;
                    }
                    if ((objMode > 36 || objMode < 31) && objMode != -1) {
                        cout << "Unknown command. Try again.\nWrite obj mode: ";
                        cin >> objMode;
                    }
                    
                }
            }
            else cout << "Cannot find this data.\n"; 
            
            
            //cout << bt->search2(k) << endl;
            cout << "Write command's id: ";
        }
        // вывод структуры в консоль
        if (mode == 4) {
            bt->show();
            cout << "Write command's id: ";
        }
        // запись структуры в бинарный файл
        if (mode == 5) {
            bt->wrBin();
            cout << "Write command's id: ";
        }
        // чтение структуры из бинарного файла
        if (mode == 6) {
            bt = new Btree;
            bt->rBin();
            cout << "Write command's id: ";
        }
        // выход
        if (mode == 7) {
            cout << "Exiting...";
            exit(-1);
        }
        // размер дерева
        if (mode == 8) {
            cout << "Binary tree size - " << bt->size() << endl;
            cout << "Write command's id: ";
        }
        // список команд
        if (mode == 0) {
            cout << commands;
        }
        if (mode > 8 || mode < 0) {
            cout << "Unknown command. Try again.\nWrite command's id: ";
        }
        cin >> mode;
    }
    
    return 0;
}