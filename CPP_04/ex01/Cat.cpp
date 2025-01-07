#include "Cat.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

Cat::Cat(void)
{
	this->_type = "Cat";
	std::cout
		<< "Cat: Constructor Called"
		<< std::endl;
	return ;
}

Cat::Cat(Cat const & src)
{
	*this = src;
	std::cout
		<< "Cat: Copy Constructor Called"
		<< std::endl;
	return ;
}

Cat::~Cat(void)
{
	std::cout
		<< "Cat: Destructor Called"
		<< std::endl;
	return;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

Cat &	Cat::operator=(Cat const & rhs)
{
	Animal::operator=(rhs);
	return (*this);
}

/****************************************************************************/
/*                           Getters / Setters                              */
/****************************************************************************/

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void		Cat::makeSound(void) const
{
    std::cout
        << this->_type
        << ": MEOW!"
        << std::endl;
    return ;
}
