#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cout << "Zzz..." << std::endl, 1);

    Harl        harl;
    std::string level = av[1];
    harl.complain(level);
    return (0);
}