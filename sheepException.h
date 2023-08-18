#ifndef CPP_FARM_SHEEPEXCEPTION_H
#define CPP_FARM_SHEEPEXCEPTION_H
#include "exception"
using namespace std;

class sheepException: public exception{
public:
    virtual const char* what() const throw(){
        return "Insert valid number of sheep farms";
    }
};


#endif //CPP_FARM_SHEEPEXCEPTION_H
