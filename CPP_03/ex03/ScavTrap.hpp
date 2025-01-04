#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
    public:

        ScavTrap(ScavTrap const & src);
        ScavTrap(std::string const & name);
        ~ScavTrap(void);

        ScavTrap &	operator=(ScavTrap const & rhs);

        void        attack(const std::string& target);
        void        guardGate(void);

    protected:

        std::string     _name;
        bool            _gkMode;
        unsigned int    _defaultEnergy;
        
        ScavTrap(void);
};

#endif