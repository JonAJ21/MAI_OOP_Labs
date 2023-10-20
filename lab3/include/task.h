#ifndef TASK_H
#define TASK_H

#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"

class Task final {
private:
    Figure* _figures;
    size_t _sz;
public:
    friend std::istream& operator>>(std::istream& is, Square & sq);
    friend std::ostream& operator<<(std::ostream& os, Square const & sq); 
};

#endif // TASK_H