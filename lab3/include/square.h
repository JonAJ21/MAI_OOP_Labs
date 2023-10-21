#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square final : public Figure {
private:
    Point2D _first;
    Point2D _second;
    Point2D _third;
    Point2D _fourth;

    bool is_square(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth) const;

public:
    explicit Square() = default;
    explicit Square(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth);

    Point2D center() const noexcept override;
    double area() const noexcept override;
    explicit operator double() const noexcept override;
    bool operator==(Square const & sq);

    void input(std::istream& is) override;
    void print(std::ostream& os) const override;

    friend std::istream& operator>>(std::istream& is, Square & sq);
    friend std::ostream& operator<<(std::ostream& os, Square const & sq); 
};

#endif // SQUARE_H