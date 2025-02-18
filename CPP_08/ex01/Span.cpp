#include "Span.hpp"

/****************************************************************************/
/*                      Constructors / Destructors                          */
/****************************************************************************/

Span::Span(void) // private
{
    return;
}

Span::Span(unsigned int nbElements) : _nbElements(nbElements)
{
    std::cout
        << YELLOW
        << "Span: Constructor Called"
        << END
        << std::endl;
    return ;
}

Span::Span(const Span & src)
{
    *this = src;
    std::cout
        << YELLOW
        << "Span: Copy Constructor Called"
        << END
        << std::endl;
    return ;
}

Span::~Span(void)
{
    std::cout
        << YELLOW
        << "Span: Destructor Called"
        << END
        << std::endl;
    return ;
}

/****************************************************************************/
/*                               Operators                                  */
/****************************************************************************/

Span &  Span::operator=(const Span & rhs)
{
    this->_list = rhs._list;
    this->_nbElements = rhs._nbElements;
    return (*this);
}

/****************************************************************************/
/*                           Members Functions                              */
/****************************************************************************/

void    Span::addNumber(int number)
{
    if (this->_nbElements == this->_list.size())
        throw Span::ListFull();
    this->_list.push_back(number);
    return ;
}

void    Span::fillNumbers(std::list<int> sequence)
{
    if (this->_list.size() + sequence.size() > this->_nbElements)
        throw Span::ListFull();
    this->_list.insert(this->_list.end(), sequence.begin(), sequence.end());
    return ;
}

int Span::shortestSpan(void)
{
    if (this->_list.empty() || this->_list.size() == 1)
        throw Span::NoSpan();
    this->_list.sort();
    std::list<int>::iterator    it = this->_list.begin();
    int                         span = std::numeric_limits<int>::max();  
    for(unsigned long i = 0; i < this->_list.size() - 1; i++)
    {
        int temp = std::abs(*it - *(++it));
        if (temp < span)
            span = temp;
    }
    return (span);
}

int Span::longestSpan(void)
{
    if (this->_list.empty() || this->_list.size() == 1)
        throw Span::NoSpan();
    this->_list.sort();
    return (this->_list.back() - this->_list.front());
}

const char  *Span::ListFull::what() const throw() 
{
    return ("Error: Span->_list is full");
}

const char  *Span::NoSpan::what() const throw()
{
    return ("No span can be found");
}
