#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public virtual WrongAnimal
{
	public:

		WrongCat(void);
		WrongCat(WrongCat const & src);
		~WrongCat(void);

		WrongCat &	operator=(WrongCat const & rhs);

	private:

};

#endif