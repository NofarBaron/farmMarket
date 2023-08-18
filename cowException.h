#ifndef CPP_FARM_COWEXCEPTION_H
#define CPP_FARM_COWEXCEPTION_H
#include "exception"
using namespace std;

class cowException: public exception{
public:
    virtual const char* what() const throw(){
        return "Insert valid number of cow farms";
    }
};


#endif //CPP_FARM_COWEXCEPTION_H
