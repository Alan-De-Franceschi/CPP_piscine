#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
    public:

        FragTrap(FragTrap const & src);
        FragTrap(std::string const & name);
        ~FragTrap(void);

        FragTrap &	operator=(FragTrap const & rhs);

        void        attack(const std::string& target);
        void        highFivesGuys(void);

    protected:
        
        std::string     _name;
        unsigned int    _defaultHit;
        unsigned int    _defaultAttack;

        FragTrap(void);
};

#endif
