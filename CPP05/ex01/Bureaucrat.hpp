#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;
        static const int _highestGrade = 1;
        static const int _lowestGrade = 150;
        void setGrade(int grade);
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& src);
        Bureaucrat& operator=(const Bureaucrat& src);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
        void incrementGrade();
        void decrementGrade();
        void signForm(class Form& form);

        class GradeTooHighException : public std::exception {
            private:
                const char* _errmsg;
            public:
                GradeTooHighException(const char *msg) : _errmsg(msg) {}
                const char* what() const throw() {
                    return _errmsg;
                }
        };

        class GradeTooLowException : public std::exception {
            private:
                const char* _errmsg;
            public:
                GradeTooLowException(const char* msg) : _errmsg(msg) {}
                const char* what() const throw() {
                    return _errmsg;
                }
        };
};


#endif
