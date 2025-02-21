#include "BitcoinExchange.hpp"

int main(void)
{
    try
    {
        BitcoinExchange("test");
    }
    catch (std::ios_base::failure & e)
    {

    }
    return (0);
}