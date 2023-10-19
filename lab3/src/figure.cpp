#include "figure.h"

double Figure::get_machine_epsilon() const {
    double epsilon = 1.0;
    while (1.0 + epsilon > 1.0) {
        epsilon = epsilon / 2.0;
    }
    return epsilon;
}

bool Figure::are_sides_parallel(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth) const {
    if (second.x - first.x == 0) return (fourth.x - third.x == 0);
    if (second.y - first.y == 0) return (fourth.y - third.y == 0);
    
    double derivative_1 = (second.y - first.y) / (second.x - first.x);
    double derivative_2 = (fourth.y - third.y) / (fourth.x - third.x);

    return (abs(derivative_1 - derivative_2) < get_machine_epsilon());
}

double Figure::get_len(Point2D const & first, Point2D const & second) const {
    return sqrt((second.x - first.x) * (second.x - first.x) + (second.y - first.y) * (second.y - first.y));
}