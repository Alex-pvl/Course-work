#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include "math.h"
#include "object.hpp"
using namespace std;

class Date : public object {
public:
    Date();
    Date(int, int, int);
    Date(int, int, int, int, int, int);

    int getDay();
    int getMonth();
    int getYear();
    int getHour();
    int getMinute();
    int getSecond();

    void setYear(int);
    void setMonth(int);
    void setDay(int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    void incYear();
    void incMonth();
    void incDay();
    void incHour();
    void incMinutes();
    void incSecond();

    void decYear();
    void decMonth();
    void decDay();
    void decHour();
    void decMinute();
    void decSecond();

    // перевод строки в дату
    object* loadFromString(char*);
    // перевод даты в строку
    char* uploadInString();
    // получение имени класса
    char* getName();
    // получение идентификатора класса
    int getId();
    // сравнение двух объектов
    int equals(object*);
    // сумма объектов
    object* unionObj(object*, object*);
    // создание копии объекта
    object* makeCopy(object*);
    // запись объекта в бинарный файл
    void writeInBinary(ofstream&);
    // чтение объекта из бинарного файла
    void readFromBinary(ifstream&);
    // запись объекта в текстовый файл
    void writeInTxt(ofstream&);
    // чтение объекта из текстового файла
    void readFromTxt(ifstream&);

    friend Date& operator+(Date& d ,int hours);
    friend Date& operator-(Date& d ,int hours);

    Date& operator=(const Date& d);

    ~Date();
private:
    int day;
    int mon;
    int year;
    int h;
    int m;
    int s;
};

Date::Date() {
    this->setDay(1);
    this->setMonth(1);
    this->setYear(1);
    this->setHour(0);
    this->setMinute(0);
    this->setSecond(0);
}

Date::Date(int day, int mon, int year) {
    this->setDay(day);
    this->setMonth(mon);
    this->setYear(year);
    this->setHour(0);
    this->setMinute(0);
    this->setSecond(0);
}

Date::Date(int day, int mon, int year, int h, int m, int s) : Date::Date(day, mon, year) {
    this->setHour(h);
    this->setMinute(m);
    this->setSecond(s);
}

int Date::getDay() { 
    return this->day; 
}

int Date::getMonth() { 
    return this->mon; 
}

int Date::getYear() { 
    return this->year; 
}

int Date::getHour() { 
    return this->h; 
}

int Date::getMinute() { 
    return this->m; 
}

int Date::getSecond() { 
    return this->s; 
}

void Date::setYear(int year) {
    try
    {
        if (year < 0) throw runtime_error("Invalid Date Format, check year");
        this->year = year;
    }
    catch(exception& e)
    {
        cerr << e.what() << '\n';
    }
}
 
void Date::setMonth(int mon) {
    try
    {
        if (mon > 12 || mon < 0) throw runtime_error("Invalid Date Format, check month");
        this->mon = mon;
    }
    catch(exception& e)
    {
        cerr << e.what() << '\n';
    }
}

void Date::setDay(int day) {
    try
    {
        if (day > 31 || day < 0) throw runtime_error("Invalid Date Format, check day");
        this->day = day;
    }
    catch(exception& e)
    {
        cout<< e.what() << '\n';
    }
}

void Date::setHour(int h) {
    try
    {
        if (h > 23 || h < 0) throw runtime_error("Invalid Date Format, check hours");
        this->h = h;
    }
    catch(exception& e)
    {
        cerr << e.what() << '\n';
    }
}

void Date::setMinute(int m) {
    try
    {
        if (m > 59 || m < 0) throw runtime_error("Invalid Date Format, check minutes");
        this->m = m;
    }
    catch(exception& e)
    {
        cerr << e.what() << '\n';
    }
}

void Date::setSecond(int s) {
    try
    {
        if (s > 59 || s < 0) throw runtime_error("Invalid Date Format, check seconds");
        this->s = s;
    }
    catch(exception& e)
    {
        cerr << e.what() << '\n';
    }
}

void Date::incYear() { 
    this->setYear(this->getYear() + 1); 
}

void Date::incMonth() {
    if (this->getMonth() == 12) {
        this->incYear();
        this->setMonth(1);
    } else {
        this->setMonth(this->getMonth() + 1);
    }
}

void Date::incDay() {
    if ((this->getMonth() == 4 || this->getMonth() == 6 ||
    this->getMonth() == 9 || this->getMonth() == 11) && this->getDay() == 30) {
        this->incMonth();
        this->setDay(1);
    } else if (this->getMonth() == 2) {
        if (this->getYear() % 4 == 0) {
            if (this->getYear() % 100 == 0 && this->getYear() % 400 != 0) {
                if (this->getDay() == 28) {
                    this->incMonth();
                    this->setDay(1);
                } else {
                    this->setDay(this->getDay() + 1);
                }
            } else {
                if (this->getDay() == 29) {
                    this->incMonth();
                    this->setDay(1);
                } else {
                    this->setDay(this->getDay() + 1);
                }
            }
        } else if (this->getDay() == 28) {
            this->incMonth();
            this->setDay(1);
        } else {
            this->setDay(this->getDay() + 1);
        }
    } else if (this->getDay() == 31) {
        this->incMonth();
        this->setDay(1);
    } else {
        this->setDay(this->getDay() + 1);
    }
}

void Date::incHour() {
    if (this->getHour() == 23) {
        this->incDay();
        this->setHour(0);
    } else {
        this->setHour(this->getHour() + 1);
    }
}

void Date::incMinutes() {
    if (this->getMinute() == 59) {
        this->incHour();
        this->setMinute(0);
    } else {
        this->setMinute(this->getMinute() + 1);
    }
}

void Date::incSecond() {
    if (this->getSecond() == 59) {
        this->incMinutes();
        this->setSecond(0);
    } else {
        this->setSecond(this->getSecond() + 1);
    }
}

void Date::decYear() { 
    this->setYear(this->getYear() - 1); 
}

void Date::decMonth() {
    if (this->getMonth() == 1) {
        this->decYear();
        this->setMonth(12); 
    } else {
        this->setMonth(this->getMonth() - 1);
    }
}

void Date::decDay() {
    if ((this->getMonth() == 5 || this->getMonth() == 7 ||
    this->getMonth() == 10 || this->getMonth() == 12) && this->getDay() == 1) {
        this->decMonth();
        this->setDay(30);
    } else if (this->getMonth() == 3) {
        if (this->getYear() % 4 == 0) {
            if (this->getYear() % 100 == 0 && this->getYear() % 400 != 0) {
                if (this->getDay() == 1) {
                    this->decMonth();
                    this->setDay(28);
                } else {
                    this->setDay(this->getDay() - 1);
                }
            } else {
                if (this->getDay() == 1) {
                    this->decMonth();
                    this->setDay(29);
                } else {
                    this->setDay(this->getDay() - 1);
                }
            }
        } else if (this->getDay() == 1) {
            this->decMonth();
            this->setDay(28);
        } else {
            this->setDay(this->getDay() - 1);
        }
    } else if (this->getDay() == 1) {
        this->decMonth();
        this->setDay(31);
    } else {
        this->setDay(this->getDay() - 1);
    }
} 

void Date::decHour() {
    if (this->getHour() == 0) {
        this->decDay();
        this->setHour(23);
    } else {
        this->setHour(this->getHour() - 1);
    }
}

void Date::decMinute() {
    if (this->getMinute() == 0) {
        this->decHour();
        this->setMinute(59);
    } else {
        this->setMinute(this->getMinute() - 1);
    }
}

void Date::decSecond() {
    if (this->getSecond() == 0) {
        this->decMinute();
        this->setSecond(59);
    } else {
        this->setSecond(this->getSecond() - 1);
    }
}

Date& operator+(Date& d, int hours) {
    for (; hours > 0; hours--) d.incHour();
    return d;
} 

Date& operator-(Date& d, int hours) {
    for (; hours > 0; hours--) d.decHour();
    return d;
}

object* Date::loadFromString(char *date) {
    int day, mon, year, h, m, s;
    if (date[0] == 0) {
        day = date[1] - '0';
    } else {
        day = 10 * (date[0]-'0') + date[1] - '0';
    }
    if (date[3] == 0) {
        mon = date[4] - '0';
    } else {
        mon = 10 * (date[3] - '0') + date[4] - '0';
    }
    if (date[6] == 0) {
        if (date[7] == 0) {
            if (date[8] == 0) {                // 12/45/7890 11:11:11
                year = date[9] - '0';
            } else {
                year = 10 * (date[8] - '0') + date[9] - '0';
            }
        } else {
            year = 100 * (date[7] - '0') + 10 * (date[8] - '0') + date[9] - '0';
        }
    } else {
        year = 1000 * (date[6] - '0') + 100 * (date[7] - '0') + 10 * (date[8] - '0') + date[9] - '0';
    }
    this->setDay(day); this->setMonth(mon); this->setYear(year);
    if (date[11] == 0) {
        h = date[12] - '0';
    } else {
        h = 10 * (date[11] - '0') + date[12] - '0';
    }
    if (date[14] == 0) {
        m = date[15] - '0';
    } else {
        m = 10 * (date[14] - '0') + date[15] - '0';
    }
    if (date[17] == 0) {
        s = date[18] - '0';
    } else {
        s = 10 * (date[17] - '0') + date[18] - '0';
    }
    this->setHour(h); this->setMinute(m); this->setSecond(s);
    return this;
}

char* Date::uploadInString() {
    char* str = new char[19];
    sprintf(str, "%.2d/%.2d/%.4d %.2d:%.2d:%.2d", this->getDay(), this->getMonth(), this->getYear(), 
    this->getHour(), this->getMinute(), this->getSecond());
    return str;
}

char* Date::getName() {
    char *d_name = new char[4];
    strcpy(d_name, "Date");
    return d_name;
}

int Date::getId() {
    return 2;
}

int Date::equals(object* o) {
    // if (this->day > ((Date*) o)->value) return 1;
    // else if (this->value < ((Integer*) o)->value) return -1;
    // else return 0;
    return 0;
}

object* Date::unionObj(object* o1, object* o2) {
    object* r = new Date;
	((Date*)r)->day += ((Date*)o1)->day;
	((Date*)r)->mon += ((Date*)o1)->mon;
    ((Date*)r)->year += ((Date*)o1)->year;
    ((Date*)r)->h += ((Date*)o1)->h;
    ((Date*)r)->m += ((Date*)o1)->m;
    ((Date*)r)->s += ((Date*)o1)->s;
    ((Date*)r)->day += ((Date*)o2)->day;
	((Date*)r)->mon += ((Date*)o2)->mon;
    ((Date*)r)->year += ((Date*)o2)->year;
    ((Date*)r)->h += ((Date*)o2)->h;
    ((Date*)r)->m += ((Date*)o2)->m;
    ((Date*)r)->s += ((Date*)o2)->s;
	day = ((Date*)r)->day;
    mon = ((Date*)r)->mon;
    year = ((Date*)r)->year;
    h = ((Date*)r)->h;
    m = ((Date*)r)->m;
    s = ((Date*)r)->s;
	return r;
}

object* Date::makeCopy(object* o) {
    int day = ((Date*) o)->getDay();
    int mon = ((Date*) o)->getMonth();
    int year = ((Date*) o)->getYear();
    int h = ((Date*) o)->getHour();
    int m = ((Date*) o)->getMinute();
    int s = ((Date*) o)->getSecond();
    return new Date(day, mon, year, h, m, s);
}

void Date::writeInBinary(ofstream& fout) {
    // int id = getId();
    // fout.write((char*)&id, sizeof(int));
    // fout.write((char*)&value, sizeof(int));
    // fout.close();
}
    
void Date::readFromBinary(ifstream& fin) {
    // int id;
    // fin.read((char*)&id, sizeof(int));
    // fin.read((char*)&value, sizeof(int));
    // fin.close();
}

void Date::writeInTxt(ofstream& fout) {
    // int id = getId();
    // fout << id << " ";
    // fout << this->getValue();
}

void Date::readFromTxt(ifstream& fin) {
    // int id, n;
    // fin >> id >> n;
    // this->setValue(n);
}

Date& Date::operator=(const Date& d) {
    day = d.day;
    mon = d.mon;
    year = d.year;
    h = d.h;
    m = d.m;
    s = d.s;
    return *this;
}

Date::~Date() {
    delete this;    
}