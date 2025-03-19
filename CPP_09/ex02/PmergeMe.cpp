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
    std::vector<int>        jacob;

    printContainer(this->_vector, 0);

    makePairs(pVector, this->_vector);
    pVector = mergeSort(pVector);
    // for (std::vector<std::pair<int, int> >::iterator it = pVector.begin(); it != pVector.end(); it++)
    // {
    //     std::cout << "first = " << (*it).first << " second = " << (*it).second << std::endl;
    // }
    getLarge(pVector, vSorted);
    jacob = getJacobsthal<std::vector<int> >(pVector.size());
   // insertion(pVector, vSorted, jacob);
    
   std::clock_t    vStop = std::clock();

    // for (std::vector<int>::iterator it = jacob.begin(); it != jacob.end(); it++)
    //    std::cout << *it << "  " << std::flush;

    // std::deque<contPair>   pDeque;
    // std::deque<int>        dlarge;
    
    // makePairs(pDeque, this->_deque);
    // getLarge(pDeque, dlarge);
    // if (this->_odd != -1)
    //     dlarge.push_back(this->_odd);
    // dlarge = recursive(dlarge);
    // for (std::deque<int>::iterator it = dlarge.begin(); it != dlarge.end(); it++)
    //    std::cout << *it << "  " << std::flush;

    std::cout
        << std::endl
        << "Time to process a range of  "
        << this->_vector.size()
        << " elements with std::vector :   "
        << std::fixed << std::setprecision(6)
        << double(vStop - vStart) / CLOCKS_PER_SEC
        << " us"
        << std::endl;

    return ;
}