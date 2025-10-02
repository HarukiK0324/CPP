#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point();
        Point( const float x, const float y );
        Point( Point &src);
        Point& operator=( const Point &src);
        ~Point();

        Fixed getX() const { return this->x; }
        Fixed getY() const { return this->y; }
};

#endif