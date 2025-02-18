#include "Span.hpp"

int main(void)
{
    try
    {
        std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==                TEST DU SUJET               =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;

        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr
            << RED
            << e.what()
            << END
            << std::endl;
    }

    try
    {
        std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==                   TEST 1                   =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;

        Span test(10);

        test.addNumber(10);
        test.addNumber(3);
        test.addNumber(13);
        test.addNumber(7);
        test.addNumber(8);
        test.addNumber(17);
        test.addNumber(5);
        test.addNumber(24);
        test.addNumber(37);
        test.addNumber(99);
        

        std::cout << "Shortest span = " << test.shortestSpan() << std::endl;
        std::cout << "Longest span = " << test.longestSpan() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr
            << RED
            << e.what()
            << END
            << std::endl;
    }

    try
    {
        std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==                   TEST 2                   =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;

        Span test(0);
        
        test.shortestSpan();
    }
    catch (std::exception & e)
    {
        std::cerr
            << RED
            << e.what()
            << END
            << std::endl;
    }

    try
    {
        std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==                   TEST 3                   =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;

        Span test(1);
        
        test.addNumber(10);

        test.shortestSpan();
    }
    catch (std::exception & e)
    {
        std::cerr
            << RED
            << e.what()
            << END
            << std::endl;
    }

    try
    {
        std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==                   TEST 4                   =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;

        Span test(200000);
        
        for (int i = 0; i < 200000; i++)
            test.addNumber(i);

        std::cout << "Shortest span = " << test.shortestSpan() << std::endl;
        std::cout << "Longest span = " << test.longestSpan() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr
            << RED
            << e.what()
            << END
            << std::endl;
    }

    try
    {
        std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==                   TEST 5                   =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;

        Span test(200000);
        
        for (int i = 0; i <= 200000; i++)
            test.addNumber(i);
    }
    catch (std::exception & e)
    {
        std::cerr
            << RED
            << e.what()
            << END
            << std::endl
            << std::endl;
    }
    return (0);
}