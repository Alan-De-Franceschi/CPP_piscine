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
    // for (std::map<std::string, float>::iterator it = this->_exchangeRate.begin(); it != this->_exchangeRate.end(); ++it)
    //     std::cout << "key = " << it->first << " | " << "value = " << it->second << std::endl;
    file.close();
}

static void checkDelimiter(std::string & line)
{
    if (line.find(" | ") == std::string::npos)
        throw std::invalid_argument("Error: bad input => " + line);
}

static void checkDateFormat(std::string & date)
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
}

static void checkDateValidity(std::string & date)
{
    long int    year = std::strtol((date.substr(0, date.find('-'))).c_str(), NULL, 10);
    long int    month = std::strtol((date.substr(date.find('-') + 1, date.rfind('-'))).c_str(), NULL, 10);
    long int    day = std::strtol((date.substr(date.rfind('-') + 1)).c_str(), NULL, 10);

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
            checkDelimiter(line);
            std::string date = line.substr(0, line.find(" | "));
            std::string value = line.substr(line.find(" | ") + 3);
            checkDateFormat(date);
            checkDateValidity(date);
        }
        catch (std::exception & e)
        {
            if (nbLine != 0)
                std::cout << e.what() << std::endl;
        }
        nbLine++;
    }
}