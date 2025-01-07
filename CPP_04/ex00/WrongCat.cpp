#include "WrongCat.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

WrongCat::WrongCat(void)
{
	this->_type = "WrongCat";
	std::cout
		<< "WrongCat: Constructor Called"
		<< std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const & src)
{
	*this = src;
	std::cout
		<< "WrongCat: Copy Constructor Called"
		<< std::endl;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout
		<< "WrongCat: Destructor Called"
		<< std::endl;
	return;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

WrongCat &	WrongCat::operator=(WrongCat const & rhs)
{
	WrongAnimal::operator=(rhs);
	return (*this);
}

/****************************************************************************/
/*                           Getters / Setters                              */
/****************************************************************************/

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/
