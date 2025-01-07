#include "WrongAnimal.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

WrongAnimal::WrongAnimal(void) : _type("Undefined Wronganimal")
{
    std::cout
        << "WrongAnimal: Constructor Called"
        << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
    *this = src;
    std::cout
        << "WrongAnimal: Copy Constructor Called"
        << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout
        << "WrongAnimal: Destructor Called"
        << std::endl;
	return;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & rhs)
{
	this->_type = rhs._type;
	return (*this);
}

/****************************************************************************/
/*                           Getters / Setters                              */
/****************************************************************************/

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::setType(int const type)
{
	this->_type = type;
	return ;
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void		WrongAnimal::makeSound(void) const
{
    std::cout
        << this->_type
        << ": undefined sound"
        << std::endl;
    return ;
}
