#include "Dog.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

Dog::Dog(void)
{
	this->_type = "Dog";
	std::cout
		<< GREEN
		<< "Dog: Constructor Called"
		<< END
		<< std::endl;
	return ;
}

Dog::Dog(Dog const & src) : Animal(src)
{
	*this = src;
	std::cout
		<< GREEN
		<< "Dog: Copy Constructor Called"
		<< END
		<< std::endl;
	return ;
}

Dog::~Dog(void)
{
	std::cout
		<< GREEN
		<< "Dog: Copy Destructor Called"
		<< END
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
		<< GREEN
        << this->_type
        << ": WOOF!"
		<< END
        << std::endl;
    return ;
}