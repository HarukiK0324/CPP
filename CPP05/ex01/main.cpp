#include "Form.hpp"

int main()
{
    Bureaucrat bob("Bob", 149);
    try {
        bob.decrementGrade();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << bob << std::endl;
    try {
        bob.decrementGrade();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
