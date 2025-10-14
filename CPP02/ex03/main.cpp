#include "Point.hpp"
#include <iostream>

int         main( void ) {

    Point a(0, 0);
    Point b(0, 20);
    Point c(20, 0);

    bsp(a, b, c, Point(1,1)) ? std::cout << "Inside" << std::endl : std::cout << "Outside" << std::endl;
    
    return 0;
}
