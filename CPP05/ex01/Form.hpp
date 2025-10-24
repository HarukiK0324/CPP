#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _executeGrade;
        static const int _highestGrade = 1;
        static const int _lowestGrade = 150;
    public:
        Form();
        Form(const std::string& name, int signGrade, int executeGrade);
        Form(const Form& src);
        Form& operator=(const Form& src);
        ~Form();

        std::string getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        friend std::ostream& operator<<(std::ostream& os, const Form& src);

        void beSigned(const Bureaucrat& bureaucrat);

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
                GradeTooLowException(const char *msg) : _errmsg(msg) {}
                const char* what() const throw() {
                    return _errmsg;
                }
        };
};

#endif
