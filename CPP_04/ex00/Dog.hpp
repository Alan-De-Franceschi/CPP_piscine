#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public virtual Animal
{
	public:

		Dog(void);
		Dog(Dog const & src);
		~Dog(void);

		Dog &	operator=(Dog const & rhs);

		void	makeSound(void) const;

	private:

};

#endif