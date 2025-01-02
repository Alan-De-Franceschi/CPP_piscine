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

void FragTrap::highFivesGuys(void)
{
    std::cout
        << this->_className
        << " "
        << this->_name
        << "is ready for an HIGH FIVES!!"
        << std::endl;
    return ;
}
