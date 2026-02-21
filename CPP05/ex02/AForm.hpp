#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _executeGrade;
        static const int _highestGrade = highestGrade;
        static const int _lowestGrade = lowestGrade;
    public:
        AForm();
        AForm(const std::string& name, int signGrade, int executeGrade);
        AForm(const AForm& src);
        AForm& operator=(const AForm& src);
        virtual ~AForm();

        std::string getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        friend std::ostream& operator<<(std::ostream& os, const AForm& src);

        void beSigned(const Bureaucrat& bureaucrat);
        void beExecuted(Bureaucrat const & executor) const;
        virtual void execute(Bureaucrat const & executor) const = 0;

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

        class NotSignedException : public std::exception {
            private:
                const char* _errmsg;
            public:
                NotSignedException(const char *msg) : _errmsg(msg) {}
                const char* what() const throw() {
                    return _errmsg;
                }
        };

        class AlreadySignedException : public std::exception {
            private:
                const char* _errmsg;
            public:
                AlreadySignedException(const char *msg) : _errmsg(msg) {}
                const char* what() const throw() {
                    return _errmsg;
                }
        };
};

#endif
