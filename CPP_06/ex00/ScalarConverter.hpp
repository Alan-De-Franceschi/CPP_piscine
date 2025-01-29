#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include <limits.h>
#include <iomanip>
#include <cmath>

# define BLUE	"\033[0;36m"
# define RED	"\033[0;31m"
# define END	"\033[0m"

class   ScalarConverter
{
    public:
    
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter & src);
        virtual ~ScalarConverter(void) = 0;

        ScalarConverter &   operator=(const ScalarConverter & rhs);

        static void         convert(std::string literal);

    private:
};

void    isChar(std::string & literal, int & type);
void    isInt(std::string & literal, int & type);
void    isFloat(std::string & literal, int & type);
void    isDouble(std::string & literal, int & type);

void    convertChar(std::string & literal);
void    convertInt(std::string & literal);
void    convertFloat(std::string & literal);
void    convertDouble(std::string & literal);

#endif