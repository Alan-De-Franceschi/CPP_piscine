#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

# define RED	"\033[0;31m"
# define END	"\033[0m"

class WrongAnimal
{
	public:

		WrongAnimal(void);
		WrongAnimal(WrongAnimal const & src);
		virtual ~WrongAnimal(void);

		WrongAnimal &	operator=(WrongAnimal const & rhs);

		std::string 	getType(void) const;
		void	    	setType(int attribute);
		void			makeSound(void) const;

	protected:

		std::string 	_type;
};

#endif