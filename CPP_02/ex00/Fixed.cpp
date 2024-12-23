#include "Fixed.hpp"

const int Fixed::_nBits = 8;

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout 
		<< "Default constructor called"
		<< std::endl;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout 
		<< "Destructor called"
		<< std::endl;
	return ;
}

int	Fixed::getRawBits(void) const
{
	std::cout
		<< "getRawBits member function called"
		<< std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout
		<< "setRawBits member function called"
		<< std::endl;
	this->_rawBits = raw;
	return ;
}