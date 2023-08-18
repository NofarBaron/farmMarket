#ifndef CPP_FARM_SHEEP_H
#define CPP_FARM_SHEEP_H
#include "Animal.h"

class Sheep: public Animal{
    static int period_of_life;
    static int price;
public:
    Sheep();
    virtual ~Sheep(){};
    virtual int getPrice();
    //friend class ChickenFarm;
    virtual int get_period_of_life();

};


#endif //CPP_FARM_SHEEP_H
