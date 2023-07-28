// 5_타입6.c
#include <stdio.h>
#include <limits.h>

// 1. 부호 있는 정수의 연산은 오버플로우의 가능성이 있습니다.
// 2. 오버플로우(Overflow)는 미정의 동작입니다.

// 3. 오버플로우는 미정의 동작이므로, 그로 인한 취약점이 발생할 수 있으며
//    오버플로우가 발생하지 않도록 방어해야 합니다.
#if 0
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
#endif

#if 0
int main(void)
{
    int a;
    int b;
    int result;

    // a = INT_MAX;
    // b = 1;

    a = INT_MIN;
    b = -1;
    if ((a > 0 && b > 0) && (a > (INT_MAX - b))) {
        printf("Overflow\n"); // 양수 일때
    } else if ((a < 0 && b < 0) && (a < (INT_MIN - b))) {
        printf("Overflow\n"); // 음수 일때
    } else {
        result = a + b;
        printf("result: %d\n", result);
    }

    return 0;
}
#endif

int main(void)
{
    int a;
    int b;
    int result;

    b = INT_MAX;
    a = 2;

    // result = a * b; /* Overflow! */
    // printf("result: %d\n", result);

    int is_overflow = 0;
    if (a > 0) { // a가 양수 일때
        if (b > 0) { // b가 양수 일때
            if (b != 0 && a > (INT_MAX / b)) {
                printf("Overflow!\n");
                is_overflow = 1;
            }

        } else { // b가 음수 일때
            if (a != 0 && b < (INT_MIN / a)) {
                printf("Overflow!\n");
                is_overflow = 1;
            }
        }

    } else { // a가 음수 일때
        if (b > 0) {
            if (b != 0 && a < (INT_MIN / b)) {
                printf("Overflow!\n");
                is_overflow = 1;
            }

        } else {
            if (a != 0 && b < (INT_MAX / a)) {
                printf("Overflow!\n");
                is_overflow = 1;
            }
        }
    }

    if (!is_overflow) {
        result = a * b;
        printf("result: %d\n", result);
    }

    return 0;
}
