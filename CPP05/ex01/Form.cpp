#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150) {}

Form::Form(const std::string& name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < _highestGrade || executeGrade < _highestGrade) {
        throw GradeTooHighException("grade is too high");
    }
    if (signGrade > _lowestGrade || executeGrade > _lowestGrade) {
        throw GradeTooLowException("grade is too low");
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
    if(isSigned())
    {
        throw AlreadySignedException("form is already signed");
    }
    else if(bureaucrat.getGrade() <= _signGrade)
        _isSigned = true;
    else
        throw GradeTooLowException("grade is too low");
}
