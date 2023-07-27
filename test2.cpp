#include <iostream>
using namespace std;
// test2.cpp

// C++은 다양한 선형 자료구조를 제공합니다. => STL, Container
#include <vector>
#include <list>

template <typename T>
void print_array(T begin, T end)
{
    auto p = begin;
    while (p != end) {
        std::cout << *p << std::endl;
        ++p;
    }
}

int main()
{
    // int arr[5] = { 1, 2, 3, 4, 5 };
    // vector<int> arr = { 1, 2, 3, 4, 5 };
    list<int> arr = { 1, 2, 3, 4, 5 };
    print_array(std::begin(arr), std::end(arr));
}
