#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define GREEN 	"\033[0;32m"
# define RED	"\033[0;31m"
# define END	"\033[0m"
# define BLUE	"\033[0;36m"
# define YELLOW	"\033[0;33m"

# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <limits>
# include <cstdlib>
# include <algorithm>
# include <utility>
# include <ctime>
# include <iomanip>

class PmergeMe
{
    public:

        PmergeMe(void);
        PmergeMe(const PmergeMe & src);
        ~PmergeMe(void);

        PmergeMe &  operator=(const PmergeMe & rhs);

        void    parsing(std::string & intList);
        void    sortContainer(void);

    private:

        typedef std::pair<int, int> contPair;

        std::vector<int>    _vector;
        std::deque<int>     _deque;
        int                 _odd;

        void    checkList(std::string & intList);

        template<typename C>
        bool    isSorted(C & container);
        template<typename C>
        void    printContainer(C & container, int status);
        template<typename P, typename C>
        void    makePairs (P & pairs, C & container);
        template<typename P, typename C>
        void    getLarge(P & pairs, C & container);
        template<typename P>
        P       mergeSort(P & pairs);
        template<typename P>
        P       merge(P & left, P & right);
        template<typename C>
        C       getJacobsthal(size_t size);
        template<typename P, typename C>
        void    insertion(P & pairs, C & container, C & jacob);
        template<typename C>
        void    binarySearch(int n, C & container, int size);
};

template<typename C>
bool    PmergeMe::isSorted(C & container)
{
    typename C::iterator it = container.begin();
    for (size_t i = 0; i < container.size() - 1; i++)
    {
        if (*it > *(it + 1))
            return (false);
        it++;
    }
    return (true);
}

template<typename C>
void    PmergeMe::printContainer(C & container, int status)
{
    if (status == 0)
        std::cout << RED << "Before:   " << std::flush;
    else
        std::cout << GREEN << "After:    " << std::flush;
    typename C::iterator it = container.begin();
    for (size_t i = 0; i < container.size(); i++)
    {
        std::cout
            << *it
            << std::flush;
        if (i != container.size() - 1)
            std::cout << ' ' << std::flush;
        ++it;
    }
    std::cout << END;
    std::cout << std::endl;
    return ;
}

template<typename P, typename C>
void    PmergeMe::makePairs (P & pairs, C & container)
{
    if (container.size() % 2 != 0)
    {
        this->_odd = container.back();
        container.pop_back();
    }
    typename C::iterator it = container.begin();
    for (size_t i = 0; i < container.size() - 1; i += 2)
    {
        contPair temp;
        temp.first = *it;
        temp.second = *(it + 1);
        pairs.push_back(temp);
        it += 2;
    }
    for (typename P::iterator pit = pairs.begin(); pit != pairs.end(); pit++)
    {
        if (pit->first > pit->second)
        {
            int temp = pit->first;
            pit->first = pit->second;
            pit->second = temp;
        }
    }
}

template<typename P, typename C>
void    PmergeMe::getLarge(P & pairs, C & container)
{
    for (typename P::iterator pit = pairs.begin(); pit != pairs.end(); pit++)
        container.push_back(pit->second);
}

template<typename P>
P   PmergeMe::merge(P & left, P & right)
{
    P merged;
    
    for (; !left.empty() && !right.empty() ;)
    {
        if (left.front().second < right.front().second)
        {
            merged.push_back(left.front());
            left.erase(left.begin());
        }
        else
        {
            merged.push_back(right.front());
            right.erase(right.begin());
        }
    }
    if (!left.empty())
    {
        for (; !left.empty();)
        {
            merged.push_back(left.front());
            left.erase(left.begin());
        }
    }
    else if (!right.empty())
    {
        for (; !right.empty();)
        {
            merged.push_back(right.front());
            right.erase(right.begin());
        }
    }
    return (merged);
}

template<typename P>
P   PmergeMe::mergeSort(P & pairs)
{
    P       left;
    P       right;
    P       sortLeft;
    P       sortRight;
    size_t  i = 0;

    if (pairs.size() == 1)
        return (pairs) ;

    for (; i < pairs.size() / 2; i++)
        left.push_back(pairs[i]);
    for (; i < pairs.size(); i++)
        right.push_back(pairs[i]);
    sortLeft = mergeSort(left);
    sortRight = mergeSort(right);
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    return (merge(sortLeft, sortRight));
}

template<typename C>
C   PmergeMe::getJacobsthal(size_t size)
{
    C jacob;

    jacob.push_back(3);
    jacob.push_back(5);
    jacob.push_back(11);
    for (; jacob.size() < size ;)
    {
        int prev = *(jacob.end() - 1);
        int prevPrev = *(jacob.end() - 2);
        jacob.push_back(prev + 2 * prevPrev);
    }
    return (jacob);
}

template<typename C>
void    PmergeMe::binarySearch(int n, C & container, int size)
{
    int start = 0;
    int mid;
    int end = size - 1;

    for (; start <= end; )
    {
        mid = ((end - start) / 2) + start;
        if (n < container[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    container.insert(container.begin() + start, n);
    return ;
}

template<typename P, typename C>
void    PmergeMe::insertion(P & pairs, C & container, C & jacob)
{
    size_t  jacobIndex;
    size_t  prevIndex = 0;
    size_t  i = 0;
    
    container.insert(container.begin(), pairs[0].first);
    while (true)
    {
        if (container.size() == pairs.size() * 2)
            break ;
        if (static_cast<size_t>(jacob[i]) > pairs.size())
            jacobIndex = pairs.size() - 1;
        else
            jacobIndex = jacob[i] - 1;
        
        for (; jacobIndex > prevIndex; jacobIndex--)
        {
            binarySearch(pairs[jacobIndex].first, container, 
                std::find(container.begin(), container.end(), pairs[jacobIndex].second) - container.begin());
        }
        prevIndex = jacob[i] - 1;
        i++;
    }
    if (this->_odd != -1)
        binarySearch(this->_odd, container, container.size() - 1);
    return ;
}

#endif