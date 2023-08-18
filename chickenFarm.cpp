#include "chickenFarm.h"
chickenFarm::chickenFarm() {
    id_counter++;
    ID=id_counter;
    my_products_name="Eggs";
    my_products_price=1;
    other_products_name = "Wool";
    other_products_price=2;
    num_of_animals=3;
    for(int i=0;i<3;i++){
        Chicken *new_chicken = new Chicken();
        animals.push_back(new_chicken);
    }
}


chickenFarm::~chickenFarm(){
}

void chickenFarm::update_age(int years) {
    Chicken c;
    int t;
    auto it = begin(animals);
    while (it != end(animals)) {
        (*it)->setAge(years);
        if ((*it)->getAge()>=c.get_period_of_life()) {
            it = animals.erase(it);
            //delete (*it);
            (*it)->~Animal();
            this->num_of_animals--;
        }
        else
            it++;
    }
}

void chickenFarm::animals_purchase(){
    Chicken c;
    int amount = Money/c.getPrice();
    for (int i=0;i<amount;i++){
        Chicken *c1=new Chicken();
        animals.push_back(c1);
    }
    this->Money -=(amount*c.getPrice());
    num_of_animals+=amount; //update the total animals i have
    if (amount!=0)
        cout << "Chicken farm(" << ID << ") bought " << amount << " chickens for " << amount*c.getPrice() << " dollars" << endl;

}

void chickenFarm::sell(Farm *f){
    f->add_chicken_to_my_client_list(this);
}

void chickenFarm::add_cow_to_my_client_list(Farm *f){
    clients.push_back(f);
    cout << "Chicken farm(" << this->get_my_Id() << ") Added Cow farm(" << f->get_my_Id() << ") to his client list" << endl ;
}

void chickenFarm::purchase(Farm *f) { //(this) try to buy from f
    int total_elm = f->get_my_products(); //max products i can buy
    int amount  = this->Money/this->other_products_price; //max products i can buy with my money
    if (total_elm<amount){
        Money= Money-(total_elm*this->other_products_price);
        this->other_products_num+=total_elm;
        f->Set_my_products(0);
        f->Set_myMoney(total_elm*other_products_price);
        if (total_elm!=0)
            cout << "Chicken farm(" << this->get_my_Id() << ") bought " << total_elm << " wool for " << total_elm* this->other_products_price << " dollars from Sheep farm(" << f->get_my_Id() << ")" << endl;
    }
    else {
        Money= Money-(amount*other_products_price);
        this->other_products_num+=amount;
        f->Set_myMoney(amount*other_products_price);
        f->Set_my_products(total_elm-amount);
        if (amount!=0)
            cout << "Chicken farm(" << this->get_my_Id() << ") bought " << amount << " wool for " << amount*this->other_products_price << " dollars from Sheep farm(" << f->get_my_Id() << ")" << endl;

    }
}
void chickenFarm::printFarm() {
    cout << "Farm Id: " << ID << ", type: Chicken Farm, Money: " << Money << ", Animals: " << num_of_animals << " chickens, ";
    cout << "Products: Milk[0], Wool[" << other_products_num<< "], Eggs[" << my_products_num << "]" << endl;
}