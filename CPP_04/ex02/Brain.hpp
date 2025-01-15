#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>
#include <sstream>

# define PURPLE	"\033[0;35m"
# define END	"\033[0m"

class Brain
{
	public:

		Brain(void);
		Brain(Brain const & src);
		~Brain(void);

		Brain &				operator=(Brain const & rhs);

		const std::string	getIdea(int i) const;
		void				setIdea(int i, const std::string & idea);

	private:

        std::string 		_ideas[100];
};

#endif