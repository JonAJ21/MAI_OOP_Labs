#include <iostream>
#include "queue.h"

int main() {
    mai::Queue<int> q{10, 2, 3, 4, 5};
    
    mai::Queue<int> q2;
    q2 = q;

    std::cout << q << std::endl;
    std::cout << "capacity: " << q.capacity() << std::endl;
    std::cout << "size: " << q.size() << std::endl;
    std::cout << std::boolalpha << "empty: " << q.empty() << std::endl;

    q.push(125);
    q.push(125);
    q.push(125);
    q.push(125);
    q.push(125);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.push(125);
    q.push(125);
    q.push(125);
    std::cout << q << std::endl;
    std::cout << "capacity: " << q.capacity() << std::endl;
    std::cout << "size: " << q.size() << std::endl;
    std::cout << std::boolalpha << "empty: " << q.empty() << std::endl;




    return 0;
}  