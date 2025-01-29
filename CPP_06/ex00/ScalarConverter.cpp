#include "ScalarConverter.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

ScalarConverter::ScalarConverter(void)
{
    std::cout
        << BLUE
        << "ScalarConverter: Constructor Called"
        << END
        << std::endl;
    return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter & src)
{
    std::cout
        << BLUE
        << "ScalarConverter: Copy Constructor Called"
        << END
        << std::endl;
    return ;
}

ScalarConverter::~ScalarConverter(void)
{
    std::cout
        << BLUE
        << "ScalarConverter: Destructor Called"
        << END
        << std::endl;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

ScalarConverter &   ScalarConverter::operator=(const ScalarConverter & rhs)
{
    return (*this);
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

static bool isInt(std::string & literal)
{
    long    num;

    if (literal.find_first_not_of("0123456789") != std::string::npos)
        return (false);
    
    return (true);
}

static bool isChar(std::string & literal)
{

    return (false);
}

static bool isDouble(std::string & literal)
{

    return (false);
}

static bool isFloat(std::string & literal)
{

    return (false);
}

void    ScalarConverter::convert(std::string literal)
{
    return ;
}