// 3_선언16.c
#include <stdio.h>

// 1. const 상수를 const가 아닌 포인터를 통해 참조(읽기/쓰기)하는 것은
//    미정의 동작입니다.

// 2. volatile 변수를 volatile이 아닌 포인터를 통해 참조(읽기/쓰기)하는 것은
//    미정의 동작입니다.

// 3. restrict 한정된 포인터를 일반 포인터를 통해 참조(읽기/쓰기)하는 것은
//    허용됩니다.

// const int c = 10;
volatile int v = 0;

int main(void)
{
    const int c = 10;
    int* pc = &c; /* 컴파일 경고 */

    *pc = 100; /* 미정의 동작 */
    printf("%d\n", *pc); /* 미정의 동작 */
    printf("%d\n", c);

    int* pv = &v; /* 컴파일 경고 */
    *pv = 100; /* 미정의 동작 */
    printf("%d\n", *pv); /* 미정의 동작 */

    int n = 10;
    int* restrict pr = &n;
    int* pn = pr;

    *pn = 100;
    printf("%d\n", *pn);

    return 0;
}
