# include "PmergeMe.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

PmergeMe::PmergeMe(void): _odd(-1)
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
/*                                 Sort                                     */
/****************************************************************************/

void    PmergeMe::sortContainer(void)
{
    if (this->_vector.size() == 1 || isSorted(this->_vector))
        throw std::invalid_argument("Sequence is already sort");
    
    std::clock_t    vStart = std::clock();

    std::vector<contPair>   pVector;
    std::vector<int>        vSorted;
    std::vector<int>        vJacob;

    printContainer(this->_vector, 0);

    makePairs(pVector, this->_vector);
    pVector = mergeSort(pVector);
    getLarge(pVector, vSorted);
    vJacob = getJacobsthal<std::vector<int> >(pVector.size());
    insertion(pVector, vSorted, vJacob);
    
    std::clock_t    vStop = std::clock();

    std::clock_t            dStart = std::clock();
    std::deque<contPair>    pDeque;
    std::deque<int>         dSorted;
    std::deque<int>         dJacob;

    makePairs(pDeque, this->_deque);
    pDeque = mergeSort(pDeque);
    getLarge(pDeque, dSorted);
    dJacob = getJacobsthal<std::deque<int> >(pDeque.size());
    insertion(pDeque, dSorted, dJacob);
    
    std::clock_t    dStop = std::clock();

    printContainer(vSorted, 1);

    std::cout
       << "Time to process a range of  "
       << vSorted.size()
       << BLUE
       << " elements with std::vector :   "
       << END
       << std::fixed << std::setprecision(6)
       << double(vStop - vStart) / CLOCKS_PER_SEC
       << " us"
       << std::flush;

    std::cout
        << std::endl
        << "Time to process a range of  "
        << dSorted.size()
        << YELLOW
        << " elements with std::deque :   "
        << END
        << std::fixed << std::setprecision(6)
        << double(dStop - dStart) / CLOCKS_PER_SEC
        << " us"
        << std::endl;

    return ;
}