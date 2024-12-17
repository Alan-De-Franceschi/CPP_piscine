#ifndef HUMANB_H
# define HUMANB_H

# include <iostream>
# include <string>
# include "Weapon.hpp"

class	HumanB
{
	public:

		HumanB(std::string name);
		~HumanB(void);

		void	setWeapon(Weapon &weapon);
		void	attack(void);

	private:

		std::string	_name;
		Weapon		*_weapon;
};

#endif