#ifndef FORM_HPP
#define FORM_HPP

#define MAX_GRADE 1
#define MIN_GRADE 150

#include <iostream>
#include <string>
#include <exception>


class Form
{
    private:
        std::string const name;
        bool singed;
        unsigned int const signGrade;
        unsigned int const execGrade;
    public:
        Form();
        Form(const Form &copy);
        Form& operator=(const Form &copy);
        ~Form();

        std::string getName() const;
        unsigned int getSignGrade() const;
        unsigned int getExecGrade() const;
        bool getSigned() const;


        class GradeTooHighException : public std::exception
        {
            const char *what() const throw();
        };

        class GradeTooLowException : public std::exception 
        {
            const char *what() const throw();
        };

};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif