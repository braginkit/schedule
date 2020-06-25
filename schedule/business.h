#ifndef BUSINESS_H
#define BUSINESS_H
#include <affair.h>
#include <string.h>
#include <iostream>
using namespace std;

class Business: public Affair
{
private:
    struct business_point
    {
        Affair * point;
        business_point * next;
    };
    business_point * first;
    business_point * last;
    bool complete_all;
public:
    Business(); //конструктор по умолчанию
    Business(const string name, const int priority, const bool complete = false); //конструктор с параметрами
    ~Business(){}
    void add_point(Affair * point); //добавление пункта с сортировкой
    void delete_point(Affair * point); //удаление пункта
    void delete_business(); //удаление всех пунктов
    void check_complete_all(); //проверка выполненности всех пунктов
    bool get_complete_all() const; //возвращает статус выполненности
    void show(); //для тестов, удалить в конце

    //написать метод для изменения статуса выполненности подзадачи? через итератор, либо через указатель
};

#endif // BUSINESS_H
