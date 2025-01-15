#include "Animal.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

Animal::Animal(void) : _type("Undefined animal")
{
    std::cout
        << YELLOW
        << "Animal: Constructor Called"
        << END
        << std::endl;
	return ;
}

Animal::Animal(Animal const & src)
{
    *this = src;
    std::cout
        << YELLOW
        << "Animal: Copy Constructor Called"
        << END
        << std::endl;
	return ;
}

Animal::~Animal(void)
{
    std::cout
        << YELLOW
        << "Animal: Destructor Called"
        << END
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

const std::string   Animal::getIdea(int i) const
{
    (void)i;
    return ("Undefined animal has no brain!");
}

void    Animal::setIdea(int i, const std::string & idea)
{
    (void)i;
    (void)idea;
    std::cout 
        << "Undefined animal has no brain!" 
        << std::endl;
    return ;
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void		Animal::makeSound(void) const
{
    std::cout
        << YELLOW
        << this->_type
        << ": undefined sound"
        << END
        << std::endl;
    return ;
}
