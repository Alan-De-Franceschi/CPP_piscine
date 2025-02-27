#ifndef RPN_HPP
# define RPN_HPP

# define GREEN 	"\033[0;32m"
# define RED	"\033[0;31m"
# define END	"\033[0m"

# include <iostream>
# include <list>
# include <cstdlib>
# include <limits>

class   RPN
{
    public:

        RPN(void);
        RPN(const RPN & src);
        ~RPN(void);

        RPN &   operator=(const RPN & rhs);

        void    rpnCalculator(const std::string & expression);

    private:

        std::list<double>  _stack;

        void    checkExpression(const std::string & expression);
        void    addToStack(char c);
        bool    isOperator(char c);
        void    doOperation(char c);
        void    addition(void);
        void    soustraction(void);
        void    multiplication(void);
        void    division(void);
};

#endif