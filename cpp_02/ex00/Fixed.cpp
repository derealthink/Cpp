#include "Fixed.hpp"

fixedPoint::fixedPoint() : n(0) {std::cout << "Deafult constructor called\n";}

fixedPoint::fixedPoint(const fixedPoint &copy) : n(copy.n){
    std::cout << "Copy constructor called\n";
}

fixedPoint &fixedPoint::operator=(const fixedPoint &copy){
    std::cout << "Copy assignment operator called\n";
    if (this == &copy)
        return *this;
    this->setRawbits(copy.getRawbits());
    return *this;
}

fixedPoint::~fixedPoint(){
    std::cout << "Destructor called\n";
}

int fixedPoint::getRawbits(void) const {
    std::cout << "Destrcutor called\n";
    return (n);
}

void fixedPoint::setRawbits(const int raw){
    n = raw;
}

