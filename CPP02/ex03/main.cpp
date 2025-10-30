#include "Point.hpp"
#include <iostream>

// int         main( void ) {

//     Point a(0, 0);
//     Point b(0, 20);
//     Point c(20, 0);

//     bsp(a, b, c, Point(0.001f, 0.001f)) ? std::cout << "Inside" << std::endl : std::cout << "Outside" << std::endl;
//     bsp(a, b, c, Point(9.999f, 0.001f)) ? std::cout << "Inside" << std::endl : std::cout << "Outside" << std::endl;
//     bsp(a, b, c, Point(10, 10.001f)) ? std::cout << "Inside" << std::endl : std::cout << "Outside" << std::endl;
//     return 0;
// }

int main(void)
{
    Point a(0, 0);
    Point b(0, 20);
    Point c(20, 0);

    bsp(a, b, c, Point(1, 1)) ? std::cout << "Inside" << std::endl : std::cout << "Outside" << std::endl;
    bsp(a, b, c, Point(5, 5)) ? std::cout << "Inside" << std::endl : std::cout << "Outside" << std::endl;
    bsp(a, b, c, Point(12, 12)) ? std::cout << "Inside" << std::endl : std::cout << "Outside" << std::endl;
    return 0;
}
