#include "FragTrap.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

FragTrap::FragTrap(void)
{
	return ;
}

FragTrap::FragTrap(FragTrap const & src)
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

FragTrap::FragTrap(std::string const & name) : ClapTrap(name)
{
	this->_hit = 100;
	this->_maxHit = 100;
	this->_energy = 100;
	this->_attack = 30;
	this->_className = "FragTrap";
	std::cout
		<< this->_className
		<< " "
		<< this->_name
		<< ": Constructor called"
		<< std::endl;
    return ;
}

FragTrap::~FragTrap(void)
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

FragTrap &	FragTrap::operator=(FragTrap const & rhs)
{
	ClapTrap::operator=(rhs);
	return (*this);
}

/****************************************************************************/
/*                           Getters / Setters                              */
/****************************************************************************/


/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void	FragTrap::attack(const std::string & target)
{
	if (this->_energy > 0 && this->_hit > 0)
	{
		std::cout
			<< this->_className
			<< " "
			<< this->_name
			<< " CHAAAAARGE on "
			<< target
			<< ", causing "
			<< this->_attack
			<< " damages, sorry not sorry!"
			<< std::endl;
		this->_energy--;
	}
	else if (this->_hit == 0)
	{
		std::cout
			<< this->_className
			<< " "
			<< this->_name
			<< " can't attack because it's too broken!"
			<< std::endl;
	}
	else if (this->_energy == 0)
	{
		std::cout
			<< this->_className
			<< " "
			<< this->_name
			<< " can't attack, it has no energy left!"
			<< std::endl;
	}
	return ;
}

void FragTrap::highFivesGuys(void)
{
    std::cout
        << this->_className
        << " "
        << this->_name
        << " is ready for an HIGH FIVES!!"
        << std::endl;
    return ;
}
