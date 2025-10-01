#ifndef POINT_HPP
#define POINT_HPP

class Point {
    private:
        const x;
        const y;
    public:
        Point();
        Point( const float x, const float y );
        Point( Point &src);
        
        ~Point();
};

#endif