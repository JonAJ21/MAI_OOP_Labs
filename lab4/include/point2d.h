#ifndef POINT2D_H
#define POINT2D_H

#include <cmath>

template<typename T>
struct Point2D {
    T x;
    T y;
};

template<typename T>
bool are_equal(T lhs, T rhs, double epsilon) {
    return abs(lhs - rhs) < epsilon;
}

template<typename T>
bool are_sides_parallel(Point2D<T> const & first, Point2D<T> const & second, Point2D<T> const & third, Point2D<T> const & fourth) {
    if (second.x - first.x == 0) return (fourth.x - third.x == 0);
    if (second.y - first.y == 0) return (fourth.y - third.y == 0);
    
    double derivative_1 = (second.y - first.y) / (second.x - first.x);
    double derivative_2 = (fourth.y - third.y) / (fourth.x - third.x);

    return are_equal(derivative_1, derivative_2, 1e-6);
}

template<typename T>
double get_len(Point2D<T> const & first, Point2D<T> const & second) {
    return sqrt((second.x - first.x) * (second.x - first.x) + (second.y - first.y) * (second.y - first.y));
}

#endif // POINT2D_H