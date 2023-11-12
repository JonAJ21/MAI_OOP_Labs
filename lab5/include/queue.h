#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

namespace mai {

    template<typename T, typename Allocator = std::allocator<T>>
    class Queue {
    private:
        Allocator _allocator;
        size_t _size;
        size_t _capacity;
        T* _data;
        size_t _head_idx;
    public:
        Queue();
        Queue(size_t size);
        Queue(std::initializer_list<T> const & init_list);
        // Queue(Allocator const & allocator);
        Queue(Queue<T, Allocator> const & other);
        Queue(Queue<T, Allocator>&& other);
        Queue<T, Allocator>& operator=(Queue<T, Allocator> const & other);
        Queue<T, Allocator>& operator=(Queue<T, Allocator>&& other);
        ~Queue();

        void reserve(size_t capacity);
        void clear();

        T& front();
        void pop();
        void push(T const & value);

        bool empty();
        size_t size();
        size_t capacity();

        
        void print(std::ostream& os) const;
        template<T, Allocator> friend std::ostream& operator<<(std::ostream& os, Queue<T, Allocator> const & queue);
    };

    template<typename T, typename Allocator>
    Queue<T, Allocator>::Queue() : _size(0), _capacity(0), _data(nullptr), _head_idx(0) {
    }

    template<typename T, typename Allocator>
    Queue<T, Allocator>::Queue(size_t size) : _size(size), _capacity(size), _head_idx(0) {
        _data = _allocator.allocate(_capacity);
    }

    template<typename T, typename Allocator>
    Queue<T, Allocator>::Queue(std::initializer_list<T> const & init_list) : _size(init_list.size()), _capacity(init_list.size()), _head_idx(0) {
        _data = _allocator.allocate(_capacity);
        size_t i = 0;
        for (auto elem : init_list) {
            _data[i++] = elem;
        }
    }


    // template<typename T, typename Allocator>
    // Queue<T, Allocator>::Queue(Allocator const & allocator) : _allocator(allocator), _size(0), _capacity(0), _data(nullptr) {
    //     // TODO
    // }

    template<typename T, typename Allocator>
    Queue<T, Allocator>::Queue(Queue<T, Allocator> const & other) : _size(other._size), _capacity(other._capacity), _head_idx(other._head_idx) {
        _data = _allocator.allocate(_capacity);
        for (size_t i = 0; i < _size; ++i) {
            _data[(_head_idx + i) % _capacity] = other._data[(_head_idx + i) % _capacity];
        }
    }

    template<typename T, typename Allocator>
    Queue<T, Allocator>::Queue(Queue<T, Allocator>&& other) : _size(other._size) , _capacity(other._capacity), _data(other._data), _head_idx(other._head_idx) {
        other._size = 0;
        other._capacity = 0;
        other._data = nullptr;
        other._head_idx = 0;
    }

    template<typename T, typename Allocator>
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

    template<typename T, typename Allocator>
    Queue<T, Allocator>& Queue<T, Allocator>::operator=(Queue<T, Allocator>&& other) {
        if (this == &other) return *this;
        // _allocator = other._allocator;
        _size = other._size;
        _capacity = other._capacity;
        _data = other._data;
        _head_idx = other._head_idx;
        
        other._size = 0;
        other._capacity = 0;
        other._data = nullptr;
        other._head_idx = 0;
        return *this;
    }

    template<typename T, typename Allocator>
    Queue<T, Allocator>::~Queue() {
        _allocator.deallocate(_data, _capacity);
    }

    template<typename T, typename Allocator>
    void Queue<T, Allocator>::reserve(size_t capacity) {
        T* data = _allocator.allocate(capacity);
        if (capacity > _size ) {
            for (size_t i = 0; i < _size; ++i) {
                data[(_head_idx + i) % _capacity] = _data[i];
            }
        } else {
            for (size_t i = 0; i < capacity; ++i) {
                data[(_head_idx + i) % _capacity] = _data[i];
            }
            _size = capacity;
        }
        _allocator.deallocate(_data, _capacity);
        _data = data;
        _head_idx = 0;
        _capacity = capacity;
    }

    template<typename T, typename Allocator>
    void Queue<T, Allocator>::clear() {
        for (size_t i = 0; i < _size; ++i) {
            _data[(_head_idx + i) % _capacity] = T();
        }
        _size = 0;
        _head_idx = 0;
    }

    template<typename T, typename Allocator>
    T& Queue<T, Allocator>::front() {
        if (_size == 0) {
            return T(); // Вероятно, здесь нужно кидать ошибку, но какую?
        }
        return _data[_head_idx];
    }

    template<typename T, typename Allocator>
    void Queue<T, Allocator>::pop() {
        if (_size == 0) { 
            return; // Вероятно, здесь нужно кидать ошибку, но какую?
        }
        T head_value = _data[_head_idx];
        _data[_head_idx] = T();
        _head_idx = (_head_idx + 1) % _capacity;
        --_size; 
    }

    template<typename T, typename Allocator>
    void Queue<T, Allocator>::push(T const & value) {
        if (_capacity == _size) {
            this->reserve(_capacity * 2);
        }
        _data[(_head_idx + _size++) % _capacity] = value;
    }

    template<typename T, typename Allocator>
    bool Queue<T, Allocator>::empty() {
        return (_size == 0);
    }

    template<typename T, typename Allocator>
    size_t Queue<T, Allocator>::size() {
        return _size;
    }

    template<typename T, typename Allocator>
    size_t Queue<T, Allocator>::capacity() {
        return _capacity;
    }

    template<typename T, typename Allocator>
    void Queue<T, Allocator>::print(std::ostream& os) const {
        for (size_t i = 0; i < _size; ++i) {
            os << _data[(_head_idx + i) % _capacity] << ' ';
        }
    }

    template<typename T, typename Allocator>
    std::ostream& operator<<(std::ostream& os, mai::Queue<T, Allocator> const & queue) {
        queue.print(os);
        return os;
    }

}
#endif // QUEUE_H