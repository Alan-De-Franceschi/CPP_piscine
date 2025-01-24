#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

# define BLUE	"\033[0;36m"
# define RED	"\033[0;31m"
# define END	"\033[0m"

class   ScalarConverter
{
    public:
    
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter & src);
        ~ScalarConverter(void);

        ScalarConverter &   operator=(const ScalarConverter & rhs);

        static void         convert(std::string literal);

    private:
};

#endif