#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& src) {
    (void)src;
}

Intern& Intern::operator=(const Intern& src) {
    (void)src;
    return *this;
}

Intern::~Intern() {}

AForm* createPresidential(std::string const& target) {
    return new PresidentialPardonForm(target);
}

AForm* createRobotomy(std::string const& target) {
    return new RobotomyRequestForm(target);
}

AForm* createShrubbery(std::string const& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string const& name, std::string const& target) {
    AForm* form = NULL;
    std::string formNames[] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };
    AForm* (*formCreators[])(std::string const&) = {
        &createPresidential,
        &createRobotomy,
        &createShrubbery
    };

    for(int i = 0;i < 3;i++) {
        if(name == formNames[i]) {
            form = formCreators[i](target);
            std::cout << "Intern creates " << name << " form." << std::endl;
            return form;
        }
    }
    std::cout << "Intern could not find the form: " << name << std::endl;
    return NULL;
}
