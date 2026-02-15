#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    private:
        enum Grades {
                REQUIRED_SIGN_GRADE = 145,
                REQUIRED_EXECUTE_GRADE = 137
            };
        std::string _target;

        static const int _requiredSignGrade = REQUIRED_SIGN_GRADE;
        static const int _requiredExecuteGrade = REQUIRED_EXECUTE_GRADE;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& src);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const & executor) const;
};

#endif
