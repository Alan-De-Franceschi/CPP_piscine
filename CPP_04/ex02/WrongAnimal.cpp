#include "WrongAnimal.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

WrongAnimal::WrongAnimal(void) : _type("Undefined Wronganimal")
{
    std::cout
        << RED
        << "WrongAnimal: Constructor Called"
        << END
        << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
    *this = src;
    std::cout
        << RED
        << "WrongAnimal: Copy Constructor Called"
        << END
        << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout
        << RED
        << "WrongAnimal: Destructor Called"
        << END
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
        << RED
        << this->_type
        << ": undefined sound"
        << END
        << std::endl;
    return ;
}
