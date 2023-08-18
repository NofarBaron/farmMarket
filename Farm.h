#ifndef CPP_FARM_FARM_H
#define CPP_FARM_FARM_H
#include <string>
#include <iostream>
#include "Animal.h"
#include <vector>
#include <list>
using namespace std;
class Animal;

class Farm{
protected:
    static int id_counter;
    int ID;
    int Money;
    vector<Farm*> clients;
    vector<Animal*> animals;
    int num_of_animals;

    string my_products_name;
    int my_products_price;
    int my_products_num;

    string other_products_name;
    int other_products_price;
    int other_products_num;
public:
    Farm();
    virtual ~Farm(); //implement in cpp
    virtual void production();
    virtual void animals_purchase()=0;
    virtual void printFarm()=0;

    void Set_my_products(int curr);
    void Set_myMoney(int money);
    int get_my_products() const;
    virtual void update_age(int years)=0;

    virtual void sell(Farm *f)=0;
    virtual void add_cow_to_my_client_list(Farm *f)=0;
    virtual void add_chicken_to_my_client_list(Farm *f)=0;
    virtual void add_sheep_to_my_client_list(Farm *f)=0;
    virtual void purchase(Farm *f)=0;
    virtual vector<Farm*> *get_my_clients();
    virtual int get_my_Id();

};


#endif //CPP_FARM_FARM_H
