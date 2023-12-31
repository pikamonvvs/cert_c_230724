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
    // (*pn)++;

    // ++*pn;
    ++(*pn); /* 우선순위 문제는 발생하지 않지만, 가독성을 위해서 괄호를 사용합니다. */
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
#if 0
int main(void)
{
    int a, b, c, d;

    a = b = c = d = 0;
    d = a++ && ++b;
    printf("%d %d %d %d\n", a, b, c, d); // 1 0 0 0

    a = b = c = d = 0;
    d = ++a || ++b;
    printf("%d %d %d %d\n", a, b, c, d); // 1 0 0 1

    // 1. &&, || 우선순위가 다릅니다.
    // 2. 우선순위는 결합을 결정합니다.
    //  => 10 + 2 * 3 => 10 + (2 * 3);
    // 3. 연산자는 우선순위와 결합의 방향이 존재합니다.
    // 결론: &&, || 연산자를 함께 사용할 경우, 괄호를 반드시 사용해서
    //      우선순위 문제가 발생하지 않도록 주의해야 합니다.
    a = b = c = d = 0;
    // d = ++a || b++ && ++c;

    d = ++a || (b++ && ++c);
    printf("%d %d %d %d\n", a, b, c, d); // 1 0 0 1

    int e = 0;
    a = b = c = d = 0;

    e = a++ || b++ && ++c || d++;
    // e = (a++ || (b++ && ++c)) || d++;

    printf("%d %d %d %d %d\n", a, b, c, d, e);
    // 1 1 0 1 0

    return 0;
}
#endif

#if 1
void foo(int a, int b)
{
    printf("%d, %d\n", a, b);
}

int main(void)
{
    int a, b, c;

    // 대입/복합 대입 연산자는 오른쪽에서 왼쪽으로 연산이 수행됩니다.
    a = b = c = 10;
    // a = b = (c = 10);
    // a = (b = 10));
    // a = (10);

    // 나열 연산자(Comma operator)
    // => 사용하지 않는 것이 좋습니다.
    foo(10, (20, 30));

    return 0;
}
#endif
