#include "Bureaucrat.hpp"
#include "Form.hpp"

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
            std::cerr
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
            std::cerr
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
            std::cerr
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
            std::cerr
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
            std::cerr
                << RED
                << "Error -> quit"
                << END
                << std::endl;
           return (1);
        }
    }


    else if (av[1][0] == '5')
    {
        std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==                   TEST 5                   =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;

        try
        {
            Form a("Glam", 10, 100);
            Form b (a);
            std::cout
                << b
                << std::endl;
        }
        catch(const std::exception & e)
        {
            std::cerr
                << RED
                << "Error -> quit"
                << END
                << std::endl;
           return (1);
        }
    }


    else if (av[1][0] == '6')
    {
        std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==                   TEST 6                   =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;

        try
        {
            Form a("Glam", 151, 151);
        }
        catch(const std::exception & e)
        {
            std::cerr
                << RED
                << "Error -> quit"
                << END
                << std::endl;
           return (1);
        }
    }


    else if (av[1][0] == '7')
    {
        std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==                   TEST 7                   =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;

        try
        {
            Form b("BeautifulForm", 10, 100);
            Bureaucrat a("Pinky", 1);
            
            std::cout << b << std::endl;
            a.signForm(b);
            std::cout << b << std::endl;
        }
        catch(const std::exception & e)
        {
            std::cerr
                << RED
                << "Error -> quit"
                << END
                << std::endl;
           return (1);
        }
    }


    else if (av[1][0] == '8')
    {
        std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==                   TEST 8                   =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;

        try
        {
            Form b("BeautifulForm", 1, 100);
            Bureaucrat a("Pinky", 2);
            
            std::cout << b << std::endl;
            a.signForm(b);
        }
        catch(const std::exception & e)
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
