#include "Farm.h"
#include "Market.h"

int main() {

//    Farm *f[3];
//    Farm *f0 = new cowFarm();
//    Farm *f1 = new chickenFarm();
//    Farm *f2=new sheepFarm();
//    f[0]=f0,f[1]=f1,f[2]=f2;
//    f[0]->printFarm();
//    f[1]->printFarm();
//    f[2]->printFarm();
//    f[0]->update_age(4);
//    f[1]->update_age(2); //chicken die at age of 3
//    f[2]->update_age(3);
//
//    cout << "--after updating--" << endl;
//    f[0]->printFarm();
//    f[1]->printFarm();
//    f[2]->printFarm();
//
//    f[0]->products_purchase(f[2]);
//    f[0]->products_purchase(f[1]);
//    //f[0]->update_age(1);
//    cout << "--after purchase--" << endl;
//    f[0]->printFarm();
//    f[1]->printFarm();
//    f[2]->printFarm();
//
//    cout << "--after animal purchase--" << endl;
//    f[0]->animals_purchase();
//    f[0]->update_age(1);
//    f[0]->printFarm();
//    f[1]->printFarm();
//    f[2]->printFarm();
//
//    Market* market = new Market();
//    market->nextYear();
//    cout<< "Year:" << market->getYear() <<endl;
//    market->printMarketFarms();
//    //market->Trading_day();
//    //market->printMarketFarms();

    Market* market = new Market();
    char gameOption='0';
    while(gameOption!='4')
    {
        cout<< "Year:" << market->getYear() <<endl;
        cout<< "1. Next year" << endl;
        cout<< "2. Fast forward" << endl;
        cout<< "3. Print farms in market" << endl;
        cout<< "4. Exit" << endl;
        cin >> gameOption;
        switch(gameOption){
            case '1':
                market->nextYear();
                break;
            case '2':
                market->fastForwardYears();
                break;
            case '3':
                market->printMarketFarms();
                break;
            case '4':
                cout<<"Bye.. "<<endl;
                delete market;
                break;
        }
    }

    return 0;
}