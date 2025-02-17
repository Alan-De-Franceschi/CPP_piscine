#include "Span.hpp"

int main(void)
{
    Span test(10);

    test.addNumber(10);
    test.addNumber(3);
    test.addNumber(7);
    test.addNumber(8);
    test.addNumber(13);

    std::cout << test.shortestSpan() << std::endl;
    std::cout << test.longestSpan() << std::endl;
    return (0);
}