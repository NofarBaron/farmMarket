#ifndef CPP_FARM_ANIMAL_H
#define CPP_FARM_ANIMAL_H
#include <iostream>

using namespace std;

class Animal {
protected:
    int age;
public:
    Animal();
    virtual ~Animal(){};
    virtual int getAge();
    virtual void setAge(int update_age);
    virtual int getPrice()=0;
    virtual int get_period_of_life()=0;

};


#endif //CPP_FARM_ANIMAL_H
