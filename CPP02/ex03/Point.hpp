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
        Point( const Point &src);
        Point& operator=( const Point &src);
        ~Point();

        Fixed getX() const { return this->x; }
        Fixed getY() const { return this->y; }
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
bool same_point(Point const a, Point const b);

#endif
