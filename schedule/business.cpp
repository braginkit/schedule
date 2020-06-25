#include "business.h"

Business::Business() : Affair()
{
    this->first = nullptr;
    this->last = nullptr;
    complete_all = false;
}

Business::Business(const string new_name, const int new_priority, const bool new_complete) : Affair(new_name, new_priority, new_complete)
{
    this->first = nullptr;
    this->last = nullptr;
    complete_all = false;
}

void Business::add_point(Affair * point)
{
    Affair * tmp = new Affair(*point);
    if(first == nullptr)
    {
        business_point * current = new business_point;
        current->point = tmp;
        current->next = nullptr;
        first = current;
        last = current;
    }
    else
    {
        business_point * place_finder = first;
        business_point * back_place_finder = first;
        while(place_finder->point->get_priority() < tmp->get_priority() && place_finder != last)
        {
            if(place_finder != first)
                back_place_finder = back_place_finder->next;
            place_finder = place_finder->next;
        }
        if((place_finder == first && first->point->get_priority() > tmp->get_priority()) || (place_finder == first && first->point->get_priority() == tmp->get_priority()) )
        {
            business_point * current = new business_point;
            current->point = tmp;
            current->next = first;
            first = current;
        }
        else if(place_finder == first && first->point->get_priority() < tmp->get_priority())
        {
            business_point * current = new business_point;
            current->point = first->point;
            current->next = first;
            first->point = tmp;
            first = current;
        }
        else if(place_finder == last && last->point->get_priority() < tmp->get_priority())
        {
            business_point * current = new business_point;
            current->point = tmp;
            current->next = nullptr;
            last->next = current;
            last = current;
        }
        else if(place_finder == last && last->point->get_priority() > tmp->get_priority())
        {
            business_point * current = new business_point;
            current->point = last->point;
            current->next = nullptr;
            last->point = tmp;
            last->next = current;
            last = last->next;
        }
        else
        {
            business_point * current = new business_point;
            current->point = tmp;
            back_place_finder->next = current;
            current->next = place_finder;
        }
    }
}

void Business::delete_point(Affair * point)
{
    business_point * place_finder = first;
    business_point * back_place_finder = first;
    while(point != place_finder->point)
    {
        if(place_finder != first)
            back_place_finder = back_place_finder->next;
        place_finder = place_finder->next;
    }
    if(place_finder == first && place_finder != last)
    {
        first = first->next;
        delete place_finder->point;
        delete place_finder;
    }
    else if(place_finder == last && place_finder != first)
    {
        last = back_place_finder;
        back_place_finder->next = nullptr;
        delete place_finder->point;
        delete place_finder;
    }
    else if(place_finder == first && place_finder == last)
    {
        delete place_finder->point;
        delete place_finder;
        first = nullptr;
        last = nullptr;
    }
    else
    {
        back_place_finder->next = place_finder->next;
        delete place_finder->point;
        delete place_finder;
    }
}

void Business::delete_business()
{
    business_point * current;
    current = first;
    while(first->next != nullptr)
    {
        current = first;
        first = first->next;
        delete current->point;
        delete current;
    }
    first = nullptr;
    last = nullptr;
}

void Business::check_complete_all()
{
    business_point * current;
    current = first;
    bool flag = true;
    while(current->next != nullptr)
    {
        if(current->point->get_compete() == false)
            flag = false;
        current = current->next;
    }
    if(flag)
        this->complete_all = true;
}

bool Business::get_complete_all() const
{
    return complete_all;
}

void Business::show()
{
    business_point * place_finder = first;
    for(int c = 0; c<10; c++)
    {
        if(place_finder != nullptr)
        {
            cout<<place_finder->point->get_name()<<" "<<place_finder->point->get_priority()<<endl;
            place_finder = place_finder->next;
        }
    }
    cout<<endl;
}






