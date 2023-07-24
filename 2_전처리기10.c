// 2_전처리기10.c
#include <stdio.h>

#if 0
// 매크로 함수
// 1) 호출하지 않고, 전처리 과정에서 텍스트 치환을 수행합니다.
//   => 함수 호출 오버헤드가 존재하지 않습니다.

// 2) 타입에 종속적이지 않은 함수를 구현할 수 있습니다.
#define ABS(x) ((x) > 0 ? (x) : -(x))

// 타입에 따라서, 여러개의 함수를 제공해야 합니다.
// 동일한 이름의 함수를 여러개 제공할 수 없습니다.
// => 각 타입에 따라서 다른 이름의 함수를 구현해야 합니다.
static inline int iabs(int x) { return x > 0 ? x : -x; }
static inline double dabs(double x) { return x > 0 ? x : -x; }
static inline long long llabs(long long x) { return x > 0 ? x : -x; }

int main(void)
{
    int n = -10;
    printf("%d\n", ABS(n));
    printf("%d\n", iabs(n));

    double d = -3.14;
    printf("%lf\n", ABS(d));
    printf("%lf\n", dabs(n));

    return 0;
}
#endif

// #define ABS(x) ((x) > 0 ? (x) : -(x))
// > 미정의 동작의 가능성이 있습니다.
//   하나의 이름(ABS)을 통해, 모든 타입에 대해서 사용할 수 있습니다.

#if 0
static inline int iabs(int x) { return x > 0 ? x : -x; }
static inline double dabs(double x) { return x > 0 ? x : -x; }
static inline long long llabs(long long x) { return x > 0 ? x : -x; }
// > 미정의 동작은 발생하지 않습니다.
//   각 타입에 따라서 다른 이름의 함수를 사용해야 합니다.

// 해결 방법. C11표준 - _Generic

#define ABS(x) _Generic((x), int: iabs(x), double: dabs(x), long long: llabs(x))

int main(void)
{
    int n = -10;
    printf("%d\n", ABS(n));
    printf("%d\n", iabs(n));

    double d = -3.14;
    printf("%lf\n", ABS(d));
    printf("%lf\n", dabs(n));

    long long ll = -32423232323LL;
    printf("%lld\n", ABS(ll));
    printf("%lld\n", llabs(ll));

    return 0;
}
#endif

#define PrintValue(x) _Generic((x), int: printf("Int: %d\n", x), double: printf("Double: %lf\n", x), char*: printf("String: %s\n", x), default: printf("Unknown type\n"))

int main(void)
{
    int a = 42;
    double d = 3.14;
    char* s = "Hello";

    PrintValue(a);
    PrintValue(d);
    PrintValue(s);

    return 0;
}
