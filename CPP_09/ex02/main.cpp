#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac < 2)
            throw std::invalid_argument("Error: too few arguments");

        PmergeMe    item;
        
        for (int i = 1; av[i]; i++)
        {
            std::string intList = av[i];
            item.parsing(intList);
        }
        item.printVector();
        item.printDeque();
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