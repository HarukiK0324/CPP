#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Point ab, ac, ap;
    Fixed s,t;

    ab = Point(b.getX().toFloat() - a.getX().toFloat(), b.getY().toFloat() - a.getY().toFloat());
    ac = Point(c.getX().toFloat() - a.getX().toFloat(), c.getY().toFloat() - a.getY().toFloat());
    ap = Point(point.getX().toFloat() - a.getX().toFloat(), point.getY().toFloat() - a.getY().toFloat());

    s = ;
    t = ;

    return (s > 0) && (t > 0) && (s + t < Fixed(1));
}
