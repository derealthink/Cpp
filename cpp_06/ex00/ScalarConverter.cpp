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

bool ScalarConverter::isChar(std::string& rep)
{
    if (rep.size() == 1 && std::isprint(rep.at(0)) 
        && !std::isdigit(rep.at(0)))
        return true;
    else
        return false;
}

bool ScalarConverter::isInteger(std::string& rep)
{
    int len = rep.length();
    int i = 0;
    if (rep.at(i) == '-')
        i++;
    
    while (i < len)
    {
        if (!std::isdigit(rep.at(i)))
            return false;
        i++;
    }
    return true;
}

bool ScalarConverter::isFloat(std::string& rep)
{
    int len = rep.length();
    size_t pos = rep.find('.');
    
    if (pos == std::string::npos || rep.at(len - 1) != 'f')
        return false;
    int i = 0;
    int s = 0;
    if (rep.at(i) == '-')
        i++;
    while (i < len)
    {
        if (rep[i] == '.' || rep[i] == 'f')
            s++;
        else if (!isdigit(rep.at(i)))
            return false;
        i++;
    }
    if (s != 2)
        return false;

    return true;
}

bool ScalarConverter::isDouble(std::string& rep)
{
    size_t pos = rep.find('.');
    int len = rep.length();
    if (pos == std::string::npos)
        return false;
    int s = 0;
    for (int i = 0; i < len; i++)
    {
        if (rep.at(i) == '.')
            s++;
        else if (!isdigit(rep.at(i)))
            return false;
    }

    if (s != 1)
        return false;

    return true;
}

bool ScalarConverter::isInfinite(std::string& rep)
{
    return (rep == "nan" || rep == "+inf" || rep == "-inf" ||
        rep == "nanf" || rep == "+inff" || rep == "-inff");
}

void ScalarConverter::convertToNumber(const std::string &rep,long double number) 
{
    if (number < std::numeric_limits<char>::min() ||number > std::numeric_limits<char>::max())
        std::cout << "char: overflows" << std::endl;
    
    else
        convertToChar(static_cast<char>(number));

    
    if (number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max())
        std::cout << "int: overflows" << std::endl;
    
    else
        std::cout << "int: " << std::atoi(rep.c_str()) << std::endl;
    
    if (number < -std::numeric_limits<float>::max() || number > std::numeric_limits<float>::max())
        std::cout << "float: overflows" << std::endl;
    
    else
        std::cout << "float: " << std::strtof(rep.c_str(), NULL) << "f"<< std::endl;
    
    if (number < -std::numeric_limits<double>::max() || number > std::numeric_limits<double>::max())
        std::cout << "double: overflows" << std::endl;
    
    else
        std::cout << "double: " << std::strtod(rep.c_str(), NULL) << std::endl;
}


void ScalarConverter::convertFromChar(const std::string &rep) 
{
    convertToChar(rep[0]);
    std::cout << "int: " << static_cast<int>(rep[0]) << std::endl;
  
    std::cout << "float: " << static_cast<float>(rep[0]) << "f"<< std::endl;
  
    std::cout << "double: " << static_cast<double>(rep[0])<< std::endl;
}

void ScalarConverter::convertToChar(const char &c) 
{
    if (std::isprint(c)) 
        std::cout << "char: " << "'" << c << "'" << std::endl; 
    else
        std::cout << "char: "<< "Non displayable" << std::endl;
}

void ScalarConverter::convertFromInfinite(const std::string &rep) 
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (rep.find("nan") != std::string::npos) 
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        } 
    else 
        {
            std::cout << "float: " << rep[0] << "inff" << std::endl;
            std::cout << "double: " << rep[0] << "inf" << std::endl;
        }
}

void ScalarConverter::convert(const std::string &rep) 
{
    if (isChar(rep)) 
        convertFromChar(rep);
    else if (isInteger(rep)) 
        convertToNumber(rep, std::strtold(rep.c_str(), NULL));
    else if (isFloat(rep)) 
        convertToNumber(rep, std::strtold(rep.c_str(), NULL));
    else if (isDouble(rep)) 
        convertToNumber(rep, std::strtold(rep.c_str(), NULL));
    else if (isInfinite(rep)) 
        convertFromInfinite(rep);
    else
        std::cout << "Unknown type" << std::endl;
}
