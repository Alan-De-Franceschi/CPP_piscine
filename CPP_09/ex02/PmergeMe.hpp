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

class PmergeMe
{
    public:

        PmergeMe(void);
        PmergeMe(const PmergeMe & src);
        ~PmergeMe(void);

        PmergeMe &  operator=(const PmergeMe & rhs);

        void    mergeList(std::string & intList);

    private:

        std::vector<int>    _vector;
        std::deque<int>     _deque;

        void    parsing(std::string & intList);
        void    checkList(std::string & intList);
};

#endif