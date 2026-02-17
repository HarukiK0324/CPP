#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);

    MutantStack<int>::const_iterator cit = mstack.begin();
    MutantStack<int>::const_iterator cite = mstack.end();
    ++cit;
    --cit;
    while (cit != cite)
    {
    std::cout << *cit << std::endl;
    ++cit;
    }

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    ++lit;
    --lit;
    while (lit != lite)
    {
    std::cout << *lit << std::endl;
    ++lit;
    }
    std::list<int> lst2(lst);

    MutantStack<std::string> strStack;
    strStack.push("Hello");
    strStack.push("World");
    strStack.push("from");
    strStack.push("MutantStack!");
    for(MutantStack<std::string>::reverse_iterator rit = strStack.rbegin(); rit != strStack.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;
    for(MutantStack<std::string>::const_reverse_iterator crit = strStack.rbegin(); crit != strStack.rend(); ++crit)
        std::cout << *crit << " ";
    std::cout << std::endl;
    return 0;
}
