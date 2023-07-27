// 4_표현식13.c
#include <stdio.h>

// ++, --
// => 증감 연산자
//  : 다른 연산과 복합적으로 사용할 경우,
//    미정의 동작이 발생하지 않도록 주의해야 합니다.

void func(int a, int b)
{
    printf("%d %d\n", a, b);
}

int main(void)
{
    int i = 2;
    // func(i++, i); /* 미정의 동작 */

    func(i, i);
    i++;

    return 0;
}
