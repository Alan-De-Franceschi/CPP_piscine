#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# define GREEN 	"\033[0;32m"
# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define END	"\033[0m"

# include <iostream>
# include <map>
# include <fstream>
# include <iterator>

class   BitcoinExchange
{
    public:
    
        BitcoinExchange(const std::string & file);
        BitcoinExchange(const BitcoinExchange & src);
        ~BitcoinExchange(void);

        BitcoinExchange &   operator=(const BitcoinExchange & rhs);

    private:

        std::map<std::string, double> _exchangeRate;
        std::map<std::string, double> _inputValues;

        BitcoinExchange(void);

        void    fillRate(void);
        void    fillValues(const std::string & file);
};

#endif