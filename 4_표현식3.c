// 4_표현식3.c
#include <stdio.h>
#include <stdlib.h>

// 홀수인지 판단하는 함수 입니다.
#if 0
int is_odd(int n)
{
    return n % 2 == 1;
}
#endif

int is_odd(int n)
{
    return abs(n % 2) == 1;
}

// 1) n % 2 => r
//    C는 나머지 연산의 결과의 부호에 대한 정의가 존재하지 않았습니다.
// 2) C99 표준에서 정수에 대한 /, % 연산의 결과는 나누는 수의 부호로 결정됩니다.

int main(void)
{
    printf("%d\n", is_odd(-1));
    printf("%d\n", is_odd(-3));
    printf("%d\n", is_odd(5));
    printf("%d\n", is_odd(7));

    printf("%d\n", is_odd(-2));
    printf("%d\n", is_odd(-4));
    printf("%d\n", is_odd(6));
    printf("%d\n", is_odd(8));

    return 0;
}
