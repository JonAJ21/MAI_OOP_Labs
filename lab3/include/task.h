#ifndef TASK_H
#define TASK_H

#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"

class Task final {
private:
    Figure** _figures;
    size_t _sz;
public:
    Task();
    Task(std::initializer_list<Figure*> const & init_list);
    Task(Task const & t) noexcept;
    Task(Task&& t) noexcept;
    Task& operator=(Task const & t) noexcept;
    Task& operator=(Task&& t) noexcept;
    ~Task();

    bool push_back(Figure const & fig);
    Figure pop_back();
    bool insert(Figure const & fig, size_t idx);
    Figure remove(size_t idx);

    double total_area() noexcept;

    friend std::istream& operator>>(std::istream& is, Square & sq);
    friend std::ostream& operator<<(std::ostream& os, Square const & sq); 
};

#endif // TASK_H