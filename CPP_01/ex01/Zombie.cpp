#include "Zombie.hpp"

Zombie::Zombie(void)
{
    return ;
}

Zombie::Zombie(std::string z_name) : _name(z_name)
{
    return ;
}

Zombie::~Zombie(void)
{
    std::cout
        << this->_name
        << ": destructor called"
        << std::endl;
    return ;
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
    return ;
}

void    Zombie::announce(void)
{
    std::cout 
        << this->_name 
        << ": BraiiiiiiinnnzzzZ..." 
        << std::endl;
    return ;
}
