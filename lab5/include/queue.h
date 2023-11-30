#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

namespace mai {

    template<typename T, template <typename> typename Allocator = std::allocator>
    class Queue final {
    private:
        Allocator<T> _allocator;
        size_t _size;
        size_t _capacity;
        T* _data;
        size_t _head_idx;
    public:
        
        Queue() noexcept;
        Queue(size_t size);
        Queue(std::initializer_list<T> const & init_list);
        Queue(Queue<T, Allocator> const & other);
        Queue(Queue<T, Allocator>&& other) noexcept;
        Queue<T, Allocator>& operator=(Queue<T, Allocator> const & other);
        Queue<T, Allocator>& operator=(Queue<T, Allocator>&& other) noexcept;
        ~Queue();

        void reserve(size_t capacity);
        void clear() noexcept;

        T& front() const;
        void pop();
        void push(T const & value);

        bool empty() const noexcept;
        size_t size() const noexcept;
        size_t capacity() const noexcept;

        void print(std::ostream& os) const noexcept;
    };

    template<typename T, template <typename> typename Allocator>
    Queue<T, Allocator>::Queue() noexcept : _size(0), _capacity(0), _data(nullptr), _head_idx(0) {
    }

    template<typename T, template <typename> typename Allocator>
    Queue<T, Allocator>::Queue(size_t size) : _size(size), _capacity(size), _head_idx(0) {
        _data = _allocator.allocate(_capacity);
    }

    template<typename T, template <typename> typename Allocator>
    Queue<T, Allocator>::Queue(std::initializer_list<T> const & init_list) : _size(init_list.size()), _capacity(init_list.size()), _head_idx(0) {
        _data = _allocator.allocate(_capacity);
        size_t i = 0;
        for (auto elem : init_list) {
            _data[i++] = elem;
        }
    }

    template<typename T, template <typename> typename Allocator>
    Queue<T, Allocator>::Queue(Queue<T, Allocator> const & other) : _size(other._size), _capacity(other._capacity), _head_idx(other._head_idx) {
        _data = _allocator.allocate(_capacity);
        for (size_t i = 0; i < _size; ++i) {
            _data[(_head_idx + i) % _capacity] = other._data[(_head_idx + i) % _capacity];
        }
    }

    template<typename T, template <typename> typename Allocator>
    Queue<T, Allocator>::Queue(Queue<T, Allocator>&& other) noexcept : _allocator(other._allocator), _size(other._size) , _capacity(other._capacity), _data(other._data), _head_idx(other._head_idx) {
        other._allocator = Allocator();
        other._size = 0;
        other._capacity = 0;
        other._data = nullptr;
        other._head_idx = 0;
    }

    template<typename T, template <typename> typename Allocator>
    Queue<T, Allocator>& Queue<T, Allocator>::operator=(Queue<T, Allocator> const & other) {
        if (this == &other) return *this;
        _size = other._size;
        _capacity = other._capacity;
        _head_idx = other._head_idx;
        _data = _allocator.allocate(_capacity);
        for (size_t i = 0; i < _size; ++i) {
            _data[(_head_idx + i) % _capacity] = other._data[(_head_idx + i) % _capacity];
        }
        return *this;
    }

    template<typename T, template <typename> typename Allocator>
    Queue<T, Allocator>& Queue<T, Allocator>::operator=(Queue<T, Allocator>&& other) noexcept {
        if (this == &other) return *this;
        
        _allocator = other._allocator;
        _size = other._size;
        _capacity = other._capacity;
        _data = other._data;
        _head_idx = other._head_idx;
        
        other._allocator = Allocator();
        other._size = 0;
        other._capacity = 0;
        other._data = nullptr;
        other._head_idx = 0;
        return *this;
    }

    template<typename T, template <typename> typename Allocator>
    Queue<T, Allocator>::~Queue() {
        _allocator.deallocate(_data, _capacity);
    }

    template<typename T, template <typename> typename Allocator>
    void Queue<T, Allocator>::reserve(size_t capacity) {
        T* data = _allocator.allocate(capacity);
        if (capacity > _size ) {
            for (size_t i = 0; i < _size; ++i) {
                data[(_head_idx + i) % capacity] = _data[i];
            }
        } else {
            for (size_t i = 0; i < capacity; ++i) {
                data[(_head_idx + i) % capacity] = _data[i];
            }
            _size = capacity;
        }
        _allocator.deallocate(_data, _capacity);
        _data = data;
        _head_idx = 0;
        _capacity = capacity;
    }

    template<typename T, template <typename> typename Allocator>
    void Queue<T, Allocator>::clear() noexcept {
        for (size_t i = 0; i < _size; ++i) {
            _data[(_head_idx + i) % _capacity] = T();
        }
        _size = 0;
        _head_idx = 0;
    }

    template<typename T, template <typename> typename Allocator>
    T& Queue<T, Allocator>::front() const {
        if (_size == 0) {
            throw std::logic_error("Error (front()): queue is empty");
        }
        return _data[_head_idx];
    }

    template<typename T, template <typename> typename Allocator>
    void Queue<T, Allocator>::pop() {
        if (_size == 0) {
            throw std::logic_error("Error (pop()): queue is empty");
        }
        T head_value = _data[_head_idx];
        _data[_head_idx] = T();
        _head_idx = (_head_idx + 1) % _capacity;
        --_size; 
    }

    template<typename T, template <typename> typename Allocator>
    void Queue<T, Allocator>::push(T const & value) {
        if (_capacity == _size) {
            this->reserve(_capacity * 2);
        }
        _data[(_head_idx + _size++) % _capacity] = value;
    }

    template<typename T, template <typename> typename Allocator>
    bool Queue<T, Allocator>::empty() const noexcept{
        return (_size == 0);
    }

    template<typename T, template <typename> typename Allocator>
    size_t Queue<T, Allocator>::size() const noexcept{
        return _size;
    }

    template<typename T, template <typename> typename Allocator>
    size_t Queue<T, Allocator>::capacity() const noexcept {
        return _capacity;
    }

    template<typename T, template <typename> typename Allocator>
    void Queue<T, Allocator>::print(std::ostream& os) const noexcept{
        for (size_t i = 0; i < _size; ++i) {
            os << _data[(_head_idx + i) % _capacity] << ' ';
        }
    }

}
#endif // QUEUE_H