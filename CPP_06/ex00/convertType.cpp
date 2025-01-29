#include "ScalarConverter.hpp"

void    convertChar(std::string & literal)
{
    char    c;
    int     i;
    float   f;
    double  d;

    c = static_cast<char>(literal[0]);
    if (!isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << "'" << c << "'" << std::endl;

    i = static_cast<int>(c);
    std::cout << "int: " << i << std::endl;

    f = static_cast<float>(c);
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    d = static_cast<double>(c);
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;

    return ;
}

void    convertInt(std::string & literal)
{
    char    c;
    int     i;
    float   f;
    double  d;

    std::stringstream strm(literal);
    strm >> i;

    c = static_cast<char>(i);
    if (!isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << "'" << c << "'" << std::endl;

    std::cout << "int: " << i << std::endl;

    f = static_cast<float>(i);
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    d = static_cast<double>(i);
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;

    return ;
}

void    convertFloat(std::string & literal)
{
    char    c;
    int     i;
    float   f;
    double  d;

    std::stringstream strm(literal);
    if (!(strm >> f))
        throw std::invalid_argument("Error: wrong input -> float");

    if (f > 127 || f < 0)
        std::cout << "char: Impossible" << std::endl;
    else
    {
        c = static_cast<char>(f);
        if (!isprint(c))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << "'" << c << "'" << std::endl;
    }

    i = static_cast<int>(f);
    if (i == INT_MIN)
        std::cout << "int: Impossible" << std::endl;
    std::cout << "int: " << i << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    d = static_cast<double>(f);
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;

    return ;
}

void    convertDouble(std::string & literal)
{
    char    c;
    int     i;
    float   f;
    double  d;

    std::stringstream strm(literal);
    if (!(strm >> d))
        throw std::invalid_argument("Error: wrong input -> double");

    if (d > 127 || d < 0)
        std::cout << "char: Impossible" << std::endl;
    else
    {
        c = static_cast<char>(d);
        if (!isprint(c))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << "'" << c << "'" << std::endl;
    }

    i = static_cast<int>(d);
    if (i == INT_MIN)
        std::cout << "int: Impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    f = static_cast<float>(d);
    if (isinff(f))
        std::cout << "float: Impossible" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;

    return ;
}

void    convertNone(std::string & literal)
{
    if (literal == "")
        throw std::invalid_argument("Error -> empty string");
    else if (literal == "nan")
    {
        std::cout
            << "char: Impossible" << std::endl
            << "int: Impossible" << std::endl
            << "float: nanf" << std::endl
            << "double: nan" << std::endl;
    }
    else if (literal == "nanf")
    {
        std::cout
            << "char: Impossible" << std::endl
            << "int: Impossible" << std::endl
            << "float: nanf" << std::endl
            << "double: nan" << std::endl;
    }
    else if (literal == "+inf")
    {
        std::cout
            << "char: Impossible" << std::endl
            << "int: Impossible" << std::endl
            << "float: Impossible" << std::endl
            << "double: +inf" << std::endl;
    }
    else if (literal == "-inf")
    {
        std::cout
            << "char: Impossible" << std::endl
            << "int: Impossible" << std::endl
            << "float: Impossible" << std::endl
            << "double: -inf" << std::endl;
    }
    else if (literal == "+inff")
    {
        std::cout
            << "char: Impossible" << std::endl
            << "int: Impossible" << std::endl
            << "float: +inff" << std::endl
            << "double: 340282346638528859811704183484516925440.0" << std::endl;
    }
    else if (literal == "-inff")
    {
        std::cout
            << "char: Impossible" << std::endl
            << "int: Impossible" << std::endl
            << "float: -inff" << std::endl
            << "double: -340282346638528859811704183484516925440.0" << std::endl;
    }
}
