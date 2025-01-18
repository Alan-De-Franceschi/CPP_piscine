#include "Bureaucrat.hpp"
#include <iostream>

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
            Bureaucrat a("Pinky", 1);
            std::cout
                << a
                << std::endl;
            Bureaucrat b("Glam", 0);
        }
        catch(const std::exception & e)
        {
            std::cout
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
            Bureaucrat a("Pinky", 2);
            std::cout
                << a
                << std::endl;
            Bureaucrat b(a);
            std::cout
                << b
                << std::endl;
            a.upGrade();
            b.downGrade();
            std::cout
                << a
                << std::endl;
            std::cout
                << b
                << std::endl;
        }
        catch(const std::exception & e)
        {
            std::cout
                << RED
                << "Error -> quit"
                << END
                << std::endl;
           return (1);
        }
    }
    else if (av[1][0] == '3')
    {
        std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==                   TEST 3                   =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;

        try
        {
            Bureaucrat a("Pinky", 1);
            std::cout
                << a
                << std::endl;
            a.upGrade();
        }
        catch(Bureaucrat::GradeTooHighException & e)
        {
            std::cout
                << RED
                << e.what()
                << std::endl
                << "Error -> quit"
                << END
                << std::endl;
           return (1);
        }
        catch(const std::exception & e)
        {
            std::cout
                << RED
                << "Error -> quit"
                << END
                << std::endl;
           return (1);
        }
    }
    else if (av[1][0] == '4')
    {
        std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==                   TEST 4                   =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;

        try
        {
            Bureaucrat a("Pinky", 150);
            std::cout
                << a
                << std::endl;
            a.downGrade();
        }
        catch(Bureaucrat::GradeTooLowException & e)
        {
            std::cout
                << RED
                << e.what()
                << std::endl
                << "Error -> quit"
                << END
                << std::endl;
           return (1);
        }
        catch(const std::exception & e)
        {
            std::cout
                << RED
                << "Error -> quit"
                << END
                << std::endl;
           return (1);
        }
    }
    return (0);
}
