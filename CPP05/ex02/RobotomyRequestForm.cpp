#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request Form", requiredSignGrade, requiredExecuteGrade), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) 
    : AForm("Robotomy Request Form", requiredSignGrade, requiredExecuteGrade), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : AForm(src), _target(src._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
    if(this != &src) {
        AForm::operator=(src);
        _target = src._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

