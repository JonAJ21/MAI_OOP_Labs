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
    explicit Rectangle();
    explicit Rectangle(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth);
    explicit Rectangle(Rectangle const & rec);
    explicit Rectangle(Rectangle&& rec);
    Rectangle& operator=(Rectangle const & rec) noexcept;
    Rectangle& operator=(Rectangle&& rec) noexcept;
    ~Rectangle() noexcept;

    Point2D center() const noexcept override;
    double area() const noexcept override;
    explicit operator double() const noexcept override;
    bool operator==(Rectangle const & rec);

    friend std::istream& operator>>(std::istream& is, Rectangle & rec);
    friend std::ostream& operator<<(std::ostream& os, Rectangle const & rec); 
};


#endif // RECTANGLE_H