#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    *this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    if (this == &copy)
        return (*this);
    return (*this);
}

ScalarConverter::~ScalarConverter(){}

bool ScalarConverter::isChar(std::string &rep)
{
    if (rep.size() == 1 && std::isprint(rep.at(0)) 
        && std::isdigit(rep.at(0)))
        return true;
    else
        return false;
}

bool ScalarConverter::isInteger(std::string &rep)
{
    int len = rep.length();
    if (!std::isdigit(rep.at(0)) || rep.at(0) != '-')
        return false;
    for (int i = 1; i < len; i++)
    {
        if (!std::isdigit(rep.at(i)))
            return false;
    }
    return true;
}

