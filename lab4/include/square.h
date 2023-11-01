#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

template<typename T>
class Square final : public Figure<T> {
private:
    Point2D<T> _first;
    Point2D<T> _second;
    Point2D<T> _third;
    Point2D<T> _fourth;

    bool is_square(Point2D<T> const & first, Point2D<T> const & second, Point2D<T> const & third, Point2D<T> const & fourth) const;

public:
    explicit Square() = default;
    explicit Square(Point2D<T> const & first, Point2D<T> const & second, Point2D<T> const & third, Point2D<T> const & fourth);

    Point2D<T> center() const noexcept override;
    double area() const noexcept override;
    explicit operator double() const noexcept override;

    bool operator==(Square<T> const & sq) const;

    void input(std::istream& is) override;
    void print(std::ostream& os) const override;

    template<T> friend std::istream& operator>>(std::istream& is, Square<T> & sq);
    template<T> friend std::ostream& operator<<(std::ostream& os, Square<T> const & sq); 
};

template<typename T>
bool Square<T>::is_square(Point2D<T> const & first, Point2D<T> const & second, Point2D<T> const & third, Point2D<T> const & fourth) const {
    double lens[6];

    lens[0] = get_len(first, second);
    lens[1] = get_len(first, third);   
    lens[2] = get_len(first, fourth);   
    lens[3] = get_len(second, third);    
    lens[4] = get_len(second, fourth);   
    lens[5] = get_len(third, fourth);            
    
    // Bubble sort
    for (size_t i = 0; i < 5; ++i) {
        int swapped = 0;
        for (size_t j = 0; j < 5 - i; ++j) {
            if (lens[j] > lens[j + 1]) {
                double temp = lens[j];
                lens[j] = lens[j + 1];
                lens[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) break;
    }

    return (are_equal(lens[0], lens[1], 1e-6) && are_equal(lens[0], lens[2], 1e-6) && are_equal(lens[0], lens[3], 1e-6) &&
            are_equal(lens[4], lens[5], 1e-6) && are_equal(lens[4], lens[0] * sqrt(2), 1e-6));
}

template<typename T>
Square<T>::Square(Point2D<T> const & first, Point2D<T> const & second, Point2D<T> const & third, Point2D<T> const & fourth) {
    if (!is_square(first, second, third, fourth)) {
        throw std::invalid_argument("It is not a square");
    }
    _first = first;
    _second = second;
    _third = third;
    _fourth = fourth;
}

template<typename T>
Point2D<T> Square<T>::center() const noexcept {
    Point2D<T> center;
    center.x = (_first.x + _second.x + _third.x + _fourth.x) / 4;
    center.y = (_first.y + _second.y + _third.y + _fourth.y) / 4;
    return center;
}

template<typename T>
double Square<T>::area() const noexcept {
    double len_1 = get_len(_first, _second);
    double len_2 = get_len(_first, _third);
    double len_3 = get_len(_first, _fourth);
    if (len_1 <= len_2 && len_1 <= len_3) return (len_1 * len_1);
    if (len_2 <= len_1 && len_2 <= len_3) return (len_2 * len_2);
    return (len_3 * len_3);

}

template<typename T>
Square<T>::operator double() const noexcept {
    return area();
}

template<typename T>
bool Square<T>::operator==(Square<T> const & sq) const {
    return (are_equal(_first.x, sq._first.x, 1e-6) && are_equal(_first.y, sq._first.y, 1e-6) &&
            are_equal(_second.x, sq._second.x, 1e-6) && are_equal(_second.y, sq._second.y, 1e-6) &&
            are_equal(_third.x, sq._third.x, 1e-6) && are_equal(_third.y, sq._third.y, 1e-6) &&
            are_equal(_fourth.x, sq._fourth.x, 1e-6) && are_equal(_fourth.y, sq._fourth.y, 1e-6));
}

template<typename T>
void Square<T>::input(std::istream& is) {
    Point2D<T> first, second, third, fourth;

    is >> first.x >> first.y;
    is >> second.x >> second.y;
    is >> third.x >> third.y;
    is >> fourth.x >> fourth.y;

    if (!is_square(first, second, third, fourth)) {
        throw std::invalid_argument("It is not a square");
    }

    _first = first;
    _second = second;
    _third = third;
    _fourth = fourth;
}

template<typename T>
void Square<T>::print(std::ostream& os) const {
    os << '{' << _first.x << ", " << _first.y << "} ";
    os << '{' << _second.x << ", " << _second.y << "} ";
    os << '{' << _third.x << ", " << _third.y << "} ";
    os << '{' << _fourth.x << ", " << _fourth.y << "} ";
}


template<typename T>
std::istream& operator>>(std::istream& is, Square<T>& sq) {
    sq.input(is);
    return is;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, Square<T> const & sq) {
    sq.print(os);
    return os;
}



#endif // SQUARE_H