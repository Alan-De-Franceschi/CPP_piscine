#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac < 2)
            throw std::invalid_argument("Error: too few arguments");
        else if (ac > 2)
            throw std::invalid_argument("Error: too many arguments");
        ScalarConverter::convert(av[1]);
    }
    catch(std::exception & e)
    {
        std::cerr
            << RED
            << e.what()
            << END
            << std::endl;
    }
    return (0);
}