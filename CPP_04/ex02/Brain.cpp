#include "Brain.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

Brain::Brain(void)
{
	std::cout
		<< PURPLE
		<< "Brain: Constructor Called"
		<< END
		<< std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::ostringstream 	buf;
		buf << "Great idea " << i;
		this->_ideas[i] = buf.str();
	}
	return ;
}

Brain::Brain(Brain const & src)
{
	*this = src;
	std::cout
		<< PURPLE
		<< "Brain: Copy Constructor Called"
		<< END
		<< std::endl;
	return ;
}

Brain::~Brain(void)
{
	std::cout
		<< PURPLE
		<< "Brain: Destructor Called"
		<< END
		<< std::endl;
	return;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

Brain &	Brain::operator=(Brain const & rhs)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	return (*this);
}

/****************************************************************************/
/*                           Getters / Setters                              */
/****************************************************************************/

const std::string	Brain::getIdea(int i) const
{
	return (this->_ideas[i]);
}

void	Brain::setIdea(int i, const std::string & idea)
{
	this->_ideas[i] = idea;
	return ;
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/
