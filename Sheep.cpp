#include "Sheep.h"
int Sheep::price=5;
int Sheep::period_of_life=5;
Sheep::Sheep() {
    age=0;
}

int Sheep::getPrice() {
    return price;
}

int Sheep::get_period_of_life(){return period_of_life;};
