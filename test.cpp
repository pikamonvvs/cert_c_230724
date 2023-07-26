
// 자원 소유권(Ownership)
// 1) 독점
//   : 복사 금지

// 2) 공유
//   : 참조 계수 복사 수행

// Smart Pointer
#include <iostream>
#include <memory>
// unique_ptr
// => 소유권 독점
//    소유권 이동

// shared_ptr

class Resource { };

int main()
{
    std::unique_ptr<Resource> p1(new Resource);
    std::cout << p1 << std::endl;

    // std::unique_ptr<Resource> p2 = p1; // 복사 금지
    std::unique_ptr<Resource> p2 = std::move(p1);

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;

    return 0;
}
