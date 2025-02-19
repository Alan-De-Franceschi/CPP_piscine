#include "MutantStack.hpp"
#include <list>
#include <vector>

int main(void)
{
    std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==               TEST MutantStack             =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;
    
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top = " << mstack.top() << std::endl;
    std::cout << "Size before pop = " << mstack.size() << std::endl;
    mstack.pop();
    std::cout << "Size after pop = " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    std::cout << std::endl << BLUE << "Test iterator = " << END << std::endl << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }

    std::cout << std::endl << BLUE << "Test Reverse iterator = " << END << std::endl << std::endl;

    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    ++rit;
    --rit;

    while (rit != rite)
    {
    std::cout << *rit << std::endl;
    ++rit;
    }

    std::cout << std::endl << BLUE << "Test Objet par copie de MutantStack = " << END << std::endl << std::endl;

    std::stack<int> s(mstack);
    std::cout << "stack copy Top = " << s.top() << std::endl;
    std::cout << "stack copie Size = " << s.size() << std::endl;

    MutantStack<int> ms(mstack);
    std::cout << "MutantStack copie Top = " << ms.top() << std::endl;
    std::cout << "MutantStack copie Size = " << ms.size() << std::endl;

    std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==                  TEST List                 =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;

        std::list<int> myList;

        myList.push_back(5);
        myList.push_back(17);
    
        std::cout << "Top = " << myList.back() << std::endl;
        std::cout << "Size before pop = " << myList.size() << std::endl;
        myList.pop_back();
        std::cout << "Size after pop = " << myList.size() << std::endl;
    
        myList.push_back(3);
        myList.push_back(5);
        myList.push_back(737);
        //[...]
        myList.push_back(0);
    
        std::cout << std::endl << BLUE << "Test iterator = " << END << std::endl << std::endl;
    
        std::list<int>::iterator itl = myList.begin();
        std::list<int>::iterator itel = myList.end();
    
        ++itl;
        --itl;
    
        while (itl != itel)
        {
        std::cout << *itl << std::endl;
        ++itl;
        }

        std::cout << std::endl << BLUE << "Test Reverse iterator = " << END << std::endl << std::endl;
    
        std::list<int>::reverse_iterator ritl = myList.rbegin();
        std::list<int>::reverse_iterator ritel = myList.rend();
    
        ++ritl;
        --ritl;
    
        while (ritl != ritel)
        {
        std::cout << *ritl << std::endl;
        ++ritl;
        }

        std::cout
        << std::endl
        << GREEN
        << "================================================"
        <<std::endl
        << "==                  TEST Vector               =="
        << std::endl
        << "================================================"
        << END
        << std::endl << std::endl;

        std::vector<int> myVector;

        myVector.push_back(5);
        myVector.push_back(17);
    
        std::cout << "Top = " << myVector.back() << std::endl;
        std::cout << "Size before pop = " << myVector.size() << std::endl;
        myVector.pop_back();
        std::cout << "Size after pop = " << myVector.size() << std::endl;
    
        myVector.push_back(3);
        myVector.push_back(5);
        myVector.push_back(737);
        //[...]
        myVector.push_back(0);
    
        std::cout << std::endl << BLUE << "Test iterator = " << END << std::endl << std::endl;
    
        std::vector<int>::iterator itv = myVector.begin();
        std::vector<int>::iterator itev = myVector.end();
    
        ++itv;
        --itv;
    
        while (itv != itev)
        {
        std::cout << *itv << std::endl;
        ++itv;
        }

        std::cout << std::endl << BLUE << "Test Reverse iterator = " << END << std::endl << std::endl;
    
        std::vector<int>::reverse_iterator ritv = myVector.rbegin();
        std::vector<int>::reverse_iterator ritev = myVector.rend();
    
        ++ritv;
        --ritv;
    
        while (ritv != ritev)
        {
        std::cout << *ritv << std::endl;
        ++ritv;
        }
    
        std::cout << std::endl;

    return 0;
}