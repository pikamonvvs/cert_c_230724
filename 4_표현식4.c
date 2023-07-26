// 4_표현식4.c
#include <stdio.h>

// 1. 우선순위 규칙은 식별자의 오른쪽에 위치하는 연산자가
//    우선순위가 높습니다.
//  => [], (), ++, --
//  => 식별자를 기준으로 왼쪽과 오른쪽에 연산자가 존재하는 경우
//     먼저 수행되어야 하는 연산자가 오른쪽이 아니면,
//     반드시 괄호가 필요합니다.

void increment(int* pn)
{
    // *pn++;
    (*pn)++;
}

int main(void)
{
    int n = 10;
    increment(&n);

    printf("n: %d\n", n);

    return 0;
}
