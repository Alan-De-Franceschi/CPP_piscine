#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(int ac, char **av) 
{
    if (ac > 2 || ac < 2)
        return (1);

    Intern      random;
    Bureaucrat  boss("Boss", 1);
    AForm*      form = NULL;

    try
    {
        form = random.makeForm(av[1], "Bender");

        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }
    catch (const std::exception & e)
    {
        std::cerr
            << RED
            << "Error -> quit"
            << END
            << std::endl;
        delete form;
        return (1);
    }
    return (0);
}
