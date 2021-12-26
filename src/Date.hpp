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
    // геттеры полей
    int getDay();
    int getMonth();
    int getYear();
    int getHour();
    int getMinute();
    int getSecond();
    int getValue();
    // сеттеры полей
    void setYear(int);
    void setMonth(int);
    void setDay(int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);
    // инкрементирование полей 
    void incYear();
    void incMonth();
    void incDay();
    void incHour();
    void incMinutes();
    void incSecond();
    // перевод строки в дату
    object* loadFromString(char*);
    // перевод даты в строку
    string uploadInString();
    // получение имени класса
    string getName();
    // получение идентификатора класса
    int getId();
    // сравнение двух объектов
    int equals(object*, object*);
    // сумма объектов
    object* unionObj(object*, object*);
    // создание копии объекта
    object* makeCopy(object*);
    // запись объекта в бинарный файл
    void writeInBinary(ofstream&);
    // чтение объекта из бинарного файла
    void readFromBinary(ifstream&);
    // ввод числа с клавиатуры
    void getObject();
    int getValueObj();

    Date& operator=(const Date& d);
    friend ostream& operator<<(ostream&, Date&);
    friend istream& operator>>(istream&, Date&);
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
    try {
        if (day > 31 || day < 0 || mon > 12 || mon < 0 || year < 0) throw runtime_error("Invalid Date Format.");
        this->setDay(day);
        this->setMonth(mon);
        this->setYear(year);
        this->setHour(0);
        this->setMinute(0);
        this->setSecond(0);
    } catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Date::Date(int day, int mon, int year, int h, int m, int s) {
    try {
        if (day > 31 || day < 0 || mon > 12 || mon < 0 || year < 0 || 
        h > 23 || h < 0 || m > 59 || m < 0 || s > 59 || s < 0) throw runtime_error("Invalid Date Format.");
        this->setDay(day);
        this->setMonth(mon);
        this->setYear(year);
        this->setHour(h);
        this->setMinute(m);
        this->setSecond(s);
    } catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
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

int Date::getValueObj() {
    return this->year;
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
            if (date[8] == 0) {                
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

string Date::uploadInString() {
    char* str = new char[19];
    sprintf(str, "%.2d/%.2d/%.4d %.2d:%.2d:%.2d", this->getDay(), this->getMonth(), this->getYear(), 
    this->getHour(), this->getMinute(), this->getSecond());
    return str;
}

string Date::getName() {
    return "Date";
}

int Date::getId() {
    return 2;
}

int Date::equals(object* o1, object* o2) {
    int first_d = 0, first_s = 0, second_d = 0, second_s = 0;

    for (int i = 1; i < ((Date*)o1)->getYear(); i++) {
        if (i % 4 == 0 || ((i % 100 != 0) && (i % 400 == 0))) {
            first_d += 366;
        } else first_d += 365;
    }
    for (int i = 1; i < ((Date*)o1)->getMonth(); i++) {
        if (i == 4 || i == 6 || i == 9 || i == 11) {
            first_d += 30;
        } else if (i == 2) {
            if (((Date*)o1)->getYear() % 4 == 0 || ((((Date*)o1)->getYear() % 100 != 0) && (((Date*)o1)->getYear() % 400 == 0))) {
                first_d += 29;
            } else first_d += 28;
        } else first_d += 31;
    }
    first_d += ((Date*)o1)->getDay();

    first_s += 3600 * ((Date*)o1)->getHour() + 60 * ((Date*)o1)->getMinute() + ((Date*)o1)->getSecond();

    for (int i = 1; i < ((Date*)o2)->getYear(); i++) {
        if (i % 4 == 0 || ((i % 100 != 0) && (i % 400 == 0))) {
            second_d += 366;
        } else second_d += 365;
    }
    for (int i = 1; i < ((Date*)o2)->getMonth(); i++) {
        if (i == 4 || i == 6 || i == 9 || i == 11) {
            second_d += 30;
        } else if (i == 2) {
            if (((Date*)o2)->getYear() % 4 == 0 || ((((Date*)o2)->getYear() % 100 != 0) && (((Date*)o2)->getYear() % 400 == 0))) {
                second_d += 29;
            } else second_d += 28;
        } else second_d += 31;
    }
    second_d += ((Date*)o2)->getDay();

    second_s += 3600 * ((Date*)o2)->getHour() + 60 * ((Date*)o2)->getMinute() + ((Date*)o2)->getSecond();

    if (first_d > second_d) return 1;
    else if (first_d < second_d) return -1;
    else {
        if (first_s > second_s) return 1;
        else if (first_s < second_s) return -1;
        else return 0;
    }
}

object* Date::unionObj(object* o1, object* o2) {
    int sec = ((Date*)o1)->getSecond() + ((Date*)o2)->getSecond();
    int min = ((Date*)o1)->getMinute() + ((Date*)o2)->getMinute();
    int hours = ((Date*)o1)->getHour() + ((Date*)o2)->getHour();
    int years = ((Date*)o1)->getYear() + ((Date*)o2)->getYear();
    int months = ((Date*)o1)->getMonth() + ((Date*)o2)->getMonth();
    int days = ((Date*)o1)->getDay() + ((Date*)o2)->getDay();
    for (int i = 1; i < days; i++) {
        this->incDay();
    }
    for (int i = 1; i < months; i++) {
        this->incMonth();
    }
    for (int i = 1; i < years; i++) {
        this->incYear();
    }    
    for (int i = 0; i < sec; i++) {
        this->incSecond();
    }
    for (int i = 0; i < min; i++) {
        this->incMinutes();
    }
    for (int i = 0; i < hours; i++) {
        this->incHour();
    }
    return this;
}

object* Date::makeCopy(object* o) {
    this->setDay(((Date*) o)->getDay());
    this->setMonth(((Date*) o)->getMonth());
    this->setYear(((Date*) o)->getYear());
    this->setHour(((Date*) o)->getHour());
    this->setMinute(((Date*) o)->getMinute());
    this->setSecond(((Date*) o)->getSecond());
    return (Date*)this;
}

void Date::writeInBinary(ofstream& fout) {
    fout.write((char*)&day, sizeof(int));
    fout.write((char*)&mon, sizeof(int));
    fout.write((char*)&year, sizeof(int));
    fout.write((char*)&h, sizeof(int));
    fout.write((char*)&m, sizeof(int));
    fout.write((char*)&s, sizeof(int));
}
    
void Date::readFromBinary(ifstream& fin) {
    fin.read((char*)&day, sizeof(int));
    fin.read((char*)&mon, sizeof(int));
    fin.read((char*)&year, sizeof(int));
    fin.read((char*)&h, sizeof(int));
    fin.read((char*)&m, sizeof(int));
    fin.read((char*)&s, sizeof(int));
}

void Date::getObject() {
    cin >> this->day >> this->mon >> this->year >> this->h >> this->m >> this->s;
}

Date& Date::operator=(const Date& d) {
    try {
        if (day > 31 || day < 0 || mon > 12 || mon < 0 || year < 0 || 
        h > 23 || h < 0 || m > 59 || m < 0 || s > 59 || s < 0) throw runtime_error("Invalid Date Format.");
        this->setDay(d.day);
        this->setMonth(d.mon);
        this->setYear(d.year);
        this->setHour(d.h);
        this->setMinute(d.m);
        this->setSecond(d.s);
    } catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return *this;
}

ostream& operator<<(ostream& os, Date& d) {
    os << ((Date*)&d)->uploadInString();
    return os;
}

istream& operator>>(istream& is, Date& d) {
    int day, mon, year, h, m, s;
    is >> day >> mon >> year >> h >> m >> s;
    try
    {
        if (day > 31 || day < 0 || mon > 12 || mon < 0 || year < 0 || 
        h > 23 || h < 0 || m > 59 || m < 0 || s > 59 || s < 0) throw runtime_error("Invalid Date Format.");
        d.setDay(day);
        d.setMonth(mon);
        d.setYear(year);
        d.setHour(h);
        d.setMinute(m);
        d.setSecond(s);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return is;
}

Date::~Date() {
    delete this;    
}