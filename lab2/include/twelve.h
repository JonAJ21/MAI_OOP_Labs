#ifndef TWELVE_H
#define TWELVE_H

#include <iostream>

class Twelve {
private:
    unsigned char* _number;
    size_t _sz;
public:
    //----------------------------------------------
    // The rule of five

    // Assignment constructors
    Twelve();
    Twelve(const std::initializer_list<unsigned char>& init_list);
    Twelve(const std::string& str);
    // Copy constructor
    Twelve(const Twelve& other);
    // Move constructor
    Twelve(Twelve&& other) noexcept;
    // Move assignment operator
    Twelve& operator=(Twelve&& other); // ???????????
    // Destructor
    virtual ~Twelve() noexcept;

    //----------------------------------------------
    // Methods
    
    Twelve add(Twelve& other);
    Twelve add(Twelve& lhs, Twelve& rhs);

    Twelve substract(Twelve& other);
    Twelve substarct(Twelve& lhs, Twelve& rhs);
    
    bool is_bigger(Twelve& other);
    bool is_bigger(Twelve& lhs, Twelve& rhs);
    
    bool is_smaller(Twelve& other);
    bool is_smaller(Twelve& lhs, Twelve& rhs);
    
    bool is_equal(Twelve& other);
    bool is_equal(Twelve& lhs, Twelve& rhs);

    std::ostream& print(std::ostream& os);
};

#endif // TWELVE_H