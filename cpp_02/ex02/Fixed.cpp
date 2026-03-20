#include "Fixed.hpp"

Fixed::Fixed() : n(0) {
    //std::cout << "Deafult constructor called\n";
}

Fixed::Fixed(const int n){
    //std::cout << "Int constructor called\n";
    this->n = n << 8;
}

Fixed::Fixed(const float n){
    //std::cout << "Float constrcutor called\n";
    this->n = roundf(n * 256);
}

Fixed::Fixed(const Fixed &copy) : n(copy.n){
    //std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &copy){
    //std::cout << "Copy assignment operator called\n";
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

Fixed::~Fixed(){
    //std::cout << "Destructor called\n";
}



//___________COMPARISON_OPERATORS___________

bool Fixed::operator<(const Fixed& other) const {
    bool result;
    result = this->n < other.n;
    return result;
}

bool Fixed::operator>(const Fixed& other) const {
    bool result;
    result = this->n > other.n;
    return result;
}

bool Fixed::operator<=(const Fixed& other) const {
    bool result;
    result = this->n <= other.n;
    return result;
}

bool Fixed::operator>=(const Fixed& other) const {
    bool result;
    result = this->n >= other.n;
    return result;
}

bool Fixed::operator==(const Fixed& other) const {
    bool result;
    result = this->n == other.n;
    return result;
}

bool Fixed::operator!=(const Fixed& other) const {
    bool result;
    result = this->n != other.n;
    return result;
}



//___________ARITHMETIC_OPERATORS___________

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.n = this->n + other.n;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.n = this->n - other.n;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result.n = (this->n * other.n) >> frac;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    result.n = (this->n >> frac) / (other.n >> frac);
    return result;
}

//___________IN/DECREMENT_OPERATORS___________

Fixed &Fixed::operator++() {
    this->n++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->n++;
    return temp;
}

Fixed &Fixed::operator--() {
    this->n--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->n--;
    return temp;
}

//___________MIN_MAX_FUNCTIONS___________

Fixed &Fixed::min(Fixed &Fixed1, Fixed &Fixed2) {
  return (Fixed1 < Fixed2 ? Fixed1 : Fixed2);
}

const Fixed &Fixed::min(const Fixed &Fixed1, const Fixed &Fixed2) {
  return (Fixed1 < Fixed2 ? Fixed1 : Fixed2);
}

Fixed &Fixed::max(Fixed &Fixed1, Fixed &Fixed2) {
  return (Fixed1 > Fixed2 ? Fixed1 : Fixed2);
}

const Fixed &Fixed::max(const Fixed &Fixed1, const Fixed &Fixed2) {
  return (Fixed1 > Fixed2 ? Fixed1 : Fixed2);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj){
    os << obj.toFloat();
    return os;
};

