#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# define GREEN 	"\033[0;32m"
# define RED	"\033[0;31m"
# define END	"\033[0m"

# include <iostream>
# include <algorithm>
# include <list>
# include <vector>

template<typename T>
bool easyfind(T container, int n)
{
    // for(typename T::iterator it = container.begin(); it != container.end(); ++it)
    // {
    //     if (*it == n)
    //         return (true); 
    // }
   // return (false);
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    return ((it != container.end()));
}

#endif