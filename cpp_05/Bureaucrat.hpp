#ifndef BUREAUCRAT_HPP
#define BUREACRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat : public std::exception
{
    private:
        std::string const name;
        unsigned int grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat& operator=(const Bureaucrat &copy);
        ~Bureaucrat();

        void getName();
        void getGrade();
   

};  


#endif