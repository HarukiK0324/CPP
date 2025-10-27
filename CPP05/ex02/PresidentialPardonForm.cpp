#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Pardon Form", requiredSignGrade, requiredExecuteGrade), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) 
    : AForm("Presidential Pardon Form", requiredSignGrade, requiredExecuteGrade), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
    : AForm(src), _target(src._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
    if(this != &src) {
        AForm::operator=(src);
        _target = src._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

