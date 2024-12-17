#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

const std::string	&Weapon::getType(void)
{
	const std::string	&_typeREF = this->_type;
	return (_typeREF);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}
