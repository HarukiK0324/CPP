#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat bob("Bob", 100);
    Form taxForm("Tax Form", 100, 50);
    Form applicationForm("Application Form", 50, 25);
    try
    {
        Form permitForm("Permit Form", 180, 75);
    }
    catch(const std::exception& e)
    {
        std::cerr << "unable to create form: " << e.what() << '\n';
    }

    try {
        bob.signForm(taxForm);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << bob << std::endl;
    bob.signForm(applicationForm);
}
