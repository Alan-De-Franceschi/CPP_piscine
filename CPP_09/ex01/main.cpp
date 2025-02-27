#include "RPN.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac < 2)
            throw std::invalid_argument("Error: too few arguments");
        if (ac > 2)
            throw std::invalid_argument("Error: too much arguments");

        RPN calculator;

        calculator.rpnCalculator(av[1]);
    }
    catch (std::exception & e)
    {
        std::cerr
            << RED
            << e.what()
            << END
            << std::endl;
        return (1);
    }
    return (0);
}