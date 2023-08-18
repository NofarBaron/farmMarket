#ifndef CPP_FARM_SHEEPFARM_H
#define CPP_FARM_SHEEPFARM_H
#include "Farm.h"
#include "Sheep.h"
#include "Animal.h"

class sheepFarm :public Farm{
public:
    sheepFarm();
    virtual ~sheepFarm();
    virtual void printFarm();

    virtual void animals_purchase();

    virtual void update_age(int years);

    virtual void sell(Farm *f);
    virtual void add_cow_to_my_client_list(Farm *f) { };
    virtual void add_chicken_to_my_client_list(Farm *f);
    virtual void add_sheep_to_my_client_list(Farm *f) { };
    virtual void purchase(Farm *f);


};


#endif //CPP_FARM_SHEEPFARM_H
