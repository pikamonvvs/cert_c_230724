// 5_타입6.c
#include <stdio.h>
#include <limits.h>

// 1. 부호 있는 정수의 연산은 오버플로우의 가능성이 있습니다.
// 2. 오버플로우(Overflow)는 미정의 동작입니다.

int main(void)
{
    int a;
    int b;

    a = INT_MAX;
    b = 1;

    long long result = a + b; /* 오버플로우, 미정의 동작 */
    printf("result: %lld\n", result);

    return 0;
}
