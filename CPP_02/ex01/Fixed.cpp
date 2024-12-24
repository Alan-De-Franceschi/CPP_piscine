#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout 
		<< "Default constructor called"
		<< std::endl;
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout
		<< "Copy constructor called"
		<< std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(int const src)
{
	std::cout
		<< "Int constructor called"
		<< std::endl;
	return ;
}

Fixed::Fixed(float const src)
{
	std::cout
		<< "Float constructor called"
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

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout
		<< "Copy assignment operator called"
		<< std::endl;
	this->_rawBits = rhs.getRawBits();
	return (*this);
}

float   Fixed::toFloat(void) const
{
	return ;
}

int     Fixed::toInt(void) const
{
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
