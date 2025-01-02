#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:

        FragTrap(FragTrap const & src);
        FragTrap(std::string const & name);
        ~FragTrap(void);

       FragTrap &	operator=(FragTrap const & rhs);

       void         highFivesGuys(void);

    private:
        
        FragTrap(void);
};

#endif
