#include "Animal.h"

Animal::Animal() {

}

int Animal::getAge(){
    return age;
}

void Animal::setAge(int update_age) {
    this->age+=update_age;
}