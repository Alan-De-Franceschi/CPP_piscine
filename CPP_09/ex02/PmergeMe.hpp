#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define GREEN 	"\033[0;32m"
# define RED	"\033[0;31m"
# define END	"\033[0m"

# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <limits>
# include <cstdlib>
# include <algorithm>
# include <utility>

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

        template<typename P, typename C>
        void    makePairs (P & pairs, C & container);
        template<typename P, typename C>
        void    getLarge(P & pairs, C & container);
        template<typename C>
        C       mergeSort(C & container);
        template<typename C>
        C       merge(C & left, C & right);
        template<typename C>
        C       getJacobsthal(size_t size);
        template<typename P, typename C>
        void    insertion(P & pairs, C & container, C & jacob);
};


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

template<typename C>
C   PmergeMe::merge(C & left, C & right)
{
    C merged;
    
    for (; !left.empty() && !right.empty() ;)
    {
        if (left.front() < right.front())
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

template<typename C>
C   PmergeMe::mergeSort(C & container)
{
    C       left;
    C       right;
    C       sortLeft;
    C       sortRight;
    size_t  i = 0;

    if (container.size() == 1)
        return (container) ;

    for (; i < container.size() / 2; i++)
        left.push_back(container[i]);
    for (; i < container.size(); i++)
        right.push_back(container[i]);
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

    jacob.push_back(0);
    jacob.push_back(1);
    jacob.push_back(3);
    for (; jacob.size() != size ;)
    {
        int prev = *(jacob.end() - 1);
        int prevPrev = *(jacob.end() - 2);
        jacob.push_back(prev + 2 * prevPrev);
    }
    return (jacob);
}

template<typename P, typename C>
void    PmergeMe::insertion(P & pairs, C & container, C & jacob)
{
    C   to_sorted;

    for (size_t i = 0; i < pairs.size(); i++)
    {

    }
    return ;
}

#endif