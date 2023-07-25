// 3_선언2.c
#include <stdio.h>

#if 0
const int** ipp;
int* ip;
const int i = 42;

int main(void)
{
    ipp = &ip;
    *ipp = &i;

    *ip = 100; /* 미정의 동작 */

    printf("end\n");

    return 0;
}
#endif

#if 0
const int** ipp;
const int* ip;
const int i = 42;

int main(void)
{
    ipp = &ip;
    *ipp = &i;

    // *ip = 100;

    printf("end\n");

    return 0;
}
#endif

// 핵심
// - const 위치
// 1) * 기호 앞에 존재할 때
//  => 대상체의 값을 변경할 수 없습니다.
//   p -----> <n>

// 2) * 기호 뒤에 존재할 때
//  => 자신의 값을 변경할 수 없습니다.
//  <p> -----> n

int main(void)
{
    int n = 10;
    int x = 100;

    const int* p1 = &n;
    p1 = &x;
    // *p1 = 100; /* 에러 */

    int const* p2 = &n;
    p2 = &x;
    // *p2 = 100; /* 에러 */

    int* const p3 = &n;
    *p3 = 100;
    // p3 = &x; /* 에러 */

    const int* const p4 = &n;
    int const* const p5 = &n;

    return 0;
}
