#ifndef SPAN_HPP
# define SPAN_HPP

# define GREEN 	"\033[0;32m"
# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define END	"\033[0m"

# include <iostream>
# include <list>
# include <exception>
# include <limits>
# include <cstdlib>

class   Span
{
    public:

        Span(unsigned int nbElements);
        Span(const Span & src);
        ~Span(void);

        Span &          operator=(const Span & rhs);

        void            addNumber(int number);
        int             shortestSpan(void); 
        int             longestSpan(void);

        class ListFull :  public std::exception
        {
            public:

                virtual const char* what() const throw();
        };

        class NoSpan :  public std::exception
        {
            public:

                virtual const char* what() const throw();
        };

    private:

        Span(void);

        unsigned int    _nbElements;
        std::list<int>  _list;
};

#endif