#ifndef AFFAIR_H
#define AFFAIR_H
#include <abc.h>
#include <string.h>
#include <iostream>
using namespace std;

class Affair : public ABC
{
private:
    bool complete;
    int priority;
public:
    Affair(); //конструктор по умолчанию
    Affair(const string name, const int priority, const bool complete = false); //конструктор с параметрами
    Affair(Affair * other); //конструктор копирования
    ~Affair(); //деструктор
    void change_complete(); //изменения статуса завершенности
    void change_priority(const int new_priority); //изменения приоритета
    bool get_compete() const; //возвращает статус завершенности
    int get_priority() const; //возвращает приоритет
};

#endif // AFFAIR_H
