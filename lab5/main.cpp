#include <iostream>
#include <map>
#include <chrono>
#include "queue.h"
#include "allocator.h"

#include <deque>

int main() {

    // std::deque<int> d {1, 2, 3, 4, 5};
    // for (auto el : d) {
    //     std::cout << el << ' ';
    // }
    // std::cout << std::endl;

    // d.erase(d.begin() + 3);
    // for (auto el : d) {
    //     std::cout << el << ' ';
    // }

    // std::map<int, int, std::less<int>, mai::Allocator<std::pair<const int, int>>> m;

    // int64_t counter = 1;
    // m.insert(std::pair<int, int>(0, 0));
    // for (int64_t i = 1; i < 10; ++i) {
    //     counter *= i;
    //     m.insert(std::pair<int, int>(i, counter));
    // }

    // for (auto e: m) {
    //     std::cout << e.first << ' ' << e.second << '\n';
    // }



    {
        auto begin = std::chrono::high_resolution_clock::now();
        using Allocator = mai::Allocator<std::pair<const int, int>>;
        std::map<int, int, std::less<int>, Allocator> m;
        // std::map<int, int> m;
        int64_t counter = 1;
        m.insert(std::pair<int, int>(0, 0));
        for (int64_t i = 1; i < 10000; ++i) {
            counter *= i;
            m.insert(std::pair<int, int>(i, counter));
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "test1: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
    }
    {
        auto begin = std::chrono::high_resolution_clock::now();
        using Allocator = std::allocator<std::pair<const int, int>>;
        std::map<int, int, std::less<int>, Allocator> m;
        // std::map<int, int> m;
        int64_t counter = 1;
        m.insert(std::pair<int, int>(0, 0));
        for (int64_t i = 1; i < 10000; ++i) {
            counter *= i;
            m.insert(std::pair<int, int>(i, counter));
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "test2: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
    }
    
    // for (auto e: m) {
    //     std::cout << e.first << ' ' << e.second << '\n';
    // }

    // mai::Queue<int, mai::Allocator<int>> q{10, 2, 3, 4, 5};
    
    // mai::Queue<int, mai::Allocator<int>> q2;
    // q2 = q;

    // // std::cout << q << std::endl;
    // q.print(std::cout);
    // std::cout << "capacity: " << q.capacity() << std::endl;
    // std::cout << "size: " << q.size() << std::endl;
    // std::cout << std::boolalpha << "empty: " << q.empty() << std::endl;

    // q.push(125);
    // q.push(125);
    // q.push(125);
    // q.push(125);
    // q.push(125);
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.push(125);
    // q.push(125);
    // q.push(125);
    // // std::cout << q << std::endl;
    // // q.reserve(3);
    // q.print(std::cout);
    // std::cout << "capacity: " << q.capacity() << std::endl;
    // std::cout << "size: " << q.size() << std::endl;
    // std::cout << std::boolalpha << "empty: " << q.empty() << std::endl;




    return 0;
}  