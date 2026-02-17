#include "easyfind.hpp"
#include <stdio.h>
#include <vector>

int main()
{
    std::vector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i);
    std::vector<int>::iterator it = easyfind(v, 5);
    if (it != v.end())
        printf("Found: %d\n", *it);
    else
        printf("Not found\n");
    it = easyfind(v, 11);
    if (it != v.end())
        printf("Found: %d\n", *it);
    else
        printf("Not found\n");
}
