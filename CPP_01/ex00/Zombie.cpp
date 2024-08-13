

#include "Zombie.hpp"

Zombie::Zombie(std::string z_name) : name(z_name)
{
    Zombie::announce();
    return ;
}

Zombie::~Zombie(void)
{
    return ;
}

void    Zombie::announce(void)
{
    std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}
