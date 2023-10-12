#ifndef TWELVE_H
#define TWELVE_H

#include <iostream>

class Twelve final {
private:
    static char const ALPHABET[];
    unsigned char* _number;
    size_t _sz;
public:
    //----------------------------------------------
    // The rule of five

    // Assignment constructors
    Twelve();
    Twelve(std::initializer_list<unsigned char> const & init_list);
    Twelve(std::string const & str);
    // Copy constructor
    Twelve(Twelve const & other);
    // Move constructor
    Twelve(Twelve&& other) noexcept;
    // Copy assignment operator
    Twelve& operator=(Twelve const & other);
    // Move assignment operator
    Twelve& operator=(Twelve&& other) noexcept;
    // Destructor
    ~Twelve() noexcept;

    //----------------------------------------------
    // Methods

    size_t get_sz() const;
    unsigned char* get_number() const;

    bool is_equal(Twelve const & other) const;
    bool is_bigger(Twelve const & other) const;
    bool is_smaller(Twelve const & other) const;

    Twelve add(Twelve const & other) const;
    Twelve substract(Twelve const & other) const;

    friend std::ostream& operator<<(std::ostream& os, Twelve const & t);
};

#endif // TWELVE_H