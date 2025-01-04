#include "DiamondTrap.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

DiamondTrap::DiamondTrap(void)
{
    return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src)
{
	*this = src;
	return ;
}

DiamondTrap::DiamondTrap(std::string const & name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    this->_hit = FragTrap::_defaultHit;
    this->_maxHit = FragTrap::_defaultHit;
    this->_energy = ScavTrap::_defaultEnergy;
	this->_attack = FragTrap::_defaultAttack;
	this->_className = "DiamondTrap";
	std::cout
		<< this->_className
		<< " "
		<< this->_name
		<< ": Constructor called"
		<< std::endl;
    return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout 
		<< this->_className
		<< " "
		<< this->_name
		<< ": Destructor called"
		<< std::endl;
	return;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

DiamondTrap &	DiamondTrap::operator=(DiamondTrap const & rhs)
{
	this->ClapTrap::_name = rhs.ClapTrap::_name;
    this->DiamondTrap::_name = rhs.DiamondTrap::_name;
    this->_hit = rhs._hit;
	this->_maxHit = rhs._maxHit;
    this->_energy = rhs._energy;
    this->_attack = rhs._attack;
	this->_className = rhs._className;
	this->ScavTrap::_gkMode = rhs.ScavTrap::_gkMode;
	return (*this);
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void	DiamondTrap::attack(const std::string & target)
{
	ScavTrap::attack(target);
	return ;
}

void DiamondTrap::whoAmI(void)
{
	std::cout
		<< "I'm a "
		<< this->_className
		<< ", my names are "
		<< this->_name
		<< " and "
		<< this->ClapTrap::_name
		<< std::endl;
	return ;
}

void	DiamondTrap::showStats(void)
{
	std::cout 
		<< BLUE
		<< this->_className
		<< " "
		<< this->_name 
		<< " hit = " 
		<< this->_hit 
		<< ", attack = " 
		<< this->_attack 
		<< ", energy = " 
		<< this->_energy 
		<< END 
		<< std::endl;
	return ;
}