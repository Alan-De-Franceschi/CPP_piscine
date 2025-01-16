#include "Bureaucrat.hpp"
#include <iostream>

int main(void) 
{
    try
    {
        Bureaucrat a("Pinky", 1);
        std::cout
            << a.getName()
            << ": grade "
            << a.getGrade()
            << std::endl;
        Bureaucrat b("Glam", 0);
    }
    catch(const std::exception & e)
    {
        std::cout
            << "Error -> quit"
            << std::endl;
       return (1);
    }
    return (0);
}
