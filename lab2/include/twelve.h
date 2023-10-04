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
    // Move assignment operator
    Twelve& operator=(Twelve&& other); // ???????????
    Twelve& operator=(Twelve const & other); // ???????????
    // Destructor
    ~Twelve() noexcept;

    //----------------------------------------------
    // Methods

    bool is_equal(Twelve const & other) const;
    // bool is_equal(Twelve& lhs, Twelve& rhs);

    bool is_bigger(Twelve const & other) const;
    // bool is_bigger(Twelve& lhs, Twelve& rhs);
    
    bool is_smaller(Twelve const & other) const;
    // bool is_smaller(Twelve& lhs, Twelve& rhs);

    Twelve add(Twelve const & other) const;
    // Twelve add(Twelve& lhs, Twelve& rhs);

    Twelve substract(Twelve const & other) const;
    // Twelve substarct(Twelve& lhs, Twelve& rhs);

    // Friend
    friend std::ostream& operator<<(std::ostream& os, Twelve const & t);
};

#endif // TWELVE_H

//Переписать print cout << +
// Переписать is smaller is bigger(сделать проще) +-
// убрать лишние try catch +
// Alphabet должен быть static +

// Сократить toupper от 2 использований до 1 + 
// Попросить пример с The rule of five
// При объявлении конструкторов добавить const в конце, если не меняется +