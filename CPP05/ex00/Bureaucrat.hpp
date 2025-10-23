#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

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
        
        void incrementGrade();
        void decrementGrade();

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
