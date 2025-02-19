#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# define RED "\033[1;31m"
# define BLUE "\033[1;94m"
# define GREEN "\033[1;92m"
# define YELLOW "\033[1;93m"
# define END "\033[0m"

# include <iostream>
# include <stack>

template<typename T>
class   MutantStack : virtual public std::stack<T>
{
    public:

        MutantStack(void);
        MutantStack(const MutantStack<T> & src);
        ~MutantStack(void);

        MutantStack<T> &   operator=(const MutantStack<T> & rhs);

        typedef typename MutantStack<T>::container_type::iterator iterator;
        typedef typename MutantStack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename MutantStack<T>::container_type::const_iterator const_iterator;
        typedef typename MutantStack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        iterator begin(void);
        iterator end(void);
        reverse_iterator rbegin(void);
        reverse_iterator rend(void);
        const_iterator begin(void) const;
        const_iterator end(void) const;
        const_reverse_iterator rbegin(void) const;
        const_reverse_iterator rend(void) const;
    
    private:

};

template<typename T>
MutantStack<T>::MutantStack(void)
{
    std::cout
        << YELLOW
        << "MutantStack: Constructor Called"
        << END
        << std::endl;
    return ;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack & src)
{
    *this = src;
    std::cout
        << YELLOW
        << "MutantStack: Copy Constructor Called"
        << END
        << std::endl;
    return ;
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{
    std::cout
        << YELLOW
        << "MutantStack: Destructor Called"
        << END
        << std::endl;
    return ;
}

template<typename T>
MutantStack<T> &    MutantStack<T>::operator=(const MutantStack<T> & rhs)
{
    this->std::stack<T>::operator=(rhs);
    return (*this);
}

template<typename T>
typename MutantStack<T>::iterator    MutantStack<T>::begin(void)
{
    return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator    MutantStack<T>::end(void)
{
    return (this->c.end());
}

template<typename T>
typename MutantStack<T>::reverse_iterator    MutantStack<T>::rbegin(void)
{
    return (this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::reverse_iterator    MutantStack<T>::rend(void)
{
    return (this->c.rend());
}

template<typename T>
typename MutantStack<T>::const_iterator    MutantStack<T>::begin(void) const
{
    return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::const_iterator    MutantStack<T>::end(void) const
{
    return (this->c.end());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator    MutantStack<T>::rbegin(void) const
{
    return (this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator    MutantStack<T>::rend(void) const
{
    return (this->c.rend());
}

#endif