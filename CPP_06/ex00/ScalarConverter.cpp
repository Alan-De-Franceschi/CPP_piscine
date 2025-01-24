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

void    ScalarConverter::convert(std::string literal)
{
    return ;
}