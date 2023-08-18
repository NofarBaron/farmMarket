#ifndef CPP_FARM_CHICKEN_H
#define CPP_FARM_CHICKEN_H
#include "Animal.h"

class Chicken: public Animal{
    static int period_of_life;
    static int price;
public:
    Chicken();
    virtual ~Chicken(){ };
    virtual int getPrice();
    virtual int get_period_of_life();



};


#endif //CPP_FARM_CHICKEN_H
