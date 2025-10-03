#include "Point.hpp"

bool same_point(Point const a, Point const b)
{
    if(a.getX() == b.getX() && a.getY() == b.getY())
        return true;
    return false;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Point ab, ac, ap;
    float s,t,u;

    if(same_point(a, b) || same_point(b, c) || same_point(c, a))
        return false;

    ab = Point(b.getX().toFloat() - a.getX().toFloat(), b.getY().toFloat() - a.getY().toFloat());
    ac = Point(c.getX().toFloat() - a.getX().toFloat(), c.getY().toFloat() - a.getY().toFloat());
    ap = Point(point.getX().toFloat() - a.getX().toFloat(), point.getY().toFloat() - a.getY().toFloat());

    u = ab.getX().toFloat() * ac.getY().toFloat() - ab.getY().toFloat() * ac.getX().toFloat();
    if(u == 0)
        return false;
    s = (ap.getX().toFloat() * ac.getY().toFloat() - ap.getY().toFloat() * ac.getX().toFloat()) / u;
    if(ac.getX().toFloat() != 0)
        t = (ap.getX().toFloat() - ab.getX().toFloat() * s) / ac.getX().toFloat();
    else
        t = (ap.getY().toFloat() - ab.getY().toFloat() * s) / ac.getY().toFloat();

    return ((s > 0) && (t > 0) && (s + t < 1.0f));
}
