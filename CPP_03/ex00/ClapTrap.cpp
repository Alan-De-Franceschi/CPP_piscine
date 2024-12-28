#include "ClapTrap.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

ClapTrap::ClapTrap(void)
{
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout 
		<< this->_name
		<< ": Copy Constructor called"
		<< std::endl;
	*this = src;
	return ;
}

ClapTrap::ClapTrap(std::string const & name) : _name(name), _hit(10), _energy(10), _attack(0)
{
	std::cout 
		<< this->_name
		<< ": Constructor called"
		<< std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout 
		<< this->_name
		<< ": Destructor called"
		<< std::endl;
	return ;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

ClapTrap &	ClapTrap::operator=(ClapTrap const & rhs)
{
	this->_name = rhs._name;
	this->_hit = rhs._hit;
	this->_energy = rhs._energy;
	this->_attack = rhs._attack;
	return (*this);
}

/****************************************************************************/
/*                           Getters / Setters                              */
/****************************************************************************/

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

void	ClapTrap::setName(std::string const & name)
{
	this->_name = name;
	return ;
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void	ClapTrap::attack(const std::string & target)
{
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	return ;
}
