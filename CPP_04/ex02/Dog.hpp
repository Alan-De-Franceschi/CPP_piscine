#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public virtual Animal
{
	public:

		Dog(void);
		Dog(Dog const & src);
		~Dog(void);

		Dog &				operator=(Dog const & rhs);

		const std::string	getIdea(int i) const; 
		void				setIdea(int i, const std::string & idea);
		void				makeSound(void) const;

	private:

		Brain*				_brain;
};

#endif