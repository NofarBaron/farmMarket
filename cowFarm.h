#ifndef CPP_FARM_COWFARM_H
#define CPP_FARM_COWFARM_H
#include "Farm.h"
#include "Cow.h"
#include "Animal.h"

class cowFarm :public Farm{
public:
    cowFarm();
    virtual ~cowFarm();
    virtual void printFarm();
    virtual void animals_purchase();

    virtual void update_age(int years);

    virtual void sell(Farm *f);
    virtual void add_cow_to_my_client_list(Farm *f) { };
    virtual void add_chicken_to_my_client_list(Farm *f) { };
    virtual void add_sheep_to_my_client_list(Farm *f) ;
    virtual void purchase(Farm *f);

};


#endif //CPP_FARM_COWFARM_H
