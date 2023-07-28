// 5_타입11.c
#include <stdio.h>
#include <math.h>

// 부동 소수점
// 1) float: 32bit
// 2) double: 64bit
// 3) long double
//  - MSVC: 64bit
//  -  GCC: 128bit

// 상수 리터럴을 표현할 때,
// long, long long, long double
// => 대문자 L을 사용해야 합니다.
#if 0
int main(void)
{
    printf("%zu\n", sizeof(float));
    printf("%zu\n", sizeof(double));
    printf("%zu\n", sizeof(long double));

    // float f = 3.14F;
    float f = 3.14f;
    double d = 3.14;
    long double ld = 3.14L;

    return 0;
}
#endif

// - 정수를 0으로 나누거나 나머지 연산은 미정의 동작입니다.
// - 부동 소수점 타입은 0으로 나누는 것은
//   미정의 동작이 아닙니다.
//    * 부동 소수점을 0으로 나누면 => 무한대 => inf
//    * 부동 소수점 타입을 0/0으로 나누면 => nan(Not a number)

// - 부동 소수점 연산을 수행하면서, inf 또는 nan이 발생하지 않도록
//   주의해야 합니다.
#if 0
int main(void)
{
    // float a = 10;
    float a = 0;
    float b = 0;

    float result = a / b;
    printf("%f\n", result);

    float x = NAN;
    printf("%f\n", x + 10); // NAN
    printf("%d\n", x == NAN); // NAN은 비교가 불가능합니다.

    if (isnan(x)) {
        printf("x는 NAN 입니다.\n");
    }

    float y = INFINITY;
    float y2 = 0.0 / 0.0;
    printf("%f\n", y + 10); // INFINITY
    printf("%d\n", y == INFINITY); // 1
    printf("%d\n", y == y2); // 무한대도 비교가 불가능합니다.

    if (isinf(y)) {
        printf("y는 INFINITY 입니다.\n");
    }
    if (isinf(y2)) {
        printf("y는 INFINITY 입니다.\n");
    }

    return 0;
}
#endif

// 부동 소수점은 연산에 오차가 존재합니다.
int main(void)
{
    double a = 0.1 * 7;
    double b = 0.7;

#if 0
    if (a == b) {
        printf("동등합니다...\n");
    } else {
        printf("%lf\n", a);
        printf("%lf\n", b);
    }
#endif

    if (fabs(a - b) < 0.000000001) {
        printf("동등합니다...\n");
    }

    return 0;
}
