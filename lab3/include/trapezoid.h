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
    explicit Trapezoid();
    explicit Trapezoid(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth);
    explicit Trapezoid(Trapezoid const & tr);
    explicit Trapezoid(Trapezoid&& tr);
    Trapezoid& operator=(Trapezoid const & tr) noexcept;
    Trapezoid& operator=(Trapezoid&& rec) noexcept;
    ~Trapezoid() noexcept;

    Point2D center() const noexcept override;
    double area() const noexcept override;
    explicit operator double() const noexcept override;

    friend std::istream& operator>>(std::istream& is, Trapezoid & tr);
    friend std::ostream& operator<<(std::ostream& os, Trapezoid const & tr); 
};

#endif // TRAPEZOID_H