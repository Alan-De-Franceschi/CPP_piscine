#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public virtual Animal
{
	public:

		Cat(void);
		Cat(Cat const & src);
		~Cat(void);

		Cat &				operator=(Cat const & rhs);

		const std::string	getIdea(int i) const; 
		void				setIdea(int i, const std::string & idea);
		void				makeSound(void) const;

	private:

		Brain*				_brain;
};

#endif