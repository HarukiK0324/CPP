#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(_lowestGrade) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    if (this != &src) {
        _grade = src._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::setGrade(int grade)
{
    if (grade < _highestGrade) {
        throw GradeTooHighException("grade is too high");
    }
    else if (grade > _lowestGrade) {
        throw GradeTooLowException("grade is too low");
    }
    this->_grade = grade;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}

void Bureaucrat::incrementGrade()
{
    setGrade(_grade - 1);
}

void Bureaucrat::decrementGrade()
{
    setGrade(_grade + 1);
}
