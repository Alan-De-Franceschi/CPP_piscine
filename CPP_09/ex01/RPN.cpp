#include "RPN.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

RPN::RPN(void)
{
    return ;
}

RPN::RPN(const RPN & src)
{
    *this = src;
    return ;
}

RPN::~RPN(void)
{
    return ;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

RPN &   RPN::operator=(const RPN & rhs)
{
    this->_stack = rhs._stack;
    return (*this);
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void    RPN::checkExpression(const std::string & expression)
{
    if (expression.empty())
        throw std::invalid_argument("Error: empty expression");
    if (expression.find_first_not_of("0123456789 +-*/") != std::string::npos)
        throw std::invalid_argument("Error: bad input => " + expression);
    if (expression.find_first_not_of(' ') == std::string::npos)
        throw std::invalid_argument("Error: bad input => " + expression);
    if (expression.find_first_of("+-*/") == std::string::npos)
        throw std::invalid_argument("Error: No operator => " + expression);
}

void    RPN::addToStack(char c)
{
    double    num = std::strtod(&c, NULL);

    this->_stack.push_front(num);
    return ;
}

bool    RPN::isOperator(char c)
{
    std::string op = "+-*/";

    if (op.find(c) == std::string::npos)
        return (false);
    return (true);
}

void    RPN::addition(void)
{
    double   b = this->_stack.front();
    this->_stack.pop_front();
    double   a = this->_stack.front();
    this->_stack.pop_front();

    if (a + b > std::numeric_limits<int>::max())
        throw std::invalid_argument("Error: int overflow");
    this->_stack.push_front(a + b);
    return ;
}

void    RPN::soustraction(void)
{
    double   b = this->_stack.front();
    this->_stack.pop_front();
    double   a = this->_stack.front();
    this->_stack.pop_front();

    if (a - b < std::numeric_limits<int>::min())
        throw std::invalid_argument("Error: int overflow");
    this->_stack.push_front(a - b);
    return ;
}

void    RPN::multiplication(void)
{
    double   b = this->_stack.front();
    this->_stack.pop_front();
    double   a = this->_stack.front();
    this->_stack.pop_front();

    if (a * b > std::numeric_limits<int>::max())
        throw std::invalid_argument("Error: int overflow");
    if (a * b < std::numeric_limits<int>::min())
        throw std::invalid_argument("Error: int overflow");
    this->_stack.push_front(a * b);
    return ;
}

void    RPN::division(void)
{
    double   b = this->_stack.front();
    this->_stack.pop_front();
    double   a = this->_stack.front();
    this->_stack.pop_front();

    if (b == 0)
            throw std::invalid_argument("Error: division by 0");
    this->_stack.push_front(a / b);
    return ;
}

void    RPN::doOperation(char c)
{
    std::string operators = "+-*/";
    int         op = operators.find(c);

    switch (op)
    {
        case 0:
            addition();
            break;
        case 1:
            soustraction();
            break;
        case 2:
            multiplication();
            break;
        case 3:
            division();
            break;
    }
    return ;
}
#include <vector>

void    RPN::rpnCalculator(const std::string & expression)
{
    checkExpression(expression);
    for (std::string::size_type i = 0; i < expression.length(); i++)
    {
        if (isdigit(expression[i]))
        {
            if (isdigit(expression[i + 1]))
                throw std::invalid_argument("Error: numbers should be less than 10");
            addToStack(expression[i]);
        }
        if (isOperator(expression[i]))
        {
            if (this->_stack.size() < 2)
                throw std::invalid_argument("Error: Not enough numbers to do operation");
            doOperation(expression[i]);
        }   
    }
    if (this->_stack.size() > 1)
        throw std::invalid_argument("Error:");
    std::cout << this->_stack.front() << std::endl;
    return ;
}