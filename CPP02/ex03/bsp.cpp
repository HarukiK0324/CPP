#include "Point.hpp"

bool same_point(Point const a, Point const b)
{
    if(a.getX() == b.getX() && a.getY() == b.getY())
        return true;
    return false;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float s,t,u;

    if(same_point(a, b) || same_point(b, c) || same_point(c, a))
        return false;

    const Point ab(b.getX().toFloat() - a.getX().toFloat(), b.getY().toFloat() - a.getY().toFloat());
    const Point ac(c.getX().toFloat() - a.getX().toFloat(), c.getY().toFloat() - a.getY().toFloat());
    const Point ap(point.getX().toFloat() - a.getX().toFloat(), point.getY().toFloat() - a.getY().toFloat());

    // std::cout << "ab: (" << ab.getX() << ", " << ab.getY() << ")" << std::endl;
    // std::cout << "ac: (" << ac.getX() << ", " << ac.getY() << ")" << std::endl;
    // std::cout << "ap: (" << ap.getX() << ", " << ap.getY() << ")" << std::endl;

    u = (ab.getX() * ac.getY() - ab.getY() * ac.getX()).toFloat();
    // std::cout << "u: " << u << std::endl;
    if(u == 0)
        return false;
    s = (ap.getX().toFloat() * ac.getY().toFloat() - ap.getY().toFloat() * ac.getX().toFloat()) / u;
    if(ac.getX().toFloat() != 0)
        t = (ap.getX().toFloat() - ab.getX().toFloat() * s) / ac.getX().toFloat();
    else
        t = (ap.getY().toFloat() - ab.getY().toFloat() * s) / ac.getY().toFloat();

    // std::cout << "s: " << s << ", t: " << t << ", u: " << u << std::endl;
    return ((s > 0) && (t > 0) && (s + t < 1.0f));
}
