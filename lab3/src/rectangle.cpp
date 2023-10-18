#include "rectangle.h"

bool Rectangle::is_rectangle(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth) const {
    double lens[6];
    lens[0] = sqrt((first.x - second.x) * (first.x - second.x)
                 + (first.y - second.y) * (first.y - second.y));
    lens[1] = sqrt((first.x - third.x) * (first.x - third.x)
                 + (first.y - third.y) * (first.y - third.y));
    lens[2] = sqrt((first.x - fourth.x) * (first.x - fourth.x)
                 + (first.y - fourth.y) * (first.y - fourth.y));
    
    lens[3] = sqrt((second.x - third.x) * (second.x - third.x)
                 + (second.y - third.y) * (second.y - third.y));
    lens[4] = sqrt((second.x - fourth.x) * (second.x - fourth.x)
                 + (second.y - fourth.y) * (second.y - fourth.y));

    lens[5] = sqrt((third.x - fourth.x) * (third.x - fourth.x)
                 + (third.y - fourth.y) * (third.y - fourth.y));               
    
    // Machine epsilon
    double epsilon = 1.0;
    while (1.0 + epsilon > 1.0) {
        epsilon = epsilon / 2.0;
    }
    
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
    return ((lens[1] - lens[0] < epsilon) && (lens[3] - lens[2] < epsilon) && (lens[5] - lens[4] < epsilon) &&
            (lens[4] - sqrt(lens[0] * lens[0] + lens[2] * lens[2]) < epsilon));
}


Rectangle::Rectangle() : _first({0, 0}), _second({0, 0}), _third({0, 0}), _fourth({0, 0}) {
    std::cout << "Default constructor" << std::endl;
}

Rectangle::Rectangle(Point2D const & first, Point2D const & second, Point2D const & third, Point2D const & fourth) {
    std::cout << "Init_list constructor" << std::endl;

    if (!is_rectangle(first, second, third, fourth)) {
        throw std::invalid_argument("It is not a rectangle");
    }

    _first = first;
    _second = second;
    _third = third;
    _fourth = fourth;
}

Rectangle::Rectangle(Rectangle const & rec) : _first(rec._first), _second(rec._second), _third(rec._third), _fourth(rec._fourth) {
    std::cout << "Copy constructor" << std::endl;
}

Rectangle::Rectangle(Rectangle&& rec) : _first(rec._first), _second(rec._second), _third(rec._third), _fourth(rec._fourth) {
    std::cout << "Move constructor" << std::endl;
    rec._first = {0, 0};
    rec._second = {0, 0};
    rec._third = {0, 0};
    rec._fourth = {0, 0};
}

Rectangle& Rectangle::operator=(Rectangle const & rec) noexcept {
    std::cout << "Copy assignment operator" << std::endl;
    if (this == &rec) {
        return *this;
    }
    _first = rec._first;
    _second = rec._second;
    _third = rec._third;
    _fourth = rec._fourth;
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& rec) noexcept {
    std::cout << "Move assignment operator" << std::endl;
    if (this == &rec) {
        return *this;
    }
    rec._first = {0, 0};
    rec._second = {0, 0};
    rec._third = {0, 0};
    rec._fourth = {0, 0};
    return *this;
}

Rectangle::~Rectangle() noexcept {
    std::cout << "Destructor" << std::endl;
}

Rectangle::Point2D Rectangle::center() const noexcept {
    Point2D center;
    center.x = (_first.x + _second.x + _third.x + _fourth.x) / 4;
    center.y = (_first.y + _second.y + _third.y + _fourth.y) / 4;
    return center;
}

double Rectangle::area() const noexcept {
    double len_1 = sqrt((_first.x - _second.x) * (_first.x - _second.x)
                      + (_first.y - _second.y) * (_first.y - _second.y));
    double len_2 = sqrt((_first.x - _third.x) * (_first.x - _third.x)
                      + (_first.y - _third.y) * (_first.y - _third.y));
    double len_3 = sqrt((_first.x - _fourth.x) * (_first.x - _fourth.x)
                      + (_first.y - _fourth.y) * (_first.y - _fourth.y));
    double a, b;
    if (len_1 <= len_2 && len_1 <= len_3) a = len_1;
    if (len_2 <= len_1 && len_2 <= len_3) a = len_2;
    if (len_3 <= len_1 && len_3 <= len_2) a = len_3;

    if (len_1 >= len_2 && len_1 >= len_3) b = (len_1 + len_2 + len_3) - a - len_1;
    if (len_2 >= len_1 && len_2 >= len_3) b = (len_1 + len_2 + len_3) - a - len_2;
    if (len_3 >= len_1 && len_3 >= len_2) b = (len_1 + len_2 + len_3) - a - len_3;

    return a * b;
}

Rectangle::operator double() const noexcept {
    return area();
}


std::istream& operator>>(std::istream& is, Rectangle& rec) {
    Rectangle::Point2D first, second, third, fourth;

    is >> first.x >> first.y;
    is >> second.x >> second.y;
    is >> third.x >> third.y;
    is >> fourth.x >> fourth.y;

    if (!rec.is_rectangle(first, second, third, fourth)) {
        throw std::invalid_argument("It is not a rectangle");
    }
    rec._first = first;
    rec._second = second;
    rec._third = third;
    rec._fourth = fourth;
    return is;
}

std::ostream& operator<<(std::ostream& os, Rectangle const & rec) {
    os << '{' << rec._first.x << ", " << rec._first.y << "} ";
    os << '{' << rec._second.x << ", " << rec._second.y << "} ";
    os << '{' << rec._third.x << ", " << rec._third.y << "} ";
    os << '{' << rec._fourth.x << ", " << rec._fourth.y << "} ";
    return os;
}
