#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0))
{
    std::cout << "Default constructor called" << std::endl;
}

Point::Point( const float x, const float y ) : x(Fixed(x)), y(Fixed(y))
{
    std::cout << "Parameterized constructor called" << std::endl;
}

Point::Point( Point &src) : x(src.x), y(src.y)
{
    std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=( const Point &src)
{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &src)
    {
        Point(src);
    }
    return *this;
}

Point::~Point()
{
    std::cout << "Destructor called" << std::endl;
}
