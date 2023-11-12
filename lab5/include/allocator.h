#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <iostream>
#include <deque>

namespace mai {
    
    template<typename T>
    class Allocator final {
    private:
        size_t _memory_sz;
        std::deque<std::pair<void*, size_t>> _used_blocks;
        std::deque<void*> _free_blocks;
        size_t _free_count;
    public:
        using value_type = T;
        using pointer = T*;
        using const_pointer = T const *;
        using size_type = size_t;

        Allocator();
        Allocator(Allocator const & other);
        Allocator(Allocator&& other);
        Allocator& operator=(Allocator<T> const & other);
        Allocator& operator=(Allocator<T>&& other);
        ~Allocator();

        template<typename U>
        struct rebind {using other = Allocator<U>};

        T* allocate(size_t n);
        void dealocate(T* pointer, size_t);

        template <typename T, typename U>
        constexpr bool operator==(Allocator<T> const & lhs, Allocator<U> const & rhs);

        template <typename T, typename U>
        constexpr bool operator!=(Allocator<T> const & lhs, Allocator<U> const & rhs);
    };
}

#endif // ALLOCATOR_H