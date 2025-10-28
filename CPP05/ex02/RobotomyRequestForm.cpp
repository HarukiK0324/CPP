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

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    (void)executor;
    std::cout << "Bzzzz... Drilling noises..." << std::endl;
    if (rand() % 2) {
        std::cout << _target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "Robotomy on " << _target << " failed." << std::endl;
    }
}
