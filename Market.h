#ifndef CPP_FARM_MARKET_H
#define CPP_FARM_MARKET_H
#include "Farm.h"
#include "chickenException.h"
#include "cowException.h"
#include "sheepException.h"
#include "cowFarm.h"
#include "chickenFarm.h"
#include "sheepFarm.h"
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Market{
    int market_year;
    vector<Farm*> all_farms;

public:
    Market();
    virtual ~Market(); //need to call distructor of farms
    int getYear() const;
    void Create_new_farm();
    void Trading_day();
    void nextYear();
    void fastForwardYears();
    void printMarketFarms();
    void Add(Farm *f);
};


#endif //CPP_FARM_MARKET_H
