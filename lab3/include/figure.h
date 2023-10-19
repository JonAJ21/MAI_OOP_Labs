#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <cmath>

class Figure {
public:
    struct Point2D {
        double x, y;
    };

    virtual ~Figure() noexcept = default;

    virtual Point2D center() const noexcept = 0;
    virtual double area() const noexcept = 0;
    explicit virtual operator double() const noexcept = 0;

protected:
    double get_machine_epsilon() const;
    bool are_sides_parallel(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth) const;
    double get_len(Point2D const & first, Point2D const & second) const;
    // friend std::istream& operator>>(std::istream& is, Figure & fig);
    // friend std::ostream& operator<<(std::ostream& os, Figure const & fig);
};

#endif // FIGURE_H