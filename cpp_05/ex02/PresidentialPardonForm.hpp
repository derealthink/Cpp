#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonFormForm : public Form
{
    private:
        std::string _target;
    public:
    PresidentialPardonFormForm();
    PresidentialPardonFormForm(const std::string &target);
    PresidentialPardonFormForm(const PresidentialPardonFormForm &copy);
    PresidentialPardonFormForm &operator=(const PresidentialPardonFormForm &copy);
    ~PresidentialPardonFormForm();
    
    void executer() const;

};


#endif 