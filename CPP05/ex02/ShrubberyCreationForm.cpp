#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation Form", requiredSignGrade, requiredExecuteGrade), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) 
    : AForm("Shrubbery Creation Form", requiredSignGrade, requiredExecuteGrade), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : AForm(src), _target(src._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
    if(this != &src) {
        AForm::operator=(src);
        _target = src._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
