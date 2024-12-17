#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

class   Zombie
{
    public:

        Zombie(void);
        Zombie(std::string z_name);
        ~Zombie(void);

        void    setName(std::string name);
        void    announce(void);

    private:

        std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif