#ifndef POINT2D_H
#define POINT2D_H

#include <cmath>
#include <type_traits>

template<typename T>
struct Point2D {
    static_assert(std::is_arithmetic<T>::value, "T must be arithmetic");
    T x;
    T y;
};

template<typename T>
bool are_equal(T lhs, T rhs, double epsilon) {
    return abs(lhs - rhs) < epsilon;
}

template<typename T>
bool are_sides_parallel(Point2D<T> const & first, Point2D<T> const & second, Point2D<T> const & third, Point2D<T> const & fourth) {
    if (are_equal(first.x, second.x, 1e-6)) return are_equal(third.x, fourth.x, 1e-6);
    if (are_equal(first.y, second.y, 1e-6)) return are_equal(third.y, fourth.y, 1e-6);
    
    double derivative_1 = (second.y - first.y) / (second.x - first.x);
    double derivative_2 = (fourth.y - third.y) / (fourth.x - third.x);

    return are_equal(derivative_1, derivative_2, 1e-6);
}

template<typename T>
double get_len(Point2D<T> const & first, Point2D<T> const & second) {
    return sqrt((second.x - first.x) * (second.x - first.x) + (second.y - first.y) * (second.y - first.y));
}

#endif // POINT2D_H