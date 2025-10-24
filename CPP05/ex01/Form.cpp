#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150) {}

Form::Form(const std::string& name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < _highestGrade || signGrade > _lowestGrade) {
        throw GradeTooHighException("sign grade is out of range");
    }
    if (executeGrade < _highestGrade || executeGrade > _lowestGrade) {
        throw GradeTooLowException("execute grade is out of range");
    }
}

Form::Form(const Form& src)
    : _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _executeGrade(src._executeGrade) {}

Form& Form::operator=(const Form& src) {
    if (this != &src) {
        _isSigned = src._isSigned;
    }
    return *this;
}

Form::~Form() {}

std::string Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _isSigned;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExecuteGrade() const {
    return _executeGrade;
}

std::ostream& operator<<(std::ostream& os, const Form& src) {
    os << "Form Name: " << src.getName()
       << ", Signed: " << (src.isSigned() ? "Yes" : "No")
       << ", Sign Grade: " << src.getSignGrade()
       << ", Execute Grade: " << src.getExecuteGrade();
    return os;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if(bureaucrat.getGrade() <= _signGrade)
        _isSigned = true;
    else
        throw GradeTooLowException(("bureaucrat " + bureaucrat.getName() + "'s grade is too low to sign the form").c_str());
}
