

#include "Zombie.hpp"

Zombie::Zombie(std::string z_name) : name(z_name)
{
    return ;
}

Zombie::~Zombie(void)
{
    std::cout
        << this->name
        << ": destructor called"
        << std::endl;
    return ;
}

void    Zombie::announce(void)
{
    std::cout 
        << this->name 
        << ": BraiiiiiiinnnzzzZ..." 
        << std::endl;
    return ;
}
