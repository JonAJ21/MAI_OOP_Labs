#ifndef ITEM_QUEUE_H
#define ITEM_QUEUE__H

#include <iostream>

namespace mai {

    template<typename T>
    struct Item {
        T _data;
        Item<T>* _next;
    };

    template<typename T, template <typename> typename Allocator = std::allocator>
    class Queue final {
    private:
        Allocator<Item<T>> _allocator;
        Item<T>* _head;
        Item<T>* _tail;
        size_t _size;
    public:
        
        class QueueIterator final {
        private:
            Item<T>* _item;
        public:
            friend class Queue;
            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = T;
            using pointer_type = T*;
            using reference_type = T&;
            
            QueueIterator() = default;
            QueueIterator(Item<T>* ptr) : _item(ptr) {}
            ~QueueIterator() = default;

            T& operator*() const {
                if (_item == nullptr) {
                    throw std::logic_error("Error: iterator");
                }
                return _item->_data;
            }

            QueueIterator& operator++() {
                if (_item == nullptr) {
                    throw std::logic_error("Error: iterator");
                }
                _item = _item->_next;
                return *this;
            }

            QueueIterator& operator++(int) {
                auto item = *this;
                ++(*this);
                return item;
            }

            QueueIterator& operator+=(size_t n) {
                for (size_t i = 0; i < n; ++i) {
                    if (_item != nullptr) {
                        ++(*this);
                    }
                }
                return *this;
            }

            bool operator==(QueueIterator const & other) const {
                return _item == other._item;
            }

            bool operator!=(QueueIterator const & other) const {
                return _item != other._item;
            }

        };

        class ConstQueueIterator final {
        private:
            Item<T> const * _item;
        public:
            friend class Queue;
            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = T const;
            using pointer_type = T const *;
            using reference_type = T const &;
            
            ConstQueueIterator() = default;
            ConstQueueIterator(Item<T> const * ptr) : _item(ptr) {}
            ~ConstQueueIterator() = default;
            
            T& operator*() const {
                if (_item == nullptr) {
                    throw std::logic_error("Error: iterator");
                }
                return _item->_data;
            }

            ConstQueueIterator& operator++() {
                if (_item == nullptr) {
                    throw std::logic_error("Error: iterator");
                }
                _item = _item->_next;
                return *this;
            }

            ConstQueueIterator& operator++(int) {
                auto item = *this;
                ++(*this);
                return item;
            }

            ConstQueueIterator& operator+=(size_t n) {
                for (size_t i = 0; i < n; ++i) {
                    if (_item != nullptr) {
                        ++(*this);
                    }
                }
                return *this;
            }

            bool operator==(ConstQueueIterator const & other) const {
                return _item == other._item;
            }

            bool operator!=(ConstQueueIterator const & other) const {
                return _item != other._item;
            }

        };

        Queue() : _size(0) {
            _head = _tail = _allocator.allocate(1);
        }
        
        Queue(size_t size, T value = T()) : _size(0) {
            _head = _tail = _allocator.allocate(1);
            for (size_t i = 0; i < size; ++i) {
                this->push(value);
            }
        }
        Queue(std::initializer_list<T> const & init_list) : _size(0) {
            _head = _tail = _allocator.allocate(1);
            for (auto el : init_list) {
                this->push(el);
            }
        }
        Queue(Queue<T, Allocator> const & other) : _size(0) {
            QueueIterator it {other._head};
            QueueIterator end {other._tail};
            _head = _tail = _allocator.allocate(1);
            for (; it != end; ++it) {
                this->push(*it);
            }
        }
        Queue(Queue<T, Allocator>&& other) : _head(other._head), _tail(other._tail), _size(other._size) {
            _allocator = std::move(other._allocator);
            other._head = nullptr;
            other._tail = nullptr;
            other._size = 0;
        }
        Queue<T, Allocator>& operator=(Queue<T, Allocator> const & other) {
            this->clear();
            _size = 0;
            QueueIterator it {other._head};
            QueueIterator end {other._tail};
            for (; it != end; ++it) {
                this->push(*it);
            }
            return *this;
        }
        Queue<T, Allocator>& operator=(Queue<T, Allocator>&& other) {
            this->clear();
            _allocator.deallocate(_head, 1);
            _head = other._head;
            _tail = other._tail;
            _size = other._size;
            _allocator = std::move(other._allocator);
            other._head = nullptr;
            other._tail = nullptr;
            other._size = 0;
            return *this;
        }
        ~Queue() {
            this->clear();
            _allocator.deallocate(_head, 1);
        }

        // void reserve(size_t capacity);
        //     //TODO
        void clear() {
            while(!this->empty()) {
                this->pop();
            }
        }

        T& front() const {
            if (_head == _tail) {
                throw std::logic_error("Error: queue is empty");
            }
            return _head->_data;
        }

        void pop() {
            if (_head == _tail) {
                throw std::logic_error("Error: queue is empty");
            }
            Item<T>* prev_head = _head;
            _head = _head->_next;
            --_size;
            _allocator.deallocate(prev_head, 1);
        }

        void push(T const & value) {
            _tail->_next = _allocator.allocate(1);
            _tail->_data = value;
            _tail = _tail->_next;
            ++_size;
        }

        bool empty() const noexcept {
            return _head == _tail;
        }

        size_t size() const noexcept {
            return _size;
        }

        // void print(std::ostream& os) const noexcept;
    };
}

#endif // ITEM_QUEUE_H