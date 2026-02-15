#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
    private:
        enum Grades {
                REQUIRED_SIGN_GRADE = 72,
                REQUIRED_EXECUTE_GRADE = 45
            };

        std::string _target;

        static const int _requiredSignGrade = REQUIRED_SIGN_GRADE;
        static const int _requiredExecuteGrade = REQUIRED_EXECUTE_GRADE;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& src);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const & executor) const;
};

#endif
