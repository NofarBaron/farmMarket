#include "Chicken.h"
int Chicken::price=3;
int Chicken::period_of_life=3;
Chicken::Chicken() {
    age=0;
}

int Chicken::getPrice(){
    return price;
}

int Chicken::get_period_of_life() {return period_of_life;};