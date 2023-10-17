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

    // friend std::istream& operator>>(std::istream& is, Figure & fig);
    // friend std::ostream& operator<<(std::ostream& os, Figure const & fig);
};

#endif // FIGURE_H