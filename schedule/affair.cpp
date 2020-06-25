#include "affair.h"

Affair::Affair() : ABC()
{
    this->complete = false;
    this->priority = 3;
}

Affair::Affair(const string new_name, const int new_priority, const bool new_complete) : ABC(new_name)
{
    if(new_priority == 1 || new_priority == 2 || new_priority == 3)
        this->priority = new_priority;
    else
        this->priority = 3;
    this->complete = new_complete;
}

Affair::Affair(Affair * other)
{
    Affair(other->name, other->priority, other->complete);
}

Affair::~Affair(){};

void Affair::change_complete()
{
    if(this->complete == true)
        this->complete = false;
    else
        this->complete = true;
}

void Affair::change_priority(const int new_priority)
{
    this->priority = new_priority;
}

bool Affair::get_compete() const
{
    return this->complete;
}

int Affair::get_priority() const
{
    return priority;
}
