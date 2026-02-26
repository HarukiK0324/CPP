#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i);
    std::vector<int>::iterator it = easyfind(v, 5);
    if (it != v.end())
        std::cout << "Found: " << *it << std::endl;
    else
        std::cout << "Not Found" << std::endl;
    it = easyfind(v, 11);
    if (it != v.end())
        std::cout << "Found: " << *it << std::endl;
    else
        std::cout << "Not Found" << std::endl;
}
