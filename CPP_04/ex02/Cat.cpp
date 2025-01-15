#include "Cat.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

Cat::Cat(void)
{
	this->_type = "Cat";
	std::cout
		<< BLUE
		<< "Cat: Constructor Called"
		<< END
		<< std::endl;
	this->_brain = new (std::nothrow) Brain();
	return ;
}

Cat::Cat(Cat const & src) : Animal(src)
{
	std::cout
		<< BLUE
		<< "Cat: Copy Constructor Called"
		<< END
		<< std::endl;
	this->_brain = new (std::nothrow) Brain;
	*this = src;
	return ;
}

Cat::~Cat(void)
{
	if (this->_brain)
		delete this->_brain;
	std::cout
		<< BLUE
		<< "Cat: Destructor Called"
		<< END
		<< std::endl;
	return;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

Cat &	Cat::operator=(Cat const & rhs)
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

const std::string Cat::getIdea(int i) const
{
	if (!this->_brain)
		return ("(null brain)");
	return (this->_brain->getIdea(i));
}

void	Cat::setIdea(int i, const std::string & idea)
{
	if (i > 99 || i < 0)
	{
		std::cout
			<< "Cat brain has only 100 ideas"
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

void		Cat::makeSound(void) const
{
    std::cout
		<< BLUE
        << this->_type
        << ": MEOW!"
		<< END
        << std::endl;
    return ;
}
