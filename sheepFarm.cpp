#include "sheepFarm.h"
sheepFarm::sheepFarm(){
    id_counter++;
    ID=id_counter;
    my_products_name = "Wool";
    my_products_price=2;
    other_products_name= "Milk";
    other_products_price=3;
    num_of_animals=3;
    for(int i=0;i<3;i++){
        Sheep *new_sheep = new Sheep();
        animals.push_back(new_sheep);
    }
}

sheepFarm::~sheepFarm(){

}

void sheepFarm::update_age(int years) {
    Sheep s;
    int t;
    auto it= begin(animals);
    while (it!= end(animals)){
        (*it)->setAge(years);
        if((*it)->getAge()>=s.get_period_of_life()) {
            it = animals.erase(it);
            delete *it;
            //(*it)->~Animal();
            this->num_of_animals--;
        }
        else {
            it++;
        }
    }
}


void sheepFarm::animals_purchase(){
    Sheep s;
    int amount = Money/s.getPrice();
    for (int i=0;i<amount;i++){
        Sheep *s1=new Sheep();
        animals.push_back(s1);
    }
    Money= Money-(amount*s.getPrice());
    num_of_animals+=amount; //update the total animals i have
    if (amount!=0)
        cout << "Sheep farm(" << ID << ") bought " << amount << " sheeps for " << amount*s.getPrice() << " dollars" << endl;
}

void sheepFarm::sell(Farm *f){  //cow sell to sheep
    f->add_sheep_to_my_client_list(this);
}

void sheepFarm::add_chicken_to_my_client_list(Farm *f){
    clients.push_back(f);
    cout << "Sheep farm(" << this->get_my_Id() << ") Added Chicken farm(" << f->get_my_Id() << ") to his client list" << endl ;
}

void sheepFarm::purchase(Farm *f){
    int num_milk = f->get_my_products();
    int amount  = this->Money/this->other_products_price;
    if (num_milk<amount){
        Money= Money-(num_milk*this->other_products_price);
        this->other_products_num+=num_milk;
        f->Set_my_products(0);
        f->Set_myMoney(num_milk*other_products_price);
        if (num_milk!=0)
            cout << "Sheep farm(" << this->get_my_Id() << ") bought " << num_milk << " milk for " << (num_milk*this->other_products_price) << " dollars from Cow farm(" << f->get_my_Id() << ")" << endl;

    }
    else { //num_milk>=amount
        this->Set_myMoney(-amount*this->other_products_price);
        this->other_products_num+=amount;
        f->Set_myMoney(amount*this->other_products_price);
        f->Set_my_products(num_milk-amount);
        if (amount!=0)
            cout << "Sheep farm(" << this->get_my_Id() << ") bought " << amount << " milk for " << (amount*this->other_products_price) << " dollars from Cow farm(" << f->get_my_Id() << ")" << endl;

    }
}



void sheepFarm::printFarm() {
    cout << "Farm Id: " << ID << ", type: Sheep farm, Money: " << Money << ", Animals: " << num_of_animals << " sheep, ";
    cout << "Products: Milk[" << other_products_num << "], Wool[" << my_products_num<< "], Eggs[0]" << endl;
}