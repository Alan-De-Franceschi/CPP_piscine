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
    (void)src;
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
    (void)rhs;
    return (*this);
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void    ScalarConverter::convert(std::string literal)
{
    int type = 0;

    isChar(literal, type);
    isInt(literal, type);
    isFloat(literal, type);
    isDouble(literal, type);
    isNone(literal, type);

    switch (type)
    {
        case 0:
            throw std::invalid_argument("Error: wrong input");
        case 1:
            convertChar(literal.c_str());
            break ;
        case 2:
            convertInt(literal.c_str());
            break ;
        case 3:
            convertFloat(literal.c_str());
            break ;
        case 4:
            convertDouble(literal.c_str());
            break ;
        case 5:
            convertNone(literal.c_str());
            break ;
    }
    return ;
}