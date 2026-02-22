#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;

        static const int _requiredSignGrade = 145;
        static const int _requiredExecuteGrade = 137;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& src);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const & executor) const;
};

#endif
