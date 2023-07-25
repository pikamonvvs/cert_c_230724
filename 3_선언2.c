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
#if 0
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
#endif

int main(void)
{
    int x = 10;
    int y = 20;

    int* px = &x;
    int* py = &y;

    // pp1 ---> px ---> x
    int** pp1 = &px;

    // 1) **pp1
    **pp1 = 100;
    // 2) *pp1
    *pp1 = &y;
    // 3)  pp1
    pp1 = &py;

    // const int** pp2 = &px;
    int const** pp2 = &px;
    // pp1 ---> px ---> [x]
    // 1) **pp2
    // **pp2 = 100; /* Error */
    // 2) *pp2
    *pp2 = &y;
    // 3)  pp1
    pp2 = &py;

    int* const* pp3 = &px;
    // pp1 ---> [px] ---> x

    // 1) **pp3
    **pp3 = 100;
    // 2) *pp3
    // *pp3 = &y; /* Error */
    // 3)  pp1
    pp3 = &py;

    int** const pp4 = &px;
    // [pp1] ---> px ---> x
    // 1) **pp4
    **pp4 = 100;
    // 2) *pp4
    *pp4 = &y;
    // 3)  pp4
    // pp4 = &py;  /* Error */

    return 0;
}
