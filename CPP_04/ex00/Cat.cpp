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
	return ;
}

Cat::Cat(Cat const & src) : Animal(src)
{
	*this = src;
	std::cout
		<< BLUE
		<< "Cat: Copy Constructor Called"
		<< END
		<< std::endl;
	return ;
}

Cat::~Cat(void)
{
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
		<< BLUE
        << this->_type
        << ": MEOW!"
		<< END
        << std::endl;
    return ;
}
