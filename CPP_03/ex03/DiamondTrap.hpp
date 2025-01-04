#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class   DiamondTrap : public ScavTrap, public FragTrap
{
    public:

        DiamondTrap(DiamondTrap const & src);
        DiamondTrap(std::string const & name);
        ~DiamondTrap(void);

        DiamondTrap &   operator=(DiamondTrap const & rhs);

        void            attack(const std::string& target);
        void            whoAmI(void);
        void			showStats(void);

    private:

        std::string     _name;

        DiamondTrap(void);
};

#endif