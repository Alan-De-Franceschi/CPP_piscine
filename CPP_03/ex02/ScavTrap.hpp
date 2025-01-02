#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:

        ScavTrap(ScavTrap const & src);
        ScavTrap(std::string const & name);
        ~ScavTrap(void);

       ScavTrap &	operator=(ScavTrap const & rhs);

       void guardGate(void);

    private:
        
        bool    _gkMode;
        
        ScavTrap(void);
};

#endif