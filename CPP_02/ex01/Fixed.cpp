#include "Fixed.hpp"

int const	Fixed::_nBits = 8;

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
	this->_rawBits = src * (1 << _nBits);
	return ;
}

Fixed::Fixed(float const src)
{
	std::cout
		<< "Float constructor called"
		<< std::endl;
	this->_rawBits = static_cast<int>(roundf(src * (1 << _nBits)));
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
	return (static_cast<float>(this->_rawBits) / (1 << _nBits));
}

int     Fixed::toInt(void) const
{
	return (this->_rawBits / (1 << _nBits));
}

int	Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
	return ;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}
