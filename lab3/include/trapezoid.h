#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"

class Trapezoid final : public Figure {
private:
    Point2D _first;
    Point2D _second;
    Point2D _third;
    Point2D _fourth;

    bool is_trapezoid(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth) const;

public:
    explicit Trapezoid() = default;
    explicit Trapezoid(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth);

    Point2D center() const noexcept override;
    double area() const noexcept override;
    explicit operator double() const noexcept override;
    bool operator==(Trapezoid const & tr);

    void input(std::istream& is) override;
    void print(std::ostream& os) const override;

    friend std::istream& operator>>(std::istream& is, Trapezoid & tr);
    friend std::ostream& operator<<(std::ostream& os, Trapezoid const & tr); 
};

#endif // TRAPEZOID_H