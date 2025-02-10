#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <cstdlib>

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
void    isNone(std::string & literal, int & type);

void    convertChar(const char* literal);
void    convertInt(const char* literal);
void    convertFloat(const char* literal);
void    convertDouble(const char* literal);
void    convertNone(const char* literal);

#endif