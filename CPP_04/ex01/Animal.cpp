#include "Animal.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

Animal::Animal(void) : _type("Undefined animal")
{
    std::cout
        << "Animal: Constructor Called"
        << std::endl;
	return ;
}

Animal::Animal(Animal const & src)
{
    *this = src;
    std::cout
        << "Animal: Copy Constructor Called"
        << std::endl;
	return ;
}

Animal::~Animal(void)
{
    std::cout
        << "Animal: Destructor Called"
        << std::endl;
	return;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

Animal &	Animal::operator=(Animal const & rhs)
{
	this->_type = rhs._type;
	return (*this);
}

/****************************************************************************/
/*                           Getters / Setters                              */
/****************************************************************************/

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::setType(int const type)
{
	this->_type = type;
	return ;
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void		Animal::makeSound(void) const
{
    std::cout
        << this->_type
        << ": undefined sound"
        << std::endl;
    return ;
}
