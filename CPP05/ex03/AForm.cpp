#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150) {}

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < _highestGrade || executeGrade < _highestGrade) {
        throw GradeTooHighException("grade is too high");
    }
    if (signGrade > _lowestGrade || executeGrade > _lowestGrade) {
        throw GradeTooLowException("grade is too low");
    }
}

AForm::AForm(const AForm& src)
    : _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _executeGrade(src._executeGrade) {}

AForm& AForm::operator=(const AForm& src) {
    if (this != &src) {
        _isSigned = src._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _isSigned;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecuteGrade() const {
    return _executeGrade;
}

std::ostream& operator<<(std::ostream& os, const AForm& src) {
    os << "Form Name: " << src.getName()
       << ", Signed: " << (src.isSigned() ? "Yes" : "No")
       << ", Sign Grade: " << src.getSignGrade()
       << ", Execute Grade: " << src.getExecuteGrade();
    return os;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if(isSigned())
    {
        throw AlreadySignedException("form is already signed");
    }
    else if(bureaucrat.getGrade() <= _signGrade)
        _isSigned = true;
    else
        throw GradeTooLowException("grade is too low");
}

void AForm::beExecuted(Bureaucrat const & executor) const {
    if (!this->isSigned())
        throw NotSignedException("form is not signed");
    if (executor.getGrade() > this->getExecuteGrade())
        throw GradeTooLowException("executor's grade is too low to execute the form");
    std::cout << executor.getName() << " executed " << this->getName() << std::endl;
    this->execute(executor);
}
