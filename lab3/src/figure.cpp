#include "figure.h"

std::istream& operator>>(std::istream& is, Figure & fig) {
    fig.input(is);
    return is;
}
std::ostream& operator<<(std::ostream& os, Figure const & fig) {
    fig.print(os);
    return os;
} 


bool Figure::are_equal(double lhs, double rhs, double epsilon) const {
    return abs(lhs - rhs) < epsilon;
}

bool Figure::are_sides_parallel(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth) const {
    if (second.x - first.x == 0) return (fourth.x - third.x == 0);
    if (second.y - first.y == 0) return (fourth.y - third.y == 0);
    
    double derivative_1 = (second.y - first.y) / (second.x - first.x);
    double derivative_2 = (fourth.y - third.y) / (fourth.x - third.x);

    return are_equal(derivative_1, derivative_2, 1e-6);
}

double Figure::get_len(Point2D const & first, Point2D const & second) const {
    return sqrt((second.x - first.x) * (second.x - first.x) + (second.y - first.y) * (second.y - first.y));
}