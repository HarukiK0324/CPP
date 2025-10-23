#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Bureaucrat bob("Bob", 2);
    try {
        bob.incrementGrade();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << bob.getName() << ", grade " << bob.getGrade() << std::endl;
    try {
        bob.incrementGrade();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
