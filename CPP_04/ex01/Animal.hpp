#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	public:

		Animal(void);
		Animal(Animal const & src);
		virtual ~Animal(void);

		Animal &		operator=(Animal const & rhs);

		std::string 	getType(void) const;
		void	    	setType(int attribute);
		virtual void	makeSound(void) const;

	protected:

		std::string 	_type;
};

#endif