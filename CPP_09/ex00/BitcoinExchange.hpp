#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# define GREEN 	"\033[0;32m"
# define RED	"\033[0;31m"
# define END	"\033[0m"

# include <iostream>
# include <map>
# include <fstream>
# include <cstdlib>
# include <algorithm>
# include <limits>

class   BitcoinExchange
{
    public:
    
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange & src);
        ~BitcoinExchange(void);

        BitcoinExchange &   operator=(const BitcoinExchange & rhs);

        void    btcConverter(const std::string & filename);

    private:

        std::map<std::string, float>    _exchangeRate;

        void    fillRate(void);
        void    checkDelimiter(std::string & line);
        void    checkDateFormat(std::string & date);
        void    checkDateValidity(std::string & date);
        void    checkValueFormat(std::string & value);
        void    checkValueValidity(std::string & value);
        void    applyConversion(std::string & date, std::string & value);
};

#endif