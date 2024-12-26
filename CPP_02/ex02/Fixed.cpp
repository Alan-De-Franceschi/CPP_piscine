#include "Fixed.hpp"

int const	Fixed::_nBits = 8;

/* CONSTRUCTORS - DESTRUCTORS*/

Fixed::Fixed(void) : _rawBits(0)
{
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
	return ;
}

Fixed::Fixed(int const src)
{
	this->_rawBits = src * (1 << _nBits);
	return ;
}

Fixed::Fixed(float const src)
{
	this->_rawBits = static_cast<int>(roundf(src * (1 << _nBits)));
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}

/* OPERATORS */

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	this->_rawBits = rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const & rhs)
{
	float l = this->toFloat();
	float r = rhs.toFloat();

	return (Fixed(l + r));
}

Fixed	Fixed::operator-(Fixed const & rhs)
{
	float l = this->toFloat();
	float r = rhs.toFloat();

	return (Fixed(l - r));
}

Fixed	Fixed::operator*(Fixed const & rhs)
{
	float l = this->toFloat();
	float r = rhs.toFloat();

	return (Fixed(l * r));
}

Fixed	Fixed::operator/(Fixed const & rhs)
{
	float l = this->toFloat();
	float r = rhs.toFloat();

	return (Fixed(l / r));
}

bool	Fixed::operator>(Fixed const & rhs)
{
	if (this->_rawBits > rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const & rhs)
{
	if (this->_rawBits >= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const & rhs)
{
	if (this->_rawBits < rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const & rhs)
{
	if (this->_rawBits <= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const & rhs)
{
	if (this->_rawBits == rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const & rhs)
{
	if (this->_rawBits != rhs.getRawBits())
		return (true);
	return (false);
}

Fixed &	Fixed::operator++()
{
	this->_rawBits += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	++*this;
	return temp;
}

Fixed &	Fixed::operator--()
{
	this->_rawBits -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	--*this;
	return temp;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

/* MEMBER FUNCTIONS */

Fixed &  Fixed::min(Fixed & x, Fixed & y)
{
	if (x <= y)
		return (x);
	return (y);
}

Fixed &  Fixed::min(Fixed const & x, Fixed const & y)
{
	if (x <= y)
		return (x);
	return (y);
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
