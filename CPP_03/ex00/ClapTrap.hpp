#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	public:

		ClapTrap(ClapTrap const & src);
		ClapTrap(std::string const & name);
		~ClapTrap(void);

		ClapTrap &	operator=(ClapTrap const & rhs);

		std::string	getName(void) const;
		void		setName(std::string const & name);
		
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	private:

		std::string	_name;
		int			_hit;
		int			_energy;
		int			_attack;

		ClapTrap(void);
};

#endif