// 4_타입7.c
#include <limits.h>
#include <stdio.h>

// 1. unsigned(부호가 없는) 피연산자를 포함하는 계산은
//    오버플로우가 발생하지 않습니다.

// 2. unsigned 결과값이 저장되는 정수 타입으로 표현될 수 없는 경우
//    나머지 연산을 통해 값을 줄여서 "wrap around"라고 합니다.
//  => 정수 래핑(wrapping)

// 3. 부호 있는 정수의 Overflow는 미정의 동작이지만,
//    부호 없는 정수의 Wrapping은 미정의 동작이 아닙니다.

// 4. 정수 래핑은 논리적 오류의 원인이 될 수 있으므로,
//    주의해야 합니다.

#if 0
int main(void)
{
    unsigned int a = UINT_MAX;
    int b = 1;

    printf("%u\n", a + b); /* 정수 래핑, 미정의 동작이 아닙니다. */

    return 0;
}
#endif

int main(void)
{
    unsigned int a;
    unsigned int b;
    unsigned int result;

    a = UINT_MAX;
    b = 1;

    result = a + b; /* OK! */
    // 방법 1. 연산의 결과가 정수 래핑이 발생했는지 확인합니다.
    if (result < a) {
        printf("Wrapping!\n");
    } else {
        printf("result: %d\n", result);
    }

    // 방법 2. 연산의 결과가 래핑이 발생할 가능성이 있는지 미리 확인합니다.
    if (a > UINT_MAX - b) {
        printf("Wrapping!\n");
    } else {
        result = a + b;
        printf("result: %d\n", result);
    }

    // 방법 3. GCC 내장 함수
    int error;

    // 주의사항: 오버플로우가 아닙니다.
    error = __builtin_uadd_overflow(a, b, &result);
    if (0 == error) {
        printf("result: %d\n", result);
    } else {
        printf("Wrapping!\n");
    }

    return 0;
}
