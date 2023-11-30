#include <iostream>
#include <map>
#include <chrono>
#include "item_queue.h"
#include "allocator.h"

#include <deque>

int main() {

    std::map<int, int, std::less<int>, mai::Allocator<std::pair<const int, int>>> m;

    int64_t counter = 1;
    m.insert(std::pair<int, int>(0, 0));
    for (int64_t i = 1; i < 10; ++i) {
        counter *= i;
        m.insert(std::pair<int, int>(i, counter));
    }

    for (auto e: m) {
        std::cout << e.first << ' ' << e.second << '\n';
    }
     
    std::cout << "======================================" << std::endl;
    
    
    mai::Queue<int, mai::Allocator> q2 {1, 10, 3, 4, 5}; 
    
    mai::Queue<int, mai::Allocator> q{1, 2, 3, 4, 2,2,3,3,1};
    q = std::move(q2);
    std::cout << q.front() << std::endl;
    // std::cout << q.size() << std::endl;
    q.pop();

    std::cout << q.front() << std::endl;
    // std::cout << q.size() << std::endl;
    q.pop();

    std::cout << q.front() << std::endl;
    // std::cout << q.size() << std::endl;
    q.pop();

    std::cout << q.front() << std::endl;
    // std::cout << q.size() << std::endl;
    q.pop();

    std::cout << q.front() << std::endl;
    // std::cout << q.size() << std::endl;
    q.pop();


    // {
    //     auto begin = std::chrono::high_resolution_clock::now();
    //     using Allocator = mai::Allocator<std::pair<const int, int>>;
    //     std::map<int, int, std::less<int>, Allocator> m;
    //     // std::map<int, int> m;
    //     int64_t counter = 1;
    //     m.insert(std::pair<int, int>(0, 0));
    //     for (int64_t i = 1; i < 1000; ++i) {
    //         counter *= i;
    //         m.insert(std::pair<int, int>(i, counter));
    //     }
    //     auto end = std::chrono::high_resolution_clock::now();
    //     std::cout << "test1: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
    // }
    // {
    //     auto begin = std::chrono::high_resolution_clock::now();
    //     using Allocator = std::allocator<std::pair<const int, int>>;
    //     std::map<int, int, std::less<int>, Allocator> m;
    //     // std::map<int, int> m;
    //     int64_t counter = 1;
    //     m.insert(std::pair<int, int>(0, 0));
    //     for (int64_t i = 1; i < 1000; ++i) {
    //         counter *= i;
    //         m.insert(std::pair<int, int>(i, counter));
    //     }
    //     auto end = std::chrono::high_resolution_clock::now();
    //     std::cout << "test2: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
    // }
    


    return 0;
}  