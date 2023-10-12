#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class Figure {
private:
    double* coords;
    double area;
public:
    Figure();
    Figure(int const * coords);
    Figure(Figure const & fig);
    Figure(Figure&& fig) noexcept;
    Figure& operator=(Figure const & fig); 
    Figure& operator=(Figure&& fig) noexcept;
    virtual ~Figure();
    
    double* get_coords() const;

    virtual double area() const;

    friend std::ostream& operator<<(std::ostream& os, Figure const & t);
    friend std::istream& operator<<(std::istream& os, Figure const & t);
};

#endif // FIGURE_H