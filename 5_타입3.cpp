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

int main()
{
    int8_t c1 = 10;
    int8_t c2 = 20;
    PRINT_TYPE(c1 + c2); // promotion => int

    int a = 100;
    int b = 200;
    PRINT_TYPE(a + b); // int

    long la = 100L;
    long lb = 200L;

    PRINT_TYPE(la + lb); // long
}
