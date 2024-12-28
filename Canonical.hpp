#ifndef NAME_HPP
# define NAME_HPP

#include <iostream>
#include <string>

class Canonical
{
	public:

		Canonical(void);
		Canonical(Canonical const & src);
		~Canonical(void);

		Canonical &	operator=(Canonical const & rhs);

		int		getAttribute(void) const;
		void	setAttribute(int attribute);

	private:

		int	_attribute;
};

std::ostream &	operator<<(std::ostream & o, Canonical const & rhs);

#endif