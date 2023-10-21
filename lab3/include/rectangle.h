#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle final : public Figure {
private:
    Point2D _first;
    Point2D _second;
    Point2D _third;
    Point2D _fourth;

    bool is_rectangle(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth) const;

public: 
    explicit Rectangle() = default;
    explicit Rectangle(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth);
    
    Point2D center() const noexcept override;
    double area() const noexcept override;
    explicit operator double() const noexcept override;
    bool operator==(Rectangle const & rec);

    void input(std::istream& is) override;
    void print(std::ostream& os) const override;

    friend std::istream& operator>>(std::istream& is, Rectangle & rec);
    friend std::ostream& operator<<(std::ostream& os, Rectangle const & rec); 
};

#endif // RECTANGLE_H