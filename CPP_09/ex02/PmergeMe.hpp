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

class PmergeMe
{
    public:

        PmergeMe(void);
        PmergeMe(const PmergeMe & src);
        ~PmergeMe(void);

        PmergeMe &  operator=(const PmergeMe & rhs);

        void    parsing(std::string & intList);
        void    sort(void);

        void    printVector(void);
        void    printDeque(void);

    private:

        std::vector<int>    _vector;
        std::deque<int>     _deque;
        int                 _odd;

        void    checkList(std::string & intList);

        template<typename T>
        void    recursive(T & container, size_t groupSize);
};

template<typename T>
void    PmergeMe::recursive(T & container, size_t groupSize)
{
    size_t pos = (groupSize - 1)*(groupSize != 1);

    for (size_t i = groupSize - 1; i + groupSize < container.size(); i += groupSize * 2)
    {
        if (container[i] > container[i + groupSize])
        {
            typename T::iterator first = container.begin() + i - pos;
            typename T::iterator second = container.begin() + i - pos + groupSize;
            std::swap_ranges(first, second, second);
        }
    }
    printVector();
    if (groupSize <= container.size() / 2)
        recursive(container, groupSize * 2);
    return ;
}

#endif

// [12 5] [48 4] [15 47] [12 59]

// {[5 12 4 48 15 47 12 59]}

// 12 48   47 59

// 12 47 48 59