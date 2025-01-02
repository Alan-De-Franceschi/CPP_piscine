#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define GREEN 	"\033[0;32m"
# define BLUE	"\033[0;36m"
# define END	"\033[0m"

class ClapTrap
{
	public:

		ClapTrap(ClapTrap const & src);
		ClapTrap(std::string const & name);
		~ClapTrap(void);

		ClapTrap &		operator=(ClapTrap const & rhs);

		std::string		getName(void) const;
		void			setName(std::string const & name);
		int				getAttack(void) const;
		void			setAttack(unsigned int const attack);
		
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			showStats(void);

	protected:

		std::string		_name;
		unsigned int	_hit;
		unsigned int	_maxHit;
		unsigned int	_energy;
		unsigned int	_attack;
		std::string		_className;

		ClapTrap(void);
};

#endif