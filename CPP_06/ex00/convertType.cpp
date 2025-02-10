#include "ScalarConverter.hpp"

void    convertChar(const char* literal)
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

void    convertInt(const char* literal)
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

void    convertFloat(const char* literal)
{
    char    c;
    int     i;
    double  f;
    double  d;

    f = std::strtod(literal, NULL);
    if (f < std::numeric_limits<float>::min() || f > std::numeric_limits<float>::max())
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
    if (i == std::numeric_limits<int>::min() || i == std::numeric_limits<int>::max())
        std::cout << "int: Impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) <<f << "f" << std::endl;

    d = static_cast<double>(f);
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;

    return ;
}

void    convertDouble(const char* literal)
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
    if (i == std::numeric_limits<int>::min() || i == std::numeric_limits<int>::max())
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

void    convertNone(const char* literal)
{
    char    c;
    int     i;
    float   f;
    double  d;
    std::string str = literal;

    if (str == "")
        throw std::invalid_argument("Error -> empty string");

    else if (str == "nan")
    {
        d = std::numeric_limits<double>::quiet_NaN();
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);

        std::cout << "char: Impossible" << std::endl;

        if (i == std::numeric_limits<int>::min() || i == std::numeric_limits<int>::max())
            std::cout << "int: Impossible" << std::endl;

        if (isinff(f))
            std::cout << "float: Impossible" << std::endl;
        else
            std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    }

    else if (str == "nanf")
    {
        f = std::numeric_limits<float>::quiet_NaN();
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);

        std::cout << "char: Impossible" << std::endl;

        if (i == std::numeric_limits<int>::min() || i == std::numeric_limits<int>::max())
            std::cout << "int: Impossible" << std::endl;

        if (isinff(f))
            std::cout << "float: Impossible" << std::endl;
        else
            std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    }

    else if (str == "+inf")
    {
        d = std::numeric_limits<double>::infinity();
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);

        std::cout << "char: Impossible" << std::endl;

        if (i == std::numeric_limits<int>::min() || i == std::numeric_limits<int>::max())
            std::cout << "int: Impossible" << std::endl;

        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    }

    else if (str == "-inf")
    {
        d = (std::numeric_limits<double>::infinity()) * -1;
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);

        std::cout << "char: Impossible" << std::endl;

        if (i == std::numeric_limits<int>::min() || i == std::numeric_limits<int>::max())
            std::cout << "int: Impossible" << std::endl;

        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    }

    else if (str == "+inff")
    {
        f = std::numeric_limits<float>::infinity();
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);

        std::cout << "char: Impossible" << std::endl;

        if (i == std::numeric_limits<int>::min() || i == std::numeric_limits<int>::max())
            std::cout << "int: Impossible" << std::endl;

        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    }

    else if (str == "-inff")
    {
        f = (std::numeric_limits<float>::infinity()) * -1;
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);

        std::cout << "char: Impossible" << std::endl;

        if (i == std::numeric_limits<int>::min() || i == std::numeric_limits<int>::max())
            std::cout << "int: Impossible" << std::endl;

        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    }
    return ;
}
