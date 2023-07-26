// 4_표현식4.c
#include <stdio.h>

// 1. 우선순위 규칙은 식별자의 오른쪽에 위치하는 연산자가
//    우선순위가 높습니다.
//  => [], (), ++, --
//  => 식별자를 기준으로 왼쪽과 오른쪽에 연산자가 존재하는 경우
//     먼저 수행되어야 하는 연산자가 오른쪽이 아니면,
//     반드시 괄호가 필요합니다.
#if 0
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
#endif

// 2. &&, ||
//  => 논리 연산자 AND / OR는 단축 평가를 수행합니다.
//   (expr1) && (expr2)
//    : expr1 평가가 거짓인 경우, expr2 수행하지 않습니다.
//   (expr1) || (expr2)
//    | expr1 평가가 참인 경우, expr2 수행하지 않습니다.
int main(void)
{
    int a, b, c, d;

    a = b = c = d = 0;
    d = a++ && ++b;
    printf("%d %d %d %d\n", a, b, c, d); // 1 0 0 0

    a = b = c = d = 0;
    d = ++a || ++b;
    printf("%d %d %d %d\n", a, b, c, d); // 1 0 0 1

    return 0;
}
