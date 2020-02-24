#pragma once

template <typename T>
class Point
{
    Point()=delete;
public:
    explicit Point(T X,T Y) : x(X), y(Y){}
    Point(const Point & point) : x(point.x), y(point.y){}
    Point(Point<T>&& point) : x(point.x), y(point.y)
    {
        point.x = 0;
        point.y = 0;
    }
    Point<T> &operator=(const Point<T> & point)
    {
        x = point.x;
        y = point.y;
        return *this;
    }
    bool operator==(const Point<T> & point){return x=point.x && y=point.y;}
    T x,y;
};
