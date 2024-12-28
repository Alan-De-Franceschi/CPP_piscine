#include "Canonical.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

Canonical::Canonical(void)
{
	return ;
}

Canonical::Canonical(Canonical const & src)
{
	return ;
}

Canonical::~Canonical(void)
{
	return;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

Canonical &	Canonical::operator=(Canonical const & rhs)
{
	this->_attribute = rhs.getAttribute();
	return ;
}

std::ostream &	operator<<(std::ostream & o, Canonical const & rhs)
{
	o << rhs.getAttribute();
	return ;
}

/****************************************************************************/
/*                           Getters / Setters                              */
/****************************************************************************/

int	Canonical::getAttribute(void) const
{
	return (this->_attribute);
}

void	Canonical::setAttribute(int const attribute)
{
	this->_attribute = attribute;
	return ;
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/
