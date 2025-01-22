#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(int ac, char **av) 
{
    if (ac > 2 || ac < 2)
        return (1);
    if (av[1][0] == '1')
    {
        std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==                   TEST 1                   =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;

        try
        {
            //ShrubberyCreationForm   form("Pinky");
            //PresidentialPardonForm  form("Pinky");
            RobotomyRequestForm form("Pinky");

            Bureaucrat boss("Boss", 1);

            boss.executeForm(form);
        }
        catch (const std::exception & e)
        {
            std::cerr
                << RED
                << "Error -> quit"
                << END
                << std::endl;
            return (1);
        }
    }

    else if (av[1][0] == '2')
    {
        std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==                   TEST 2                   =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;

        try
        {
            ShrubberyCreationForm   form("Pinky"); // Sign = 145, Exec = 137
            //PresidentialPardonForm  form("Pinky"); // Sign = 25, Exec = 5
            //RobotomyRequestForm form("Pinky"); // Sign = 72, Exec = 45

            Bureaucrat boss("Boss", 1); // Tester differents Grades

            boss.signForm(form);
            boss.executeForm(form);
        }
        catch (const std::exception & e)
        {
            std::cerr
                << RED
                << "Error -> quit"
                << END
                << std::endl;
            return (1);
        }
    }
    return (0);
}
