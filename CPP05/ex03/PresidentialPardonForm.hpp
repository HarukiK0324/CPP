#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        enum Grades {
                REQUIRED_SIGN_GRADE = 25,
                REQUIRED_EXECUTE_GRADE = 5
            };
        std::string _target;

        static const int _requiredSignGrade = REQUIRED_SIGN_GRADE;
        static const int _requiredExecuteGrade = REQUIRED_EXECUTE_GRADE;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& src);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const & executor) const;
};

#endif
