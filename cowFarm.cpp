#include "cowFarm.h"
#include "Animal.h"
#include "Cow.h"
cowFarm::cowFarm(){
    id_counter++;
    ID=id_counter;
    my_products_name="Milk";
    my_products_price=3;
    other_products_name="Eggs";
    other_products_price=1;
    num_of_animals=3;
    for(int i=0;i<3;i++){
        Animal *new_cow = new Cow();
        animals.push_back(new_cow);
    }
}

cowFarm::~cowFarm() {
}

void cowFarm::update_age(int years) {
    Cow cc;
    int t;
    auto it= begin(animals);
    while (it!= end(animals)){
        (*it)->setAge(years);
        if((*it)->getAge()>=cc.get_period_of_life()) {
            it = animals.erase(it);
            //delete (*it);
            (*it)->~Animal();
            this->num_of_animals--;
        }
        else {
            it++;
        }
    }
}


void cowFarm::animals_purchase(){
    Cow c;
    int amount = Money/c.getPrice();
    for (int i=0;i<amount;i++){
        Cow *cc=new Cow();
        animals.push_back(cc);
    }
    Money= Money-(amount*c.getPrice());
    num_of_animals+=amount; //update the total animals I have
    if (amount!=0)
        cout << "Cow farm(" << ID << ") bought " << amount << " cows for " << amount*c.getPrice() << " dollars" << endl;
}


void cowFarm::sell(Farm *f){
    f->add_cow_to_my_client_list(this);
}
void cowFarm::add_sheep_to_my_client_list(Farm *f){
    clients.push_back(f);
    cout << "Cow farm(" << this->get_my_Id() << ") Added Sheep farm(" << f->get_my_Id() << ") to his client list" << endl ;
}


void cowFarm::purchase(Farm *f){
    int total_elm = f->get_my_products();
    int amount  = this->Money/this->other_products_price;
    if (total_elm<amount){
        Money= Money-(total_elm*this->other_products_price);
        this->other_products_num+=total_elm;
        f->Set_my_products(0);
        f->Set_myMoney(total_elm*other_products_price);
        if (total_elm!=0)
            cout << "Cow farm(" << this->get_my_Id() << ") bought " << total_elm << " eggs for " << total_elm* this->other_products_price << " dollars from Chicken farm(" << f->get_my_Id() << ")" << endl;
    }
    else { //total_elm>=amount
        this->Set_myMoney(-amount*other_products_price);
        this->other_products_num+=amount;
        f->Set_myMoney(amount*other_products_price);
        f->Set_my_products(total_elm-amount);
        if (amount!=0)
            cout << "Cow farm(" << this->get_my_Id() << ") bought " << amount << " eggs for " << amount* this->other_products_price << " dollars from Chicken farm(" << f->get_my_Id() << ")" << endl;
    }
}

void cowFarm::printFarm() {
    cout << "Farm Id: " << ID<< ", type: Cow farm, Money: " << Money << ", Animals: " << num_of_animals << " cows, ";
    cout << "Products: Milk[" << my_products_num<< "], Wool[0], Eggs[" << other_products_num << "]" << endl;
}