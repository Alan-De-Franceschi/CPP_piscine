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
	*this = src;
	std::cout 
		<< this->_className
		<< " "
		<< this->_name
		<< ": Copy Constructor called"
		<< std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string const & name) : _name(name), _hit(10), _maxHit(10), _energy(10), _attack(0), _className("ClapTrap")
{
	std::cout
		<< this->_className
		<< " "
		<< this->_name
		<< ": Constructor called"
		<< std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout 
		<< "ClapTrap "
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
	this->_maxHit = rhs._maxHit;
	this->_energy = rhs._energy;
	this->_attack = rhs._attack;
	this->_className = rhs._className;
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

int	ClapTrap::getAttack(void) const
{
	return (this->_attack);
}

void	ClapTrap::setAttack(unsigned int const attack)
{
	this->_attack = attack;
	return ;
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void	ClapTrap::attack(const std::string & target)
{
	if (this->_energy > 0 && this->_hit > 0)
	{
		std::cout
			<< this->_className
			<< " "
			<< this->_name
			<< " attacks "
			<< target
			<< ", causing "
			<< this->_attack
			<< " points of damage!"
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

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout
		<< this->_className
		<< " "
		<< this->_name
		<< " took "
		<< amount
		<< " points of damage";
	if (this->_hit == 0)
	{
		std::cout 
			<< " but it's already broken!" 
			<< std::endl;
		return ;
	}
	if (amount >= this->_hit)
	{
		this->_hit = 0;
		std::cout 
			<< " and is now broken!" 
			<< std::endl;
		return ;
	}
	this->_hit -= amount;
	std::cout << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy > 0 && this->_hit > 0)
	{
		if (this->_hit == this->_maxHit)
		{
			std::cout
				<< this->_className
				<< " "
				<< this->_name
				<< " has all its life points, it wasted one energy point :(!"
				<< std::endl;
		}
		else
		{
			std::cout
				<< this->_className
				<< " "
				<< this->_name
				<< " recovers ";
			if (amount + this->_hit > this->_maxHit )
			{
				std::cout
					<< this->_maxHit - this->_hit
					<< " life points!"
					<< std::endl;
				this->_hit += this->_maxHit - this->_hit;
			}
			else
			{
				this->_hit += amount;
				std::cout
					<< amount
					<< " life points!"
					<< std::endl;
			}
		}
		this->_energy--;
	}
	else if (this->_hit == 0)
	{
		std::cout
			<< this->_className
			<< " "
			<< this->_name
			<< " can't repair itself because it's too broken!"
			<< std::endl;
	}
	else if (this->_energy == 0)
	{
		std::cout
			<< this->_className
			<< " "
			<< this->_name
			<< " can't repair itself because it has no energy left!"
			<< std::endl;
	}
	return ;
}

void	ClapTrap::showStats(void)
{
	std::cout 
		<< BLUE 
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
