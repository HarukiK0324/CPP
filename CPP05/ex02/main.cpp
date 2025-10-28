#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    Bureaucrat bob("Bob", 1);
    Bureaucrat alice("Alice", 50);
    Bureaucrat charlie("Charlie", 150);

    ShrubberyCreationForm shrubberyForm("Home");
    RobotomyRequestForm robotomyForm("Marvin");
    PresidentialPardonForm pardonForm("Arthur");

    // Test ShrubberyCreationForm
    alice.signForm(shrubberyForm);
    alice.executeForm(shrubberyForm);

    // Test RobotomyRequestForm
    bob.signForm(robotomyForm);
    bob.executeForm(robotomyForm);

    // Test PresidentialPardonForm
    bob.signForm(pardonForm);
    bob.executeForm(pardonForm);

    charlie.signForm(pardonForm);  // Should fail due to low grade
    charlie.executeForm(pardonForm);  // Should fail due to low grade
    return 0;
}
