#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class   Harl
{
    public:
    
        Harl(void);
        ~Harl(void);

        void complain(std::string level);

    private:

        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
        void    blabla(void);
        void    printComplain(void (Harl::*f[4])(void), int index);
};

#endif