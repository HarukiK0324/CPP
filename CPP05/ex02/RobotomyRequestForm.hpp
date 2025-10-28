#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;

        static const int requiredSignGrade = 72;
        static const int requiredExecuteGrade = 45;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& src);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const & executor) const;
};

#endif
