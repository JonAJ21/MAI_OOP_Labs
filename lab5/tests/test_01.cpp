#include <gtest/gtest.h>

#include "allocator.h"
#include "item_queue.h"

TEST(queue, All) {
    
    mai::Queue<int, mai::Allocator> q1;
    ASSERT_TRUE(q1.size() == 0);
    ASSERT_TRUE(q1.empty() == true);
    ASSERT_TRUE(q1.empty() == true);

    mai::Queue<char, mai::Allocator> q2 {'a', 'b', 'c', 'd'};
    mai::Queue<char, mai::Allocator> q3 {q2};
    ASSERT_TRUE(q2.size() == 4);
    ASSERT_TRUE(q2.empty() == false);
    q2.clear();
    ASSERT_TRUE(q2.size() == 0);
    ASSERT_TRUE(q2.empty() == true);

    ASSERT_TRUE(q3.size() == 4);
    ASSERT_TRUE(q3.empty() == false);
    ASSERT_TRUE(q3.front() == 'a');
    q3.pop();
    ASSERT_TRUE(q3.size() == 3);
    ASSERT_TRUE(q3.empty() == false);
    ASSERT_TRUE(q3.front() == 'b');
    q3.push('p');
    ASSERT_TRUE(q3.size() == 4);
    q3.pop();
    q3.pop();
    q3.pop();
    ASSERT_TRUE(q3.front() == 'p');
    q3.pop();
    ASSERT_TRUE(q2.size() == 0);
    ASSERT_TRUE(q2.empty() == true);


    mai::Queue<double, mai::Allocator> q4(10, 1.2);
    ASSERT_TRUE(q4.size() == 10);
    ASSERT_TRUE(q4.empty() == false);

    mai::Queue<double, mai::Allocator> q5 {0.2, 1.3, 2.4, 3.5};
    ASSERT_TRUE(q5.size() == 4);
    ASSERT_TRUE(q5.empty() == false);

    mai::Queue<double, mai::Allocator> q6{std::move(q5)};
    ASSERT_TRUE(q6.size() == 4);
    ASSERT_TRUE(q6.empty() == false);
    ASSERT_TRUE(q6.front() == 0.2);

    q6 = q4;
    ASSERT_TRUE(q6.size() == 10);
    ASSERT_TRUE(q6.empty() == false);
    ASSERT_TRUE(q6.front() == 1.2);

    mai::Queue<double, mai::Allocator> q7{2, 43.5};
    q7 = std::move(q6);
    ASSERT_TRUE(q7.size() == 10);
    ASSERT_TRUE(q7.empty() == false);
    ASSERT_TRUE(q7.front() == 1.2);
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}