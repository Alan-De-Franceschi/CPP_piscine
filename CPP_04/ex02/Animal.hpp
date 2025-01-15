#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

# define GREEN 	"\033[0;32m"
# define BLUE	"\033[0;36m"
# define RED	"\033[0;31m"
# define END	"\033[0m"
# define YELLOW	"\033[0;33m"

class Animal
{
	public:

		Animal(void);
		Animal(Animal const & src);
		virtual ~Animal(void);

		Animal &			operator=(Animal const & rhs);

		std::string 				getType(void) const;
		void	    				setType(int attribute);
		virtual const std::string	getIdea(int i) const; 
		virtual void				setIdea(int i, const std::string & idea);
		virtual void				makeSound(void) const = 0;

	protected:

		std::string 	_type;
};

#endif