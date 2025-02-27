#include "BitcoinExchange.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

BitcoinExchange::BitcoinExchange(void)
{
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
    return (*this);
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void    BitcoinExchange::fillRate(void)
{
    std::ifstream   file("data.csv");
    if (!file.is_open())
        throw std::ios_base::failure("data.csv: could not open file");
    int nb_line = 0;
    for (std::string line; std::getline(file, line);)
    {
        if (nb_line != 0)
        {
            std::string key = line.substr(0, line.find(","));
            float       value = std::strtof((line.substr(line.find(",") + 1)).c_str(), NULL);
            this->_exchangeRate[key] = value;
        }
        nb_line++;
    }
    file.close();
    return ;
}

void BitcoinExchange::checkDelimiter(std::string & line)
{
    if (line.find(" | ") == std::string::npos)
        throw std::invalid_argument("Error: bad input => " + line);
    return ;
}

void BitcoinExchange::checkDateFormat(std::string & date)
{
    std::string             format = "xxxx-xx-xx";
    std::string::size_type  y = date.find_first_not_of(" ");

    if (date.length() < format.length())
        throw std::invalid_argument("Error: wrong date format => " + date);
    for (std::string::size_type i = 0; i < format.length(); i++)
    {
        if (format[i] == 'x' && !isdigit(date[y]))
            throw std::invalid_argument("Error: wrong date format => " + date);
        if (format[i] == '-' && date[y] != '-')
            throw std::invalid_argument("Error: wrong date format => " + date);
        y++;
    }
    for (; y < date.length(); y++)
    {
        if (date[y] != ' ')
            throw std::invalid_argument("Error: wrong date format => " + date);
    }
    date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
    return ;
}

void BitcoinExchange::checkDateValidity(std::string & date)
{
    long int    year = std::strtol((date.substr(0, date.find('-'))).c_str(), NULL, 10);
    long int    month = std::strtol((date.substr(date.find('-') + 1, date.rfind('-'))).c_str(), NULL, 10);
    long int    day = std::strtol((date.substr(date.rfind('-') + 1)).c_str(), NULL, 10);

    if (year < 2009)
        throw std::invalid_argument("Error: invalid date => " + date);
    if (year == 2009 && month == 1 && day < 2)
        throw std::invalid_argument("Error: invalid date => " + date);
    if (month < 1 || month > 12)
        throw std::invalid_argument("Error: invalid date => " + date);
    if (day < 1 || day > 31)
        throw std::invalid_argument("Error: invalid date => " + date);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw std::invalid_argument("Error: invalid date => " + date);
    if (month == 2) 
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
        {
          if (day > 29)
            throw std::invalid_argument("Error: invalid date => " + date);
        } 
        else 
        {
          if (day > 28)
            throw std::invalid_argument("Error: invalid date => " + date);
        }
    }
    return ;
}

void BitcoinExchange::checkValueFormat(std::string & value)
{
    if (value.find_first_not_of("-0123456789 .") != std::string::npos)
        throw std::invalid_argument("Error: wrong value format => " + value);
    std::string::size_type  y = value.find(' ', value.find_first_not_of(' '));
    if (y == std::string::npos)
        return ;
    if (value.find_first_not_of(' ', y) != std::string::npos)
        throw std::invalid_argument("Error: wrong value format => " + value);
    return ;
}

void BitcoinExchange::checkValueValidity(std::string & value)
{
    char *ptr = NULL;
    double   num = std::strtod(value.c_str(), &ptr);
    std::string sptr(ptr);
    if (!sptr.empty() && sptr.find_first_not_of(' ') != std::string::npos)
        throw std::invalid_argument("Error: wrong value format => " + value);
    if (num < 0)
        throw std::invalid_argument("Error: not a positive number.");
    if (num > static_cast<double>(std::numeric_limits<int>::max()) || num > 1000)
        throw std::invalid_argument("Error: too large a number.");
    return ;
}

void    BitcoinExchange::applyConversion(std::string & date, std::string & value)
{
    float   inputValue = std::strtof(value.c_str(), NULL);
    std::map<std::string, float>::iterator  it = this->_exchangeRate.find(date);

    if (it != this->_exchangeRate.end())
    {
        std::cout
            << GREEN
            << date 
            << " => " 
            << value
            << " = "
            << inputValue * it->second
            << END
            << std::endl;
    }
    else
    {
        it = this->_exchangeRate.upper_bound(date);
        it--;
        std::cout
            << GREEN
            << date 
            << " => " 
            << value
            << " = "
            << inputValue * it->second
            << END
            << std::endl;
    }
    return ;
}

void    BitcoinExchange::btcConverter(const std::string & filename)
{
    std::ifstream   file(filename.c_str());
    if (!file.is_open())
        throw std::ios_base::failure(filename + ": could not open file");
    int nbLine = 0;
    for (std::string line; std::getline(file, line);)
    {
        try
        {
            if (line.empty())
                throw std::invalid_argument("Error: empty line");
            checkDelimiter(line);
            std::string date = line.substr(0, line.find(" | "));
            std::string value = line.substr(line.find(" | ") + 3);
            checkDateFormat(date);
            checkDateValidity(date);
            checkValueFormat(value);
            checkValueValidity(value);
            applyConversion(date, value);
        }
        catch (std::exception & e)
        {
            if (nbLine != 0)
                std::cout << RED << e.what() << END << std::endl;
        }
        nbLine++;
    }
    return ;
}