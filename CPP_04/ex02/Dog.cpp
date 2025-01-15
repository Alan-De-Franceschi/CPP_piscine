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
	this->_brain = new (std::nothrow) Brain();
	return ;
}

Dog::Dog(Dog const & src) : Animal(src)
{
	std::cout
		<< GREEN
		<< "Dog: Copy Constructor Called"
		<< END
		<< std::endl;
	this->_brain = new (std::nothrow) Brain();
	*this = src;
	return ;
}

Dog::~Dog(void)
{
	if (this->_brain)
		delete this->_brain;
	std::cout
		<< GREEN
		<< "Dog: Destructor Called"
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
	if (this->_brain)
		delete this->_brain;
	this->_brain = new (std::nothrow) Brain(*rhs._brain);
	return (*this);
}

/****************************************************************************/
/*                           Getters / Setters                              */
/****************************************************************************/

const std::string	Dog::getIdea(int i) const
{
	if (!this->_brain)
		return ("(null brain)");
	return (this->_brain->getIdea(i));
}

void	Dog::setIdea(int i, const std::string & idea)
{
	if (i > 99 || i < 0)
	{
		std::cout
			<< "Dog brain has only 100 ideas"
			<< std::endl;
		return ;
	}
	if (!this->_brain)
	{
		std::cout << "(null brain)" << std::endl;
		return ;
	}
	this->_brain->setIdea(i, idea);
	return ;
}

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
