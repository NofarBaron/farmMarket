#include "Market.h"

Market::Market() {
    market_year=0;
}

Market::~Market() {
    for (auto it = begin(all_farms); it != end(all_farms); it++)
        delete (*it);
}

int Market::getYear() const {
    return market_year;
}

void Market::Create_new_farm(){
    cout << "----Creating new farms----" << endl;
    int cowNum,sheepNum,chickenNum;
    bool t=false;
    while (!t) {
        cout << "How many new cow farms will be added this year?" << endl;
        cin >> cowNum;
        try {
            if (cowNum < 0)
                throw cowException();

            cout << "How many new sheep farms will be added this year?" << endl;
            cin >> sheepNum;
            if (sheepNum < 0)
                throw sheepException();
            cout << "How many new chicken farms will be added this year?" << endl;
            cin >> chickenNum;
            if (chickenNum < 0) {
                throw chickenException();
            }
            else
                t=true;

        }
        catch (exception &e){
            cout << e.what() << endl;
        }
    }
    cout << "----Adding new farms to market----" << endl;
    for (int i=0;i<cowNum;i++){
        Farm *new_C = new cowFarm();
        Add(new_C);
        all_farms.push_back(new_C);
    }
    for (int i=0;i<sheepNum;i++){
        Farm *new_Sheep = new sheepFarm();
        Add(new_Sheep);
        all_farms.push_back(new_Sheep);
    }
    for (int i=0;i<chickenNum;i++){
        Farm *new_Chicken = new chickenFarm();
        Add(new_Chicken);
        all_farms.push_back(new_Chicken);
    }
}


void Market::Add(Farm *f){
    for (auto it= begin(all_farms);it!=end(all_farms);it++){
            (*it)->sell(f); //cow buy from->sheep
            (f)->sell(*it); //sheep->cow
    }
}


void Market::nextYear() {
    Create_new_farm();
    for (auto it = begin(all_farms); it != end(all_farms); it++) { //update animals age for each farm
        (*it)->production();
    }
    Trading_day();
    for (auto it = begin(all_farms); it != end(all_farms); it++) { //update animals age for each farm
        (*it)->update_age(1);
    }


    for (auto it = begin(all_farms); it != end(all_farms); it++)
        (*it)->Set_myMoney(10);
    market_year++;
}

void Market::Trading_day(){
    //vector<Farm*> c;
    cout << "----Begin Market----" <<endl;
    for (auto it= begin(all_farms);it!= end(all_farms);it++) {
        //c=(*it)->get_my_clients();
        for (auto client = begin(*(*it)->get_my_clients()); client != end(*(*it)->get_my_clients()); client++) {
            (*client)->purchase(*it);
        }
    }
    cout << "----Buy Animals----" <<endl;
    for (auto it= begin(all_farms);it!= end(all_farms);it++) {
        (*it)->animals_purchase();
    }
}

void Market::fastForwardYears(){
    int years;
    cout << "How many years to fast forward?" << endl;
    cin >> years;
    for (int i=0;i<years;i++) {
        for (auto it = begin(all_farms); it != end(all_farms); it++) { //update animals age for each farm
            (*it)->production();
        }
        Trading_day();
        for (auto it = begin(all_farms); it != end(all_farms); it++) { //update animals age for each farm
            //Farm *each_farm = *it;
            (*it)->update_age(1);
        }
        for (auto it = begin(all_farms); it != end(all_farms); it++)
            (*it)->Set_myMoney(10);
    }
    market_year+=years;
}

void Market::printMarketFarms(){
    cout << "----Market Farms----" << endl;
    for (auto it=begin(all_farms);it!=end(all_farms);it++){
        (*it)->printFarm();
    }
}