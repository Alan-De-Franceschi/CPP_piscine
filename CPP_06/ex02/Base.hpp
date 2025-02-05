#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>
# include <exception>


class Base
{
    public:

        virtual ~Base(void);
};

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif