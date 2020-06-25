#ifndef ABC_H
#define ABC_H
#include <string.h>
#include <iostream>
using namespace std;

class ABC
{
protected:
    string name;
public:
    ABC();
    ABC(const string name);
    ~ABC(){}
    void change_name(string const name);
    string get_name() const;
};

#endif // ABC_H
