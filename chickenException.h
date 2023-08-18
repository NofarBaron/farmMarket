#ifndef CPP_FARM_CHICKENEXCEPTION_H
#define CPP_FARM_CHICKENEXCEPTION_H
#include "exception"
using namespace std;

class chickenException: public exception{
public:
    virtual const char* what() const throw(){
        return "Insert valid number of chicken farms";
    }
};


#endif //CPP_FARM_CHICKENEXCEPTION_H
