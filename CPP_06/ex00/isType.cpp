#include "ScalarConverter.hpp"

void    isChar(std::string & literal, int & type)
{
    if (literal.length() > 1 || literal.length() < 1)
        return ;
    if (isdigit(literal[0]))
        return ;
    type = 1;
    return;
}

void    isInt(std::string & literal, int & type)
{
    long    num;

    if (literal.find_first_not_of("-+0123456789") != std::string::npos || literal.length() == 1)
        return ;
    std::stringstream strm(literal);
    strm >> num;
    if (num > INT_MAX || num < INT_MIN)
        return ;
    type = 2;
    return ;
}

void isFloat(std::string & literal, int & type)
{
    if (literal.find_first_not_of("-+0123456789.f") != std::string::npos || literal.length() == 1)
        return ;
    if (literal.find("f") != literal.length() - 1)
        return ;
    type = 3;
    return ;
}

void isDouble(std::string & literal, int & type)
{
    if (literal.find_first_not_of("-+0123456789.") != std::string::npos || literal.length() == 1)
        return ;
    type = 4;
    return ;
}

void    isNone(std::string & literal, int & type)
{
    if (literal == "" ||literal == "nan" || literal == "nanf" || literal == "-inf" || literal == "+inf" || literal == "-inff" || literal == "+inff")
        type = 5;
    return;
}