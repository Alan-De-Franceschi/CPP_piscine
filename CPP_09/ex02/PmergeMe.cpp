# include "PmergeMe.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

PmergeMe::PmergeMe(void)
{
    return ;
}

PmergeMe::PmergeMe(const PmergeMe & src)
{
    *this = src;
    return ;
}

PmergeMe::~PmergeMe(void)
{
    return ;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

PmergeMe &   PmergeMe::operator=(const PmergeMe & rhs)
{
    this->_vector = rhs._vector;
    this->_deque = rhs._deque;
    return (*this);
}

/****************************************************************************/
/*                                Parsing                                   */
/****************************************************************************/

void    PmergeMe::checkList(std::string & intList)
{
    std::size_t pos;
    

    if ((pos = intList.find_first_not_of("0123456789 ")) != std::string::npos)
    {
        std::string invalidChar = "Error: invalid character => ";
        invalidChar.push_back(intList[pos]);
        throw std::invalid_argument(invalidChar);
    }
    return ;
}

void    PmergeMe::parsing(std::string & intList)
{
    long int    num;

    checkList(intList);
    std::stringstream   s(intList);
    for (std::string buf; std::getline(s, buf, ' ');)
    {
        num = std::strtol(buf.c_str(), NULL, 10);
        if (num > std::numeric_limits<int>::max())
            throw std::invalid_argument("Error: too large a number => " + buf);
        for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); it++)
        {
            if (*it == num)
                throw std::invalid_argument("Error: duplicates");
        }
        if (!buf.empty())
        {
            this->_vector.push_back(num);
            this->_deque.push_back(num);
        }
    }
    return ;

}

/****************************************************************************/
/*                                  Prints                                  */
/****************************************************************************/

void    PmergeMe::printVector(void)
{
    std::cout << "vector = " << std::flush;
    for(std::vector<int>::iterator itv = this->_vector.begin(); itv != this->_vector.end(); itv++)
        std::cout << *itv << " " << std::flush;
    std::cout << std::endl;
    return ;
}

void    PmergeMe::printDeque(void)
{
    std::cout << "deque = " << std::flush;
    for(std::deque<int>::iterator itd = this->_deque.begin(); itd != this->_deque.end(); itd++)
        std::cout << *itd << " " << std::flush;
    std::cout << std::endl;
    return ;
}

/****************************************************************************/
/*                               Sort Vector                                */
/****************************************************************************/



void    PmergeMe::sortVector(void)
{
    std::vector<std::pair<int, int> > pVector;

    if (this->_vector.size() % 2 != 0)
    {
        this->_odd = this->_vector.back();
        this->_vector.pop_back();
    }

}