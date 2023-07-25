// 3_선언10.c
#include <stdio.h>

// 함수를 만들 때, 인자를 고정하는 것이 아닌
// "가변 인자"를 사용할 수 있습니다.
// - printf / scanf

// int printf(const char * fmt, ...)
// 1. 가변 인자를 사용하기 위해서는, 반드시 고정 인자가 1개 필요합니다.

// 2. 가변 인자 함수는 함수의 설계자와 함수의 사용자간의 [암묵적인 계약]을 정의해야 합니다.
//    계약을 통해 전달된 인자의 수를 결정할 수 있습니다.
#if 0
int main(void)
{
    printf("Hello\n"); // 1

    int n = 10;
    printf("Hello: %d\n", n); // 2

    double d = 3.14;
    printf("Hello: %d, %lf\n", n, d); // 3

    return 0;
}
#endif

// 3. 가변 인자를 통해 전달되는 인자의 타입을 알 수 없습니다.
//  => 암묵적인 계약
//   %d => int
//   %s => const char* / char[] / char*
//   %c => char
//   ...

#include <stdarg.h>
// 1) va_start: 초기화
// 2) va_arg: 인자를 얻어올 수 있습니다.
// 3) va_end: 정리

enum {
    VA_END = -1
};

// 방법 1. 마지막 인자로 VA_END가 전달됩니다.
int average(int first, ...)
{
    int sum = 0;
    int cnt = 0;

    va_list ap;
    va_start(ap, first); // 초기화

    int i = first;
    while (i != VA_END) {
        sum += i;
        ++cnt;

        i = va_arg(ap, int); // 가변인자를 통해 전달된 인자를 얻을 수 있습니다.
    }
    va_end(ap); // 정리

    return (cnt != 0) ? sum / cnt : 0;
}

int main(void)
{
    int result;
    result = average(10, 20, 30, VA_END);
    printf("result: %d\n", result);

    result = average(10, 20, VA_END);
    printf("result: %d\n", result);

    // 문제점
    result = average(10, 20, -1, VA_END);
    printf("result: %d\n", result);

    return 0;
}
