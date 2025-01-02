#include "ScavTrap.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

ScavTrap::ScavTrap(void)
{
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	*this = src;
	std::cout
		<< this->_className
		<< " "
		<< this->_name
		<< ": Copy Constructor called"
		<< std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string const & name) : ClapTrap(name), _gkMode(false)
{
	this->_hit = 100;
	this->_maxHit = 100;
	this->_energy = 50;
	this->_attack = 20;
	this->_className = "ScavTrap";
	std::cout
		<< this->_className
		<< " "
		<< this->_name
		<< ": Constructor called"
		<< std::endl;
    return ;
}

ScavTrap::~ScavTrap(void)
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

ScavTrap &	ScavTrap::operator=(ScavTrap const & rhs)
{
	ClapTrap::operator=(rhs);
	this->_gkMode = rhs._gkMode;
	return (*this);
}

/****************************************************************************/
/*                           Getters / Setters                              */
/****************************************************************************/


/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void	ScavTrap::guardGate(void)
{
	if (this->_gkMode)
	{
		std::cout
			<< this->_className
			<< " "
			<< this->_name
			<< " is already in Gate Keeper mode!"
			<< std::endl;
	}
	else
	{
		std::cout
			<< this->_className
			<< " "
			<< this->_name
			<< " is now in Gate Keeper mode!"
			<< std::endl;
			this->_gkMode = true;
	}
	return ;
}
