#include "Fixed.hpp"

Fixed::Fixed() : n(0) {std::cout << "Deafult constructor called\n";}

Fixed::Fixed(const int n){
    std::cout << "Int constructor called\n";
    this->n = n << 8;
}

Fixed::Fixed(const float n){
    std::cout << "Float constrcutor called\n";
    this->n = roundf(n * 256);//2^8 is 256
}

Fixed::Fixed(const Fixed &copy) : n(copy.n){
    std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &copy){
    std::cout << "Copy assignment operator called\n";
    if (this == &copy)
        return *this;
    this->setRawBits(copy.getRawBits());
    return *this;
}

float Fixed::toFloat(void) const{
    return (n / 256.0f);
}

int Fixed::toInt(void) const{
    return (n >> 8);
}

int Fixed::getRawBits(void) const {
    //std::cout << "getRawBits member function called\n";
    return (n);
}

void Fixed::setRawBits(const int raw){
    //std::cout << "setRawBits member function called\n";
    n = raw;
}

//stream operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& obj){
    os << obj.toFloat();
    return os;
};

Fixed::~Fixed(){
    std::cout << "Destructor called\n";
}
