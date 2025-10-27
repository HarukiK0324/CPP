#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string _target;

        static const int requiredSignGrade = 25;
        static const int requiredExecuteGrade = 5;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& src);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const & executor) const;
};

#endif
