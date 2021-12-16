#include <iostream>
#include "Date.hpp"
#include "Integer.hpp"
#include "btree.hpp"
#include <cstring>
using namespace std;


int main() {
    string commands = "Binary Tree was created.\nAvailable commands:\n[1]-insert new object\n\t[11]-new Integer\n\t[12]-new Date\n[2]-delete object\n\t[21]-delete Integer\n\t[22]-delete Date\n[3]-search\n\t[31]-search Integer\n\t[32]-search Date\n[4]-show\n[5]-write to txt file\n[6]-write to binary file\n[7]-read from txt file\n[8]-read from binary file\n[9]-delete Binary Tree\n[10]-exit\n\n[0]-help\n\n\nWrite command's id: ";
    cout << commands;
    Btree bt;
    string mode, insMode, delMode, sMode;
    cin >> mode;
    while (true) {
        // вставка объекта
        if (mode == "1") {
            cout << "Write the inserting datatype\n([11] - Integer, [12] - Date): ";
            cin >> insMode;
            if (insMode == "11") {
                cout << "Write int value: ";
                object *i = new Integer; 
                cin >> *(Integer*)i;
                if (bt.add(i)) cout << "Integer object was inserted.\n";
                else cout << "Error.\n";
            }
            else if (insMode == "12") {
                cout << "Write date in valid format [dd/MM/yyyy hh:mm:ss]: ";
                object *d = new Date;
                cin >> *(Date*)d;
                if (bt.add(d)) cout << "Date object was inserted.\n";
                else cout << "Error.\n";
            }
            else {
                cout << "Invalid datatype, try again.\n";
            }
            cout << "Write command's id: ";
            cin >> mode;
        }
        // удаление объекта
        if (mode == "2") {
            cout << "Write the deleting datatype\n([21] - Integer, [22] - Date): ";
            cin >> delMode;
            if (delMode == "21") {
                cout << "Write int value: ";
                object *i = new Integer; 
                cin >> *(Integer*)i;
                if (bt.deleteObj(i)) cout << "Integer object was deleted.\n";
                else cout << "Error.\n";
            }
            else if (delMode == "22") {
                cout << "Write date in valid format [dd/MM/yyyy hh:mm:ss]: ";
                object *d = new Date;
                cin >> *(Date*)d;
                if (bt.deleteObj(d)) cout << "Date object was deleted.\n";
                else cout << "Error.\n";
            }
            else {
                cout << "Invalid datatype, try again.\n";
            }
            cout << "Write command's id: ";
            cin >> mode;
        }
        // поиск объекта
        if (mode == "3") {
            cout << "Write the searching datatype\n([31] - Integer, [32] - Date): ";
            cin >> sMode;
            if (sMode == "31") {
                cout << "Write int value: ";
                object *i = new Integer; 
                cin >> *(Integer*)i;
                if (bt.search(i)) cout << "This element was found.\n";
                else cout << "Can't find this element.\n";
            }
            else if (sMode == "32") {
                cout << "Write date in valid format [dd/MM/yyyy hh:mm:ss]: ";
                object *d = new Date; 
                cin >> *(Date*)d;
                if (bt.search(d)) cout << "This element was found.\n";
                else cout << "Can't find this element.\n";
            }
            else {
                cout << "Invalid datatype, try again.\n";
            }
            cout << "Write command's id: ";
            cin >> mode;
        }
        // вывод структуры в консоль
        if (mode == "4") {
            bt.show();
            cout << "Write command's id: ";
            cin >> mode;
        }
        // запись структуры в текстовый файл
        if (mode == "5") {
            bt.wrTxt();
            cout << "Write command's id: ";
            cin >> mode;
        }
        // чтение структуры из текстовго файла
        if (mode == "6") {
            
        }
        // запись структуры в бинарный файл
        if (mode == "7") {
            bt.wrBin();
            cout << "Write command's id: ";
            cin >> mode;
        }
        // чтение структуры из бинарного файла
        if (mode == "8") {
            
        }
        // удаление структуры
        if (mode == "9") {
            bt.~Btree();
        }
        // выход
        if (mode == "10") {
            exit(-1);
        }
        // список команд
        if (mode == "0") {
            cout << commands;
            cin >> mode;
        }
    }
    
    return 0;
}