#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <string>
#include <iostream>
#include <cmath>


class ScalarConverter
{
    private: 
    
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &copy);
        virtual ~ScalarConverter() = 0;

        static bool isInteger(std::string &rep);
        static bool isChar(std::string &rep);
        static bool isFloat(std::string &rep);
        static bool isDouble(std::string &rep);
        static bool isInfinite(std::string &rep);

        static void convertToNumber(const std::string &rep,long double number);
        static void convertFromChar(const std::string &rep);
        static void convertToChar(const char &c);
        static void convertFromInfinite(const std::string &rep);
    public:
        static void convert(const std::string &rep);
};





#endif 