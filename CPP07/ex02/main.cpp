#include "Array.hpp"
#include <string>

int main()
{
    Array<int> intArray(5);
    for (std::size_t i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 10;
    }

    for (std::size_t i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    try {
        std::cout << intArray[-10] << std::endl; // This should throw an exception
    } catch (const Array<int>::IndexOutOfBoundsException& e) {
        std::cerr << e.what() << std::endl;
    }

    Array<std::string> strArray(2);
    strArray[0] = "Hello";
    strArray[1] = "Wold";
    std::cout << strArray[0] << " " << strArray[1] << std::endl;
    return 0;
}
