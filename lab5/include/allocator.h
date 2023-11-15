#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <iostream>
#include <deque>

namespace mai {
    
    template<typename T>
    class Allocator {
    private:
        std::deque<T*> _used_blocks;
        std::deque<T*> _free_blocks;
    public:
         // Так и не понял, зачем это пишут в примере.
        using value_type = T;
        using ptr = T*;
        using const_ptr = T const *;
        using size_type = size_t;


        Allocator() = default;
        // Allocator(Allocator const & other);
        // Allocator(Allocator&& other);
        // Allocator& operator=(Allocator<T> const & other);
        // Allocator& operator=(Allocator<T>&& other);
        ~Allocator();

        template<typename U>
        struct rebind {using other = Allocator<U>;};

        T* allocate(size_t n);
        void deallocate(T* ptr, size_t size);

        // template <typename T, typename U>
        // constexpr bool operator==(Allocator<T> const & lhs, Allocator<U> const & rhs);

        // template <typename T, typename U>
        // constexpr bool operator!=(Allocator<T> const & lhs, Allocator<U> const & rhs);
    };

    

    template<typename T>
    Allocator<T>::~Allocator() {
        size_t size = _used_blocks.size();
        for (size_t i = 0; i < size; ++i) {
            T* ptr = _used_blocks.back();
            _used_blocks.pop_back();
            delete ptr;
        }
    }

    template<typename T>
    T* Allocator<T>::allocate(size_t n) {
        if (_free_blocks.size() > 0 && n == 1) {
            T* ptr = _free_blocks.back();
            _free_blocks.pop_back();
            return ptr;
        }
        T* ptr = reinterpret_cast<T*>(::operator new(n * sizeof(T)));
        _used_blocks.push_back(ptr);
        return ptr;
    }

    template<typename T> 
    void Allocator<T>::deallocate(T* ptr, size_t size) {
        for (size_t i = 0; i < size; ++i) {
            _free_blocks.push_back(ptr + i * sizeof(T));
        }
    }


}

#endif // ALLOCATOR_H