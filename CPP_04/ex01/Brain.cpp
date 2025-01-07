#include "Brain.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

Brain::Brain(void)
{
	this->_type = "Brain";
	std::cout
		<< "Brain: Constructor Called"
		<< std::endl;
	return ;
}

Brain::Brain(Brain const & src)
{
	*this = src;
	std::cout
		<< "Brain: Copy Constructor Called"
		<< std::endl;
	return ;
}

Brain::~Brain(void)
{
	std::cout
		<< "Brain: Copy Destructor Called"
		<< std::endl;
	return;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

Brain &	Brain::operator=(Brain const & rhs)
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

void		Brain::makeSound(void) const
{
    std::cout
        << this->_type
        << ": WOOF!"
        << std::endl;
    return ;
}