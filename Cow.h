#ifndef CPP_FARM_COW_H
#define CPP_FARM_COW_H
#include "Animal.h"

class Cow: public Animal{
    static int period_of_life;
    static int price;
public:
    Cow();
    virtual ~Cow(){ };
    virtual int getPrice();
    virtual int get_period_of_life();
};


#endif //CPP_FARM_COW_H
