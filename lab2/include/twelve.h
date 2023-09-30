#ifndef TWELVE_H
#define TWELVE_H

#include <iostream>

class Twelve final {
private:
    const char* ALPHABET = "0123456789AB"; // Вопрос про static
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
    Twelve& operator=(Twelve const & other); // ???????????
    // Destructor
    ~Twelve() noexcept;

    //----------------------------------------------
    // Methods
    
    std::ostream& print(std::ostream& os);

    bool is_bigger(Twelve const & other) const;
    // bool is_bigger(Twelve& lhs, Twelve& rhs);
    
    bool is_smaller(Twelve& other);
    // bool is_smaller(Twelve& lhs, Twelve& rhs);
    
    bool is_equal(Twelve& other);
    // bool is_equal(Twelve& lhs, Twelve& rhs);

    Twelve add(Twelve& other);
    // Twelve add(Twelve& lhs, Twelve& rhs);

    Twelve substract(Twelve& other);
    // Twelve substarct(Twelve& lhs, Twelve& rhs);
};

#endif // TWELVE_H

//Переписать  для print cout, cin
// Переписать is smaller is bigger(сделать проще)
// убрать лишние try catch
// Alphabet должен быть static

// Сократить toupper от 2 использований до 1
// Попросить пример с The rule of five
// При объявлении конструкторов добавить const в конце, если не меняется