#include "Farm.h"

int Farm::id_counter=0;

Farm::Farm()
{
    Money=10;
    my_products_num=0;
    other_products_num=0;
}

Farm::~Farm() {
    for (auto it= begin(animals);it!= end(animals);it++)
        delete (*it);
}

void Farm::production() {
    for (auto it = begin(animals); it != end(animals); it++) {
        this->my_products_num += (*it)->getAge();
    }
}
void Farm::Set_myMoney(int money) {
    Money+=money;
}
void Farm::Set_my_products(int curr) {
    my_products_num = curr;
}

int Farm::get_my_products() const{
    return my_products_num;
}

vector<Farm*> *Farm::get_my_clients(){
    return &clients;
}

int Farm::get_my_Id(){
    return ID;
}

