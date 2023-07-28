// 5_타입3.cpp
#include <cstdint>
#include <iostream>
#include <string_view>
using namespace std;

template <typename T>
constexpr auto type_name()
{
    std::string_view name, prefix, suffix;
#ifdef __clang__
    name = __PRETTY_FUNCTION__;
    prefix = "auto type_name() [T = ";
    suffix = "]";
#elif defined(__GNUC__)
    name = __PRETTY_FUNCTION__;
    prefix = "constexpr auto type_name() [with T = ";
    suffix = "]";
#elif defined(_MSC_VER)
    name = __FUNCSIG__;
    prefix = "auto __cdecl type_name<";
    suffix = ">(void)";
#endif
    name.remove_prefix(prefix.size());
    name.remove_suffix(suffix.size());
    return name;
}

#define PRINT_TYPE(x) cout << type_name<decltype(x)>() << endl

// $ g++ 5_타입3.cpp -std=c++17
// 1) 같은 타입이면 변환하지 않습니다.
//  예외) 프로모션: int보다 작은 타입의 경우,
//              프로모션 후 수행됩니다.
#if 0
int main()
{
    int8_t c1 = 10;
    int8_t c2 = 20;
    PRINT_TYPE(c1 + c2); // promotion => int

    int16_t s1 = 10;
    int16_t s2 = 20;
    PRINT_TYPE(s1 + s2); // promotion => int

    int a = 100;
    int b = 200;
    PRINT_TYPE(a + b); // int

    long la = 100L;
    long lb = 200L;

    PRINT_TYPE(la + lb); // long
}
#endif

// 2) 두 개의 피연산자가 정수 타입이면, 범위가 큰 타입(상위 랭크 타입)으로 변환됩니다.
#if 0
int main()
{
    int a = 10;
    long la = 100L;

    PRINT_TYPE(a + la); // long

    long lb = 10000L;
    long long llb = 2000000LL;
    PRINT_TYPE(lb + llb);
}
#endif

// 3) 부호 없는 정수 타입의 피연산자가 다른 피연산자의 순위보다 크거나 같은 경우 부호 있는 정수 타입의 피연산자는 부호 없는 정수 타입으로 변환됩니다.
#if 0
int main()
{
    unsigned int ua = 10U;
    int a = -100;
    PRINT_TYPE(ua + a); // unsigned int

    unsigned long lb = 100L;
    int b = 10000;
    PRINT_TYPE(lb + b); // unsigned long
}
#endif

// 4) 부호 있는 정수 타입의 피연산자가 부호 없는 타입의 모든 값을
//    표현할 수 있는 경우, 부호 없는 정수 타입의 피연산자는
//    부호 있는 정수 타입으로 변환됩니다.
#if 0
int main()
{
    long long a = 10LL;
    unsigned int ua = 11000U;
    PRINT_TYPE(a + ua); // long long
}
#endif

#if 0
// 5) 부호 있는 정수 타입의 피연산자가 부호 없는 타입의 모든 값을
//    표현할 수 없는 경우, 부호 있는 정수 타입의 피연산자가 동일 타입의
//    부호 없는 타입으로 두 피연산자 모두 변환됩니다.
int main()
{
    long long lla = 1000LL;
    unsigned long la = 10000L;

    PRINT_TYPE(lla + la); // unsigned long long
}
#endif

#if 0
int main()
{
    int si = -1;
    unsigned int ui = 1;

    PRINT_TYPE(si + ui);
}
#endif

#if 0
struct s {
    signed int a : 8;
    signed int b : 8;

    unsigned int c : 8;
    unsigned int d : 8;

    unsigned int e : 31;
    unsigned int f : 31;

    unsigned int g : 32;
    unsigned int h : 32;
};

int main()
{
    struct s data = { .a = 10, .b = 20, .c = 30, .d = 40 };

    PRINT_TYPE(data.a + data.b); // int
    PRINT_TYPE(data.c + data.d); // int
    PRINT_TYPE(data.e + data.f); // int
    PRINT_TYPE(data.g + data.h); // unsigned int
}
#endif

int main()
{
    uint16_t a = 10;
    uint16_t b = 20;

    PRINT_TYPE(a + b);
}
