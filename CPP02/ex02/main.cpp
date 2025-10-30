#include "Fixed.hpp"
#include <iostream>

int         main( void ) {

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;
    
    return 0;
}


// int main()
// {
//     Fixed a(5.05f);
//     Fixed b(5.04f);

//     std::cout << "a: " << a << ", b: " << b << std::endl;
//     std::cout << "a + b: " << a + b << std::endl;
//     std::cout << "a - b: " << a - b << std::endl;
//     std::cout << "a * b: " << a * b << std::endl;
//     std::cout << "a / b: " << a / b << std::endl;
//     std::cout << "a > b: " << (a > b) << std::endl;
//     std::cout << "a < b: " << (a < b) << std::endl;
//     std::cout << "a >= b: " << (a >= b) << std::endl;
//     std::cout << "a <= b: " << (a <= b) << std::endl;
//     std::cout << "a == b: " << (a == b) << std::endl;
//     std::cout << "a != b: " << (a != b) << std::endl;
// }
