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
# include <utility>

class PmergeMe
{
    public:

        PmergeMe(void);
        PmergeMe(const PmergeMe & src);
        ~PmergeMe(void);

        PmergeMe &  operator=(const PmergeMe & rhs);

        void    sortVector(void);
        //void    sortDeque(void);
        void    parsing(std::string & intList);

        void    printVector(void);
        void    printDeque(void);

    private:

        std::vector<int>    _vector;
        std::deque<int>     _deque;
        int                 _odd;

        
        void    checkList(std::string & intList);
        void    vectorPairs(std::vector<std::pair<int, int> > & pairs);
};

#endif

// [12 5] [48 4] [15 47] [12 59]

// [5 12] [4 48] [15 47] [12 59]

// 12 48   47 59

// 12 47 48 59