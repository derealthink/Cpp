#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>
#include <string>

class fixedPoint
{
    private:
        int n;
        static const int frac = 8;
    public:
        fixedPoint(); //constructor
        fixedPoint(const fixedPoint &copy); //copy constructor
        fixedPoint& operator=(const fixedPoint &copy); //copy assignment operator
        ~fixedPoint();

        int getRawbits(void) const;
        void setRawbits(int const raw);
};


#endif