#include "Cow.h"
int Cow::price=10;
int Cow::period_of_life=10;

Cow::Cow(){
    age=0;
}

int Cow::getPrice(){
    return price;
}

int Cow::get_period_of_life(){
    return period_of_life;
}