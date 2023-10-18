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
    Task();
    Task(std::initializer_list<Figure> const & init_list);
    Task(Task const & t);
    Task(Task&& t);
    Task& operator=(Task const & t);
    Task& operator=(Task&& t);
    ~Task() noexcept;

    bool push_back(Figure const & fig);
    bool insert(Figure const & fig, size_t idx);
    bool pop(size_t idx);
    void print_areas();
    void print_centres();
    double total_area();

    void enter_figures();


    // TODO
    // Операции сравнения


};

#endif // TASK_H