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
    explicit Square();
    explicit Square(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth);
    explicit Square(Square const & sq);
    explicit Square(Square&& sq);
    Square& operator=(Square const & sq) noexcept;
    Square& operator=(Square&& sq) noexcept;
    ~Square() noexcept;

    Point2D center() const noexcept override;
    double area() const noexcept override;
    explicit operator double() const noexcept override;

    friend std::istream& operator>>(std::istream& is, Square & sq);
    friend std::ostream& operator<<(std::ostream& os, Square const & sq); 
};



#endif // SQUARE_H