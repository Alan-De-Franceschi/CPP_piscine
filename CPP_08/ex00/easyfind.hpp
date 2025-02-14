#ifndef EASYFIND_HPP
# define EASYFIND_HPP

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
    //         return (1); 
    // }
   // return (0);
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    return ((it != container.end()));
}

#endif