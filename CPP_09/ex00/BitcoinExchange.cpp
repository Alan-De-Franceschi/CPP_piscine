#include "BitcoinExchange.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

BitcoinExchange::BitcoinExchange(void) // private
{
    return ;
}

BitcoinExchange::BitcoinExchange(const std::string & file)
{
    (void)file;
    this->fillRate();
    return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & src)
{
    *this = src;
    return ;
}

BitcoinExchange::~BitcoinExchange(void)
{
    return ;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

BitcoinExchange &   BitcoinExchange::operator=(const BitcoinExchange & rhs)
{
    this->_exchangeRate = rhs._exchangeRate;
    this->_inputValues = rhs._inputValues;
    return (*this);
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void    BitcoinExchange::fillRate(void)
{
    std::ifstream   file("data.csv");
    if (!file.is_open())
        throw std::ios_base::failure("data.csv");
    
    std::string buf((std::istreambuf_iterator<char>(file)),
                    (std::istreambuf_iterator<char>()));

    file.close();
}
