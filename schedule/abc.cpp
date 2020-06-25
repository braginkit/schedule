#include "abc.h"

ABC::ABC()
{
    name = "affair";
}

ABC::ABC(string name)
{
    this->name = name;
}

void ABC::change_name(string const new_name)
{
    this->name = new_name;
}

string ABC::get_name() const
{
    return name;
}
