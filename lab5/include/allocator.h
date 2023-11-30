#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <iostream>
#include <deque>

namespace mai {

    template<typename T>
    class Allocator {
    private:    
        std::deque<std::pair<size_t, T*>> _used_blocks;
        std::deque<std::pair<size_t, T*>> _free_blocks;
    public:
        using value_type = T;
        using ptr = T*;
        using const_ptr = T const *;
        using size_type = size_t;

        Allocator() = default;
        Allocator(Allocator<T> const & other) = delete;
        Allocator(Allocator<T>&& other);
        Allocator& operator=(Allocator<T> const & other) = delete;
        Allocator& operator=(Allocator<T>&& other);
        virtual ~Allocator();

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
    Allocator<T>::Allocator(Allocator<T>&& other) {
        _used_blocks = std::move(other._used_blocks);
        _free_blocks = std::move(other._free_blocks);
    }

    template<typename T>
    Allocator<T>& Allocator<T>::operator=(Allocator<T>&& other) {
        while (!_used_blocks.empty()) {
            delete _used_blocks.back().second;
            _used_blocks.pop_back();
        }
        while (!_free_blocks.empty()) {
            delete _free_blocks.back().second;
            _free_blocks.pop_back();
        }

        _used_blocks = std::move(other._used_blocks);
        _free_blocks = std::move(other._free_blocks);
        
        return *this;
    }

    template<typename T>
    Allocator<T>::~Allocator() {
        size_t free_blocks_size = _free_blocks.size();
        for (size_t i = 0; i < free_blocks_size; ++i) {
            T* ptr = _free_blocks[i].second;
            delete ptr;
        }
    }

    template<typename T>
    T* Allocator<T>::allocate(size_t n) { // Скорость тоже оставляет желать лучшего
        for (size_t i = 0; i < _free_blocks.size(); ++i) {
            if (n <= _free_blocks[i].first) {
                T* ptr = _free_blocks[i].second;
                _used_blocks.push_back(_free_blocks[i]);
                _free_blocks.erase(_free_blocks.begin() + i);
                return ptr;
            }
        }
        T* ptr = reinterpret_cast<T*>(::operator new(n * sizeof(T)));
        _used_blocks.push_back({n, ptr});
        return ptr;
    }

    template<typename T>
    void Allocator<T>::deallocate(T* ptr, size_t size) { // ОЧЕНЬ медленно работает
        if (ptr == nullptr) return;
        for (size_t i = 0; i < _used_blocks.size(); ++i) {
            if (_used_blocks[i].first == size && _used_blocks[i].second == ptr) {
                _free_blocks.push_back(_used_blocks[i]);
                _used_blocks.erase(_used_blocks.begin() + i);
                return;
            }
            // Вопрос: что делать в остальных случаях?
            //         как ускорить?
        }
        throw std::logic_error("Error: deallocate");
    }


}

#endif // ALLOCATOR_H