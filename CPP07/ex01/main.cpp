#include "iter.hpp"
#include <iostream>

void printInt(int &x) { std::cout << x << " "; }
void printString(const std::string &s) { std::cout << s << " "; }
void printDouble(double &d) { std::cout << d << " "; }

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, printInt); // Output: 1 2 3 4 5
    std::cout << std::endl;

    std::string strArr[] = {"Hello", "World", "!"};
    iter(strArr, 3, printString); // Output: Hello World !
    std::cout << std::endl;

    double dblArr[] = {1.1, 2.2, 3.3};
    iter(dblArr, 3, printDouble); // Output: 1.1 2.2 3.3
    std::cout << std::endl;
    return 0;
}
