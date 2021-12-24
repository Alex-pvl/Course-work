#include <iostream>
#include "Date.hpp"
#include "Integer.hpp"
#include "btree.hpp"
using namespace std;

int main() {
    string commands = "Binary Tree was created.\nAvailable commands:\n[1]-insert new object\n   [11]-new Integer\n   [12]-new Date\n[2]-delete object\n   [21]-delete Integer\n   [22]-delete Date\n[3]-search\n[4]-show\n[5]-write to binary file\n[6]-read from binary file\n[7]-exit\n\n[0]-help\n\nWrite command's id: ";
    cout << commands;
    Btree *bt = new Btree;
    int mode, insMode, delMode, sMode;
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
            cout << "Write the deleting datatype\n([21] - Integer, [22] - Date): ";
            cin >> delMode;
            if (delMode == 21) {
                cout << "Write int value: ";
                object *i = new Integer; 
                cin >> *(Integer*)i;
                if (bt->deleteObj(i)) cout << "Integer object was deleted.\n";
                else cout << "Error.\n";
            }
            else if (delMode == 22) {
                cout << "Write date in valid format [dd/MM/yyyy hh:mm:ss]: ";
                object *d = new Date;
                cin >> *(Date*)d;
                if (bt->deleteObj(d)) cout << "Date object was deleted.\n";
                else cout << "Error.\n";
            }
            else {
                cout << "Invalid datatype, try again.\n";
            }
            cout << "Write command's id: ";
        }
        // поиск объекта
        if (mode == 3) {
            cout << "Write the searching data: ";
            int k;
            cin >> k;
            bt->search(k);
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
        if (mode == 8) {
            cout << bt->size();
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