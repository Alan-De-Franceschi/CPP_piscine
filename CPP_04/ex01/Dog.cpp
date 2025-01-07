#include "Dog.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

Dog::Dog(void)
{
	this->_type = "Dog";
	std::cout
		<< "Dog: Constructor Called"
		<< std::endl;
	return ;
}

Dog::Dog(Dog const & src)
{
	*this = src;
	std::cout
		<< "Dog: Copy Constructor Called"
		<< std::endl;
	return ;
}

Dog::~Dog(void)
{
	std::cout
		<< "Dog: Copy Destructor Called"
		<< std::endl;
	return;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

Dog &	Dog::operator=(Dog const & rhs)
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

void		Dog::makeSound(void) const
{
    std::cout
        << this->_type
        << ": WOOF!"
        << std::endl;
    return ;
}