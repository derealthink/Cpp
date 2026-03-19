#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int n;
        static const int frac = 8;
    public:
        Fixed(); //default constructor
        Fixed(const int n); //int constructor
        Fixed(const float n);//float constrcutor
        Fixed(const Fixed &copy); //copy constructor
        
        Fixed& operator=(const Fixed &copy); //copy assignment operator
        float toFloat( void ) const;
        int toInt( void ) const;
        ~Fixed();//destrcutor
        
        int getRawBits(void) const;
        void setRawBits(int const raw);

        bool operator<(const Fixed& other) const;
        bool operator>(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed operator++(int)
        



        //friend because needs access but inst member
        friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);
};


#endif